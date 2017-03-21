#include "CTPPS_analyzes/WW_Tools/WW_Tools.h"

class step_Jet : public edm::stream::EDFilter<> {
	public:
		explicit step_Jet(const edm::ParameterSet&);


	private:
		virtual bool filter(edm::Event&, const edm::EventSetup&) override;

		edm::EDGetTokenT<pat::JetCollection> jetsToken;
		double eta_cut, pt_jet1, pt_jet2, pt_jet3, pt_jet4, pt_jet_others;
		size_t  N_jet_min, N_jet_max;

		edm::EDGetTokenT<std::vector<size_t>> selectedjets;
};


step_Jet::step_Jet(const edm::ParameterSet& iConfig):
	jetsToken (consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets")))
	, eta_cut (iConfig.getParameter<double>("eta_cut"))
	, pt_jet1 (iConfig.getParameter<double>("pt_jet1"))
	, pt_jet2 (iConfig.getParameter<double>("pt_jet2"))
	, pt_jet3 (iConfig.getParameter<double>("pt_jet3"))
	, pt_jet4 (iConfig.getParameter<double>("pt_jet4"))
	, pt_jet_others (iConfig.getParameter<double>("pt_jet_others"))
	, N_jet_min (iConfig.getParameter<double>("N_jet_min"))
	, N_jet_max (iConfig.getParameter<double>("N_jet_max"))
	, selectedjets (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("selectedjets"))){
		produces<std::vector<size_t>>("selectedjets");
	}

bool step_Jet::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	using namespace std;


	iEvent.getByToken(jetsToken, jets);
	Handle<vector<size_t>> jets_selected;
	iEvent.getByToken(selectedjets,jets_selected);


	if (jets_selected->size() < 2) return false;

	bool tightLepVetoJetID;
	double NHF, NEMF, CHF, MUF, CEMF, NumConst, CHM;

	vector<size_t> selected_jets;
	vector<double> pt_jet = {pt_jet1,pt_jet2,pt_jet3,pt_jet4};
	if (jets_selected->size() > 4) {
		for (size_t ii = 0; ii < (jets_selected->size()-4); ii++) {pt_jet.push_back(pt_jet_others);}
	}

	for(size_t i=0; i<jets_selected->size(); i++) {   
		if(jets->at(jets_selected->at(i)).pt()<pt_jet[i] || abs(jets->at(jets_selected->at(i)).eta())>eta_cut) continue;
		NHF  = jets->at(jets_selected->at(i)).neutralHadronEnergyFraction();
		NEMF = jets->at(jets_selected->at(i)).neutralEmEnergyFraction();
		CHF  = jets->at(jets_selected->at(i)).chargedHadronEnergyFraction();
		MUF  = jets->at(jets_selected->at(i)).muonEnergyFraction();
		CEMF = jets->at(jets_selected->at(i)).chargedEmEnergyFraction();
		NumConst = jets->at(jets_selected->at(i)).chargedMultiplicity()+jets->at(jets_selected->at(i)).neutralMultiplicity();
		//	   NumNeutralParticles = jets->at(jets_selected->at(i)).neutralMultiplicity();
		CHM      = jets->at(jets_selected->at(i)).chargedMultiplicity(); 
		tightLepVetoJetID = (NHF<0.90 && NEMF<0.90 && NumConst>1 && MUF<0.8 && CHF>0 && CHM>0 && CEMF<0.90);
		if (tightLepVetoJetID) {
			selected_jets.push_back(jets_selected->at(i));
		}
	}

	if (selected_jets.size() < N_jet_min || selected_jets.size() > N_jet_max) {return false;}  
	iEvent.put(std::make_unique<std::vector<size_t>>(selected_jets),"selectedjets");

	return true;

}

//define this as a plug-in
DEFINE_FWK_MODULE(step_Jet);
