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
with uproot.open("../../intermediate-data/histograms/muon_PT.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    hist_leading, bins_leading = file['LeadingPT'].to_numpy()
    hist_subleading, bins_subleading = file['SubleadingPT'].to_numpy()

    # err_leading = file['ProbNNmu_Leading'].errors()




    bins_leading = np.array(bins_leading)/1000
    bins_subleading = np.array(bins_subleading)/1000


    ax.set_xlabel(r"$p_{\mathrm{T}} \left( \mathrm{\mu} \right) \; \mathrm{[GeV/c]}$")
    ax.set_ylabel("Kandidatai / (1 GeV)")
    ax.set_xlim(24, 130)
    # ax.set_ylim(0, 700)

    ax.hist(bins_leading[:-1], bins_leading, weights=hist_leading, label='Greitesnis', alpha=0.5, log=True)
    ax.hist(bins_subleading[:-1], bins_subleading, weights=hist_subleading, label='Lėtesnis', alpha=0.5, log=True)
    # ax.scatter(bins_subleading[:-1], hist_subleading, label='subleading')

    # ax.xaxis.set_major_locator(plt.MaxNLocator(6))
    # ax.xaxis.set_minor_locator(plt.MaxNLocator(27))
    # Set the number of major ticks
    # num_major_ticks = 10
    # ax.xaxis.set_major_locator(MultipleLocator(len(center) / (num_major_ticks)))

    # # Set the number of minor ticks (5 minor ticks between each major tick)
    # num_minor_ticks = 5
    # ax.xaxis.set_minor_locator(MultipleLocator(1/ (num_minor_ticks + 1)))


    plt.locator_params(axis='x', nbins=10) 
    ax.xaxis.set_minor_locator(AutoMinorLocator(5))
    ax.tick_params(axis='x', which='both', top=True, bottom=True)

    ax.tick_params(axis='y', which='both', left=True, right=True)



    ax.legend()
    plt.show()
