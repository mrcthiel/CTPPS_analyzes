#include "WW_Tools/WW_Tools.h"

class step_Mu : public edm::stream::EDFilter<> {
	public:
		explicit step_Mu(const edm::ParameterSet&);

	private:
		virtual bool filter(edm::Event&, const edm::EventSetup&) override;

		edm::EDGetTokenT<reco::VertexCollection> verticesToken;
		edm::EDGetTokenT<pat::MuonCollection> muonsToken;
		edm::EDGetTokenT<std::vector<size_t>> selectedmuons;
		double eta_cut, pt_muon;
		double N_muon_min, N_muon_max;
};

step_Mu::step_Mu(const edm::ParameterSet& iConfig):
	verticesToken (consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices")))
	, muonsToken (consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons")))
	, selectedmuons (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("selectedmuons")))
	, eta_cut (iConfig.getParameter<double>("eta_cut"))
	, pt_muon (iConfig.getParameter<double>("pt_muon"))
	, N_muon_min (iConfig.getParameter<double>("N_muon_min"))
	, N_muon_max (iConfig.getParameter<double>("N_muon_max")){

		produces<std::vector<size_t>>("selectedmuons");
	}

bool step_Mu::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	using namespace std;

	iEvent.getByToken(verticesToken, vertices); 
	iEvent.getByToken(muonsToken,muons);
	Handle<vector<size_t>> muons_selected;
	iEvent.getByToken(selectedmuons,muons_selected);

	if (muons_selected->size() < 1) return false;

	vector<size_t> selected_muons;
	for(size_t i=0; i<muons_selected->size(); i++) {  
		if (!muon::isTightMuon(muons->at(muons_selected->at(i)), vertices->at(0))) continue;
		if(muons->at(muons_selected->at(i)).pt()<pt_muon || abs(muons->at(muons_selected->at(i)).eta())>eta_cut) continue;
		if((muons->at(muons_selected->at(i)).isolationR03().sumPt)/(muons->at(muons_selected->at(i)).pt()) > 0.05) continue;
		//	   if ( abs(muons->at(muons_selected->at(i)).vertex().x()- vertices->at(0).x()) < 0.02) {
		//		   if ( abs(muons->at(muons_selected->at(i)).vertex().y()- vertices->at(0).y()) < 0.02) {
		//			   if ( abs(muons->at(muons_selected->at(i)).vertex().z()- vertices->at(0).z()) < 0.02) {
		selected_muons.push_back(muons_selected->at(i));
		//			   }
		//		   }
		//	   }
	}   

	if (selected_muons.size() < N_muon_min || selected_muons.size() > N_muon_max) {return false;}
	iEvent.put(std::make_unique<std::vector<size_t>>(selected_muons),"selectedmuons"); 

	return true;
}

//define this as a plug-in
DEFINE_FWK_MODULE(step_Mu);
