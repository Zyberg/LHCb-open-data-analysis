//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 12 16:50:43 2023 by ROOT version 6.28/04
// from TTree DecayTree/DecayTree
// found on file: ../data/2011Up.root
//////////////////////////////////////////////////////////

#ifndef ZDecayAnalyser_h
#define ZDecayAnalyser_h

#include <TChain.h>
#include <TFile.h>
#include <TROOT.h>

// Header file for the classes stored in the TTree if any.

class ZDecayAnalyser {
public:
  TTree *fChain;  //! pointer to the analyzed TTree or TChain
  Int_t fCurrent; //! current Tree number in a TChain

  // Fixed size dimensions of array or collections stored in the TTree if any.
  static constexpr Int_t kMaxZ_ENDVERTEX_COV = 1;
  static constexpr Int_t kMaxZ_OWNPV_COV = 1;
  static constexpr Int_t kMaxmuon1_OWNPV_COV = 1;
  static constexpr Int_t kMaxmuon1_ORIVX_COV = 1;
  static constexpr Int_t kMaxmuon2_OWNPV_COV = 1;
  static constexpr Int_t kMaxmuon2_ORIVX_COV = 1;

  // Declaration of leaf types
  Double_t Z_ENDVERTEX_X;
  Double_t Z_ENDVERTEX_Y;
  Double_t Z_ENDVERTEX_Z;
  Double_t Z_ENDVERTEX_XERR;
  Double_t Z_ENDVERTEX_YERR;
  Double_t Z_ENDVERTEX_ZERR;
  Double_t Z_ENDVERTEX_CHI2;
  Int_t Z_ENDVERTEX_NDOF;
  Float_t Z_ENDVERTEX_COV_[3][3];
  Double_t Z_OWNPV_X;
  Double_t Z_OWNPV_Y;
  Double_t Z_OWNPV_Z;
  Double_t Z_OWNPV_XERR;
  Double_t Z_OWNPV_YERR;
  Double_t Z_OWNPV_ZERR;
  Double_t Z_OWNPV_CHI2;
  Int_t Z_OWNPV_NDOF;
  Float_t Z_OWNPV_COV_[3][3];
  Double_t Z_IP_OWNPV;
  Double_t Z_IPCHI2_OWNPV;
  Double_t Z_FD_OWNPV;
  Double_t Z_FDCHI2_OWNPV;
  Double_t Z_DIRA_OWNPV;
  Double_t Z_P;
  Double_t Z_PT;
  Double_t Z_PE;
  Double_t Z_PX;
  Double_t Z_PY;
  Double_t Z_PZ;
  Double_t Z_MM;
  Double_t Z_MMERR;
  Double_t Z_M;
  Int_t Z_ID;
  Double_t muon1_MC12TuneV2_ProbNNe;
  Double_t muon1_MC12TuneV2_ProbNNmu;
  Double_t muon1_MC12TuneV2_ProbNNpi;
  Double_t muon1_MC12TuneV2_ProbNNk;
  Double_t muon1_MC12TuneV2_ProbNNp;
  Double_t muon1_MC12TuneV2_ProbNNghost;
  Double_t muon1_MC12TuneV3_ProbNNe;
  Double_t muon1_MC12TuneV3_ProbNNmu;
  Double_t muon1_MC12TuneV3_ProbNNpi;
  Double_t muon1_MC12TuneV3_ProbNNk;
  Double_t muon1_MC12TuneV3_ProbNNp;
  Double_t muon1_MC12TuneV3_ProbNNghost;
  Double_t muon1_MC12TuneV4_ProbNNe;
  Double_t muon1_MC12TuneV4_ProbNNmu;
  Double_t muon1_MC12TuneV4_ProbNNpi;
  Double_t muon1_MC12TuneV4_ProbNNk;
  Double_t muon1_MC12TuneV4_ProbNNp;
  Double_t muon1_MC12TuneV4_ProbNNghost;
  Double_t muon1_MC15TuneV1_ProbNNe;
  Double_t muon1_MC15TuneV1_ProbNNmu;
  Double_t muon1_MC15TuneV1_ProbNNpi;
  Double_t muon1_MC15TuneV1_ProbNNk;
  Double_t muon1_MC15TuneV1_ProbNNp;
  Double_t muon1_MC15TuneV1_ProbNNghost;
  Double_t muon1_OWNPV_X;
  Double_t muon1_OWNPV_Y;
  Double_t muon1_OWNPV_Z;
  Double_t muon1_OWNPV_XERR;
  Double_t muon1_OWNPV_YERR;
  Double_t muon1_OWNPV_ZERR;
  Double_t muon1_OWNPV_CHI2;
  Int_t muon1_OWNPV_NDOF;
  Float_t muon1_OWNPV_COV_[3][3];
  Double_t muon1_IP_OWNPV;
  Double_t muon1_IPCHI2_OWNPV;
  Double_t muon1_ORIVX_X;
  Double_t muon1_ORIVX_Y;
  Double_t muon1_ORIVX_Z;
  Double_t muon1_ORIVX_XERR;
  Double_t muon1_ORIVX_YERR;
  Double_t muon1_ORIVX_ZERR;
  Double_t muon1_ORIVX_CHI2;
  Int_t muon1_ORIVX_NDOF;
  Float_t muon1_ORIVX_COV_[3][3];
  Double_t muon1_P;
  Double_t muon1_PT;
  Double_t muon1_PE;
  Double_t muon1_PX;
  Double_t muon1_PY;
  Double_t muon1_PZ;
  Double_t muon1_M;
  Int_t muon1_ID;
  Double_t muon1_PIDe;
  Double_t muon1_PIDmu;
  Double_t muon1_PIDK;
  Double_t muon1_PIDp;
  Double_t muon1_PIDd;
  Double_t muon1_ProbNNe;
  Double_t muon1_ProbNNk;
  Double_t muon1_ProbNNp;
  Double_t muon1_ProbNNpi;
  Double_t muon1_ProbNNmu;
  Double_t muon1_ProbNNd;
  Double_t muon1_ProbNNghost;
  Bool_t muon1_hasMuon;
  Bool_t muon1_isMuon;
  Bool_t muon1_hasRich;
  Bool_t muon1_UsedRichAerogel;
  Bool_t muon1_UsedRich1Gas;
  Bool_t muon1_UsedRich2Gas;
  Bool_t muon1_RichAboveElThres;
  Bool_t muon1_RichAboveMuThres;
  Bool_t muon1_RichAbovePiThres;
  Bool_t muon1_RichAboveKaThres;
  Bool_t muon1_RichAbovePrThres;
  Bool_t muon1_hasCalo;
  Double_t muon2_MC12TuneV2_ProbNNe;
  Double_t muon2_MC12TuneV2_ProbNNmu;
  Double_t muon2_MC12TuneV2_ProbNNpi;
  Double_t muon2_MC12TuneV2_ProbNNk;
  Double_t muon2_MC12TuneV2_ProbNNp;
  Double_t muon2_MC12TuneV2_ProbNNghost;
  Double_t muon2_MC12TuneV3_ProbNNe;
  Double_t muon2_MC12TuneV3_ProbNNmu;
  Double_t muon2_MC12TuneV3_ProbNNpi;
  Double_t muon2_MC12TuneV3_ProbNNk;
  Double_t muon2_MC12TuneV3_ProbNNp;
  Double_t muon2_MC12TuneV3_ProbNNghost;
  Double_t muon2_MC12TuneV4_ProbNNe;
  Double_t muon2_MC12TuneV4_ProbNNmu;
  Double_t muon2_MC12TuneV4_ProbNNpi;
  Double_t muon2_MC12TuneV4_ProbNNk;
  Double_t muon2_MC12TuneV4_ProbNNp;
  Double_t muon2_MC12TuneV4_ProbNNghost;
  Double_t muon2_MC15TuneV1_ProbNNe;
  Double_t muon2_MC15TuneV1_ProbNNmu;
  Double_t muon2_MC15TuneV1_ProbNNpi;
  Double_t muon2_MC15TuneV1_ProbNNk;
  Double_t muon2_MC15TuneV1_ProbNNp;
  Double_t muon2_MC15TuneV1_ProbNNghost;
  Double_t muon2_OWNPV_X;
  Double_t muon2_OWNPV_Y;
  Double_t muon2_OWNPV_Z;
  Double_t muon2_OWNPV_XERR;
  Double_t muon2_OWNPV_YERR;
  Double_t muon2_OWNPV_ZERR;
  Double_t muon2_OWNPV_CHI2;
  Int_t muon2_OWNPV_NDOF;
  Float_t muon2_OWNPV_COV_[3][3];
  Double_t muon2_IP_OWNPV;
  Double_t muon2_IPCHI2_OWNPV;
  Double_t muon2_ORIVX_X;
  Double_t muon2_ORIVX_Y;
  Double_t muon2_ORIVX_Z;
  Double_t muon2_ORIVX_XERR;
  Double_t muon2_ORIVX_YERR;
  Double_t muon2_ORIVX_ZERR;
  Double_t muon2_ORIVX_CHI2;
  Int_t muon2_ORIVX_NDOF;
  Float_t muon2_ORIVX_COV_[3][3];
  Double_t muon2_P;
  Double_t muon2_PT;
  Double_t muon2_PE;
  Double_t muon2_PX;
  Double_t muon2_PY;
  Double_t muon2_PZ;
  Double_t muon2_M;
  Int_t muon2_ID;
  Double_t muon2_PIDe;
  Double_t muon2_PIDmu;
  Double_t muon2_PIDK;
  Double_t muon2_PIDp;
  Double_t muon2_PIDd;
  Double_t muon2_ProbNNe;
  Double_t muon2_ProbNNk;
  Double_t muon2_ProbNNp;
  Double_t muon2_ProbNNpi;
  Double_t muon2_ProbNNmu;
  Double_t muon2_ProbNNd;
  Double_t muon2_ProbNNghost;
  Bool_t muon2_hasMuon;
  Bool_t muon2_isMuon;
  Bool_t muon2_hasRich;
  Bool_t muon2_UsedRichAerogel;
  Bool_t muon2_UsedRich1Gas;
  Bool_t muon2_UsedRich2Gas;
  Bool_t muon2_RichAboveElThres;
  Bool_t muon2_RichAboveMuThres;
  Bool_t muon2_RichAbovePiThres;
  Bool_t muon2_RichAboveKaThres;
  Bool_t muon2_RichAbovePrThres;
  Bool_t muon2_hasCalo;
  UInt_t nCandidate;
  ULong64_t totCandidates;
  ULong64_t EventInSequence;
  UInt_t runNumber;
  ULong64_t eventNumber;
  UInt_t BCID;
  Int_t BCType;
  UInt_t OdinTCK;
  UInt_t L0DUTCK;
  UInt_t HLT1TCK;
  UInt_t HLT2TCK;
  ULong64_t GpsTime;
  Short_t Polarity;

