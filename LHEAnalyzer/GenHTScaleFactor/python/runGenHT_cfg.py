import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.destinations = ['cout', 'cerr']
process.MessageLogger.cerr.FwkReport.reportEvery = 5000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'root://eoscms.cern.ch//store/mc/RunIIWinter15wmLHE/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/LHE/MCRUN2_71_V1_ext1-v1/30000/00118834-2774-E511-875A-5065F3815241.root',
    )
)

process.analyzer = cms.EDAnalyzer('GenHTScaleFactor'
)

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('test.root')
                                   )


process.p = cms.Path(process.analyzer)
