void plot_nice(){
TFile * f = new TFile("covariance_matrix_ALL.root");

//TH2D *h = (TH2D*)f->Get("Frac Cov;1");
TH2D *h = (TH2D*)f->Get("Corr;1");

TCanvas *c = new TCanvas("c1","c1",1000,2000);
//c->SetGrid();
TPad *p = (TPad*)c->cd();

p->SetLeftMargin(0.15);
p->SetBottomMargin(0.15);
p->SetRightMargin(0.15);

gStyle->SetPalette(104);
gStyle->SetLabelSize(.025, "XY");
gStyle->SetTitleSize(.03, "XY");
gStyle->SetOptStat(0);

h->GetYaxis()->SetTitle("E_{e}                Cos(#theta_{e})            E_{#mu}               Cos(#theta_{#mu})");
h->GetYaxis()->CenterTitle(1);


h->GetXaxis()->SetTitle("E_{e}             Cos(#theta_{e})                E_{#mu}               Cos(#theta_{#mu})");
h->GetXaxis()->CenterTitle(1);

h->Draw("colz");

h->GetZaxis()->SetRangeUser(-1,1);

int eb = 29;
int cb = 20;
int t = 2*eb+2*cb;


h->UseCurrentStyle();
h->GetXaxis()->ChangeLabel(1,-1,-1,-1,-1,-1,"1 GeV");
h->GetXaxis()->ChangeLabel(2,-1,-1,-1,-1,-1,"2 GeV");
h->GetXaxis()->ChangeLabel(3,-1,-1,-1,-1,-1,"-1");
h->GetXaxis()->ChangeLabel(4,-1,-1,-1,-1,-1,"0");
h->GetXaxis()->ChangeLabel(5,-1,-1,-1,-1,-1,"-1");
h->GetXaxis()->ChangeLabel(6,-1,-1,-1,-1,-1,"1 GeV");
h->GetXaxis()->ChangeLabel(7,-1,-1,-1,-1,-1,"2 GeV");
h->GetXaxis()->ChangeLabel(8,-1,-1,-1,-1,-1,"-1");
h->GetXaxis()->ChangeLabel(9,-1,-1,-1,-1,-1,"0");
h->GetXaxis()->ChangeLabel(10,-1,-1,-1,-1,-1,"-1");

h->GetYaxis()->ChangeLabel(1,-1,-1,-1,-1,-1,"1 GeV");
h->GetYaxis()->ChangeLabel(2,-1,-1,-1,-1,-1,"2 GeV");
h->GetYaxis()->ChangeLabel(3,-1,-1,-1,-1,-1,"-1");
h->GetYaxis()->ChangeLabel(4,-1,-1,-1,-1,-1,"0");
h->GetYaxis()->ChangeLabel(5,-1,-1,-1,-1,-1,"-1");
h->GetYaxis()->ChangeLabel(6,-1,-1,-1,-1,-1,"1 GeV");
h->GetYaxis()->ChangeLabel(7,-1,-1,-1,-1,-1,"2 GeV");
h->GetYaxis()->ChangeLabel(8,-1,-1,-1,-1,-1,"-1");
h->GetYaxis()->ChangeLabel(9,-1,-1,-1,-1,-1,"0");
h->GetYaxis()->ChangeLabel(10,-1,-1,-1,-1,-1,"-1");


TLine *line1 = new TLine(1,1+eb-0.1,t,1+eb-0.1);
TLine *line2 = new TLine(1,eb+cb+0.5,t,eb+cb+0.5);
TLine *line3 = new TLine(1,2*eb+cb,t,2*eb+cb);

TLine *line4 = new TLine(1+eb-0.1,1,1+eb-0.1,t);
TLine *line5 = new TLine(0.5+eb+cb,1,0.5+eb+cb,t);
TLine *line6 = new TLine(2*eb+cb,1,2*eb+cb,t);

line1->SetLineWidth(3);
line2->SetLineWidth(5);
line4->SetLineWidth(3);
line3->SetLineWidth(3);
line5->SetLineWidth(5);
line6->SetLineWidth(3);

line1->Draw();
line2->Draw();
line3->Draw();
line4->Draw();
line5->Draw();
line6->Draw();
c->Update();


gPad->RedrawAxis("g"); 
}
