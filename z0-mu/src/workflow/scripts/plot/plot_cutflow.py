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
with uproot.open("../old/cutflow.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    print(file)
    histerr = file['cutFlowHistogram'].errors()
    hist, bins = file['cutFlowHistogram'].to_numpy()



    bins = [
        r"Visi",
        r"Yra $\mu^{+} \mu^{-}$ pora",
        r"$p_{\mathrm{T}} > 25\; \mathrm{GeV}$",
        r"$Z_{MMERR} > 4500$",
        r"$P\left( \mu^{+}, \mu^{-} \right) > 0{,}9$",
        r"$P\left( \mu^{+}, \mu^{-} \right) > 0{,}5$",
        r"$P\left( \mu \right) > 0{,}9$",
        r"$P\left( \pi \right) < 0{,}1$",
        r"$P\left( e \right) < 0{,}1$",
        r"$P\left( p \right) < 0{,}1$",
    ]

    ax.set_ylabel("Kandidatai / (1 GeV)")

    ax.bar(bins, hist)

    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    plt.xticks(rotation=45, ha="right")
    ax.tick_params(axis='x', which='both', top=True, bottom=True)
    plt.rc('xtick', labelsize=6)

    ax.tick_params(axis='y', which='both', left=True, right=True)
    ax.yaxis.set_minor_locator(AutoMinorLocator(5))

    ax.legend()
    plt.show()
