// -*- C++ -*-
//
// Package:    LHEAnalyzer/GenHTScaleFactor
// Class:      GenHTScaleFactor
// 
/**\class GenHTScaleFactor GenHTScaleFactor.cc LHEAnalyzer/GenHTScaleFactor/plugins/GenHTScaleFactor.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Julie Hogan
//         Created:  Tue, 31 Jan 2017 06:37:52 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "TMath.h"
#include "TH1.h"
#include "TH2D.h"
#include "TTree.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility> // std::pair
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class GenHTScaleFactor : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit GenHTScaleFactor(const edm::ParameterSet&);
      ~GenHTScaleFactor();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
  TH1D *Nevts;
  TH1D *GenHT;
  TH1D *GenHTweighted;
  TH1D *NHT_qq;
  TH1D *NHT_qbqb;
  TH1D *NHT_qqb;
  TH1D *NHT_qg;
  TH1D *NHT_qbg;
  TH1D *NHT_gg;
  TH1D *NHT_all;
  TTree *LHEtree;
  
  Float_t weightOrig;
  Float_t genht;
  Int_t   npartons;
  Int_t   npartons_ana;
  Int_t   collision;
  

      // ----------member data ---------------------------
  edm::EDGetTokenT<LHEEventProduct> LEIPtoken;  
  double htbins[23] = {0,50,100,150,200,250,300,350,400,500,600,700,800,900,1000,1200,1400,1600,1800,2000,3000,4000,5000};
  double samplebins[9] = {0,100,200,400,600,800,1200,2500,3000};
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenHTScaleFactor::GenHTScaleFactor(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");

   edm::InputTag LEIPtag("externalLHEProducer");
   LEIPtoken = consumes<LHEEventProduct>(LEIPtag);

   edm::Service<TFileService> fs;
   Nevts = fs->make<TH1D>("Nevts","",2,0,2); Nevts->Sumw2();
   GenHT = fs->make<TH1D>("GenHT","",8,samplebins); GenHT->Sumw2();
   GenHTweighted = fs->make<TH1D>("GenHTweighted","",8,samplebins); GenHTweighted->Sumw2();
   NHT_qq  = fs->make<TH1D>("NHT_qq ","",6,0,6); NHT_qq ->Sumw2();
   NHT_qbqb  = fs->make<TH1D>("NHT_qbqb ","",6,0,6); NHT_qbqb ->Sumw2();
   NHT_qqb = fs->make<TH1D>("NHT_qqb","",6,0,6); NHT_qqb->Sumw2();
   NHT_qg  = fs->make<TH1D>("NHT_qg ","",6,0,6); NHT_qg ->Sumw2();
   NHT_qbg = fs->make<TH1D>("NHT_qbg","",6,0,6); NHT_qbg->Sumw2();
   NHT_gg  = fs->make<TH1D>("NHT_gg ","",6,0,6); NHT_gg ->Sumw2();
   NHT_all = fs->make<TH1D>("NHT_all","",6,0,6); NHT_all->Sumw2();
   
   LHEtree = fs->make<TTree>("LHEtree","LHEtree");
   LHEtree->Branch("weightOrig",&weightOrig,"weightOrig/F");
   LHEtree->Branch("genht",&genht,"genht/F");
   LHEtree->Branch("npartons",&npartons,"npartons/I");
   LHEtree->Branch("collision",&collision,"collision/I");

}


GenHTScaleFactor::~GenHTScaleFactor()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
GenHTScaleFactor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  // Open the event product
  edm::Handle<LHEEventProduct> lhe_info;
  iEvent.getByToken(LEIPtoken,lhe_info);
  
  genht = 0;
  npartons = 0;
  collision = -1;
  weightOrig = 1.0;

  double ht = 0;
  int npts = 0;

  bool isgg = false;
  bool isqq = false;
  bool isqbqb = false;
  bool isqqb = false;
  bool isqg = false;
  bool isqbg = false;  

  int incoming1 = -99;
  int incoming2 = -99;

  // Save the madgraph event weight
  const lhef::HEPEUP& lheEvent =lhe_info->hepeup();
  weightOrig = lhe_info->originalXWGTUP();

  // Loop over HepEvent entries
  std::vector<lhef::HEPEUP::FiveVector> lheParticles = lheEvent.PUP;
  size_t numParticles = lheParticles.size();
  for(size_t idxParticle = 0; idxParticle < numParticles; ++idxParticle){

    // PDG ID
    int absPdgId = TMath::Abs(lheEvent.IDUP[idxParticle]);

    // Particle status
    int status = lheEvent.ISTUP[idxParticle];

    // Sum up pt and multiplicity of status 1 quarks and gluons
    if(status == 1 && ((absPdgId >= 1 && absPdgId <= 6) || absPdgId == 21)){
      ht += TMath::Sqrt(TMath::Power(lheParticles[idxParticle][0], 2.) + TMath::Power(lheParticles[idxParticle][1], 2.));
      npts++;
    }

    // Save ID of incoming particles
    if(status == -1){
      if(incoming1 == -99) incoming1 = absPdgId;
      else if(incoming2 == -99) incoming2 = absPdgId;
      else std::cout << "got a 3rd status -1: #1 = " << incoming1 << ", #2 = " << incoming2 << ", #3 = " << absPdgId << std::endl;
    }
  }

  // Split up events based on which type of collision occured
  if(incoming1 == 21 && incoming2 == 21) isqq = true;
  else if(incoming1 == 21 && incoming2 < 7 && incoming2 > 0) isqg = true;
  else if(incoming2 == 21 && incoming1 < 7 && incoming1 > 0) isqg = true;
  else if(incoming1 == 21 && incoming2 > -7 && incoming2 < 0) isqbg = true;
  else if(incoming2 == 21 && incoming1 > -7 && incoming1 < 0) isqbg = true;
  else if(incoming1 > 0 && incoming1 < 7 && incoming2 > 0 && incoming2 < 7) isqq = true;
  else if(incoming1 < 0 && incoming1 > -7 && incoming2 < 0 && incoming2 > -7) isqbqb = true;
  else if(incoming1 > 0 && incoming1 < 7 && incoming2 > -7 && incoming2 < 0) isqqb = true;
  else if(incoming2 > 0 && incoming2 < 7 && incoming1 > -7 && incoming1 < 0) isqqb = true;
  else std::cout << "Didn't categorize this one: #1 = " << incoming1 << ", #2 = " << incoming2 << std::endl;

  genht = ht;
  npartons = npts;

  // By-hand overflow prevention for histograms
  if(ht > 3000) ht = 2990;
  if(npts > 20) npts = 20;
  
  // Save multiplicity based on collision type
  if(isqq){ NHT_qq->Fill(npts); collision = 0;}
  if(isqbqb){ NHT_qbqb->Fill(npts); collision = 1;}
  if(isqqb){ NHT_qqb->Fill(npts); collision = 2;}
  if(isqg){ NHT_qg->Fill(npts); collision = 3;}
  if(isqbg){ NHT_qbg->Fill(npts); collision = 4;}
  if(isgg){ NHT_gg->Fill(npts); collision = 5;}

  // Fill histograms
  GenHT->Fill(ht);
  GenHTweighted->Fill(ht,weightOrig);
  NHT_all->Fill(npts);
  Nevts->Fill(1.0);

  // Fill tree
  LHEtree->Fill();
}


// ------------ method called once each job just before starting event loop  ------------
void 
GenHTScaleFactor::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
GenHTScaleFactor::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GenHTScaleFactor::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GenHTScaleFactor);
