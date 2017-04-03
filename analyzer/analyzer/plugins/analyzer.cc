#include "WW_Tools/WW_Tools.h"

//
// class declaration
//


class analyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
	public:
		explicit analyzer(const edm::ParameterSet&);
		~analyzer();

		static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


	private:
		virtual void beginJob() override;
		virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
		virtual void endJob() override;

		// ----------member data ---------------------------
		//PPS Tokens
		edm::EDGetTokenT<reco::VertexCollection> verticesToken;
		edm::EDGetTokenT<pat::MuonCollection> muonsToken;
		edm::EDGetTokenT<pat::JetCollection> jetsToken;
		edm::EDGetTokenT<reco::GenJetCollection> genjetsToken;
		edm::EDGetTokenT<pat::METCollection> MetToken;
		edm::EDGetTokenT< CTPPSFastTrackContainer > _tracksPPSToken;	
		edm::EDGetTokenT<std::vector<size_t>> selectedjets;
		edm::EDGetTokenT<std::vector<size_t>> selectedmuons;
		edm::EDGetTokenT<std::vector<size_t>> SelectedProtonF;
		edm::EDGetTokenT<std::vector<size_t>> SelectedProtonB;
		edm::EDGetTokenT<std::vector<double>> SelectedVertices;
		edm::Handle<std::vector<reco::GenParticle>> genP;
		edm::EDGetTokenT<std::vector<reco::GenParticle>> GenToken;
		edm::Handle<std::vector<pat::PackedCandidate>> PFCand;
		edm::EDGetTokenT<std::vector<pat::PackedCandidate>> PFCandToken;		
		edm::EDGetTokenT< edm::HepMCProduct > mcEventToken; // label of MC event
		edm::Handle< edm::HepMCProduct > EvtHandle ;
		// creating the trees
		TTree* EventBranchs_PPS;
		TTree* EventBranchs_Jets;
		TTree* EventBranchs_Muon;
		TTree* EventBranchs_WJ;
		TTree* EventBranchs_Met;
		TTree* EventBranchs_WL;
		TTree* EventBranchs_WW;
		TTree* EventBranchs_pfCand;		
		TTree* EventBranchs_Neutrino;
		TTree* EventBranchs_Neutrino_Mix;
		TTree* EventBranchs_WL_Nu;
		TTree* EventBranchs_WL_Nu_Mix;
		TTree* EventBranchs_Gen;

		//	  TTree* EventBranchs_eletron;

		std::vector<double> *MxV 	= new std::vector<double> ();
		std::vector<double> *PFxiV 	= new std::vector<double> ();
		std::vector<double> *PBxiV 	= new std::vector<double> ();
		std::vector<double> *PFtV 	= new std::vector<double> ();
		std::vector<double> *PBtV 	= new std::vector<double> ();
		std::vector<double> *PFTofV = new std::vector<double> ();
		std::vector<double> *PBTofV = new std::vector<double> ();
		std::vector<double> *PFx1V 	= new std::vector<double> ();
		std::vector<double> *PFy1V 	= new std::vector<double> ();
		std::vector<double> *PBx1V 	= new std::vector<double> ();
		std::vector<double> *PBy1V 	= new std::vector<double> ();
		std::vector<double> *PFx2V 	= new std::vector<double> ();
		std::vector<double> *PFy2V 	= new std::vector<double> ();
		std::vector<double> *PBx2V 	= new std::vector<double> ();
		std::vector<double> *PBy2V 	= new std::vector<double> ();
                std::vector<double> *PFcellId      = new std::vector<double> ();
                std::vector<double> *PBcellId      = new std::vector<double> ();
		std::vector<double> *DTofV 	= new std::vector<double> ();
		std::vector<double> *DVV 	= new std::vector<double> ();
		std::vector<double> *MWWMXV_Nu = new std::vector<double> ();
		std::vector<double> *MWWMXV_Met = new std::vector<double> ();
		std::vector<double> *MWWMXV_Mix = new std::vector<double> ();
		std::vector<double> *Y_YV_Nu = new std::vector<double> ();
		std::vector<double> *Y_YV_Met = new std::vector<double> ();
		std::vector<double> *Y_YV_Mix = new std::vector<double> ();
		std::vector<double> *VtxzV = new std::vector<double> ();
		std::vector<double> *Ypp = new std::vector<double> ();
		std::vector<double> *Dvzpf = new std::vector<double> ();
		std::vector<double> *Dvxpf = new std::vector<double> ();
		std::vector<double> *Dvypf = new std::vector<double> ();
		std::vector<double> *genProtonF_xi = new std::vector<double> ();
		std::vector<double> *genProtonF_t = new std::vector<double> ();
		std::vector<double> *genProtonB_xi = new std::vector<double> ();
		std::vector<double> *genProtonB_t = new std::vector<double> ();


		double Mx, NVPPS, NPF, NPB, PFxi, PBxi, PFt, PBt, PFTof, PBTof, PFx1, PFy1, PBx1, PBy1, PFx2, PFy2, PBx2, PBy2, DTof, Vtxz, oPV, DV;
		double NM, Mpx, Mpy, Mpz, ME, Mpt, Mphi, Meta, DMoPVx, DMoPVy, DMoPVz;
		double NJ, J1px, J1py, J1pz, J1E, J1pt, J1phi, J1eta, J2px, J2py, J2pz, J2E, J2pt, J2phi, J2eta, DphiJJ, DetaJJ, DPtJJ, DPxJJ, DPyJJ, DPzJJ, DRJJ;
		double WJM, WJpx, WJpy, WJpz, WJpt, WJE, WJphi, WJeta; 
		double METPx, METPy, METPt, METphi, METE;
		double WLM, WLacop, WLE, WLpt;
		double MWW_Nu, MWW_Met, MWW_Mix, DWWphi_Nu, DWWphi_Met, DWWphi_Mix, WW_Y_Nu, WW_Y_Met, WW_Y_Mix, WW_DR_Nu, WW_DR_Met, WW_DR_Mix, WWacop_Nu, WWacop_Met, WWacop_Mix; 
		double J3pt, DRJ3J, WJMgen, WJMgenqq;
		double dif_muon, WWacop;
		double pi = 3.14159265359;
		double npfVtx, npf, N_pfCand_tot, N_pfCand_vtx, N_pfCand_extra;		
		double Neutrino_Px, Neutrino_Py, Neutrino_Pz, Neutrino_Pt, Neutrino_phi, Neutrino_eta, Neutrino_E;
		double Neutrino_mix_Px, Neutrino_mix_Py, Neutrino_mix_Pz, Neutrino_mix_Pt, Neutrino_mix_phi, Neutrino_mix_eta, Neutrino_mix_E;
		double WLeptonic_M, WLeptonic_Px, WLeptonic_Py, WLeptonic_Pz, WLeptonic_Pt, WLeptonic_phi, WLeptonic_eta, WLeptonic_E;
		double WLeptonic_mix_M, WLeptonic_mix_Px, WLeptonic_mix_Py, WLeptonic_mix_Pz, WLeptonic_mix_Pt,	WLeptonic_mix_phi, WLeptonic_mix_eta, WLeptonic_mix_E;	
		double AcopMuMet, AcopMuWJ;
		double genWhad_px, genWhad_py, genWhad_pz, genWhad_pt, genWhad_E, genWhad_phi, genWhad_eta, genWlep_px, genWlep_py, genWlep_pz, genWlep_pt, genWlep_E, genWlep_phi, genWlep_eta, genQrk1_px, genQrk1_py, genQrk1_pz, genQrk1_pt, genQrk1_E, genQrk1_phi, genQrk1_eta, genQrk2_px, genQrk2_py, genQrk2_pz, genQrk2_pt, genQrk2_E, genQrk2_phi, genQrk2_eta, genMuon_px, genMuon_py, genMuon_pz, genMuon_pt, genMuon_E, genMuon_phi, genMuon_eta, genNeut_px, genNeut_py,	genNeut_pz, genNeut_pt, genNeut_E, genNeut_phi, genNeut_eta;
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
analyzer::analyzer(const edm::ParameterSet& iConfig):
	verticesToken (consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices")))
	//	, electronsToken (consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons")))
	, muonsToken (consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons")))
	, jetsToken (consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets")))
	, genjetsToken (consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genjets")))
	, MetToken (consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("MET")))
	, _tracksPPSToken (consumes<CTPPSFastTrackContainer>(iConfig.getParameter<edm::InputTag>("tracksPPSTag")))
	, selectedjets (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("selectedjets")))
	, selectedmuons (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("selectedmuons")))
	, SelectedProtonF (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("SelectedProtonF")))
	, SelectedProtonB (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("SelectedProtonB")))
	, SelectedVertices (consumes<std::vector<double>>(iConfig.getParameter<edm::InputTag>("SelectedVertice")))
	, GenToken (consumes<std::vector<reco::GenParticle>>(iConfig.getParameter<edm::InputTag>("genP")))
	, PFCandToken (consumes<std::vector<pat::PackedCandidate>>(iConfig.getParameter<edm::InputTag>("PFCand")))
	, mcEventToken (consumes<edm::HepMCProduct>(iConfig.getUntrackedParameter<edm::InputTag>("MCEvent",std::string("")))){

		//now do what ever initialization is needed

		usesResource("TFileService");
		edm::Service<TFileService> fs;
		EventBranchs_PPS 				= fs->make<TTree>( "PPS","PPS" );
		EventBranchs_PPS->Branch("MxV"	,"std::vector<double>",&MxV);
		EventBranchs_PPS->Branch("PFxiV","std::vector<double>",&PFxiV);
		EventBranchs_PPS->Branch("PBxiV","std::vector<double>",&PBxiV);
		EventBranchs_PPS->Branch("PFtV"	,"std::vector<double>",&PFtV);
		EventBranchs_PPS->Branch("PBtV"	,"std::vector<double>",&PBtV);
		EventBranchs_PPS->Branch("PFTofV","std::vector<double>",&PFTofV);
		EventBranchs_PPS->Branch("PBTofV","std::vector<double>",&PBTofV);
		EventBranchs_PPS->Branch("PFx1V","std::vector<double>",&PFx1V);
		EventBranchs_PPS->Branch("PFy1V","std::vector<double>",&PFy1V);
		EventBranchs_PPS->Branch("PBx1V","std::vector<double>",&PBx1V);
		EventBranchs_PPS->Branch("PBy1V","std::vector<double>",&PBy1V);
		EventBranchs_PPS->Branch("PFy2V","std::vector<double>",&PFy2V);
		EventBranchs_PPS->Branch("PFx2V","std::vector<double>",&PFx2V);
		EventBranchs_PPS->Branch("PBx2V","std::vector<double>",&PBx2V);
		EventBranchs_PPS->Branch("PBy2V","std::vector<double>",&PBy2V);
                EventBranchs_PPS->Branch("PFcellId","std::vector<double>",&PFcellId);
                EventBranchs_PPS->Branch("PBcellId","std::vector<double>",&PBcellId);
		EventBranchs_PPS->Branch("DTofV","std::vector<double>",&DTofV);
		EventBranchs_PPS->Branch("DVV"	,"std::vector<double>",&DVV);
		EventBranchs_PPS->Branch("VtxzV","std::vector<double>",&VtxzV);	
		EventBranchs_PPS->Branch("Ypp","std::vector<double>",&Ypp);	
		EventBranchs_PPS->Branch("NVPPS",&NVPPS,"NVPPS/D");
		EventBranchs_PPS->Branch("oPV",&oPV,"oPV/D");	
		EventBranchs_Muon 				= fs->make<TTree>( "Muon","Muon" );
		EventBranchs_Muon->Branch("NM",&NM,"NM/D");
		EventBranchs_Muon->Branch("Mpx",&Mpx,"Mpx/D");
		EventBranchs_Muon->Branch("Mpy",&Mpy,"Mpy/D");
		EventBranchs_Muon->Branch("Mpz",&Mpz,"Mpz/D");
		EventBranchs_Muon->Branch("ME",&ME,"ME/D");
		EventBranchs_Muon->Branch("Mpt",&Mpt,"Mpt/D");
		EventBranchs_Muon->Branch("Mphi",&Mphi,"Mphi/D");
		EventBranchs_Muon->Branch("Meta",&Meta,"Meta/D");
		EventBranchs_Muon->Branch("DMoPVx",&DMoPVx,"DMoPVx/D");
		EventBranchs_Muon->Branch("DMoPVy",&DMoPVy,"DMoPVy/D");
		EventBranchs_Muon->Branch("DMoPVz",&DMoPVz,"DMoPVz/D");					
		EventBranchs_Jets 				= fs->make<TTree>( "Jets","Jets" );
		EventBranchs_Jets->Branch("NJ",&NJ,"NJ/D");
		EventBranchs_Jets->Branch("J1px",&J1px,"J1px/D");
		EventBranchs_Jets->Branch("J1py",&J1py,"J1py/D");
		EventBranchs_Jets->Branch("J1pz",&J1pz,"J1pz/D");
		EventBranchs_Jets->Branch("J1E",&J1E,"J1E/D");
		EventBranchs_Jets->Branch("J1pt",&J1pt,"J1pt/D");
		EventBranchs_Jets->Branch("J1phi",&J1phi,"J1phi/D");
		EventBranchs_Jets->Branch("J1eta",&J1eta,"J1eta/D");
		EventBranchs_Jets->Branch("J2px",&J2px,"J2px/D");
		EventBranchs_Jets->Branch("J2py",&J2py,"J2py/D");
		EventBranchs_Jets->Branch("J2pz",&J2pz,"J2pz/D");
		EventBranchs_Jets->Branch("J2E",&J2E,"J2E/D");
		EventBranchs_Jets->Branch("J2pt",&J2pt,"J2pt/D");
		EventBranchs_Jets->Branch("J2phi",&J2phi,"J2phi/D");
		EventBranchs_Jets->Branch("J2eta",&J2eta,"J2eta/D");
		EventBranchs_Jets->Branch("DphiJJ",&DphiJJ,"DphiJJ/D");
		EventBranchs_Jets->Branch("DetaJJ",&DetaJJ,"DetaJJ/D");
		EventBranchs_Jets->Branch("DPtJJ",&DPtJJ,"DPtJJ/D");
		EventBranchs_Jets->Branch("DPxJJ",&DPxJJ,"DPxJJ/D");
		EventBranchs_Jets->Branch("DPyJJ",&DPyJJ,"DPyJJ/D");
		EventBranchs_Jets->Branch("DPzJJ",&DPzJJ,"DPzJJ/D");		
		EventBranchs_Jets->Branch("DRJJ",&DRJJ,"DRJJ/D");		
		EventBranchs_Jets->Branch("J3pt",&J3pt,"J3pt/D");
		EventBranchs_Jets->Branch("DRJ3J",&DRJ3J,"DRJ3J/D");			
		EventBranchs_WJ 				= fs->make<TTree>( "WJ","WJ" );
		EventBranchs_WJ->Branch("WJM",&WJM,"WJM/D");
		EventBranchs_WJ->Branch("WJpx",&WJpx,"WJpx/D");
		EventBranchs_WJ->Branch("WJpy",&WJpy,"WJpy/D");
		EventBranchs_WJ->Branch("WJpz",&WJpz,"WJpz/D");
		EventBranchs_WJ->Branch("WJpt",&WJpt,"WJpt/D");
		EventBranchs_WJ->Branch("WJE",&WJE,"WJE/D");
		EventBranchs_WJ->Branch("WJphi",&WJphi,"WJphi/D");
		EventBranchs_WJ->Branch("WJeta",&WJeta,"WJeta/D");			
		EventBranchs_WJ->Branch("WJMgen",&WJMgen,"WJMgen/D");			
		EventBranchs_WJ->Branch("WJMgenqq",&WJMgenqq,"WJMgenqq/D");			
		//	EventBranchs_eletron 			= fs->make<TTree>( "eletron","eletron" );				
		EventBranchs_Met 				= fs->make<TTree>( "Met","Met" );
		EventBranchs_Met->Branch("METPx",&METPx,"METPx/D");
		EventBranchs_Met->Branch("METPy",&METPy,"METPy/D");
		EventBranchs_Met->Branch("METPt",&METPt,"METPt/D");
		EventBranchs_Met->Branch("METphi",&METphi,"METphi/D");
		EventBranchs_Met->Branch("METE",&METE,"METE/D");
		EventBranchs_Neutrino 				= fs->make<TTree>( "Neutrino","Neutrino" );
		EventBranchs_Neutrino->Branch("Neutrino_Px",&Neutrino_Px,"Neutrino_Px/D");
		EventBranchs_Neutrino->Branch("Neutrino_Py",&Neutrino_Py,"Neutrino_Py/D");
		EventBranchs_Neutrino->Branch("Neutrino_Pz",&Neutrino_Pz,"Neutrino_Pz/D");
		EventBranchs_Neutrino->Branch("Neutrino_Pt",&Neutrino_Pt,"Neutrino_Pt/D");
		EventBranchs_Neutrino->Branch("Neutrino_phi",&Neutrino_phi,"Neutrino_phi/D");
		EventBranchs_Neutrino->Branch("Neutrino_eta",&Neutrino_eta,"Neutrino_eta/D");
		EventBranchs_Neutrino->Branch("Neutrino_E",&Neutrino_E,"Neutrino_E/D");		
		EventBranchs_Neutrino_Mix			= fs->make<TTree>( "Neutrino_Mix","Neutrino_Mix" );
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_Px",&Neutrino_mix_Px,"Neutrino_mix_Px/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_Py",&Neutrino_mix_Py,"Neutrino_mix_Py/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_Pz",&Neutrino_mix_Pz,"Neutrino_mix_Pz/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_Pt",&Neutrino_mix_Pt,"Neutrino_mix_Pt/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_phi",&Neutrino_mix_phi,"Neutrino_mix_phi/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_eta",&Neutrino_mix_eta,"Neutrino_mix_eta/D");
		EventBranchs_Neutrino_Mix->Branch("Neutrino_mix_E",&Neutrino_mix_E,"Neutrino_mix_E/D");
		EventBranchs_WL 				= fs->make<TTree>( "WL","WL" );
		EventBranchs_WL->Branch("WLM",&WLM,"WLM/D");
		EventBranchs_WL->Branch("WLE",&WLE,"WLE/D");	
		EventBranchs_WL->Branch("WLpt",&WLpt,"WLpt/D");	
		EventBranchs_WL_Nu 				= fs->make<TTree>( "WL_Nu","WL_Nu" );
		EventBranchs_WL_Nu->Branch("WLeptonic_M",&WLeptonic_M,"WLeptonic_M/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_Px",&WLeptonic_Px,"WLeptonic_Px/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_Py",&WLeptonic_Py,"WLeptonic_Py/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_Pz",&WLeptonic_Pz,"WLeptonic_Pz/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_Pt",&WLeptonic_Pt,"WLeptonic_Pt/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_phi",&WLeptonic_phi,"WLeptonic_phi/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_eta",&WLeptonic_eta,"WLeptonic_eta/D");
		EventBranchs_WL_Nu->Branch("WLeptonic_E",&WLeptonic_E,"WLeptonic_E/D");
		EventBranchs_WL_Nu_Mix 				= fs->make<TTree>( "WL_Nu_Mix","WL_Nu_Mix" );
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_M",&WLeptonic_mix_M,"WLeptonic_mix_M/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_Px",&WLeptonic_mix_Px,"WLeptonic_mix_Px/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_Py",&WLeptonic_mix_Py,"WLeptonic_mix_Py/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_Pz",&WLeptonic_mix_Pz,"WLeptonic_mix_Pz/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_Pt",&WLeptonic_mix_Pt,"WLeptonic_mix_Pt/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_phi",&WLeptonic_mix_phi,"WLeptonic_mix_phi/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_eta",&WLeptonic_mix_eta,"WLeptonic_mix_eta/D");
		EventBranchs_WL_Nu_Mix->Branch("WLeptonic_mix_E",&WLeptonic_mix_E,"WLeptonic_mix_E/D");
		EventBranchs_WW 				= fs->make<TTree>( "WW","WW" );
		EventBranchs_WW->Branch("MWW_Nu",&MWW_Nu,"MWW_Nu/D");
		EventBranchs_WW->Branch("MWW_Met",&MWW_Met,"MWW_Met/D");
		EventBranchs_WW->Branch("MWW_Mix",&MWW_Mix,"MWW_Mix/D");
		EventBranchs_WW->Branch("DWWphi_Nu",&DWWphi_Nu,"DWWphi_Nu/D");
		EventBranchs_WW->Branch("DWWphi_Met",&DWWphi_Met,"DWWphi_Met/D");
		EventBranchs_WW->Branch("DWWphi_Mix",&DWWphi_Mix,"DWWphi_Mix/D");
		EventBranchs_WW->Branch("WW_Y_Nu",&WW_Y_Nu,"WW_Y_Nu/D");
		EventBranchs_WW->Branch("WW_Y_Met",&WW_Y_Met,"WW_Y_Met/D");
		EventBranchs_WW->Branch("WW_Y_Mix",&WW_Y_Mix,"WW_Y_Mix/D");
		EventBranchs_WW->Branch("WW_DR_Nu",&WW_DR_Nu,"WW_DR_Nu/D");
		EventBranchs_WW->Branch("WW_DR_Met",&WW_DR_Met,"WW_DR_Met/D");
		EventBranchs_WW->Branch("WW_DR_Mix",&WW_DR_Mix,"WW_DR_Mix/D");
		EventBranchs_WW->Branch("WWacop_Nu",&WWacop_Nu,"WWacop_Nu/D");
		EventBranchs_WW->Branch("WWacop_Met",&WWacop_Met,"WWacop_Met/D");
		EventBranchs_WW->Branch("WWacop_Mix",&WWacop_Mix,"WWacop_Mix/D");
		EventBranchs_WW->Branch("MWWMXV_Nu","std::vector<double>",&MWWMXV_Nu);
		EventBranchs_WW->Branch("MWWMXV_Met","std::vector<double>",&MWWMXV_Met);
		EventBranchs_WW->Branch("MWWMXV_Mix","std::vector<double>",&MWWMXV_Mix);
		EventBranchs_WW->Branch("Y_YV_Nu","std::vector<double>",&Y_YV_Nu);
		EventBranchs_WW->Branch("Y_YV_Met","std::vector<double>",&Y_YV_Met);
		EventBranchs_WW->Branch("Y_YV_Mix","std::vector<double>",&Y_YV_Mix);
		EventBranchs_WW->Branch("AcopMuMet",&AcopMuMet,"AcopMuMet/D");
		EventBranchs_WW->Branch("AcopMuWJ",&AcopMuWJ,"AcopMuWJ/D");
		EventBranchs_Gen                                = fs->make<TTree>( "Gen","Gen" );
		EventBranchs_Gen->Branch("genWhad_px",&genWhad_px,"genWhad_px/D");
		EventBranchs_Gen->Branch("genWhad_py",&genWhad_py,"genWhad_py/D");
		EventBranchs_Gen->Branch("genWhad_pz",&genWhad_pz,"genWhad_pz/D");
		EventBranchs_Gen->Branch("genWhad_pt",&genWhad_pt,"genWhad_pt/D");
		EventBranchs_Gen->Branch("genWhad_E",&genWhad_E,"genWhad_E/D");
		EventBranchs_Gen->Branch("genWhad_phi",&genWhad_phi,"genWhad_phi/D");
		EventBranchs_Gen->Branch("genWhad_eta",&genWhad_eta,"genWhad_eta/D");
		EventBranchs_Gen->Branch("genWlep_px",&genWlep_px,"genWlep_px/D");
		EventBranchs_Gen->Branch("genWlep_py",&genWlep_py,"genWlep_py/D");
		EventBranchs_Gen->Branch("genWlep_pz",&genWlep_pz,"genWlep_pz/D");
		EventBranchs_Gen->Branch("genWlep_pt",&genWlep_pt,"genWlep_pt/D");
		EventBranchs_Gen->Branch("genWlep_E",&genWlep_E,"genWlep_E/D");
		EventBranchs_Gen->Branch("genWlep_phi",&genWlep_phi,"genWlep_phi/D");
		EventBranchs_Gen->Branch("genWlep_eta",&genWlep_eta,"genWlep_eta/D");
		EventBranchs_Gen->Branch("genQrk1_px",&genQrk1_px,"genQrk1_px/D");
		EventBranchs_Gen->Branch("genQrk1_py",&genQrk1_py,"genQrk1_py/D");
		EventBranchs_Gen->Branch("genQrk1_pz",&genQrk1_pz,"genQrk1_pz/D");
		EventBranchs_Gen->Branch("genQrk1_pt",&genQrk1_pt,"genQrk1_pt/D");
		EventBranchs_Gen->Branch("genQrk1_E",&genQrk1_E,"genQrk1_E/D");
		EventBranchs_Gen->Branch("genQrk1_phi",&genQrk1_phi,"genQrk1_phi/D");
		EventBranchs_Gen->Branch("genQrk1_eta",&genQrk1_eta,"genQrk1_eta/D");
		EventBranchs_Gen->Branch("genQrk2_px",&genQrk2_px,"genQrk2_px/D");
		EventBranchs_Gen->Branch("genQrk2_py",&genQrk2_py,"genQrk2_py/D");
		EventBranchs_Gen->Branch("genQrk2_pz",&genQrk2_pz,"genQrk2_pz/D");
		EventBranchs_Gen->Branch("genQrk2_pt",&genQrk2_pt,"genQrk2_pt/D");
		EventBranchs_Gen->Branch("genQrk2_E",&genQrk2_E,"genQrk2_E/D");
		EventBranchs_Gen->Branch("genQrk2_phi",&genQrk2_phi,"genQrk2_phi/D");
		EventBranchs_Gen->Branch("genQrk2_eta",&genQrk2_eta,"genQrk2_eta/D");
		EventBranchs_Gen->Branch("genMuon_px",&genMuon_px,"genMuon_px/D");
		EventBranchs_Gen->Branch("genMuon_py",&genMuon_py,"genMuon_py/D");
		EventBranchs_Gen->Branch("genMuon_pz",&genMuon_pz,"genMuon_pz/D");
		EventBranchs_Gen->Branch("genMuon_pt",&genMuon_pt,"genMuon_pt/D");
		EventBranchs_Gen->Branch("genMuon_E",&genMuon_E,"genMuon_E/D");
		EventBranchs_Gen->Branch("genMuon_phi",&genMuon_phi,"genMuon_phi/D");
		EventBranchs_Gen->Branch("genMuon_eta",&genMuon_eta,"genMuon_eta/D");
		EventBranchs_Gen->Branch("genNeut_px",&genNeut_px,"genNeut_px/D");
		EventBranchs_Gen->Branch("genNeut_py",&genNeut_py,"genNeut_py/D");
		EventBranchs_Gen->Branch("genNeut_pz",&genNeut_pz,"genNeut_pz/D");
		EventBranchs_Gen->Branch("genNeut_pt",&genNeut_pt,"genNeut_pt/D");
		EventBranchs_Gen->Branch("genNeut_E",&genNeut_E,"genNeut_E/D");
		EventBranchs_Gen->Branch("genNeut_phi",&genNeut_phi,"genNeut_phi/D");
		EventBranchs_Gen->Branch("genNeut_eta",&genNeut_eta,"genNeut_eta/D");
		EventBranchs_Gen->Branch("genProtonF_xi","std::vector<double>",&genProtonF_xi);
		EventBranchs_Gen->Branch("genProtonB_xi","std::vector<double>",&genProtonB_xi);
		EventBranchs_Gen->Branch("genProtonF_t","std::vector<double>",&genProtonF_t);
		EventBranchs_Gen->Branch("genProtonB_t","std::vector<double>",&genProtonB_t);
		EventBranchs_pfCand                             = fs->make<TTree>( "pfCand","pfCand" );
		EventBranchs_pfCand->Branch("N_pfCand_tot",&N_pfCand_tot,"N_pfCand_tot/D");
		EventBranchs_pfCand->Branch("N_pfCand_vtx",&N_pfCand_vtx,"N_pfCand_vtx/D");
		EventBranchs_pfCand->Branch("N_pfCand_extra",&N_pfCand_extra,"N_pfCand_extra/D");
		EventBranchs_pfCand->Branch("Dvzpf","std::vector<double>",&Dvzpf);
		EventBranchs_pfCand->Branch("Dvxpf","std::vector<double>",&Dvxpf);
		EventBranchs_pfCand->Branch("Dvypf","std::vector<double>",&Dvypf);

		//	EventBranchs_Gen 				= fs->make<TTree>( "Gen","Gen" );	
	}
