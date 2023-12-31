# LHCb Open Data Analysis

This repository contains some analysis of the data available via LHCb open data.

- `z0-mu` - analysis of Z boson decay to muon-antimuon pair.
- `z0-e` - analysis of Z boson decay to electron-positron pair.

---


## Data Sources

The links containing lists of all the data files that were used for analysis are listed below:

- [LHCb_2011_Beam3500GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21r1](https://eospublichttp.cern.ch/eos/opendata/lhcb/Collision11/EW/LHCb_2011_Beam3500GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21r1_EW_DST/file-indexes/LHCb_2011_Beam3500GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21r1_EW_DST_file_index.txt)
- [LHCb_2011_Beam3500GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21r1](https://eospublichttp.cern.ch/eos/opendata/lhcb/Collision11/EW/LHCb_2011_Beam3500GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21r1_EW_DST/file-indexes/LHCb_2011_Beam3500GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21r1_EW_DST_file_index.txt)
- [LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21](https://eospublichttp.cern.ch/eos/opendata/lhcb/Collision12/EW/LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21_EW_DST/file-indexes/LHCb_2012_Beam4000GeV_VeloClosed_MagUp_RealData_Reco14_Stripping21_EW_DST_file_index.txt)
- [LHCb_2012_Beam4000GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21](https://eospublichttp.cern.ch/eos/opendata/lhcb/Collision12/EW/LHCb_2012_Beam4000GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21_EW_DST/file-indexes/LHCb_2012_Beam4000GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21_EW_DST_file_index.txt)

To obtain valid python files usable with `Z_data_to_root.py` script, go to either of these links, open _Developer Tools_ (`ctrl + shift + i` on chrome), go to _Console_, paste down this _Java Script_ code:

    copy(`DaVinci().Input += [\n\t${document.querySelector('pre').innerText.split('\n').filter(r => !!r).map(r => `"DATAFILE='${r}'TYP='POOL_ROOTTREE'OPT='READ'"`).join(',\n\t')}\n]`)

This code will automatically copy and format all the data file links in a format usable by _DaVinci_. Examples of what should be produced in the clipboard are under the `/sources` folder.

To get _root_ tuples a script `Z_data_to_root.py` has been written, specific configurations for muons or electrons are stored under `z0-mu/Z_data_to_root.py` and `z0-e/Z_data_to_root.py` respectivelly. Make sure to enter the correct _DataType_ option (`line 34`) for respective data sources. To use the script with _DaVinci_ simply run this command in your terminal after you have the _cvmfs_ environment variables set up (make sure to change the source file name):

    lb-run Davinci/v45r8 gaudirun.py Z_data_to_root.py SOURCE_LHCb_2011_Beam3500GeV_VeloClosed_MagDown_RealData_Reco14_Stripping21r1_EW_DST.py

The resulting data should look somewhat similar to the data in the `/data` folder.
