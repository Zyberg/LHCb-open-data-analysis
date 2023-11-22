# Z boson decay into two muons analysis

Detailed description of the analysis and theoretical background can be found in the latex generated `.pdf` file under `/analysis`.

## To do list

- [x] Have a somewhat decent theoretical understanding of the processes that are happening in the specific decay.

- [x] Create an event loop file to access some variables.
- [x] Compute the invariant mass of the two leading leptons in the event and plot it. Also: $p_z = p_T sinh(\nu)$ - evaluate it's dependency on the polar angle $\theta$ and then rewrite as a function of pseudorapidity $\nu$.
- [x] Compare invariant mass calculation with TLorentzVector results

- [x] Create a "cut flow" histogram. With these cuts, if possible (taken from ATLAS, adapt): weights, trigger, GRL, vertex, 2 Lepton, PDGID, charge, $p_T$ cut, isolation, tight ID, Z mass.
- [x] Create a mass "cut flow" chart with overlapping cuts
- [x] Choose a reasonable selection and process all the data sources with it.

- [x] Fit Z mass to Gauss and Breit-Wigner line shapes.
- [ ] Try to compare results with [PDG](https://pdg.lbl.gov/)

Additional workflow improvements:

- [x] Utilize _Snakemake_.
- [x] Extract cutflow and data preparation step out of charting code for all currently described variables.
- [ ] Prepare config for _Kolmogorov–Smirnov test_ implementation.
