# Auto generated configuration file
# using: 
# Revision: 1.381.2.7 
# Source: /local/reps/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: Configuration/GenProduction/python/EightTeV/Hadronizer_MgmMatchTuneZ2star_8TeV_madgraph_tauola_cff.py --step GEN --beamspot Realistic8TeVCollision --conditions START52_V9::All --pileup NoPileUp --datamix NODATAMIXER --eventcontent RAWSIM --datatier GEN -n -1 --python_filename=Temp_Hadronizer_5498_1.py --filein root://eoscms//eos/cms/'root://cmsxrootd.fnal.gov//store/lhe/5498/DY1JetsToLL_M-50_8TeV-madgraph_10001.lhe --no_output --no_exec
import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.parseArguments()

process = cms.Process('ANA')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:mc', '')
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
)

process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.source = cms.Source(
    "PoolSource",
    fileNames  = cms.untracked.vstring(
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0015A622-AA2B-E611-A12D-0023AEFDE888.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/00D9F874-AF2B-E611-B1F2-008CFA19746C.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/00F77F0B-AB2B-E611-9297-0025907277FE.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0256CD8F-AA2B-E611-AC4B-0025B326861E.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/02CEB422-AE2B-E611-A900-00259074AE8A.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0403FB7A-B02B-E611-A8AE-008CFA1111F4.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/040CD967-AA2B-E611-A74E-0025901D1668.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/046441ED-AA2B-E611-9A22-0090FAA59ED4.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/06156480-AB2B-E611-8400-047D7B881D74.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/06E8856E-AF2B-E611-A73A-002590548934.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0805096D-AF2B-E611-8AF9-0025905504C6.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0C7077D4-AB2B-E611-80AA-0025907B50FC.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0C7B3085-AA2B-E611-AF50-549F35AD8C0A.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0E6EC933-AA2B-E611-B765-842B2B17F557.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/0EB27E87-AD2B-E611-BDFF-008CFA197B80.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/10EF5A59-AC2B-E611-ADD5-0CC47A123FBC.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1293C184-B02B-E611-8559-008CFA197454.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/12EAE426-AD2B-E611-85CE-002590775158.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/14D52F86-AC2B-E611-9F4D-44A842BE770B.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/163FC677-AE2B-E611-A62A-008CFA197DA4.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1642C677-B02B-E611-A043-002590550504.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1888DE71-B02B-E611-A300-008CFA165F44.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1A9813EF-AA2B-E611-B9A0-44A842B29918.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1C369A64-AA2B-E611-8852-0025900EAB5E.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1C73EADA-AB2B-E611-8441-001EC9ADE690.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/1EB55A8A-AC2B-E611-8403-44A842BE8F71.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/206F1781-B02B-E611-8345-008CFA1111B4.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/20A4BDF5-AB2B-E611-B0F0-44A842BECCB1.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/223A88F3-AA2B-E611-9FA6-0CC47A123FBC.root',
'root://cmsxrootd.fnal.gov//store/mc/RunIISpring16MiniAODv2/WJetsToLNu_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/60000/223EB7F2-AA2B-E611-ADA2-00266CF83D7C.root',
),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)


process.dummy2 = cms.EDAnalyzer("GenXSecAnalyzer")



# Path and EndPath definitions
process.ana = cms.Path(process.dummy2)
# Schedule definition
process.schedule = cms.Schedule(process.ana)
