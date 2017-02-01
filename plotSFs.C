void plotSFs(){

  // Expects hadded files from GenHTScaleFactor
  TFile *f100 = TFile::Open("WJets100ext.root");
  TFile *f200 = TFile::Open("WJets200ext.root");
  TFile *f400 = TFile::Open("WJets400ext.root");
  TFile *f600 = TFile::Open("WJets600ext.root");
  TFile *f800 = TFile::Open("WJets800ext.root");
  TFile *f1200 = TFile::Open("WJets1200ext.root");
  TFile *f2500 = TFile::Open("WJets2500ext.root");
  TFile *finc = TFile::Open("WJetsIncext.root");

  // Opens the LHETree object
  TTree *T100 = (TTree*)f100->Get("GenHTScaleFactor/LHEtree");
  TTree *T200 = (TTree*)f200->Get("GenHTScaleFactor/LHEtree");
  TTree *T400 = (TTree*)f400->Get("GenHTScaleFactor/LHEtree");
  TTree *T600 = (TTree*)f600->Get("GenHTScaleFactor/LHEtree");
  TTree *T800 = (TTree*)f800->Get("GenHTScaleFactor/LHEtree");
  TTree *T1200 = (TTree*)f1200->Get("GenHTScaleFactor/LHEtree");
  TTree *T2500 = (TTree*)f2500->Get("GenHTScaleFactor/LHEtree");
  TTree *Tinc = (TTree*)finc->Get("GenHTScaleFactor/LHEtree");

  // Histograms with constant binning to see shapes
  TH1D *H100  = new TH1D("H100","GenHT, pre-matching xsec scale",50,0,5000); H100->Sumw2();
  TH1D *H200  = new TH1D("H200","GenHT, pre-matching xsec scale",50,0,5000); H200->Sumw2();
  TH1D *H400  = new TH1D("H400","GenHT, pre-matching xsec scale",50,0,5000); H400->Sumw2();
  TH1D *H600  = new TH1D("H600","GenHT, pre-matching xsec scale",50,0,5000); H600->Sumw2();
  TH1D *H800  = new TH1D("H800","GenHT, pre-matching xsec scale",50,0,5000); H800->Sumw2();
  TH1D *H1200 = new TH1D("H1200","GenHT, pre-matching xsec scale",50,0,5000); H1200->Sumw2();
  TH1D *H2500 = new TH1D("H2500","GenHT, pre-matching xsec scale",50,0,5000); H2500->Sumw2();
  TH1D *Hinc  = new TH1D("Hinc","GenHT, pre-matching xsec scale",50,0,5000); Hinc->Sumw2();

  // Histograms binned according to sample boundaries.
  double bins[9] = {0,100,200,400,600,800,1200,2500,5000};  
  // TH1D *H100  = new TH1D("H100","GenHT, pre-matching xsec scale",8,bins); H100->Sumw2();
  // TH1D *H200  = new TH1D("H200","GenHT, pre-matching xsec scale",8,bins); H200->Sumw2();
  // TH1D *H400  = new TH1D("H400","GenHT, pre-matching xsec scale",8,bins); H400->Sumw2();
  // TH1D *H600  = new TH1D("H600","GenHT, pre-matching xsec scale",8,bins); H600->Sumw2();
  // TH1D *H800  = new TH1D("H800","GenHT, pre-matching xsec scale",8,bins); H800->Sumw2();
  // TH1D *H1200 = new TH1D("H1200","GenHT, pre-matching xsec scale",8,bins); H1200->Sumw2();
  // TH1D *H2500 = new TH1D("H2500","GenHT, pre-matching xsec scale",8,bins); H2500->Sumw2();
  // TH1D *Hinc  = new TH1D("Hinc","GenHT, pre-matching xsec scale",8,bins); Hinc->Sumw2();

  // Optional test with the Madgraph weights -- normalization is a problem here since this
  // should be used with a known "N" madgraph runs, where the event weights in 1 Madgraph
  // run should equal the cross section. We lack that information. 
  // T100->Draw("genht>>H100","(weightOrig)*(1)");
  // T200->Draw("genht>>H200","(weightOrig)*(1)");
  // T400->Draw("genht>>H400","(weightOrig)*(1)");
  // T600->Draw("genht>>H600","(weightOrig)*(1)");
  // T800->Draw("genht>>H800","(weightOrig)*(1)");
  // T1200->Draw("genht>>H1200","(weightOrig)*(1)");
  // T2500->Draw("genht>>H2500","(weightOrig)*(1)");
  // Tinc->Draw("genht>>Hinc","(weightOrig)*(1)");

  // Standard unweighted draw command
  T100->Draw("genht>>H100");
  T200->Draw("genht>>H200");
  T400->Draw("genht>>H400");
  T600->Draw("genht>>H600");
  T800->Draw("genht>>H800");
  T1200->Draw("genht>>H1200");
  T2500->Draw("genht>>H2500");
  Tinc->Draw("genht>>Hinc");

  // 1/fb arbitrary luminosity
  // weight = lumi*pre-matching xsec / N_LHE_events
  H100->Scale(1000.0*13072.8173/290044442.0);
  H200->Scale(1000.0*4223.9214/176970364.0);
  H400->Scale(1000.0*627.9155/74659159.0);
  H600->Scale(1000.0*159.1029/206073807.0);
  H800->Scale(1000.0*73.4766/91933713.0);
  H1200->Scale(1000.0*17.5912/97857692.0);
  H2500->Scale(1000.0*0.3970/29554520.0);
  Hinc->Scale(1000.0*135668.9534/1069037433.0);
  
  // Option test for weighted histograms, divide by N files
  // guessing that 1 LHE file = 1 madgraph run? Doesn't 
  // seem to work.
  // H100->Scale(1000.0/6420.0);
  // H200->Scale(1000.0/3824.0);
  // H400->Scale(1000.0/1668.0);
  // H600->Scale(1000.0/4325.0);
  // H800->Scale(1000.0/2054.0);
  // H1200->Scale(1000.0/2175.0);
  // H2500->Scale(1000.0/706.0);
  // Hinc->Scale(1000.0/22866.0);

  // Add binned histograms together
  Htotal = (TH1D*)H100->Clone("Htotal");
  Htotal->Add(H200);
  Htotal->Add(H400);
  Htotal->Add(H600);
  Htotal->Add(H800);
  Htotal->Add(H1200);
  Htotal->Add(H2500);

  // Draw HT comparison
  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  gPad->SetLogy(1);
  Htotal->SetLineColor(kBlue);
  Htotal->Draw("hist");
  Hinc->SetLineColor(kRed);
  Hinc->Draw("hist same");
  c1->SaveAs("PMXsec_HT.png");
  c1->SaveAs("PMXsec_HT.pdf");
  c1->SaveAs("PMXsec_HT.root");

  Hratio = (TH1D*)Hinc->Clone("Hratio");
  Hdenom = (TH1D*)Htotal->Clone("Hdenom");

  // Ensure no overflow events are left out of scale factor calculation
  int nbins = Hratio->GetNbinsX();
  double addoverflow = Hratio->GetBinContent(nbins)+Hratio->GetBinContent(nbins+1);
  double erroverflow = sqrt(pow(Hratio->GetBinError(nbins),2)+pow(Hratio->GetBinError(nbins+1),2));
  Hratio->SetBinContent(nbins,addoverflow);
  Hratio->SetBinError(nbins,erroverflow);

  nbins = Hdenom->GetNbinsX();
  addoverflow = Hdenom->GetBinContent(nbins)+Hdenom->GetBinContent(nbins+1);
  erroverflow = sqrt(pow(Hdenom->GetBinError(nbins),2)+pow(Hdenom->GetBinError(nbins+1),2));
  Hdenom->SetBinContent(nbins,addoverflow);
  Hdenom->SetBinError(nbins,erroverflow);
  
  Hratio->Divide(Hdenom);
  
  // Draw ratio
  TCanvas *c2 = new TCanvas("c2","c2",800,600);
  gPad->SetLogy(0);
  Hratio->SetLineColor(kBlack);
  Hratio->Draw("hist");
  c2->SaveAs("PMXsec_Ratio.png");
  c2->SaveAs("PMXsec_Ratio.pdf");
  c2->SaveAs("PMXsec_Ratio.root");
  
  // print scale factors (makes sense when the sample-binned histograms are used) 
  cout << "Ratio Inclusive/Binned" << endl;
  for(int ibin = 1; ibin < nbins+1; ibin++){
    printf("%f +/- %f\n",Hratio->GetBinContent(ibin),Hratio->GetBinError(ibin));
  }
  
}