  // List of branches
  TBranch *b_Z_ENDVERTEX_X;                //!
  TBranch *b_Z_ENDVERTEX_Y;                //!
  TBranch *b_Z_ENDVERTEX_Z;                //!
  TBranch *b_Z_ENDVERTEX_XERR;             //!
  TBranch *b_Z_ENDVERTEX_YERR;             //!
  TBranch *b_Z_ENDVERTEX_ZERR;             //!
  TBranch *b_Z_ENDVERTEX_CHI2;             //!
  TBranch *b_Z_ENDVERTEX_NDOF;             //!
  TBranch *b_Z_ENDVERTEX_COV_;             //!
  TBranch *b_Z_OWNPV_X;                    //!
  TBranch *b_Z_OWNPV_Y;                    //!
  TBranch *b_Z_OWNPV_Z;                    //!
  TBranch *b_Z_OWNPV_XERR;                 //!
  TBranch *b_Z_OWNPV_YERR;                 //!
  TBranch *b_Z_OWNPV_ZERR;                 //!
  TBranch *b_Z_OWNPV_CHI2;                 //!
  TBranch *b_Z_OWNPV_NDOF;                 //!
  TBranch *b_Z_OWNPV_COV_;                 //!
  TBranch *b_Z_IP_OWNPV;                   //!
  TBranch *b_Z_IPCHI2_OWNPV;               //!
  TBranch *b_Z_FD_OWNPV;                   //!
  TBranch *b_Z_FDCHI2_OWNPV;               //!
  TBranch *b_Z_DIRA_OWNPV;                 //!
  TBranch *b_Z_P;                          //!
  TBranch *b_Z_PT;                         //!
  TBranch *b_Z_PE;                         //!
  TBranch *b_Z_PX;                         //!
  TBranch *b_Z_PY;                         //!
  TBranch *b_Z_PZ;                         //!
  TBranch *b_Z_MM;                         //!
  TBranch *b_Z_MMERR;                      //!
  TBranch *b_Z_M;                          //!
  TBranch *b_Z_ID;                         //!
  TBranch *b_muon1_MC12TuneV2_ProbNNe;     //!
  TBranch *b_muon1_MC12TuneV2_ProbNNmu;    //!
  TBranch *b_muon1_MC12TuneV2_ProbNNpi;    //!
  TBranch *b_muon1_MC12TuneV2_ProbNNk;     //!
  TBranch *b_muon1_MC12TuneV2_ProbNNp;     //!
  TBranch *b_muon1_MC12TuneV2_ProbNNghost; //!
  TBranch *b_muon1_MC12TuneV3_ProbNNe;     //!
  TBranch *b_muon1_MC12TuneV3_ProbNNmu;    //!
  TBranch *b_muon1_MC12TuneV3_ProbNNpi;    //!
  TBranch *b_muon1_MC12TuneV3_ProbNNk;     //!
  TBranch *b_muon1_MC12TuneV3_ProbNNp;     //!
  TBranch *b_muon1_MC12TuneV3_ProbNNghost; //!
  TBranch *b_muon1_MC12TuneV4_ProbNNe;     //!
  TBranch *b_muon1_MC12TuneV4_ProbNNmu;    //!
  TBranch *b_muon1_MC12TuneV4_ProbNNpi;    //!
  TBranch *b_muon1_MC12TuneV4_ProbNNk;     //!
  TBranch *b_muon1_MC12TuneV4_ProbNNp;     //!
  TBranch *b_muon1_MC12TuneV4_ProbNNghost; //!
  TBranch *b_muon1_MC15TuneV1_ProbNNe;     //!
  TBranch *b_muon1_MC15TuneV1_ProbNNmu;    //!
  TBranch *b_muon1_MC15TuneV1_ProbNNpi;    //!
  TBranch *b_muon1_MC15TuneV1_ProbNNk;     //!
  TBranch *b_muon1_MC15TuneV1_ProbNNp;     //!
  TBranch *b_muon1_MC15TuneV1_ProbNNghost; //!
  TBranch *b_muon1_OWNPV_X;                //!
  TBranch *b_muon1_OWNPV_Y;                //!
  TBranch *b_muon1_OWNPV_Z;                //!
  TBranch *b_muon1_OWNPV_XERR;             //!
  TBranch *b_muon1_OWNPV_YERR;             //!
  TBranch *b_muon1_OWNPV_ZERR;             //!
  TBranch *b_muon1_OWNPV_CHI2;             //!
  TBranch *b_muon1_OWNPV_NDOF;             //!
  TBranch *b_muon1_OWNPV_COV_;             //!
  TBranch *b_muon1_IP_OWNPV;               //!
  TBranch *b_muon1_IPCHI2_OWNPV;           //!
  TBranch *b_muon1_ORIVX_X;                //!
  TBranch *b_muon1_ORIVX_Y;                //!
  TBranch *b_muon1_ORIVX_Z;                //!
  TBranch *b_muon1_ORIVX_XERR;             //!
  TBranch *b_muon1_ORIVX_YERR;             //!
  TBranch *b_muon1_ORIVX_ZERR;             //!
  TBranch *b_muon1_ORIVX_CHI2;             //!
  TBranch *b_muon1_ORIVX_NDOF;             //!
  TBranch *b_muon1_ORIVX_COV_;             //!
  TBranch *b_muon1_P;                      //!
  TBranch *b_muon1_PT;                     //!
  TBranch *b_muon1_PE;                     //!
  TBranch *b_muon1_PX;                     //!
  TBranch *b_muon1_PY;                     //!
  TBranch *b_muon1_PZ;                     //!
  TBranch *b_muon1_M;                      //!
  TBranch *b_muon1_ID;                     //!
  TBranch *b_muon1_PIDe;                   //!
  TBranch *b_muon1_PIDmu;                  //!
  TBranch *b_muon1_PIDK;                   //!
  TBranch *b_muon1_PIDp;                   //!
  TBranch *b_muon1_PIDd;                   //!
  TBranch *b_muon1_ProbNNe;                //!
  TBranch *b_muon1_ProbNNk;                //!
  TBranch *b_muon1_ProbNNp;                //!
  TBranch *b_muon1_ProbNNpi;               //!
  TBranch *b_muon1_ProbNNmu;               //!
  TBranch *b_muon1_ProbNNd;                //!
  TBranch *b_muon1_ProbNNghost;            //!
  TBranch *b_muon1_hasMuon;                //!
  TBranch *b_muon1_isMuon;                 //!
  TBranch *b_muon1_hasRich;                //!
  TBranch *b_muon1_UsedRichAerogel;        //!
  TBranch *b_muon1_UsedRich1Gas;           //!
  TBranch *b_muon1_UsedRich2Gas;           //!
  TBranch *b_muon1_RichAboveElThres;       //!
  TBranch *b_muon1_RichAboveMuThres;       //!
  TBranch *b_muon1_RichAbovePiThres;       //!
  TBranch *b_muon1_RichAboveKaThres;       //!
  TBranch *b_muon1_RichAbovePrThres;       //!
  TBranch *b_muon1_hasCalo;                //!
  TBranch *b_muon2_MC12TuneV2_ProbNNe;     //!
  TBranch *b_muon2_MC12TuneV2_ProbNNmu;    //!
  TBranch *b_muon2_MC12TuneV2_ProbNNpi;    //!
  TBranch *b_muon2_MC12TuneV2_ProbNNk;     //!
  TBranch *b_muon2_MC12TuneV2_ProbNNp;     //!
  TBranch *b_muon2_MC12TuneV2_ProbNNghost; //!
  TBranch *b_muon2_MC12TuneV3_ProbNNe;     //!
  TBranch *b_muon2_MC12TuneV3_ProbNNmu;    //!
  TBranch *b_muon2_MC12TuneV3_ProbNNpi;    //!
  TBranch *b_muon2_MC12TuneV3_ProbNNk;     //!
  TBranch *b_muon2_MC12TuneV3_ProbNNp;     //!
  TBranch *b_muon2_MC12TuneV3_ProbNNghost; //!
  TBranch *b_muon2_MC12TuneV4_ProbNNe;     //!
  TBranch *b_muon2_MC12TuneV4_ProbNNmu;    //!
  TBranch *b_muon2_MC12TuneV4_ProbNNpi;    //!
  TBranch *b_muon2_MC12TuneV4_ProbNNk;     //!
  TBranch *b_muon2_MC12TuneV4_ProbNNp;     //!
  TBranch *b_muon2_MC12TuneV4_ProbNNghost; //!
  TBranch *b_muon2_MC15TuneV1_ProbNNe;     //!
  TBranch *b_muon2_MC15TuneV1_ProbNNmu;    //!
  TBranch *b_muon2_MC15TuneV1_ProbNNpi;    //!
  TBranch *b_muon2_MC15TuneV1_ProbNNk;     //!
  TBranch *b_muon2_MC15TuneV1_ProbNNp;     //!
  TBranch *b_muon2_MC15TuneV1_ProbNNghost; //!
  TBranch *b_muon2_OWNPV_X;                //!
  TBranch *b_muon2_OWNPV_Y;                //!
  TBranch *b_muon2_OWNPV_Z;                //!
  TBranch *b_muon2_OWNPV_XERR;             //!
  TBranch *b_muon2_OWNPV_YERR;             //!
  TBranch *b_muon2_OWNPV_ZERR;             //!
  TBranch *b_muon2_OWNPV_CHI2;             //!
  TBranch *b_muon2_OWNPV_NDOF;             //!
  TBranch *b_muon2_OWNPV_COV_;             //!
  TBranch *b_muon2_IP_OWNPV;               //!
  TBranch *b_muon2_IPCHI2_OWNPV;           //!
  TBranch *b_muon2_ORIVX_X;                //!
  TBranch *b_muon2_ORIVX_Y;                //!
  TBranch *b_muon2_ORIVX_Z;                //!
  TBranch *b_muon2_ORIVX_XERR;             //!
  TBranch *b_muon2_ORIVX_YERR;             //!
  TBranch *b_muon2_ORIVX_ZERR;             //!
  TBranch *b_muon2_ORIVX_CHI2;             //!
  TBranch *b_muon2_ORIVX_NDOF;             //!
  TBranch *b_muon2_ORIVX_COV_;             //!
  TBranch *b_muon2_P;                      //!
  TBranch *b_muon2_PT;                     //!
  TBranch *b_muon2_PE;                     //!
  TBranch *b_muon2_PX;                     //!
  TBranch *b_muon2_PY;                     //!
  TBranch *b_muon2_PZ;                     //!
  TBranch *b_muon2_M;                      //!
  TBranch *b_muon2_ID;                     //!
  TBranch *b_muon2_PIDe;                   //!
  TBranch *b_muon2_PIDmu;                  //!
  TBranch *b_muon2_PIDK;                   //!
  TBranch *b_muon2_PIDp;                   //!
  TBranch *b_muon2_PIDd;                   //!
  TBranch *b_muon2_ProbNNe;                //!
  TBranch *b_muon2_ProbNNk;                //!
  TBranch *b_muon2_ProbNNp;                //!
  TBranch *b_muon2_ProbNNpi;               //!
  TBranch *b_muon2_ProbNNmu;               //!
  TBranch *b_muon2_ProbNNd;                //!
  TBranch *b_muon2_ProbNNghost;            //!
  TBranch *b_muon2_hasMuon;                //!
  TBranch *b_muon2_isMuon;                 //!
  TBranch *b_muon2_hasRich;                //!
  TBranch *b_muon2_UsedRichAerogel;        //!
  TBranch *b_muon2_UsedRich1Gas;           //!
  TBranch *b_muon2_UsedRich2Gas;           //!
  TBranch *b_muon2_RichAboveElThres;       //!
  TBranch *b_muon2_RichAboveMuThres;       //!
  TBranch *b_muon2_RichAbovePiThres;       //!
  TBranch *b_muon2_RichAboveKaThres;       //!
  TBranch *b_muon2_RichAbovePrThres;       //!
  TBranch *b_muon2_hasCalo;                //!
  TBranch *b_nCandidate;                   //!
  TBranch *b_totCandidates;                //!
  TBranch *b_EventInSequence;              //!
  TBranch *b_runNumber;                    //!
  TBranch *b_eventNumber;                  //!
  TBranch *b_BCID;                         //!
  TBranch *b_BCType;                       //!
  TBranch *b_OdinTCK;                      //!
  TBranch *b_L0DUTCK;                      //!
  TBranch *b_HLT1TCK;                      //!
  TBranch *b_HLT2TCK;                      //!
  TBranch *b_GpsTime;                      //!
  TBranch *b_Polarity;                     //!

