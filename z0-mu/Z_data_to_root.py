# Please note that this fills a tuple with all particles selected by the stripping line. Further selection requirements may be needed for a clean peak! The user may also need to run additional tuple tools to get more information about each event.

from Configurables import DaVinci
from Configurables import LoKi__HDRFilter
stripFilter = LoKi__HDRFilter('StripFilter',
                              Code = "HLT_PASS('StrippingZ02MuMuLineDecision')",
                              Location = '/Event/Strip/Phys/DecReports')  

from Configurables import DecayTreeTuple, TupleToolDecay
mytuple = DecayTreeTuple("Tuple")
mytuple.Decay = "Z0 -> ^mu+ ^mu-" 
mytuple.Inputs = [
    '/Event/EW/Phys/Z02MuMuLine/Particles'
    ]
mytuple.Branches = ({
    'Z'          : 'Z0 -> mu+ mu-',
    'muon1'      : 'Z0 -> ^mu+ mu-',
    'muon2'      : 'Z0 -> mu+ ^mu-'
})
mytuple.addTool( TupleToolDecay, name = "muon1" )               
mytuple.addTool( TupleToolDecay, name = "muon2" )
mytuple.ToolList +=  [
      "TupleToolKinematic"
    ]

DaVinci().EventPreFilters = [ stripFilter ]
DaVinci().HistogramFile = "Z_Histos.root"           
DaVinci().TupleFile = "Z_test.root"        
DaVinci().EvtMax = -1                              
DaVinci().Simulation   = False                       
DaVinci().WriteFSR = True
DaVinci().InputType = 'DST'
DaVinci().PrintFreq           = 1000      
DaVinci().DataType = "2012"    
DaVinci().DDDBtag = 'dddb-20130929-1' 
DaVinci().CondDBtag = 'cond-20141107' 
DaVinci().Lumi = False

DaVinci().UserAlgorithms += [  mytuple ]
DaVinci().MainOptions  = ""                   

#This allows a local test
#uncomment the below and run with e.g. lb-run Davinci/v45r8 gaudirun.py Z_data.py
# DaVinci().Input   += ["DATAFILE='root://eospublic.cern.ch://eos/opendata/lhcb/Collision12/EW/LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21_EW_DST/00041834/0000/00041834_00000270_1.ew.dst'TYP='POOL_ROOTTREE'OPT='READ'"]
#DaVinci().Input   += ["DATAFILE='root://eospublic.cern.ch://eos/opendata/lhcb/Collision12/EW/LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21_EW_DST/00041834/0000/00041834_00000270_1.ew.dst'TYP='POOL_ROOTTREE'OPT='READ'",
#                      "DATAFILE='root://eospublic.cern.ch://eos/opendata/lhcb/Collision12/EW/LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21_EW_DST/00041834/0000/00041834_00000580_1.ew.dst'TYP='POOL_ROOTTREE'OPT='READ'",]

