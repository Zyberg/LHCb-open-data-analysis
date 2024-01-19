import mplhep as hep
import numpy as np
import matplotlib.pyplot as plt
import uproot
from scipy.optimize import curve_fit
from matplotlib.ticker import AutoMinorLocator

hep.style.use("LHCb1")

def lorentzian(x, a, x0):
    return a / ((x-x0)**2 + a**2) / np.pi

# Read data
with uproot.open("../../intermediate-data/histograms/muon_Pseudorapidity_sum.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    histerr = file['SumPseudorapidity'].errors()
    hist, bins = file['SumPseudorapidity'].to_numpy()

    hist[ hist==0 ] = np.nan


    ax.set_xlabel(r"$\eta_{\mathrm{Z}}$")
    ax.set_ylabel("Kandidatai / (1 GeV)")

    ax.errorbar(bins[:-1], hist, histerr, linestyle="None", c='black', elinewidth=1, capthick=2, capsize=4, zorder=1)
    ax.scatter(bins[:-1], hist, zorder=2)

    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.set_yscale('log')
    ax.tick_params(axis='y', which='both', left=True, right=True)


    ax.legend()
    plt.show()
