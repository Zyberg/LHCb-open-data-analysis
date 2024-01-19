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
with uproot.open("../../intermediate-data/histograms/muon_PT_sum.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    histerr = file['SumPT'].errors()
    hist, bins = file['SumPT'].to_numpy()

    bins = np.array(bins)/1000

    bin_centers = 0.5*(bins[1:] + bins[:-1])

    ax.set_xlabel(r"$p_{\mathrm{T}} \left( \mathrm{Z^0} \right) \; \mathrm{[GeV/c]}$")
    ax.set_ylabel("Kandidatai / (1 GeV)")
    ax.set_xlim(0, 120)

    ax.hist(bins[:-1], bins, weights=hist, log=True)
    ax.errorbar(bin_centers, hist, histerr, linestyle="None", c='black', elinewidth=1, capthick=2, capsize=4, zorder=1)

    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.tick_params(axis='y', which='both', left=True, right=True)

    ax.legend()
    plt.show()
