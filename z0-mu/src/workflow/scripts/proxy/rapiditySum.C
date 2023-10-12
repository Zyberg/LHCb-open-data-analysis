#include <TLorentzVector.h>
#include <Math/LorentzVector.h>


// TODO: extract to utility
struct Muon {
  Double_t PX;
  Double_t PY;
  Double_t PZ;
  Double_t M;
};

TLorentzVector* makeLorentzVectorFromMuon(Muon m) {
  return new TLorentzVector(m.PX, m.PY, m.PZ, TMath::Sqrt(m.M * m.M + m.PX * m.PX + m.PY * m.PY + m.PZ * m.PZ));
}

double rapiditySum() {
  // TODO: figure out how to use these magic variables
  auto muon1 = makeLorentzVectorFromMuon({muon1_PX, muon1_PY, muon1_PZ, muon1_M});
  auto muon2 = makeLorentzVectorFromMuon({muon2_PX, muon2_PY, muon2_PZ, muon2_M});

  TLorentzVector total = muon1 + muon2;

  return total.Rapidity();
}