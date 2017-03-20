import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# define collections once
ppsgen           = 'ppssim:PPSGen'
ppssim           = 'ppssim:PPSSim'
ppsreco          = 'ppssim:PPSReco'
vertices         = 'offlineSlimmedPrimaryVertices'
jet		 = 'slimmedJets'#'slimmedJetsAK8'
genjet           = 'slimmedGenJets'#'slimmedJets'
muon		 = 'slimmedMuons'
MET		 = 'slimmedMETs'
ppsz_resolution  = cms.double(0.22)
eta_cut		 	 = cms.double(2.4)
pt_jet		 	 = cms.double(30.0)
pt_muon		 	 = cms.double(20.0)


process.load("FWCore.MessageService.MessageLogger_cfi")
process.options=cms.untracked.PSet(wantSummary=cms.untracked.bool(True))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


# file with rootfile names
sourcefile = 'files.txt'

# path to rootfiles
path = '/afs/cern.ch/work/m/mthiel/private/ANALYZER/CMSSW_8_0_12/src/analyzer/analyzer/mount/'
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



process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string("out.root")
)

process.p = cms.Path(process.demo)
