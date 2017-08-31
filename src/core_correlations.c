void core_correlations(){
	gROOT->ProcessLine("#include <map>");
	gROOT->ProcessLine("#include <vector>");
	gROOT->ProcessLine("#include <string>");
	gSystem->Load("/uboone/app/users/markrl/sbnfit/whipping_star/src/mdict_h.so");

	gStyle->SetOptStat(0);

	TFile *fe = new TFile("/uboone/data/users/mastbaum/rw_test/fittree_nue_rw2.root");
	TTree *te = (TTree*)fe->Get("fittree");

	std::map<std::string, std::vector<double> > * fWeights = 0;
	TLorentzVector * fLepMom = 0;
	TBranch * be;
	TBranch * bw;
	int PDGnu;

	te->SetBranchAddress("leptonMom", &(fLepMom), &(be)  );
	te->SetBranchAddress("mcweight", &fWeights, &(bw) );
	te->SetBranchAddress("nuPDG", &PDGnu);

	TH2D * h_e_th = new TH2D("h_e_th","h_e_th",30,0,3.0,20,-1,1);
	TH1D * h_e = new TH1D("h_e","h_e",30,0,3);
	TH1D * h_th = new TH1D("h_th","h_th",20,-1,1);
	TVector3 zaxis(0,0,1);

	for(int i=0; i<10000;i++){
		if(i%1000==0) std::cout<<i<<" of "<<te->GetEntries()<<std::endl;
		te->GetEntry(i);
		if( PDGnu == 13 || PDGnu = -13){

			double lepAngle = cos(zaxis.Angle(fLepMom->Vect()));
			double lepE = fLepMom->E();					

			//fWeights->at("bnbcorrection_FluxHist").at(0);
			h_e_th->Fill(lepE, lepAngle  );
			h_e->Fill(lepE );
			h_th->Fill(lepAngle  );
		}

	}
	TCanvas *c = new TCanvas("c1","c1",1700,700);
	c->Divide(3,1);
	c->cd(1);
	h_e_th->Draw("colz");
	c->cd(2);
	h_e->Draw();
	c->cd(3);
	h_th->Draw();
	c->Update();
}
