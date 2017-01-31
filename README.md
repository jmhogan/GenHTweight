# GenHTweight

EDAnalyzer LHEAnalyzer contains plugin GenHTScaleFactor, which saves a tree and 
several histograms with genHT related quantities. 

To calculate scale factors, run GenHTScaleFactor over all LHE-tier ROOT files for 
binned and inclusive samples, using the config file in the python directory.

test with: cmsRun runGenHT_cfg.py

To get pre-matching cross sections, use cmsRun on runXsecAna.py with AOD files
for the relevant sample (MINIAOD possible, gives less complete info than AOD). 
The number of events is an input parameter -- at least 100k events should be run, 
with more events making a more precise result. This can't be split into lots of 
jobs with few events since the result is just text, nothing to hadd.

cmsRun runXsecAna.py --maxEvents=100000

To plot genHT and ratios there is the ROOT macro plotSFs.C. 

root -l -b -q plotSFs.C

-- Julie


