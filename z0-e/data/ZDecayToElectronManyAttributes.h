//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 22 09:53:40 2023 by ROOT version 6.28/04
// from TTree DecayTree/DecayTree
// found on file: 2012UpAll.root
//////////////////////////////////////////////////////////

#ifndef ZDecayToElectronManyAttributes_h
#define ZDecayToElectronManyAttributes_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class ZDecayToElectronManyAttributes {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxZ_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxZ_OWNPV_COV = 1;

   // Declaration of leaf types
   Double_t        Z_ENDVERTEX_X;
   Double_t        Z_ENDVERTEX_Y;
   Double_t        Z_ENDVERTEX_Z;
   Double_t        Z_ENDVERTEX_XERR;
   Double_t        Z_ENDVERTEX_YERR;
   Double_t        Z_ENDVERTEX_ZERR;
   Double_t        Z_ENDVERTEX_CHI2;
   Int_t           Z_ENDVERTEX_NDOF;
   Float_t         Z_ENDVERTEX_COV_[3][3];
   Double_t        Z_OWNPV_X;
   Double_t        Z_OWNPV_Y;
   Double_t        Z_OWNPV_Z;
   Double_t        Z_OWNPV_XERR;
   Double_t        Z_OWNPV_YERR;
   Double_t        Z_OWNPV_ZERR;
   Double_t        Z_OWNPV_CHI2;
   Int_t           Z_OWNPV_NDOF;
   Float_t         Z_OWNPV_COV_[3][3];
   Double_t        Z_IP_OWNPV;
   Double_t        Z_IPCHI2_OWNPV;
   Double_t        Z_FD_OWNPV;
   Double_t        Z_FDCHI2_OWNPV;
   Double_t        Z_DIRA_OWNPV;
   Double_t        Z_P;
   Double_t        Z_PT;
   Double_t        Z_PE;
   Double_t        Z_PX;
   Double_t        Z_PY;
   Double_t        Z_PZ;
   Double_t        Z_MM;
   Double_t        Z_MMERR;
   Double_t        Z_M;
   Int_t           Z_ID;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;

   // List of branches
   TBranch        *b_Z_ENDVERTEX_X;   //!
   TBranch        *b_Z_ENDVERTEX_Y;   //!
   TBranch        *b_Z_ENDVERTEX_Z;   //!
   TBranch        *b_Z_ENDVERTEX_XERR;   //!
   TBranch        *b_Z_ENDVERTEX_YERR;   //!
   TBranch        *b_Z_ENDVERTEX_ZERR;   //!
   TBranch        *b_Z_ENDVERTEX_CHI2;   //!
   TBranch        *b_Z_ENDVERTEX_NDOF;   //!
   TBranch        *b_Z_ENDVERTEX_COV_;   //!
   TBranch        *b_Z_OWNPV_X;   //!
   TBranch        *b_Z_OWNPV_Y;   //!
   TBranch        *b_Z_OWNPV_Z;   //!
   TBranch        *b_Z_OWNPV_XERR;   //!
   TBranch        *b_Z_OWNPV_YERR;   //!
   TBranch        *b_Z_OWNPV_ZERR;   //!
   TBranch        *b_Z_OWNPV_CHI2;   //!
   TBranch        *b_Z_OWNPV_NDOF;   //!
   TBranch        *b_Z_OWNPV_COV_;   //!
   TBranch        *b_Z_IP_OWNPV;   //!
   TBranch        *b_Z_IPCHI2_OWNPV;   //!
   TBranch        *b_Z_FD_OWNPV;   //!
   TBranch        *b_Z_FDCHI2_OWNPV;   //!
   TBranch        *b_Z_DIRA_OWNPV;   //!
   TBranch        *b_Z_P;   //!
   TBranch        *b_Z_PT;   //!
   TBranch        *b_Z_PE;   //!
   TBranch        *b_Z_PX;   //!
   TBranch        *b_Z_PY;   //!
   TBranch        *b_Z_PZ;   //!
   TBranch        *b_Z_MM;   //!
   TBranch        *b_Z_MMERR;   //!
   TBranch        *b_Z_M;   //!
   TBranch        *b_Z_ID;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!

   ZDecayToElectronManyAttributes(TTree *tree=0);
   virtual ~ZDecayToElectronManyAttributes();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ZDecayToElectronManyAttributes_cxx
ZDecayToElectronManyAttributes::ZDecayToElectronManyAttributes(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("2012UpAll.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("2012UpAll.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("2012UpAll.root:/Tuple");
      dir->GetObject("DecayTree",tree);

   }
   Init(tree);
}

