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
with uproot.open("../../intermediate-data/histograms/muon_ProbNNmu.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    hist_leading, bins_leading = file['ProbNNmu_Leading'].to_numpy()
    hist_subleading, bins_subleading = file['ProbNNmu_Subleading'].to_numpy()

    # err_leading = file['ProbNNmu_Leading'].errors()


    bins = np.array(bins_leading)/1000
    center = (bins[:-1] + bins[1:]) / 2
    width = bins[1] - bins[0]


    ax.set_xlabel(r"${\rm P (\mu^{+} \mu^{-})}$ [GeV]")
    ax.set_ylabel("Kandidatai / (1 GeV)")
    ax.set_xlim(0, 1)
    ax.set_ylim(0, 1800)

    plt.axvline(x=0.5, ls='--', color='black', alpha=0.4, zorder=1)

    ax.scatter(bins_leading[:-1], hist_leading, label='Greitesnis', zorder=4)
    ax.scatter(bins_subleading[:-1], hist_subleading, label='Lėtesnis', zorder=3)


    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.tick_params(axis='y', which='both', left=True, right=True)
    ax.yaxis.set_minor_locator(AutoMinorLocator(5))



    ax.legend()
    plt.show()
