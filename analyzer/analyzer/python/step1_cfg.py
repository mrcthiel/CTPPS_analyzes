import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# define collections once
vertices         = 'offlineSlimmedPrimaryVertices'
MET		 = 'slimmedMETs'
PFCand           = 'packedPFCandidates'
ppsz_resolution  = cms.double(0.22)

# Muons
muon             = 'slimmedMuons'
eta_cut_muon     = cms.double(2.4)
pt_muon          = cms.double(20.0)
N_muon_min	 = cms.double(1.0)
N_muon_max       = cms.double(3.0)

# Jets
jet              = 'slimmedJets' #'slimmedJets'#'cleanJets'  'slimmedJetsAK8'
genjet           = 'slimmedGenJets'#'slimmedJets'
eta_cut_jet      = cms.double(2.4)
pt_jet1          = cms.double(30.0)
pt_jet2          = cms.double(30.0)
pt_jet3          = cms.double(30.0)
pt_jet4          = cms.double(30.0)
pt_jet_others    = cms.double(30.0)
N_jet_min	 = cms.double(2.0)
N_jet_max        = cms.double(99.0)





process.load("FWCore.MessageService.MessageLogger_cfi")
process.options=cms.untracked.PSet(wantSummary=cms.untracked.bool(True))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(40000) )
## std sequence for pat
process.load("PhysicsTools.PatAlgos.cleaningLayer1.cleanPatCandidates_cff")


# file with rootfile names
sourcefile = 'files.txt'

# path to rootfiles
path = 'mount/'
source = []
# read input files from source file
with open(sourcefile,'r') as f:
  lines = f.read().splitlines()
  for i in lines :
    source += ['file:' + path + i]

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(source),
    duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
    secondaryFileNames = cms.untracked.vstring()
) 


process.cleanJets = cms.EDProducer("PATJetCleaner",
    src = cms.InputTag("slimmedJets"),
    
    # preselection (any string-based cut on pat::Jet)
    preselection = cms.string(''),

    # overlap checking configurables
    checkOverlaps = cms.PSet(
        muons = cms.PSet(
           src       = cms.InputTag("slimmedMuons"),
           algorithm = cms.string("byDeltaR"),
           preselection        = cms.string(""),
           deltaR              = cms.double(0.5), 
           checkRecoComponents = cms.bool(False), # don't check if they share some AOD object ref
           pairCut             = cms.string(""),
           requireNoOverlaps   = cms.bool(True), # overlaps don't cause the jet to be discared
        ),
    ),
    # finalCut (any string-based cut on pat::Jet)
    finalCut = cms.string(''),

)


process.filter0N = cms.EDFilter( 'step_0'
        , tracksPPSTag 			= cms.InputTag("CTPPSFastTracks","CTPPSFastTrack")
        , jets                  	= cms.InputTag(jet)
        , muons                         = cms.InputTag(muon)
)

process.filterCTPPS = cms.EDFilter( 'step_CTPPS'
        , jets                  = cms.InputTag(jet)
        , muons                 = cms.InputTag(muon)
        , vertices              = cms.InputTag(vertices)
        , ppsz_resolution       = ppsz_resolution
        , SelectedVertice       = cms.InputTag("filter0N","SelectedVertice")
        , SelectedProtonF       = cms.InputTag("filter0N","SelectedProtonF")
        , SelectedProtonB       = cms.InputTag("filter0N","SelectedProtonB")
)

process.filterMuons = cms.EDFilter( 'step_Mu'
       	, muons		 	= cms.InputTag(muon)
        , vertices		= cms.InputTag(vertices)
	, eta_cut         	= eta_cut_muon
	, pt_muon		= pt_muon
        , N_muon_min            = N_muon_min 
        , N_muon_max            = N_muon_max
	, selectedmuons		= cms.InputTag("filter0N","selectedmuons")		
)

process.filterJets = cms.EDFilter( 'step_Jet'
        , jets                  = cms.InputTag(jet)
	, eta_cut               = eta_cut_jet
	, pt_jet1		= pt_jet1
        , pt_jet2               = pt_jet2
        , pt_jet3               = pt_jet3
        , pt_jet4               = pt_jet4
        , pt_jet_others         = pt_jet_others
	, N_jet_min		= N_jet_min
        , N_jet_max             = N_jet_max
	, selectedjets		= cms.InputTag("filter0N","selectedjets")
)


process.demo = cms.EDAnalyzer('analyzer'
        	, vertices          = cms.InputTag(vertices)
		, jets  		= cms.InputTag(jet)
                , genjets               = cms.InputTag(genjet)
		, muons			= cms.InputTag(muon)
		, MET			= cms.InputTag(MET)
		, genP 			= cms.InputTag("genParticles")
	        , tracksPPSTag          = cms.InputTag("CTPPSFastTracks","CTPPSFastTrack")
        	, SelectedVertice       = cms.InputTag("filterCTPPS","SelectedVertice")
        	, SelectedProtonF       = cms.InputTag("filterCTPPS","SelectedProtonF")
	        , SelectedProtonB       = cms.InputTag("filterCTPPS","SelectedProtonB")
		, selectedjets		= cms.InputTag("filterJets","selectedjets")
		, selectedmuons		= cms.InputTag("filterMuons","selectedmuons")
                , PFCand                = cms.InputTag(PFCand)
		, MCEvent 		= cms.untracked.InputTag("LHCTransport")
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string("out.root")
									)

process.outp1=cms.OutputModule("PoolOutputModule",
      fileName = cms.untracked.string('step1.root'),
      SelectEvents = cms.untracked.PSet(
              SelectEvents = cms.vstring('p')
      )
)
									

process.p = cms.Path(process.filter0N*process.filterCTPPS*process.filterMuons*process.filterJets*process.demo)
process.ep = cms.EndPath(process.outp1)