ZDecayToElectronManyAttributes::~ZDecayToElectronManyAttributes()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ZDecayToElectronManyAttributes::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ZDecayToElectronManyAttributes::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ZDecayToElectronManyAttributes::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Z_ENDVERTEX_X", &Z_ENDVERTEX_X, &b_Z_ENDVERTEX_X);
   fChain->SetBranchAddress("Z_ENDVERTEX_Y", &Z_ENDVERTEX_Y, &b_Z_ENDVERTEX_Y);
   fChain->SetBranchAddress("Z_ENDVERTEX_Z", &Z_ENDVERTEX_Z, &b_Z_ENDVERTEX_Z);
   fChain->SetBranchAddress("Z_ENDVERTEX_XERR", &Z_ENDVERTEX_XERR, &b_Z_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Z_ENDVERTEX_YERR", &Z_ENDVERTEX_YERR, &b_Z_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Z_ENDVERTEX_ZERR", &Z_ENDVERTEX_ZERR, &b_Z_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Z_ENDVERTEX_CHI2", &Z_ENDVERTEX_CHI2, &b_Z_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Z_ENDVERTEX_NDOF", &Z_ENDVERTEX_NDOF, &b_Z_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Z_ENDVERTEX_COV_", Z_ENDVERTEX_COV_, &b_Z_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Z_OWNPV_X", &Z_OWNPV_X, &b_Z_OWNPV_X);
   fChain->SetBranchAddress("Z_OWNPV_Y", &Z_OWNPV_Y, &b_Z_OWNPV_Y);
   fChain->SetBranchAddress("Z_OWNPV_Z", &Z_OWNPV_Z, &b_Z_OWNPV_Z);
   fChain->SetBranchAddress("Z_OWNPV_XERR", &Z_OWNPV_XERR, &b_Z_OWNPV_XERR);
   fChain->SetBranchAddress("Z_OWNPV_YERR", &Z_OWNPV_YERR, &b_Z_OWNPV_YERR);
   fChain->SetBranchAddress("Z_OWNPV_ZERR", &Z_OWNPV_ZERR, &b_Z_OWNPV_ZERR);
   fChain->SetBranchAddress("Z_OWNPV_CHI2", &Z_OWNPV_CHI2, &b_Z_OWNPV_CHI2);
   fChain->SetBranchAddress("Z_OWNPV_NDOF", &Z_OWNPV_NDOF, &b_Z_OWNPV_NDOF);
   fChain->SetBranchAddress("Z_OWNPV_COV_", Z_OWNPV_COV_, &b_Z_OWNPV_COV_);
   fChain->SetBranchAddress("Z_IP_OWNPV", &Z_IP_OWNPV, &b_Z_IP_OWNPV);
   fChain->SetBranchAddress("Z_IPCHI2_OWNPV", &Z_IPCHI2_OWNPV, &b_Z_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Z_FD_OWNPV", &Z_FD_OWNPV, &b_Z_FD_OWNPV);
   fChain->SetBranchAddress("Z_FDCHI2_OWNPV", &Z_FDCHI2_OWNPV, &b_Z_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Z_DIRA_OWNPV", &Z_DIRA_OWNPV, &b_Z_DIRA_OWNPV);
   fChain->SetBranchAddress("Z_P", &Z_P, &b_Z_P);
   fChain->SetBranchAddress("Z_PT", &Z_PT, &b_Z_PT);
   fChain->SetBranchAddress("Z_PE", &Z_PE, &b_Z_PE);
   fChain->SetBranchAddress("Z_PX", &Z_PX, &b_Z_PX);
   fChain->SetBranchAddress("Z_PY", &Z_PY, &b_Z_PY);
   fChain->SetBranchAddress("Z_PZ", &Z_PZ, &b_Z_PZ);
   fChain->SetBranchAddress("Z_MM", &Z_MM, &b_Z_MM);
   fChain->SetBranchAddress("Z_MMERR", &Z_MMERR, &b_Z_MMERR);
   fChain->SetBranchAddress("Z_M", &Z_M, &b_Z_M);
   fChain->SetBranchAddress("Z_ID", &Z_ID, &b_Z_ID);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   Notify();
}

Bool_t ZDecayToElectronManyAttributes::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ZDecayToElectronManyAttributes::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ZDecayToElectronManyAttributes::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ZDecayToElectronManyAttributes_cxx
