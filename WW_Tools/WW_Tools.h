#ifndef WW_Tools_WW_Tools_WW_Tools_h
#define WW_Tools_WW_Tools_WW_Tools_h
//
// Original Author:  Mauricio Thiel
//         Created:  Wed, 15 Mar 2017 00:33:40 GMT
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/StreamID.h"

//CT-PPS
#include "DataFormats/CTPPSReco/interface/CTPPSFastRecHit.h"
#include "DataFormats/CTPPSReco/interface/CTPPSFastRecHitContainer.h"
#include "DataFormats/CTPPSReco/interface/CTPPSFastTrack.h"
#include "DataFormats/CTPPSReco/interface/CTPPSFastTrackContainer.h"

#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"

//CMS - Central
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"

#include "DataFormats/Math/interface/LorentzVector.h"
#include "TLorentzVector.h"
#include <vector>
#include "TTree.h"
#include "TCanvas.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "TLorentzVector.h"
#include "AnalysisDataFormats/EWK/interface/WMuNuCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "AnalysisDataFormats/EWK/interface/WMuNuCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "WW_Tools/CalculatePzNu.hpp"


typedef std::vector<CTPPSFastRecHit> CTPPSFastRecHitContainer;
typedef std::vector<CTPPSFastTrack> CTPPSFastTrackContainer;
edm::Handle<edm::PSimHitContainer> PSimHit;
edm::Handle<CTPPSFastRecHitContainer> recHits;
edm::Handle<CTPPSFastTrackContainer> tracksPPS;

//      typedef edm::View<reco::Vertex> VertexCollection;

edm::Handle<pat::MuonCollection> muons;
edm::Handle<reco::VertexCollection> vertices;
edm::Handle<pat::JetCollection> jets;
edm::Handle<reco::GenJetCollection> genjets;
edm::Handle<pat::ElectronCollection> electrons;
edm::Handle<pat::METCollection> MET;


#endif
