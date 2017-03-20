import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo2")

# define collections once
ppsgen           = 'ppssim:PPSGen'
ppssim           = 'ppssim:PPSSim'
ppsreco          = 'ppssim:PPSReco'
vertices         = 'offlineSlimmedPrimaryVertices'
jet		 = 'cleanJets'#'slimmedJets'#'cleanJets'  'slimmedJetsAK8'
genjet           = 'slimmedGenJets'#'slimmedJets'
muon		 = 'slimmedMuons'
MET		 = 'slimmedMETs'
PFCand           = 'packedPFCandidates'
Tracks           = 'generalTracks'
ppsz_resolution  = cms.double(0.22)
eta_cut		 = cms.double(2.4)
pt_jet		 = cms.double(30.0)
pt_muon		 = cms.double(20.0)
Y_Y_max		 = cms.double(0.66)
MWWMX_min	 = cms.double(0.4)

process.load("FWCore.MessageService.MessageLogger_cfi")
process.options=cms.untracked.PSet(wantSummary=cms.untracked.bool(True))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
## std sequence for pat
process.load("PhysicsTools.PatAlgos.cleaningLayer1.cleanPatCandidates_cff")


# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WJets_inc_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WW_exc_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WW_exc_noPU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WW_inc_semilep_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WZ_inc_WLep_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/WZ_inc_ZLep_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/single_t_inc_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/ttbar_all_inc_PU_miniAOD_step1_stepCTPPS.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/stepCTPPS/events/ttbar_mumu_inc_PU_miniAOD_step1_stepCTPPS.root'
	'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/WW_exc_PU_step1_Tracks.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/WW_inc_PU_step1_Tracks.root'
    ),
    duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
    secondaryFileNames = cms.untracked.vstring()
) 


process.filterNMNJ = cms.EDFilter( 'step_NmuonNjets'
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , selectedjets          = cms.InputTag("filterYcut","sectedjets")
                , selectedmuons         = cms.InputTag("filterYcut","sectedmuons")
)

process.filterDRJJ = cms.EDFilter( 'step_DRJJ'
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , selectedjets          = cms.InputTag("filterYcut","sectedjets")
                , selectedmuons         = cms.InputTag("filterYcut","sectedmuons")
)

process.filterWJM = cms.EDFilter( 'step_WJmass'
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , selectedjets          = cms.InputTag("filterYcut","sectedjets")
                , selectedmuons         = cms.InputTag("filterYcut","sectedmuons")
)

process.filterWWacop = cms.EDFilter( 'step_WWacoplanarity'
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , MET                           = cms.InputTag(MET)
                , selectedjets          = cms.InputTag("filterYcut","sectedjets")
                , selectedmuons         = cms.InputTag("filterYcut","sectedmuons")
)

process.demo1 = cms.EDAnalyzer('analyzer'
        	, vertices          = cms.InputTag(vertices)
		, jets  		 	= cms.InputTag(jet)
                , genjets                       = cms.InputTag(genjet)
		, muons			 	= cms.InputTag(muon)
		, MET			 	= cms.InputTag(MET)
		, ppsReco   		= cms.InputTag(ppsreco)
		, genP 			= cms.InputTag("genParticles")
                , SelectedVertice       = cms.InputTag("filter3","SelectedVertice")
		, selectedjets		= cms.InputTag("filter3","sectedjets")
		, selectedmuons		= cms.InputTag("filter3","sectedmuons")
                , PFCand                = cms.InputTag(PFCand)
                , Tracks                = cms.InputTag(Tracks)
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
									

process.p = cms.Path(process.demo1)
#process.p = cms.Path(process.filterNMNJ*process.filterDRJJ*process.filterWJM*process.filterWWacop*process.demo1)
#process.ep = cms.EndPath(process.outp1)
