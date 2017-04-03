import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo1")

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
Tracks		 = 'generalTracks'
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
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WJets_inc_PU_miniAOD_step1.root'
	'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WW_exc_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WW_exc_noPU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WW_inc_semilep_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WZ_inc_WLep_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/WZ_inc_ZLep_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/single_t_inc_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/ttbar_all_inc_PU_miniAOD_step1.root'
	#'file:/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/step1/events/ttbar_mumu_inc_PU_miniAOD_step1.root'
    ),
    duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
    secondaryFileNames = cms.untracked.vstring()
) 



process.filterMassFraction = cms.EDFilter( 'step_MassFraction'
        	, vertices          = cms.InputTag(vertices)
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , MET                           = cms.InputTag(MET)
                , ppsReco               = cms.InputTag(ppsreco)
                , SelectedVertice       = cms.InputTag("filter3","SelectedVertice")
                , selectedjets          = cms.InputTag("filter3","sectedjets")
                , selectedmuons         = cms.InputTag("filter3","sectedmuons")
                , MWWMX_min             = MWWMX_min
)

process.filterMassFractionCut = cms.EDFilter( 'step_MassFractionCut'
                , vertices          = cms.InputTag(vertices)
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , MET                           = cms.InputTag(MET)
                , ppsReco               = cms.InputTag(ppsreco)
                , SelectedVertice       = cms.InputTag("filterMassFraction","SelectedVertice")
                , selectedjets          = cms.InputTag("filterMassFraction","sectedjets")
                , selectedmuons         = cms.InputTag("filterMassFraction","sectedmuons")
                , MWWMX_min             = MWWMX_min
)

process.filterYcut = cms.EDFilter( 'step_Ycut'
                , vertices          = cms.InputTag(vertices)
                , jets                          = cms.InputTag(jet)
                , muons                         = cms.InputTag(muon)
                , MET                           = cms.InputTag(MET)
                , ppsReco               = cms.InputTag(ppsreco)
                , SelectedVertice       = cms.InputTag("filterMassFractionCut","SelectedVertice")
                , selectedjets          = cms.InputTag("filterMassFractionCut","sectedjets")
                , selectedmuons         = cms.InputTag("filterMassFractionCut","sectedmuons")
                , Y_Y_max             	= Y_Y_max
)


process.demo1 = cms.EDAnalyzer('analyzer'
        	, vertices          = cms.InputTag(vertices)
		, jets  		 	= cms.InputTag(jet)
                , genjets                       = cms.InputTag(genjet)
		, muons			 	= cms.InputTag(muon)
		, MET			 	= cms.InputTag(MET)
		, ppsReco   		= cms.InputTag(ppsreco)
		, genP 			= cms.InputTag("genParticles")
                , SelectedVertice       = cms.InputTag("filterMassFraction","SelectedVertice")
                , selectedjets          = cms.InputTag("filterMassFraction","sectedjets")
                , selectedmuons         = cms.InputTag("filterMassFraction","sectedmuons")
                , PFCand                = cms.InputTag(PFCand)
		, Tracks		= cms.InputTag(Tracks)
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
									

process.p = cms.Path(process.filterMassFraction*process.demo1)
#process.p = cms.Path(process.filterSelVert*process.demo1)
#process.p = cms.Path(process.filterSelVert*process.filterMassFraction*process.demo1)
#process.ep = cms.EndPath(process.outp1)
