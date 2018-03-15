#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <getopt.h>
#include <cstring>

#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TString.h"
#include "TNtuple.h"
#include "TChain.h"
#include "TMath.h"
#include "TSystem.h"
#include "TMatrixT.h"
#include "TRandom.h"
#include "TError.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TLorentzVector.h"
#include "TVector3.h"

#include "TROOT.h"
#include "TRint.h"
#include "TSystem.h"
#include "TStyle.h"

#include <map>
#include <ctime>
#include "params.h"



#define no_argument 0
#define required_argument 1
#define optional_argument 2


/*************************************************************
 *************************************************************
 *		BEGIN example.cxx
 ************************************************************
 ************************************************************/
int main(int argc, char* argv[])
{

	std::string dict_location = "../../src/AutoDict_map_string__vector_double____cxx.so";
	gROOT->ProcessLine("#include <map>");
	gROOT->ProcessLine("#include <vector>");
	gROOT->ProcessLine("#include <string>");

	gSystem->Load(  (dict_location).c_str());
	gStyle->SetOptStat(0);



TFile * f = new TFile("/home/mark/work/uBooNE/uboone_covariance_builder/rootfiles/fittree_nue_rw2.root");

TTree *t = (TTree*)f->Get("fittree");


TBranch  * bweight =0;
double en=0;
int pdg=0;

std::map<std::string, std::vector<double> >  *fWeights = 0;


		delete fWeights;
		fWeights = 0;
		//t->SetBranchAddress("mcweight", &fWeights , &bweight);
		delete fWeights;
		fWeights = 0;

		t->SetBranchAddress("leptonEnergy",&en);
		t->SetBranchAddress("type",&pdg);



	for(int i=0; i< 20000; i++){
		t->GetEntry(i);

		if(i%1000==0) std::cout<<i<<" "<<en<<" "<<pdg<<" "<<std::endl;
		
		//if(i%1000==0) std::cout<<i<<" "<<en<<" "<<pdg<<" "<<fWeights->at("bnbcorrection_FluxHist").at(0)<<std::endl;

	}

	delete fWeights;
	fWeights=0;


}



