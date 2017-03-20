#include "WW_Tools/WW_Tools.h"

class step_CTPPS : public edm::stream::EDFilter<> {
	public:
		explicit step_CTPPS(const edm::ParameterSet&);

	private:
		virtual bool filter(edm::Event&, const edm::EventSetup&) override;

		edm::EDGetTokenT<reco::VertexCollection> verticesToken;
		double ppsz_resolution;

		edm::EDGetTokenT<std::vector<double>> SelectedVertices;
		edm::EDGetTokenT<std::vector<size_t>> SelectedProtonF;
		edm::EDGetTokenT<std::vector<size_t>> SelectedProtonB;

};

step_CTPPS::step_CTPPS(const edm::ParameterSet& iConfig):
	verticesToken (consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices")))
	, ppsz_resolution (iConfig.getParameter<double>("ppsz_resolution"))
	, SelectedVertices (consumes<std::vector<double>>(iConfig.getParameter<edm::InputTag>("SelectedVertice")))
	, SelectedProtonF (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("SelectedProtonF")))
	, SelectedProtonB (consumes<std::vector<size_t>>(iConfig.getParameter<edm::InputTag>("SelectedProtonB"))){
		produces<std::vector<double>>("SelectedVertice");
		produces<std::vector<size_t>>("SelectedProtonF");
		produces<std::vector<size_t>>("SelectedProtonB");		
	}


bool step_CTPPS::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	using namespace std;

	Handle<vector<double>> Vertice_selected;
	iEvent.getByToken(SelectedVertices,Vertice_selected);
	Handle<vector<size_t>> ProtonF_selected;
	iEvent.getByToken(SelectedProtonF,ProtonF_selected);
	Handle<vector<size_t>> ProtonB_selected;
	iEvent.getByToken(SelectedProtonB,ProtonB_selected);   

	iEvent.getByToken(verticesToken, vertices); 


	double oPV_0 = vertices->at(0).z();

	vector<double> Vertice;
	vector<size_t> ProtonF;
	vector<size_t> ProtonB;   

	for (size_t i = 0; i < Vertice_selected->size(); i++) {
		double zppsmax = Vertice_selected->at(i) + ppsz_resolution;
		double zppsmin = Vertice_selected->at(i) - ppsz_resolution;	
		if( oPV_0 < zppsmax && oPV_0 > zppsmin) {
			Vertice.push_back(Vertice_selected->at(i));
			ProtonF.push_back(ProtonF_selected->at(i));
			ProtonB.push_back(ProtonB_selected->at(i));
		}
	}

	if (Vertice.size() == 0){return false;} else {
		iEvent.put(std::make_unique<std::vector<double>>(Vertice),"SelectedVertice");
		iEvent.put(std::make_unique<std::vector<size_t>>(ProtonF),"SelectedProtonF");
		iEvent.put(std::make_unique<std::vector<size_t>>(ProtonB),"SelectedProtonB");	   
	}

	return true;

}

//define this as a plug-in
DEFINE_FWK_MODULE(step_CTPPS);
