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
with uproot.open("../../intermediate-data/histograms/muon_Rapidity_sum.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    hist, bins = file['SumRapidity'].to_numpy()

    # err_leading = file['ProbNNmu_Leading'].errors()



    ax.set_xlabel(r"$Sparta$")
    ax.set_ylabel("Kandidatai / (1 GeV)")
    # ax.set_xlim(0, 1)
    ax.set_xlim(1, 5.5)

    ax.scatter(bins[:-1], hist)


    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.tick_params(axis='y', which='both', left=True, right=True)
    ax.yaxis.set_minor_locator(AutoMinorLocator(5))



    ax.legend()
    plt.show()
