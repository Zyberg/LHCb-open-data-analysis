import mplhep as hep
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import uproot
from scipy.optimize import curve_fit
from matplotlib.ticker import AutoMinorLocator

hep.style.use("LHCb1")

def lorentzian(x, a, x0):
    return a / ((x-x0)**2 + a**2) / np.pi

# Read data
with uproot.open("../../intermediate-data/histograms/muon_Rapidity.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    hist_leading, bins_leading = file['LeadingRapidity'].to_numpy()
    hist_subleading, bins_subleading = file['SubleadingRapidity'].to_numpy()

    # err_leading = file['ProbNNmu_Leading'].errors()




    bins = np.array(bins_leading)/1000
    center = (bins[:-1] + bins[1:]) / 2
    width = bins[1] - bins[0]


    ax.set_xlabel(r"$Sparta$")
    ax.set_ylabel("Kandidatai / (1 GeV)")

    ax.hist(bins_leading[:-1], bins_leading, weights=hist_leading, label='Greitesnis', alpha=0.5)
    ax.hist(bins_subleading[:-1], bins_subleading, weights=hist_subleading, label='Lėtesnis', alpha=0.5)


    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.tick_params(axis='y', which='both', left=True, right=True)
    ax.yaxis.set_minor_locator(AutoMinorLocator(5))



    ax.legend()
    plt.show()
