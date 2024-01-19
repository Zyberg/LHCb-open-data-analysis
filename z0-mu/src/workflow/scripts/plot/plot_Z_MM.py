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
with uproot.open("../../intermediate-data/histograms/Z_MM.root") as file:
    fig, ax = plt.subplots(figsize=(10, 5))
    hist, bins = file['InvariantMassZ'].to_numpy()

    err = file['InvariantMassZ'].errors()





    bins = np.array(bins)/1000
    center = (bins[:-1] + bins[1:]) / 2
    width = bins[1] - bins[0]

    maxind = np.argmax(hist)
    print(center[maxind])

    normalization_factor = np.trapz(center, hist)  # area under the curve

    popt, pcov = curve_fit(lorentzian, center, hist/normalization_factor)

    # Results
    a, x0 = popt[0], popt[1]

    x = np.linspace(40, 140, num=250)

    maxind = np.argmax(lorentzian(x, a, x0)*(normalization_factor))
    print(x[maxind])
    ax.plot(x, lorentzian(x, a, x0)*(normalization_factor),
           color='crimson', label='Breit-Wigner Tinkinimas', linestyle='dashed', marker='', linewidth=2)

    ax.errorbar(
        center,
        hist,
        yerr=err,
        linestyle="None",
        color="black",
        marker="o",
        label="Duomenys"
    )

    ax.set_xlabel(r"${\rm m (\mu^{+} \mu^{-})} \; \mathrm{[GeV/c^2]}$ ")
    ax.set_ylabel("Kandidatai / (1 GeV)")
    ax.set_xlim(40, 140)

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
    ax.yaxis.set_minor_locator(AutoMinorLocator(5))



    ax.legend()
    plt.show()
