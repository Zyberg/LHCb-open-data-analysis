from Configurables import DaVinci
from Configurables import LoKi__HDRFilter
from Configurables import DecayTreeTuple, TupleToolDecay

stripFilter = LoKi__HDRFilter('StripFilter',
                                Code="HLT_PASS('StrippingZ02MuMuLineDecision')",
                                Location='/Event/Strip/Phys/DecReports')

mytuple = DecayTreeTuple("Tuple")
mytuple.Decay = "Z0 -> ^mu+ ^mu-"
mytuple.Inputs = [
    '/Event/EW/Phys/Z02MuMuLine/Particles'
]
mytuple.Branches = ({
    'Z': 'Z0 -> mu+ mu-',
    'muon1': 'Z0 -> ^mu+ mu-',
    'muon2': 'Z0 -> mu+ ^mu-'
})
mytuple.addTool(TupleToolDecay, name="muon1")
mytuple.addTool(TupleToolDecay, name="muon2")
mytuple.ToolList += [
    "TupleToolKinematic",
    "TupleToolPid",
    "TupleToolANNPID",
    "TupleToolGeometry",
    "TupleToolEventInfo"
]

DaVinci().EventPreFilters = [stripFilter]
DaVinci().HistogramFile = 'batch_2_histos.root'
DaVinci().TupleFile = 'batch_2.root'
DaVinci().EvtMax = -1
DaVinci().Simulation = False
DaVinci().WriteFSR = True
DaVinci().InputType = 'DST'
DaVinci().PrintFreq = 1000
DaVinci().DataType = "2012"
DaVinci().DDDBtag = 'dddb-20130929-1'
DaVinci().CondDBtag = 'cond-20141107'
DaVinci().Lumi = False

DaVinci().UserAlgorithms += [mytuple]
DaVinci().MainOptions = ""