analyzer::~analyzer()
{

	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)

}
//
// member functions
//

// ------------ method called for each event  ------------
void
analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){
	MxV->clear();
	PFxiV->clear();
	PBxiV->clear();
	PFtV->clear();
	PBtV->clear();
	PFTofV->clear();
	PBTofV->clear();
	PFx1V->clear();
	PFy1V->clear();
	PBx1V->clear();
	PBy1V->clear();
	PFx2V->clear();
	PFy2V->clear();
	PBx2V->clear();
	PBy2V->clear();
        PFcellId->clear();
        PBcellId->clear();
	DTofV->clear();
	DVV->clear();
	MWWMXV_Nu->clear();
	MWWMXV_Met->clear();
	MWWMXV_Mix->clear();
	Y_YV_Nu->clear();
	Y_YV_Met->clear();
	Y_YV_Mix->clear();
	VtxzV->clear();
	Ypp->clear();
	Dvzpf->clear();
	Dvxpf->clear();
	Dvypf->clear();
	genProtonF_xi->clear();
	genProtonB_xi->clear();
	genProtonF_t->clear();
	genProtonB_t->clear();


	using namespace edm;
	using namespace std;


	Handle<vector<size_t>> jets_selected;
	iEvent.getByToken(selectedjets,jets_selected);
	Handle<vector<size_t>> muons_selected;
	iEvent.getByToken(selectedmuons,muons_selected);
	Handle<vector<size_t>> protonF_selected;
	iEvent.getByToken(SelectedProtonF,protonF_selected);
	Handle<vector<size_t>> protonB_selected;
	iEvent.getByToken(SelectedProtonB,protonB_selected);
	Handle<vector<double>> Vertice_selected;
	iEvent.getByToken(SelectedVertices,Vertice_selected);
	iEvent.getByToken( _tracksPPSToken, tracksPPS);
	iEvent.getByToken(verticesToken, vertices); 
	iEvent.getByToken(muonsToken, muons);
	iEvent.getByToken(jetsToken, jets);
	iEvent.getByToken(genjetsToken, genjets);
	iEvent.getByToken(MetToken, MET);
	iEvent.getByToken(GenToken, genP);
	iEvent.getByToken(PFCandToken, PFCand);
	Handle<edm::HepMCProduct> EvtHandle;
	iEvent.getByToken(mcEventToken, EvtHandle);

	//
	// CT-PPS:
	//
	oPV = vertices->at(0).z();
	if ( Vertice_selected->size() > 0){
		for (size_t jj = 0; jj < Vertice_selected->size(); jj++) {
			MxV->push_back(13000*pow((tracksPPS->at(protonB_selected->at(jj)).xi())*(tracksPPS->at(protonF_selected->at(jj)).xi()),0.5));
			PFxiV->push_back(tracksPPS->at(protonF_selected->at(jj)).xi());
			PBxiV->push_back(tracksPPS->at(protonB_selected->at(jj)).xi());
			PFtV->push_back(tracksPPS->at(protonF_selected->at(jj)).t());
			PBtV->push_back(tracksPPS->at(protonB_selected->at(jj)).t());
			PFTofV->push_back(tracksPPS->at(protonF_selected->at(jj)).tof());
			PBTofV->push_back(tracksPPS->at(protonB_selected->at(jj)).tof());
			PFx1V->push_back(tracksPPS->at(protonF_selected->at(jj)).X1());
			PFy1V->push_back(tracksPPS->at(protonF_selected->at(jj)).Y1());
			PBx1V->push_back(tracksPPS->at(protonB_selected->at(jj)).X1());
			PBy1V->push_back(tracksPPS->at(protonB_selected->at(jj)).Y1());
			PFx2V->push_back(tracksPPS->at(protonF_selected->at(jj)).X2());
			PFy2V->push_back(tracksPPS->at(protonF_selected->at(jj)).Y2());
			PBx2V->push_back(tracksPPS->at(protonB_selected->at(jj)).X2());
			PBy2V->push_back(tracksPPS->at(protonB_selected->at(jj)).Y2());
                        PFcellId->push_back(tracksPPS->at(protonF_selected->at(jj)).cellId());
                        PBcellId->push_back(tracksPPS->at(protonB_selected->at(jj)).cellId());
			DTofV->push_back(tracksPPS->at(protonB_selected->at(jj)).tof()-tracksPPS->at(protonF_selected->at(jj)).tof());
			Ypp->push_back(0.5*log((tracksPPS->at(protonF_selected->at(jj)).xi())/(tracksPPS->at(protonB_selected->at(jj)).xi())));
			VtxzV->push_back(Vertice_selected->at(jj));
			DVV->push_back(Vertice_selected->at(jj) - oPV);
		}

		NVPPS = Vertice_selected->size();		
	}


	//
	// MUONS
	//
	NM = muons_selected->size();
	Mpx = muons->at(muons_selected->at(0)).px();
	Mpy = muons->at(muons_selected->at(0)).py();
	Mpz = muons->at(muons_selected->at(0)).pz();
	ME = muons->at(muons_selected->at(0)).energy();
	Mpt = muons->at(muons_selected->at(0)).pt();
	Mphi = muons->at(muons_selected->at(0)).phi();
	Meta = muons->at(muons_selected->at(0)).eta();
	DMoPVx = muons->at(muons_selected->at(0)).vertex().x() - vertices->at(0).x();
	DMoPVy = muons->at(muons_selected->at(0)).vertex().y() - vertices->at(0).y();
	DMoPVz = muons->at(muons_selected->at(0)).vertex().z() - oPV;

	TLorentzVector MuonP4  = TLorentzVector(Mpx,Mpy,Mpz,ME);

	//
	// JETS
	//
	NJ = jets_selected->size();
	J1px = jets->at(jets_selected->at(0)).px();
	J1py = jets->at(jets_selected->at(0)).py();
	J1pz = jets->at(jets_selected->at(0)).pz();
	J1E = jets->at(jets_selected->at(0)).energy();
	J1pt = jets->at(jets_selected->at(0)).pt();
	J1phi = jets->at(jets_selected->at(0)).phi();
	J1eta = jets->at(jets_selected->at(0)).eta();	
	J2px = jets->at(jets_selected->at(1)).px();
	J2py = jets->at(jets_selected->at(1)).py();
	J2pz = jets->at(jets_selected->at(1)).pz();
	J2E = jets->at(jets_selected->at(1)).energy();
	J2pt = jets->at(jets_selected->at(1)).pt();
	J2phi = jets->at(jets_selected->at(1)).phi();
	J2eta = jets->at(jets_selected->at(1)).eta();
	DphiJJ = abs(deltaPhi(J1phi,J2phi));
	DetaJJ = abs(J1eta - J2eta); 
	DPtJJ = abs(J1pt - J2pt);
	DPxJJ = abs(J1px - J2px);
	DPyJJ = abs(J1py - J2py);
	DPzJJ = abs(J1pz - J2pz);
	DRJJ = pow((DphiJJ*DphiJJ+DetaJJ*DetaJJ),0.5);
	if (NJ>2){	
		J3pt = jets->at(jets_selected->at(2)).pt();
	}

	//
	// W hadronic
	//
	TLorentzVector p4SumJets;
	p4SumJets += TLorentzVector(jets->at(jets_selected->at(0)).px(), jets->at(jets_selected->at(0)).py(), jets->at(jets_selected->at(0)).pz(), jets->at(jets_selected->at(0)).energy());
	p4SumJets += TLorentzVector(jets->at(jets_selected->at(1)).px(), jets->at(jets_selected->at(1)).py(), jets->at(jets_selected->at(1)).pz(), jets->at(jets_selected->at(1)).energy());
	WJM = p4SumJets.M();
	WJpx = p4SumJets.Px();
	WJpy = p4SumJets.Py();
	WJpz = p4SumJets.Pz();
	WJpt = p4SumJets.Pt();
	WJE = p4SumJets.E();
	WJphi = p4SumJets.Phi();
	WJeta = p4SumJets.Eta();

	//
	// Met
	//
	METPx = (MET->front()).px();
	METPy = (MET->front()).py();
	METPt = (MET->front()).pt();
	METphi = (MET->front()).phi();
	METE = 	(MET->front()).et();

	//
	// W lep without neutrino - WCand
	//
	Ptr<reco::MET> metW(MET,0);
	Ptr<reco::Muon> muonW(muons,muons_selected->at(0));
	reco::WMuNuCandidate WCand(muonW,metW);
	WLM = WCand.massT();
	WLE = WCand.eT();
	WLpt = WCand.pt();
	WLacop = WCand.acop();
	TLorentzVector WCandP4 = TLorentzVector(WCand.px(),WCand.py(),0,WLE);

	//
	// Neutrino
	//	
	TLorentzVector Neutrino = Nu4Momentum(MuonP4, METPt, METphi);	// Neutrino Method
	Neutrino_Px  = Neutrino.Px();
	Neutrino_Py  = Neutrino.Py();
	Neutrino_Pz  = Neutrino.Pz();
	Neutrino_Pt  = Neutrino.Pt();
	Neutrino_phi = Neutrino.Phi();
	Neutrino_eta = Neutrino.Eta();
	Neutrino_E   = Neutrino.E();

	//
	// Neutrino mix with MET
	//
	TLorentzVector Neutrino_mix = TLorentzVector(WCand.px(),WCand.py(),Neutrino_Pz,WLE);
	Neutrino_mix_Px  = Neutrino_mix.Px();
	Neutrino_mix_Py  = Neutrino_mix.Py();
	Neutrino_mix_Pz  = Neutrino_mix.Pz();
	Neutrino_mix_Pt  = Neutrino_mix.Pt();
	Neutrino_mix_phi = Neutrino_mix.Phi();
	Neutrino_mix_eta = Neutrino_mix.Eta();
	Neutrino_mix_E   = Neutrino_mix.E();

	//
	// W lep with neutrino - WLeotonic
	//
	TLorentzVector WLeptonic = Neutrino + MuonP4;
	WLeptonic_M   = WLeptonic.M();	
	WLeptonic_Px  = WLeptonic.Px();
	WLeptonic_Py  = WLeptonic.Py();
	WLeptonic_Pz  = WLeptonic.Pz();
	WLeptonic_Pt  = WLeptonic.Pt();
	WLeptonic_phi = WLeptonic.Phi();
	WLeptonic_eta = WLeptonic.Eta();
	WLeptonic_E   = WLeptonic.E();	

	//
	// W lep with neutrino(mix) - WLeotonic
	//
	TLorentzVector WLeptonic_mix = Neutrino_mix + MuonP4;
	WLeptonic_mix_M   = WLeptonic_mix.M();	
	WLeptonic_mix_Px  = WLeptonic_mix.Px();
	WLeptonic_mix_Py  = WLeptonic_mix.Py();
	WLeptonic_mix_Pz  = WLeptonic_mix.Pz();
	WLeptonic_mix_Pt  = WLeptonic_mix.Pt();
	WLeptonic_mix_phi = WLeptonic_mix.Phi();
	WLeptonic_mix_eta = WLeptonic_mix.Eta();
	WLeptonic_mix_E   = WLeptonic_mix.E();	

	//
	// WW
	//	
	TLorentzVector WW_p4_nu  = WLeptonic + p4SumJets; 		// Wlep with Nu
	TLorentzVector WW_p4_Met = WCandP4 + p4SumJets;			// Wlep with Met
	TLorentzVector WW_p4_Mix = WLeptonic_mix + p4SumJets;	// Wlep with Met+Nu
	MWW_Nu  = WW_p4_nu.M();
	MWW_Met = WW_p4_Met.M();
	MWW_Mix = WW_p4_Mix.M();
	DWWphi_Nu = abs(deltaPhi(WLeptonic.Phi(),p4SumJets.Phi()));
	DWWphi_Met = abs(deltaPhi(WCandP4.Phi(),p4SumJets.Phi()));
	DWWphi_Mix = abs(deltaPhi(WLeptonic_mix.Phi(),p4SumJets.Phi()));
	WW_Y_Nu	 = 0.5*log((WW_p4_nu.E()+WW_p4_nu.Pz())/(WW_p4_nu.E()-WW_p4_nu.Pz()));
	WW_Y_Met = 0.5*log((WW_p4_Met.E()+WW_p4_Met.Pz())/(WW_p4_Met.E()-WW_p4_Met.Pz()));
	WW_Y_Mix = 0.5*log((WW_p4_Mix.E()+WW_p4_Mix.Pz())/(WW_p4_Mix.E()-WW_p4_Mix.Pz()));
	WW_DR_Nu  = pow((pow((deltaPhi(WLeptonic.Phi(),p4SumJets.Phi())),2)+(pow((WLeptonic.Eta()-p4SumJets.Eta()),2))),0.5);
	WW_DR_Met = pow((pow((deltaPhi(WCandP4.Phi(),p4SumJets.Phi())),2)+(pow((WCandP4.Eta()-p4SumJets.Eta()),2))),0.5);
	WW_DR_Mix = pow((pow((deltaPhi(WLeptonic_mix.Phi(),p4SumJets.Phi())),2)+(pow((WLeptonic_mix.Eta()-p4SumJets.Eta()),2))),0.5);
	WWacop_Nu  = (1-(abs(deltaPhi(p4SumJets.Phi(),WLeptonic.Phi())))/(pi)); 
	WWacop_Met = (1-(abs(deltaPhi(p4SumJets.Phi(),WCandP4.Phi())))/(pi)); 
	WWacop_Mix = (1-(abs(deltaPhi(p4SumJets.Phi(),WLeptonic_mix.Phi())))/(pi)); 
	for (size_t jj = 0; jj < Vertice_selected->size(); jj++) {
		MWWMXV_Nu->push_back(MWW_Nu/(13000*pow((tracksPPS->at(protonB_selected->at(jj)).xi())*(tracksPPS->at(protonF_selected->at(jj)).xi()),0.5)));
		MWWMXV_Met->push_back(MWW_Met/(13000*pow((tracksPPS->at(protonB_selected->at(jj)).xi())*(tracksPPS->at(protonF_selected->at(jj)).xi()),0.5)));
		MWWMXV_Mix->push_back(MWW_Mix/(13000*pow((tracksPPS->at(protonB_selected->at(jj)).xi())*(tracksPPS->at(protonF_selected->at(jj)).xi()),0.5)));
		Y_YV_Nu->push_back(WW_Y_Nu - 0.5*log((tracksPPS->at(protonF_selected->at(jj)).xi())/(tracksPPS->at(protonB_selected->at(jj)).xi())));
		Y_YV_Met->push_back(WW_Y_Met - 0.5*log((tracksPPS->at(protonF_selected->at(jj)).xi())/(tracksPPS->at(protonB_selected->at(jj)).xi())));
		Y_YV_Mix->push_back(WW_Y_Mix - 0.5*log((tracksPPS->at(protonF_selected->at(jj)).xi())/(tracksPPS->at(protonB_selected->at(jj)).xi())));
	}

	//
	// Mu-Met-jets
	//

	AcopMuMet = (1-(abs(deltaPhi(Mphi,METphi)))/(pi));
	AcopMuWJ = (1-(abs(deltaPhi(Mphi,WJphi)))/(pi));

	//
	// pfCand
	//	

	npf = 0;
	npfVtx = 0;
	for (size_t pf = 0; pf < PFCand->size(); pf++) {
		if (abs(PFCand->at(pf).pdgId()) == 211 || abs(PFCand->at(pf).pdgId()) == 11 || abs(PFCand->at(pf).pdgId()) == 13){
			if (PFCand->at(pf).fromPV(0)==3) {
				if ((abs(PFCand->at(pf).vertex().z()-vertices->at(0).z())<0.02) && (abs(PFCand->at(pf).vertex().x()-vertices->at(0).x())<0.006) && (abs(PFCand->at(pf).vertex().y()-vertices->at(0).y())<0.006)){
					npfVtx++;
					if (pow(pow(deltaPhi(PFCand->at(pf).phiAtVtx(),jets->at(jets_selected->at(0)).phi()),2)+pow(( PFCand->at(pf).eta()-jets->at(jets_selected->at(0)).eta()),2),0.5)>0.4) {
						if (pow(pow(deltaPhi(PFCand->at(pf).phiAtVtx(),jets->at(jets_selected->at(1)).phi()),2)+pow(( PFCand->at(pf).eta()-jets->at(jets_selected->at(1)).eta()),2),0.5)>0.4) {
							if (pow(pow(deltaPhi(PFCand->at(pf).phiAtVtx(),muons->at(muons_selected->at(0)).phi()),2)+pow(( PFCand->at(pf).eta()-muons->at(muons_selected->at(0)).eta()),2),0.5)>0.3) {
								npf++;
							}
						}
					}
				}

				Dvzpf->push_back(abs(PFCand->at(pf).vertex().z()-vertices->at(0).z()));
				Dvxpf->push_back(abs(PFCand->at(pf).vertex().x()-vertices->at(0).x()));
				Dvypf->push_back(abs(PFCand->at(pf).vertex().y()-vertices->at(0).y()));
			}
		}
	}


	N_pfCand_tot = PFCand->size();
	N_pfCand_vtx = npfVtx;
	N_pfCand_extra  = npf;


	//
	// GenParticle
	//

	int contagem = 0;
	TLorentzVector genWhad;
	TLorentzVector genWlep;
	TLorentzVector genMuon;
	TLorentzVector genNeut;
	TLorentzVector genQrk1;
	TLorentzVector genQrk2;

	for(size_t i = 0; i < genP->size(); ++i) {
		if (abs(genP->at(i).pdgId())>0 && abs(genP->at(i).pdgId())<7){
			if (abs(((genP->at(i)).mother())->pdgId())==24 && ((genP->at(i)).mother())->status()==195) {
				genWhad = TLorentzVector((genP->at(i).mother())->px(),(genP->at(i).mother())->py(),(genP->at(i).mother())->pz(),(genP->at(i).mother())->energy());
				contagem++;
				if (contagem == 1) {genQrk1 = TLorentzVector((genP->at(i)).px(),(genP->at(i)).py(),(genP->at(i)).pz(),(genP->at(i)).energy());}
				if (contagem == 2) {genQrk2 = TLorentzVector((genP->at(i)).px(),(genP->at(i)).py(),(genP->at(i)).pz(),(genP->at(i)).energy());}
			}
		}
		if (contagem==2) break;
	}

	contagem = 0;
	for(size_t i = 0; i < genP->size(); ++i) {
		if (abs(genP->at(i).pdgId())==13 || abs(genP->at(i).pdgId())==14){
			if (abs((genP->at(i).mother())->pdgId())==24 && (genP->at(i).mother())->status()==195) {
				genWlep = TLorentzVector((genP->at(i).mother())->px(),(genP->at(i).mother())->py(),(genP->at(i).mother())->pz(),(genP->at(i).mother())->energy());
				contagem++;
				if (abs(genP->at(i).pdgId())==13) {genMuon = TLorentzVector((genP->at(i)).px(),(genP->at(i)).py(),(genP->at(i)).pz(),(genP->at(i)).energy());}
				if (abs(genP->at(i).pdgId())==14) {genNeut = TLorentzVector((genP->at(i)).px(),(genP->at(i)).py(),(genP->at(i)).pz(),(genP->at(i)).energy());}
			}
		}
		if (contagem==2) break;
	}

	if (genQrk2.Pt()>genQrk1.Pt()) {
		TLorentzVector to_order_pt = genQrk2;
		genQrk2 = genQrk1;
		genQrk1 = to_order_pt;
	}
	genWhad_px  = genWhad.Px();
	genWhad_py  = genWhad.Py();
	genWhad_pz  = genWhad.Pz();
	genWhad_pt  = genWhad.Pt();
	genWhad_E   = genWhad.E();
	genWhad_phi = genWhad.Phi();
	genWhad_eta = genWhad.Eta();
	genWlep_px  = genWlep.Px();
	genWlep_py  = genWlep.Py();
	genWlep_pz  = genWlep.Pz();
	genWlep_pt  = genWlep.Pt();
	genWlep_E   = genWlep.E();
	genWlep_phi = genWlep.Phi();
	genWlep_eta = genWlep.Eta();
	genQrk1_px  = genQrk1.Px();
	genQrk1_py  = genQrk1.Py();
	genQrk1_pz  = genQrk1.Pz();
	genQrk1_pt  = genQrk1.Pt();
	genQrk1_E   = genQrk1.E();
	genQrk1_phi = genQrk1.Phi();
	genQrk1_eta = genQrk1.Eta();
	genQrk2_px  = genQrk2.Px();
	genQrk2_py  = genQrk2.Py();
	genQrk2_pz  = genQrk2.Pz();
	genQrk2_pt  = genQrk2.Pt();
	genQrk2_E   = genQrk2.E();
	genQrk2_phi = genQrk2.Phi();
	genQrk2_eta = genQrk2.Eta();
	genMuon_px  = genMuon.Px();
	genMuon_py  = genMuon.Py();
	genMuon_pz  = genMuon.Pz();
	genMuon_pt  = genMuon.Pt();
	genMuon_E   = genMuon.E();
	genMuon_phi = genMuon.Phi();
	genMuon_eta = genMuon.Eta();
	genNeut_px  = genNeut.Px();
	genNeut_py  = genNeut.Py();
	genNeut_pz  = genNeut.Pz();
	genNeut_pt  = genNeut.Pt();
	genNeut_E   = genNeut.E();
	genNeut_phi = genNeut.Phi();
	genNeut_eta = genNeut.Eta();

	// Gen Proton
	const double ProtonMass = 0.93827;
	const double ProtonMassSQ = pow(ProtonMass,2);
	const double fBeamEnergy = 6500.0;
	const double fBeamMomentum = sqrt(fBeamEnergy*fBeamEnergy - ProtonMassSQ);
	const HepMC::GenEvent* Evt = EvtHandle->GetEvent() ;
	for(HepMC::GenEvent::particle_const_iterator i=Evt->particles_begin(); i != Evt->particles_end();++i) {
		if(((*i)->pdg_id())!=2212) continue;
		if(!((*i)->status() == 2)) continue;	
		HepMC::FourVector momentum=(*i)->momentum();
		double e = sqrt(pow((momentum.x()),2)+pow((momentum.y()),2)+pow((momentum.z()),2)+ProtonMassSQ);
		TLorentzVector* proton = new TLorentzVector(momentum.x(),momentum.y(),momentum.z(),e);
		double energy = proton->E();
		double theta = (proton->Pz()>0)?(proton->Theta()):(TMath::Pi()-proton->Theta());
		double t = -1.;
		double xi = -1.;    
		double mom = proton->P();
//		if(proton->P()<1000) continue;
		if (mom>fBeamMomentum) mom = fBeamMomentum;
		t = -2.*(ProtonMassSQ-fBeamEnergy*energy+fBeamMomentum*mom*cos(theta));
		xi = (1.0-energy/fBeamEnergy);		
		if (proton->Pz()>0) {
			genProtonF_xi->push_back(xi);
			genProtonF_t->push_back(t);
		} else {
			genProtonB_xi->push_back(xi);
			genProtonB_t->push_back(t);
		}			
	}


	// Fill
	EventBranchs_PPS->Fill();
	EventBranchs_Muon->Fill();
	EventBranchs_WJ->Fill();
	EventBranchs_Jets->Fill();
	EventBranchs_Met->Fill();
	EventBranchs_WL->Fill();
	EventBranchs_WW->Fill();
	EventBranchs_pfCand->Fill();
	EventBranchs_Gen->Fill();
	EventBranchs_Neutrino->Fill();
	EventBranchs_WL_Nu->Fill();
	EventBranchs_WL_Nu_Mix->Fill();
	EventBranchs_Neutrino_Mix->Fill();

#ifdef THIS_IS_AN_EVENT_EXAMPLE
	Handle<ExampleData> pIn;
	iEvent.getByLabel("example",pIn);
#endif

#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
	ESHandle<SetupData> pSetup;
	iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
	void 
analyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
	void 
analyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(analyzer);