  ZDecayAnalyser(TTree *tree = 0);
  virtual ~ZDecayAnalyser();
  virtual Int_t Cut(Long64_t entry);
  virtual Int_t GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void Init(TTree *tree);
  virtual void Loop();
  virtual Bool_t Notify();
  virtual void Show(Long64_t entry = -1);

  // CUSTOM
  virtual void ProcessFill();
  virtual void Process();
};

#endif

#ifdef ZDecayAnalyser_cxx
ZDecayAnalyser::ZDecayAnalyser(TTree *tree) : fChain(0) {
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f =
        (TFile *)gROOT->GetListOfFiles()->FindObject("../data/2011Up.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("../data/2011Up.root");
    }
    TDirectory *dir = (TDirectory *)f->Get("../data/2011Up.root:/Tuple");
    dir->GetObject("DecayTree", tree);
  }
  Init(tree);
}

ZDecayAnalyser::~ZDecayAnalyser() {
  if (!fChain)
    return;
  delete fChain->GetCurrentFile();
}

Int_t ZDecayAnalyser::GetEntry(Long64_t entry) {
  // Read contents of entry.
  if (!fChain)
    return 0;
  return fChain->GetEntry(entry);
}
Long64_t ZDecayAnalyser::LoadTree(Long64_t entry) {
  // Set the environment to read one entry
  if (!fChain)
    return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0)
    return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void ZDecayAnalyser::Init(TTree *tree) {
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree)
    return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("Z_ENDVERTEX_X", &Z_ENDVERTEX_X, &b_Z_ENDVERTEX_X);
  fChain->SetBranchAddress("Z_ENDVERTEX_Y", &Z_ENDVERTEX_Y, &b_Z_ENDVERTEX_Y);
  fChain->SetBranchAddress("Z_ENDVERTEX_Z", &Z_ENDVERTEX_Z, &b_Z_ENDVERTEX_Z);
  fChain->SetBranchAddress("Z_ENDVERTEX_XERR", &Z_ENDVERTEX_XERR,
                           &b_Z_ENDVERTEX_XERR);
  fChain->SetBranchAddress("Z_ENDVERTEX_YERR", &Z_ENDVERTEX_YERR,
                           &b_Z_ENDVERTEX_YERR);
  fChain->SetBranchAddress("Z_ENDVERTEX_ZERR", &Z_ENDVERTEX_ZERR,
                           &b_Z_ENDVERTEX_ZERR);
  fChain->SetBranchAddress("Z_ENDVERTEX_CHI2", &Z_ENDVERTEX_CHI2,
                           &b_Z_ENDVERTEX_CHI2);
  fChain->SetBranchAddress("Z_ENDVERTEX_NDOF", &Z_ENDVERTEX_NDOF,
                           &b_Z_ENDVERTEX_NDOF);
  fChain->SetBranchAddress("Z_ENDVERTEX_COV_", Z_ENDVERTEX_COV_,
                           &b_Z_ENDVERTEX_COV_);
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
  fChain->SetBranchAddress("Z_IPCHI2_OWNPV", &Z_IPCHI2_OWNPV,
                           &b_Z_IPCHI2_OWNPV);
  fChain->SetBranchAddress("Z_FD_OWNPV", &Z_FD_OWNPV, &b_Z_FD_OWNPV);
  fChain->SetBranchAddress("Z_FDCHI2_OWNPV", &Z_FDCHI2_OWNPV,
                           &b_Z_FDCHI2_OWNPV);
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
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNe",
                           &muon1_MC12TuneV2_ProbNNe,
                           &b_muon1_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNmu",
                           &muon1_MC12TuneV2_ProbNNmu,
                           &b_muon1_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNpi",
                           &muon1_MC12TuneV2_ProbNNpi,
                           &b_muon1_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNk",
                           &muon1_MC12TuneV2_ProbNNk,
                           &b_muon1_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNp",
                           &muon1_MC12TuneV2_ProbNNp,
                           &b_muon1_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("muon1_MC12TuneV2_ProbNNghost",
                           &muon1_MC12TuneV2_ProbNNghost,
                           &b_muon1_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNe",
                           &muon1_MC12TuneV3_ProbNNe,
                           &b_muon1_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNmu",
                           &muon1_MC12TuneV3_ProbNNmu,
                           &b_muon1_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNpi",
                           &muon1_MC12TuneV3_ProbNNpi,
                           &b_muon1_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNk",
                           &muon1_MC12TuneV3_ProbNNk,
                           &b_muon1_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNp",
                           &muon1_MC12TuneV3_ProbNNp,
                           &b_muon1_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("muon1_MC12TuneV3_ProbNNghost",
                           &muon1_MC12TuneV3_ProbNNghost,
                           &b_muon1_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNe",
                           &muon1_MC12TuneV4_ProbNNe,
                           &b_muon1_MC12TuneV4_ProbNNe);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNmu",
                           &muon1_MC12TuneV4_ProbNNmu,
                           &b_muon1_MC12TuneV4_ProbNNmu);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNpi",
                           &muon1_MC12TuneV4_ProbNNpi,
                           &b_muon1_MC12TuneV4_ProbNNpi);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNk",
                           &muon1_MC12TuneV4_ProbNNk,
                           &b_muon1_MC12TuneV4_ProbNNk);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNp",
                           &muon1_MC12TuneV4_ProbNNp,
                           &b_muon1_MC12TuneV4_ProbNNp);
  fChain->SetBranchAddress("muon1_MC12TuneV4_ProbNNghost",
                           &muon1_MC12TuneV4_ProbNNghost,
                           &b_muon1_MC12TuneV4_ProbNNghost);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNe",
                           &muon1_MC15TuneV1_ProbNNe,
                           &b_muon1_MC15TuneV1_ProbNNe);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNmu",
                           &muon1_MC15TuneV1_ProbNNmu,
                           &b_muon1_MC15TuneV1_ProbNNmu);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNpi",
                           &muon1_MC15TuneV1_ProbNNpi,
                           &b_muon1_MC15TuneV1_ProbNNpi);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNk",
                           &muon1_MC15TuneV1_ProbNNk,
                           &b_muon1_MC15TuneV1_ProbNNk);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNp",
                           &muon1_MC15TuneV1_ProbNNp,
                           &b_muon1_MC15TuneV1_ProbNNp);
  fChain->SetBranchAddress("muon1_MC15TuneV1_ProbNNghost",
                           &muon1_MC15TuneV1_ProbNNghost,
                           &b_muon1_MC15TuneV1_ProbNNghost);
  fChain->SetBranchAddress("muon1_OWNPV_X", &muon1_OWNPV_X, &b_muon1_OWNPV_X);
  fChain->SetBranchAddress("muon1_OWNPV_Y", &muon1_OWNPV_Y, &b_muon1_OWNPV_Y);
  fChain->SetBranchAddress("muon1_OWNPV_Z", &muon1_OWNPV_Z, &b_muon1_OWNPV_Z);
  fChain->SetBranchAddress("muon1_OWNPV_XERR", &muon1_OWNPV_XERR,
                           &b_muon1_OWNPV_XERR);
  fChain->SetBranchAddress("muon1_OWNPV_YERR", &muon1_OWNPV_YERR,
                           &b_muon1_OWNPV_YERR);
  fChain->SetBranchAddress("muon1_OWNPV_ZERR", &muon1_OWNPV_ZERR,
                           &b_muon1_OWNPV_ZERR);
  fChain->SetBranchAddress("muon1_OWNPV_CHI2", &muon1_OWNPV_CHI2,
                           &b_muon1_OWNPV_CHI2);
  fChain->SetBranchAddress("muon1_OWNPV_NDOF", &muon1_OWNPV_NDOF,
                           &b_muon1_OWNPV_NDOF);
  fChain->SetBranchAddress("muon1_OWNPV_COV_", muon1_OWNPV_COV_,
                           &b_muon1_OWNPV_COV_);
  fChain->SetBranchAddress("muon1_IP_OWNPV", &muon1_IP_OWNPV,
                           &b_muon1_IP_OWNPV);
  fChain->SetBranchAddress("muon1_IPCHI2_OWNPV", &muon1_IPCHI2_OWNPV,
                           &b_muon1_IPCHI2_OWNPV);
  fChain->SetBranchAddress("muon1_ORIVX_X", &muon1_ORIVX_X, &b_muon1_ORIVX_X);
  fChain->SetBranchAddress("muon1_ORIVX_Y", &muon1_ORIVX_Y, &b_muon1_ORIVX_Y);
  fChain->SetBranchAddress("muon1_ORIVX_Z", &muon1_ORIVX_Z, &b_muon1_ORIVX_Z);
  fChain->SetBranchAddress("muon1_ORIVX_XERR", &muon1_ORIVX_XERR,
                           &b_muon1_ORIVX_XERR);
  fChain->SetBranchAddress("muon1_ORIVX_YERR", &muon1_ORIVX_YERR,
                           &b_muon1_ORIVX_YERR);
  fChain->SetBranchAddress("muon1_ORIVX_ZERR", &muon1_ORIVX_ZERR,
                           &b_muon1_ORIVX_ZERR);
  fChain->SetBranchAddress("muon1_ORIVX_CHI2", &muon1_ORIVX_CHI2,
                           &b_muon1_ORIVX_CHI2);
  fChain->SetBranchAddress("muon1_ORIVX_NDOF", &muon1_ORIVX_NDOF,
                           &b_muon1_ORIVX_NDOF);
  fChain->SetBranchAddress("muon1_ORIVX_COV_", muon1_ORIVX_COV_,
                           &b_muon1_ORIVX_COV_);
  fChain->SetBranchAddress("muon1_P", &muon1_P, &b_muon1_P);
  fChain->SetBranchAddress("muon1_PT", &muon1_PT, &b_muon1_PT);
  fChain->SetBranchAddress("muon1_PE", &muon1_PE, &b_muon1_PE);
  fChain->SetBranchAddress("muon1_PX", &muon1_PX, &b_muon1_PX);
  fChain->SetBranchAddress("muon1_PY", &muon1_PY, &b_muon1_PY);
  fChain->SetBranchAddress("muon1_PZ", &muon1_PZ, &b_muon1_PZ);
  fChain->SetBranchAddress("muon1_M", &muon1_M, &b_muon1_M);
  fChain->SetBranchAddress("muon1_ID", &muon1_ID, &b_muon1_ID);
  fChain->SetBranchAddress("muon1_PIDe", &muon1_PIDe, &b_muon1_PIDe);
  fChain->SetBranchAddress("muon1_PIDmu", &muon1_PIDmu, &b_muon1_PIDmu);
  fChain->SetBranchAddress("muon1_PIDK", &muon1_PIDK, &b_muon1_PIDK);
  fChain->SetBranchAddress("muon1_PIDp", &muon1_PIDp, &b_muon1_PIDp);
  fChain->SetBranchAddress("muon1_PIDd", &muon1_PIDd, &b_muon1_PIDd);
  fChain->SetBranchAddress("muon1_ProbNNe", &muon1_ProbNNe, &b_muon1_ProbNNe);
  fChain->SetBranchAddress("muon1_ProbNNk", &muon1_ProbNNk, &b_muon1_ProbNNk);
  fChain->SetBranchAddress("muon1_ProbNNp", &muon1_ProbNNp, &b_muon1_ProbNNp);
  fChain->SetBranchAddress("muon1_ProbNNpi", &muon1_ProbNNpi,
                           &b_muon1_ProbNNpi);
  fChain->SetBranchAddress("muon1_ProbNNmu", &muon1_ProbNNmu,
                           &b_muon1_ProbNNmu);
  fChain->SetBranchAddress("muon1_ProbNNd", &muon1_ProbNNd, &b_muon1_ProbNNd);
  fChain->SetBranchAddress("muon1_ProbNNghost", &muon1_ProbNNghost,
                           &b_muon1_ProbNNghost);
  fChain->SetBranchAddress("muon1_hasMuon", &muon1_hasMuon, &b_muon1_hasMuon);
  fChain->SetBranchAddress("muon1_isMuon", &muon1_isMuon, &b_muon1_isMuon);
  fChain->SetBranchAddress("muon1_hasRich", &muon1_hasRich, &b_muon1_hasRich);
  fChain->SetBranchAddress("muon1_UsedRichAerogel", &muon1_UsedRichAerogel,
                           &b_muon1_UsedRichAerogel);
  fChain->SetBranchAddress("muon1_UsedRich1Gas", &muon1_UsedRich1Gas,
                           &b_muon1_UsedRich1Gas);
  fChain->SetBranchAddress("muon1_UsedRich2Gas", &muon1_UsedRich2Gas,
                           &b_muon1_UsedRich2Gas);
  fChain->SetBranchAddress("muon1_RichAboveElThres", &muon1_RichAboveElThres,
                           &b_muon1_RichAboveElThres);
  fChain->SetBranchAddress("muon1_RichAboveMuThres", &muon1_RichAboveMuThres,
                           &b_muon1_RichAboveMuThres);
  fChain->SetBranchAddress("muon1_RichAbovePiThres", &muon1_RichAbovePiThres,
                           &b_muon1_RichAbovePiThres);
  fChain->SetBranchAddress("muon1_RichAboveKaThres", &muon1_RichAboveKaThres,
                           &b_muon1_RichAboveKaThres);
  fChain->SetBranchAddress("muon1_RichAbovePrThres", &muon1_RichAbovePrThres,
                           &b_muon1_RichAbovePrThres);
  fChain->SetBranchAddress("muon1_hasCalo", &muon1_hasCalo, &b_muon1_hasCalo);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNe",
                           &muon2_MC12TuneV2_ProbNNe,
                           &b_muon2_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNmu",
                           &muon2_MC12TuneV2_ProbNNmu,
                           &b_muon2_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNpi",
                           &muon2_MC12TuneV2_ProbNNpi,
                           &b_muon2_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNk",
                           &muon2_MC12TuneV2_ProbNNk,
                           &b_muon2_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNp",
                           &muon2_MC12TuneV2_ProbNNp,
                           &b_muon2_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("muon2_MC12TuneV2_ProbNNghost",
                           &muon2_MC12TuneV2_ProbNNghost,
                           &b_muon2_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNe",
                           &muon2_MC12TuneV3_ProbNNe,
                           &b_muon2_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNmu",
                           &muon2_MC12TuneV3_ProbNNmu,
                           &b_muon2_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNpi",
                           &muon2_MC12TuneV3_ProbNNpi,
                           &b_muon2_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNk",
                           &muon2_MC12TuneV3_ProbNNk,
                           &b_muon2_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNp",
                           &muon2_MC12TuneV3_ProbNNp,
                           &b_muon2_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("muon2_MC12TuneV3_ProbNNghost",
                           &muon2_MC12TuneV3_ProbNNghost,
                           &b_muon2_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNe",
                           &muon2_MC12TuneV4_ProbNNe,
                           &b_muon2_MC12TuneV4_ProbNNe);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNmu",
                           &muon2_MC12TuneV4_ProbNNmu,
                           &b_muon2_MC12TuneV4_ProbNNmu);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNpi",
                           &muon2_MC12TuneV4_ProbNNpi,
                           &b_muon2_MC12TuneV4_ProbNNpi);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNk",
                           &muon2_MC12TuneV4_ProbNNk,
                           &b_muon2_MC12TuneV4_ProbNNk);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNp",
                           &muon2_MC12TuneV4_ProbNNp,
                           &b_muon2_MC12TuneV4_ProbNNp);
  fChain->SetBranchAddress("muon2_MC12TuneV4_ProbNNghost",
                           &muon2_MC12TuneV4_ProbNNghost,
                           &b_muon2_MC12TuneV4_ProbNNghost);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNe",
                           &muon2_MC15TuneV1_ProbNNe,
                           &b_muon2_MC15TuneV1_ProbNNe);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNmu",
                           &muon2_MC15TuneV1_ProbNNmu,
                           &b_muon2_MC15TuneV1_ProbNNmu);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNpi",
                           &muon2_MC15TuneV1_ProbNNpi,
                           &b_muon2_MC15TuneV1_ProbNNpi);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNk",
                           &muon2_MC15TuneV1_ProbNNk,
                           &b_muon2_MC15TuneV1_ProbNNk);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNp",
                           &muon2_MC15TuneV1_ProbNNp,
                           &b_muon2_MC15TuneV1_ProbNNp);
  fChain->SetBranchAddress("muon2_MC15TuneV1_ProbNNghost",
                           &muon2_MC15TuneV1_ProbNNghost,
                           &b_muon2_MC15TuneV1_ProbNNghost);
  fChain->SetBranchAddress("muon2_OWNPV_X", &muon2_OWNPV_X, &b_muon2_OWNPV_X);
  fChain->SetBranchAddress("muon2_OWNPV_Y", &muon2_OWNPV_Y, &b_muon2_OWNPV_Y);
  fChain->SetBranchAddress("muon2_OWNPV_Z", &muon2_OWNPV_Z, &b_muon2_OWNPV_Z);
  fChain->SetBranchAddress("muon2_OWNPV_XERR", &muon2_OWNPV_XERR,
                           &b_muon2_OWNPV_XERR);
  fChain->SetBranchAddress("muon2_OWNPV_YERR", &muon2_OWNPV_YERR,
                           &b_muon2_OWNPV_YERR);
  fChain->SetBranchAddress("muon2_OWNPV_ZERR", &muon2_OWNPV_ZERR,
                           &b_muon2_OWNPV_ZERR);
  fChain->SetBranchAddress("muon2_OWNPV_CHI2", &muon2_OWNPV_CHI2,
                           &b_muon2_OWNPV_CHI2);
  fChain->SetBranchAddress("muon2_OWNPV_NDOF", &muon2_OWNPV_NDOF,
                           &b_muon2_OWNPV_NDOF);
  fChain->SetBranchAddress("muon2_OWNPV_COV_", muon2_OWNPV_COV_,
                           &b_muon2_OWNPV_COV_);
  fChain->SetBranchAddress("muon2_IP_OWNPV", &muon2_IP_OWNPV,
                           &b_muon2_IP_OWNPV);
  fChain->SetBranchAddress("muon2_IPCHI2_OWNPV", &muon2_IPCHI2_OWNPV,
                           &b_muon2_IPCHI2_OWNPV);
  fChain->SetBranchAddress("muon2_ORIVX_X", &muon2_ORIVX_X, &b_muon2_ORIVX_X);
  fChain->SetBranchAddress("muon2_ORIVX_Y", &muon2_ORIVX_Y, &b_muon2_ORIVX_Y);
  fChain->SetBranchAddress("muon2_ORIVX_Z", &muon2_ORIVX_Z, &b_muon2_ORIVX_Z);
  fChain->SetBranchAddress("muon2_ORIVX_XERR", &muon2_ORIVX_XERR,
                           &b_muon2_ORIVX_XERR);
  fChain->SetBranchAddress("muon2_ORIVX_YERR", &muon2_ORIVX_YERR,
                           &b_muon2_ORIVX_YERR);
  fChain->SetBranchAddress("muon2_ORIVX_ZERR", &muon2_ORIVX_ZERR,
                           &b_muon2_ORIVX_ZERR);
  fChain->SetBranchAddress("muon2_ORIVX_CHI2", &muon2_ORIVX_CHI2,
                           &b_muon2_ORIVX_CHI2);
  fChain->SetBranchAddress("muon2_ORIVX_NDOF", &muon2_ORIVX_NDOF,
                           &b_muon2_ORIVX_NDOF);
  fChain->SetBranchAddress("muon2_ORIVX_COV_", muon2_ORIVX_COV_,
                           &b_muon2_ORIVX_COV_);
  fChain->SetBranchAddress("muon2_P", &muon2_P, &b_muon2_P);
  fChain->SetBranchAddress("muon2_PT", &muon2_PT, &b_muon2_PT);
  fChain->SetBranchAddress("muon2_PE", &muon2_PE, &b_muon2_PE);
  fChain->SetBranchAddress("muon2_PX", &muon2_PX, &b_muon2_PX);
  fChain->SetBranchAddress("muon2_PY", &muon2_PY, &b_muon2_PY);
  fChain->SetBranchAddress("muon2_PZ", &muon2_PZ, &b_muon2_PZ);
  fChain->SetBranchAddress("muon2_M", &muon2_M, &b_muon2_M);
  fChain->SetBranchAddress("muon2_ID", &muon2_ID, &b_muon2_ID);
  fChain->SetBranchAddress("muon2_PIDe", &muon2_PIDe, &b_muon2_PIDe);
  fChain->SetBranchAddress("muon2_PIDmu", &muon2_PIDmu, &b_muon2_PIDmu);
  fChain->SetBranchAddress("muon2_PIDK", &muon2_PIDK, &b_muon2_PIDK);
  fChain->SetBranchAddress("muon2_PIDp", &muon2_PIDp, &b_muon2_PIDp);
  fChain->SetBranchAddress("muon2_PIDd", &muon2_PIDd, &b_muon2_PIDd);
  fChain->SetBranchAddress("muon2_ProbNNe", &muon2_ProbNNe, &b_muon2_ProbNNe);
  fChain->SetBranchAddress("muon2_ProbNNk", &muon2_ProbNNk, &b_muon2_ProbNNk);
  fChain->SetBranchAddress("muon2_ProbNNp", &muon2_ProbNNp, &b_muon2_ProbNNp);
  fChain->SetBranchAddress("muon2_ProbNNpi", &muon2_ProbNNpi,
                           &b_muon2_ProbNNpi);
  fChain->SetBranchAddress("muon2_ProbNNmu", &muon2_ProbNNmu,
                           &b_muon2_ProbNNmu);
  fChain->SetBranchAddress("muon2_ProbNNd", &muon2_ProbNNd, &b_muon2_ProbNNd);
  fChain->SetBranchAddress("muon2_ProbNNghost", &muon2_ProbNNghost,
                           &b_muon2_ProbNNghost);
  fChain->SetBranchAddress("muon2_hasMuon", &muon2_hasMuon, &b_muon2_hasMuon);
  fChain->SetBranchAddress("muon2_isMuon", &muon2_isMuon, &b_muon2_isMuon);
  fChain->SetBranchAddress("muon2_hasRich", &muon2_hasRich, &b_muon2_hasRich);
  fChain->SetBranchAddress("muon2_UsedRichAerogel", &muon2_UsedRichAerogel,
                           &b_muon2_UsedRichAerogel);
  fChain->SetBranchAddress("muon2_UsedRich1Gas", &muon2_UsedRich1Gas,
                           &b_muon2_UsedRich1Gas);
  fChain->SetBranchAddress("muon2_UsedRich2Gas", &muon2_UsedRich2Gas,
                           &b_muon2_UsedRich2Gas);
  fChain->SetBranchAddress("muon2_RichAboveElThres", &muon2_RichAboveElThres,
                           &b_muon2_RichAboveElThres);
  fChain->SetBranchAddress("muon2_RichAboveMuThres", &muon2_RichAboveMuThres,
                           &b_muon2_RichAboveMuThres);
  fChain->SetBranchAddress("muon2_RichAbovePiThres", &muon2_RichAbovePiThres,
                           &b_muon2_RichAbovePiThres);
  fChain->SetBranchAddress("muon2_RichAboveKaThres", &muon2_RichAboveKaThres,
                           &b_muon2_RichAboveKaThres);
  fChain->SetBranchAddress("muon2_RichAbovePrThres", &muon2_RichAbovePrThres,
                           &b_muon2_RichAbovePrThres);
  fChain->SetBranchAddress("muon2_hasCalo", &muon2_hasCalo, &b_muon2_hasCalo);
  fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
  fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
  fChain->SetBranchAddress("EventInSequence", &EventInSequence,
                           &b_EventInSequence);
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

Bool_t ZDecayAnalyser::Notify() {
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void ZDecayAnalyser::Show(Long64_t entry) {
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain)
    return;
  fChain->Show(entry);
}
Int_t ZDecayAnalyser::Cut(Long64_t entry) {
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}
#endif // #ifdef ZDecayAnalyser_cxx
