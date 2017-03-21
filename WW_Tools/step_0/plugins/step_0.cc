#include "CTPPS_analyzes/WW_Tools/WW_Tools.h"

class step_0 : public edm::stream::EDFilter<> {
	public:
		explicit step_0(const edm::ParameterSet&);

	private:
		virtual bool filter(edm::Event&, const edm::EventSetup&) override;
		edm::EDGetTokenT<pat::MuonCollection> muonsToken;
		edm::EDGetTokenT<pat::JetCollection> jetsToken;
		edm::EDGetTokenT< CTPPSFastTrackContainer > _tracksPPSToken;
};

step_0::step_0(const edm::ParameterSet& iConfig):
	muonsToken (consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons")))
	, jetsToken (consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets")))
	, _tracksPPSToken (consumes<CTPPSFastTrackContainer>(iConfig.getParameter<edm::InputTag>("tracksPPSTag"))){
		produces<std::vector<double>>("SelectedVertice");
		produces<std::vector<size_t>>("SelectedProtonF");
		produces<std::vector<size_t>>("SelectedProtonB");
		produces<std::vector<size_t>>("selectedjets");
		produces<std::vector<size_t>>("selectedmuons");		
	}


bool step_0::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	using namespace std;

	iEvent.getByToken( _tracksPPSToken, tracksPPS);

	vector<double> Vertice;
	vector<size_t> ProtonF;
	vector<size_t> ProtonB;
	vector<size_t> selected_jets;
	vector<size_t> selected_muons;
	Vertice.clear();
	selected_jets.clear();
	selected_muons.clear();


	double ZPPS_V = -9999;
	double limit = 431.4/(0.299792458);
	if(tracksPPS.isValid()) {
		for (size_t i = 0; i < tracksPPS->size(); i++) {
			if (tracksPPS->at(i).PZ()>0 && tracksPPS->at(i).tof()<719.9981 && tracksPPS->at(i).tof()>718.9974){
				for (size_t j = 0; j < tracksPPS->size(); j++) {
					if (tracksPPS->at(j).PZ()<0 && tracksPPS->at(j).tof()<719.9981 && tracksPPS->at(j).tof()>718.9974){
						if ( (tracksPPS->at(j).tof()+tracksPPS->at(i).tof())>(limit-0.02) && (tracksPPS->at(j).tof()+tracksPPS->at(i).tof())<(limit+0.02)) {
							ZPPS_V = (14.9896229)*(tracksPPS->at(j).tof() - tracksPPS->at(i).tof());
							Vertice.push_back(ZPPS_V);
							ProtonF.push_back(i);
							ProtonB.push_back(j);
						}
					}
				}
			}	
		}
	} else {return false;}   


	iEvent.put(std::make_unique<std::vector<double>>(Vertice),"SelectedVertice");
	iEvent.put(std::make_unique<std::vector<size_t>>(ProtonF),"SelectedProtonF");
	iEvent.put(std::make_unique<std::vector<size_t>>(ProtonB),"SelectedProtonB");

	iEvent.getByToken(muonsToken,muons);
	iEvent.getByToken(jetsToken, jets);

	for(size_t i=0; i<jets->size(); i++) {
		selected_jets.push_back(i);
	}   
	for(size_t i=0; i<muons->size(); i++) {
		selected_muons.push_back(i);
	}      

	iEvent.put(std::make_unique<std::vector<size_t>>(selected_jets),"selectedjets");
	iEvent.put(std::make_unique<std::vector<size_t>>(selected_muons),"selectedmuons");   

	return true;
}

//define this as a plug-in
DEFINE_FWK_MODULE(step_0);
