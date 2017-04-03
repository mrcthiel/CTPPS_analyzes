{

	//bool MC = true;
	TFile *File = TFile::Open("out.root");
	TDirectory *dir0 = gFile->GetDirectory("demo");
	dir0->cd();

	TTree *PPS = (TTree*)dir0->Get("PPS"); 
	TTree *Muon = (TTree*)dir0->Get("Muon"); 
	TTree *Jets = (TTree*)dir0->Get("Jets"); 
	TTree *WJ = (TTree*)dir0->Get("WJ"); 
	TTree *Met = (TTree*)dir0->Get("Met"); 
	TTree *Neutrino = (TTree*)dir0->Get("Neutrino"); 
	TTree *Neutrino_Mix = (TTree*)dir0->Get("Neutrino_Mix"); 
	TTree *WL = (TTree*)dir0->Get("WL"); 
	TTree *WL_Nu = (TTree*)dir0->Get("WL_Nu"); 
	TTree *WL_Nu_Mix = (TTree*)dir0->Get("WL_Nu_Mix"); 
	TTree *WW = (TTree*)dir0->Get("WW"); 
	TTree *Gen = (TTree*)dir0->Get("Gen"); 
	TTree *pfCand = (TTree*)dir0->Get("pfCand"); 


	// Create a root file
	TFile *f = new TFile("Histos.root","RECREATE");


	// PPS
	TH1F *MX = new TH1F("MX","PPS_MX; #xi; nEvents",180,0,1800);
	PPS->Project("MX","MxV");

	TH1F *h_PPS_xiARMF = new TH1F( "h_PPS_xiARMF" , "PPS_xiARMF; #xi; nEvents" , 100, 0., .50 );
	PPS->Project("h_PPS_xiARMF","PFxiV");

	TH1F *h_PPS_tARMF = new TH1F( "h_PPS_tARMF" , "PPS_tARMF; t [GeV^{2}]; nEvents" , 100, .0, 3.0 );
	PPS->Project("h_PPS_tARMF","PFtV");

	//TH1F *h_PPS_etaARMF = new TH1F( "PPS_etaARMF" , "PPS_etaARMF; #eta; nEvents" , 100, 8., 15.);
	//PPS->Project("","");

	//TH1F *h_PPS_phiARMF = new TH1F( "PPS_phiARMF" , "PPS_phiARMF; #phi; nEvents" , 100, -3.15, 3.15 );
	//PPS->Project("","");

	//TH1F *h_PPS_thetaXARMF = new TH1F( "PPS_thetaXARMF" , "PPS_thetaXARMF;  #theta_{X}[#murad]; nEvents" , 100, -300., 300. );
	//PPS->Project("","");

	//TH1F *h_PPS_thetaYARMF = new TH1F( "PPS_thetaYARMF" , "PPS_thetaYARMF;  #theta_{Y}[#murad]; nEvents" , 100, -300., 300. );
	//PPS->Project("","");

	TH1F *h_PPS_tofARMF = new TH1F( "h_PPS_tofARMF" , "Hits in tracks - PPS_tofARMF;  ToF [ns]; nEvents" , 100, 715., 722. );
	PPS->Project("h_PPS_tofARMF","PFTofV");

	TH1F *h_PPS_xiARMB = new TH1F( "h_PPS_xiARMB" , "PPS_xiARMB; #xi; nEvents" , 100, 0., .50 );
	PPS->Project("h_PPS_xiARMB","PBxiV");

	TH1F *h_PPS_tARMB = new TH1F( "h_PPS_tARMB" , "PPS_tARMB; t [GeV^{2}]; nEvents" , 100, .0, 3.0 );
	PPS->Project("h_PPS_tARMB","PBtV");

	//TH1F *h_PPS_etaARMB = new TH1F( "PPS_etaARMB" , "PPS_etaARMB; #eta; nEvents" , 100, -15., -8. );
	//PPS->Project("","");

	//TH1F *h_PPS_phiARMB = new TH1F( "PPS_phiARMB" , "PPS_phiARMB;|#phi - #pi|; nEvents" , 100, -3.15, 3.15 );
	//PPS->Project("","");

	//TH1F *h_PPS_thetaXARMB = new TH1F( "PPS_thetaXARMB" , "PPS_thetaXARMB;  #theta_{X}[#murad]; nEvents" , 100, -300., 300. );
	//PPS->Project("","");

	//TH1F *h_PPS_thetaYARMB = new TH1F( "PPS_thetaYARMB" , "PPS_thetaYARMB;  #theta_{Y}[#murad]; nEvents" , 100, -300., 300. );
	//PPS->Project("","");

	TH1F *h_PPS_tofARMB = new TH1F( "h_PPS_tofARMB" , "Hits in tracks - PPS_tofARMB; ToF [ns]; nEvents" , 100, 715., 722. );
	PPS->Project("h_PPS_tofARMB","PBTofV");

	//TH1F *h_PPS_xVertices = new TH1F( "PPS_xVertices" , "PPS_xVertices; x_{vPPS} [cm]; nEvents" , 100, -.40, .20 );
	//PPS->Project("","");

	//TH1F *h_PPS_yVertices = new TH1F( "PPS_yVertices" , "PPS_yVertices; y_{vPPS} [cm]; nEvents" , 100, -.10, .10 );
	//PPS->Project("","");

	TH1F *h_PPS_zVertices = new TH1F( "h_PPS_zVertices" , "PPS_zVertices; z_{vPPS} [cm]; nEvents" , 100, -20., 20. );
	PPS->Project("h_PPS_zVertices","VtxzV");

	//TH1F *h_PPS_ToF_ARMFToFDet = new TH1F( "PPS_ToF_ARMFToFDet" , "All hits - PPS_ToF_ARMFToFDet;  ToF [ns]; nEvents" , 100, 700., 740. );
	//PPS->Project("","");

	//TH1F *h_PPS_ToF_ARMBToFDet = new TH1F( "PPS_ToF_ARMBToFDet" , "All hits - PPS_ToF_ARMBToFDet;  ToF [ns]; nEvents" , 100, 700., 740. );
	//PPS->Project("","");

	//Gen PPS histo


	TH1F *h_PPS_Gen_xiARMB = new TH1F( "PPS_Gen_xiARMB" , "PPS_Gen_xiARMB; #xi; nEvents" , 100, 0., .50 );
	Gen->Project("h_PPS_Gen_xiARMB","genProtonB_xi");

	TH1F *h_PPS_Gen_tARMB = new TH1F( "PPS_Gen_tARMB" , "PPS_Gen_tARMB; t [GeV^{2}]; nEvents" , 100, .0, 3.0 );
	Gen->Project("h_PPS_Gen_tARMB","genProtonB_t");

	//TH1F *h_PPS_Gen_etaARMB = new TH1F( "PPS_Gen_etaARMB" , "PPS_Gen_etaARMB; #eta; nEvents" , 100, -15., -8. );

	//TH1F *h_PPS_Gen_phiARMB = new TH1F( "PPS_Gen_phiARMB" , "PPS_Gen_phiARMB;|#phi - #pi|; nEvents" , 100, -3.15, 3.15 );

	TH1F *h_PPS_Gen_xiARMF = new TH1F( "PPS_Gen_xiARMF" , "PPS_Gen_xiARMF; #xi; nEvents" , 100, 0., .50 );
	Gen->Project("h_PPS_Gen_xiARMF","genProtonF_xi");

	TH1F *h_PPS_Gen_tARMF = new TH1F( "PPS_Gen_tARMF" , "PPS_Gen_tARMF; t [GeV^{2}]; nEvents" , 100, .0, 3.0 );
	Gen->Project("h_PPS_Gen_tARMF","genProtonF_t");

	//TH1F *h_PPS_Gen_etaARMF = new TH1F( "PPS_Gen_etaARMF" , "PPS_Gen_etaARMF; #eta; nEvents" , 100, 8., 15.);

	//TH1F *h_PPS_Gen_phiARMF = new TH1F( "PPS_Gen_phiARMF" , "PPS_Gen_phiARMF;|#phi - #pi|; nEvents" , 100, -3.15, 3.15 );

	// TH2



	TH2F *h_xi_armB_GenReco = new TH2F( "xi_armB_GenReco" , "PPS_GenReco_xiARMB; #xi_{Gen}; #xi_{Reco}" , 100, 0., .30, 100, 0., .30 );

	TH2F *h_xi_armF_GenReco = new TH2F( "xi_armF_GenReco" , "PPS_GenReco_xiARMB; #xi_{Gen}; #xi_{Reco}" , 100, 0., .30, 100, 0., .30 );

	TH2F *h_t_armB_GenReco  = new TH2F( "t_armB_GenReco" , "PPS_GenReco_tARMB; t [GeV^{2}]_{Gen};t [GeV^{2}]_{Reco}", 100, .0, 3.0, 100, .0, 3.0 );

	TH2F *h_t_armF_GenReco  = new TH2F( "t_armF_GenReco" , "PPS_GenReco_tARMF; t [GeV^{2}]_{Gen};t [GeV^{2}]_{Reco}", 100, .0, 3.0, 100, .0, 3.0 );
	/*
	   const int nXbins = 8;
	   double xbin[nXbins+1+1] = {-20., -18.195, -13.995, -9.795, -7.445, -5.695, -4.535, -3.515, -2.505, -1.695};
	   double ybin = 4.2;
	   */
	const int nXbins = 8;
	double xbin[nXbins+1] = {-18.195, -13.995, -9.795, -7.445, -5.695, -4.535, -3.515, -2.505, -1.695};
	double ybin = 4.2;


	TH2F *h_PPS_xVsy_ARMFToF = new TH2F( "PPS_xVsy_ARMFToF" , "Hits in tracks - PPS x_vs_y_{ARMFToF}; x [mm]; y [mm]" , nXbins, xbin,3,-1.5*ybin,1.5*ybin);//diamond

	TH2F *h_PPS_xVsy_ARMBToF = new TH2F( "PPS_xVsy_ARMBToF" , "Hits in tracks - PPS x_vs_y_{ARMBToF}; x [mm]; y [mm]" , nXbins, xbin,3,-1.5*ybin,1.5*ybin);//diamond



	vector<double> *PBxiV;
	vector<double> *genProtonB_xi;
	PPS->SetBranchAddress("PBxiV",&PBxiV);
	Gen->SetBranchAddress("genProtonB_xi",&genProtonB_xi);
	vector<double> *PFxiV;
	vector<double> *genProtonF_xi;
	PPS->SetBranchAddress("PFxiV",&PFxiV);
	Gen->SetBranchAddress("genProtonF_xi",&genProtonF_xi);
	vector<double> *PBtV;
	vector<double> *genProtonB_t;
	PPS->SetBranchAddress("PBtV",&PBtV);
	Gen->SetBranchAddress("genProtonB_t",&genProtonB_t);
	vector<double> *PFtV;
	vector<double> *genProtonF_t;
	PPS->SetBranchAddress("PFtV",&PFtV);
	Gen->SetBranchAddress("genProtonF_t",&genProtonF_t);

	vector<double> *PFcellId;
	vector<double> *PBcellId;
	PPS->SetBranchAddress("PFcellId",&PFcellId);
	PPS->SetBranchAddress("PBcellId",&PBcellId);

	double PFcellId_x = 0;
	double PFcellId_y = 0;
	double PBcellId_x = 0;
	double PBcellId_y = 0;

	for (int i; i < PPS->GetEntries(); i++){
		PPS->GetEntry(i);
		Gen->GetEntry(i);
		h_xi_armB_GenReco->Fill(PBxiV->at(0),genProtonB_xi->at(0)); 
		h_xi_armF_GenReco->Fill(PFxiV->at(0),genProtonF_xi->at(0)); 
		h_t_armB_GenReco->Fill(PBtV->at(0),genProtonB_t->at(0)); 
		h_t_armF_GenReco->Fill(PFtV->at(0),genProtonF_t->at(0));
		if (PFcellId->at(0)==101){PFcellId_x = -2.1; PFcellId_y = 0.;}
		if (PFcellId->at(0)==102){PFcellId_x = -3.0; PFcellId_y = 0.;}
		if (PFcellId->at(0)==103){PFcellId_x = -4.0; PFcellId_y = 0.;}
		if (PFcellId->at(0)==104){PFcellId_x = -5.1; PFcellId_y = 0.;}
		if (PFcellId->at(0)==105){PFcellId_x = -6.6; PFcellId_y = 0.;}
		if (PFcellId->at(0)==106){PFcellId_x = -8.6; PFcellId_y = 0.;}
		if (PFcellId->at(0)==107){PFcellId_x = -11.8; PFcellId_y = 0.;}
		if (PFcellId->at(0)==108){PFcellId_x = -16.1; PFcellId_y = 0.;}
		h_PPS_xVsy_ARMFToF->Fill(PFcellId_x,PFcellId_y);
		if (PBcellId->at(0)==101){PBcellId_x = -2.1; PBcellId_y = 0.;}
		if (PBcellId->at(0)==102){PBcellId_x = -3.0; PBcellId_y = 0.;}
		if (PBcellId->at(0)==103){PBcellId_x = -4.0; PBcellId_y = 0.;}
		if (PBcellId->at(0)==104){PBcellId_x = -5.1; PBcellId_y = 0.;}
		if (PBcellId->at(0)==105){PBcellId_x = -6.6; PBcellId_y = 0.;}
		if (PBcellId->at(0)==106){PBcellId_x = -8.6; PBcellId_y = 0.;}
		if (PBcellId->at(0)==107){PBcellId_x = -11.8; PBcellId_y = 0.;}
		if (PBcellId->at(0)==108){PBcellId_x = -16.1; PBcellId_y = 0.;}
		h_PPS_xVsy_ARMBToF->Fill(PBcellId_x,PBcellId_y);	
	}



	TH2F *h_PPS_xiVstARMF = new TH2F( "h_PPS_xiVstARMF" , "PPS_xiVstARMF; #xi ; t [GeV^{2}]" , 100, 0., .50 , 100, .0, 3.0 );
	PPS->Project("h_PPS_xiVstARMF","PFtV:PFxiV");

	TH2F *h_PPS_xVsy_ARMFDt1 = new TH2F( "h_PPS_xVsy_ARMFDt1" , "Hits in tracks - PPS x_vs_y_{ARMFDt1}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	PPS->Project("h_PPS_xVsy_ARMFDt1","PFy1V:PFx1V");

	TH2F *h_PPS_xVsy_ARMFDt2 = new TH2F( "h_PPS_xVsy_ARMFDt2" , "Hits in tracks - PPS x_vs_y_{ARMFDt2}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	PPS->Project("h_PPS_xVsy_ARMFDt2","PFy2V:PFx2V");


	TH2F *h_PPS_xiVstARMB = new TH2F( "h_PPS_xiVstARMB" , "PPS_xiVstARMB; #xi ; t [GeV^{2}]" , 100, 0., .50 , 100, .0, 3.0 );
	PPS->Project("h_PPS_xiVstARMB","PBtV:PBxiV");

	TH2F *h_PPS_xVsy_ARMBDt1 = new TH2F( "h_PPS_xVsy_ARMBDt1" , "Hits in tracks - PPS x_vs_y_{ARMBDt1}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	PPS->Project("h_PPS_xVsy_ARMBDt1","PBy1V:PBx1V");

	TH2F *h_PPS_xVsy_ARMBDt2 = new TH2F( "h_PPS_xVsy_ARMBDt2" , "Hits in tracks - PPS x_vs_y_{ARMBDt2}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	PPS->Project("h_PPS_xVsy_ARMBDt2","PBy2V:PBx2V");



	/*
	   TH2F *h_PPS_xVsy_ARMFTrkDet1 = new TH2F( "PPS_xVsy_ARMFTrkDet1" , "All hits - PPS x_vs_y_{TrkDet1_ARMF}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	   PPS->Project("h_PPS_xVsy_ARMFTrkDet1",":");

	   TH2F *h_PPS_xVsy_ARMFTrkDet2 = new TH2F( "PPS_xVsy_ARMFTrkDet2" , "All hits - PPS x_vs_y_{TrkDet2_ARMF}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	   PPS->Project("h_PPS_xVsy_ARMFTrkDet2",":");

	   TH2F *h_PPS_xVsy_ARMFToFDet = new TH2F( "PPS_xVsy_ARMFToFDet" , "All hits - PPS x_vs_y_{ARMFToFDet}; x [mm]; y [mm]" , nXbins+2, xbin,3,-1.5*ybin,1.5*ybin);//diamond
	   PPS->Project("h_PPS_xVsy_ARMFToFDet",":");

	   TH2F *h_PPS_xVsy_ARMBTrkDet1 = new TH2F( "PPS_xVsy_ARMBTrkDet1" , "All hits - PPS x_vs_y_{TrkDet1_ARMB}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	   PPS->Project("h_PPS_xVsy_ARMBTrkDet1",":");

	   TH2F *h_PPS_xVsy_ARMBTrkDet2 = new TH2F( "PPS_xVsy_ARMBTrkDet2" , "All hits - PPS x_vs_y_{TrkDet2_ARMB}; x [mm]; y [mm]" , 22, -25.0, -3.0,18,-9.0,9.0 );
	   PPS->Project("h_PPS_xVsy_ARMBTrkDet2",":");

	   TH2F *h_PPS_xVsy_ARMBToFDet = new TH2F( "PPS_xVsy_ARMBToFDet" , "All hits - PPS x_vs_y_{ARMBToFDet}; x [mm]; y [mm]" , nXbins+2, xbin,3,-1.5*ybin,1.5*ybin);//diamond
	   PPS->Project("h_PPS_xVsy_ARMBToFDet",":");
	   */
	TH2F *h_PPS_Gen_xiVs_Gen_tARMB = new TH2F( "h_PPS_Gen_xiVs_Gen_tARMB" , "PPS_Gen_xiVs_Gen_tARMB; #xi ; t [GeV^{2}]" , 100, 0., .50 , 100, .0, 3.0 );
	Gen->Project("h_PPS_Gen_xiVs_Gen_tARMB","genProtonB_t:genProtonB_xi");

	TH2F *h_PPS_Gen_xiVs_Gen_tARMF = new TH2F( "h_PPS_Gen_xiVs_Gen_tARMF" , "PPS_Gen_xiVs_Gen_tARMF; #xi ; t [GeV^{2}]" , 100, 0., .50 , 100, .0, 3.0 );
	Gen->Project("h_PPS_Gen_xiVs_Gen_tARMF","genProtonF_t:genProtonF_xi");

	h_xi_armB_GenReco->SetOption("COLZ");
	h_xi_armF_GenReco->SetOption("COLZ");
	h_t_armB_GenReco->SetOption("COLZ");
	h_t_armF_GenReco->SetOption("COLZ");
	h_xi_armB_GenReco->SetStats(kFALSE);
	h_xi_armF_GenReco->SetStats(kFALSE);
	h_t_armB_GenReco->SetStats(kFALSE);
	h_t_armF_GenReco->SetStats(kFALSE);
	h_PPS_xVsy_ARMFDt1->SetOption("COLZ");
	h_PPS_xVsy_ARMFDt2->SetOption("COLZ");
	h_PPS_xVsy_ARMFToF->SetOption("COLZ");
	h_PPS_xiVstARMF->SetOption("COLZ");
	h_PPS_xVsy_ARMFDt1->SetStats(kFALSE);
	h_PPS_xVsy_ARMFDt2->SetStats(kFALSE);
	h_PPS_xVsy_ARMFToF->SetStats(kFALSE);
	h_PPS_xiVstARMF->SetStats(kFALSE);
	h_PPS_Gen_xiVs_Gen_tARMF->SetOption("COLZ");
	h_PPS_Gen_xiVs_Gen_tARMB->SetOption("COLZ");
	h_PPS_Gen_xiVs_Gen_tARMF->SetStats(kFALSE);
	h_PPS_Gen_xiVs_Gen_tARMB->SetStats(kFALSE);
	h_PPS_xVsy_ARMBDt1->SetOption("COLZ");
	h_PPS_xVsy_ARMBDt2->SetOption("COLZ");
	h_PPS_xVsy_ARMBToF->SetOption("COLZ");
	h_PPS_xiVstARMB->SetOption("COLZ");
	h_PPS_xVsy_ARMBDt1->SetStats(kFALSE);
	h_PPS_xVsy_ARMBDt2->SetStats(kFALSE);
	h_PPS_xVsy_ARMBToF->SetStats(kFALSE);
	h_PPS_xiVstARMB->SetStats(kFALSE);
	//h_PPS_xVsy_ARMFTrkDet1->SetOption("COLZ");
	//h_PPS_xVsy_ARMFTrkDet2->SetOption("COLZ");
	//h_PPS_xVsy_ARMFToFDet->SetOption("COLZ");
	//h_PPS_xVsy_ARMFTrkDet1->SetStats(kFALSE);
	//h_PPS_xVsy_ARMFTrkDet2->SetStats(kFALSE);
	//h_PPS_xVsy_ARMFToFDet->SetStats(kFALSE);
	//h_PPS_xVsy_ARMBTrkDet1->SetOption("COLZ");
	//h_PPS_xVsy_ARMBTrkDet2->SetOption("COLZ");
	//h_PPS_xVsy_ARMBToFDet->SetOption("COLZ");
	//h_PPS_xVsy_ARMBTrkDet1->SetStats(kFALSE);
	//h_PPS_xVsy_ARMBTrkDet2->SetStats(kFALSE);
	//h_PPS_xVsy_ARMBToFDet->SetStats(kFALSE);






	f->Write();

}
