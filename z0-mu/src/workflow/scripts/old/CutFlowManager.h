#ifndef INC_0REAL_CUTFLOWMANAGER_H
#define INC_0REAL_CUTFLOWMANAGER_H

#include <TH1F.h>


class CutFlowManager {
    const static int AMOUNT_OF_CRITERIA = 10;
    const static char* criteriaLabels[AMOUNT_OF_CRITERIA] = {
            "All",
            "is muon pair",
            "PT",
            "Z_MMERR",
            "Prob muon 90",
            "Prob muon 50",
            "Prob muon one 90",
            "Prob pion <10",
            "Prob electron <10",
            "Prob proton <10",
    };
public :
    TH1F* histogram = new TH1F("CutFlow", "Cut Flow", CutFlowManager::AMOUNT_OF_CRITERIA, 0.5, 20.5);


    virtual void CreateHistograms();
    virtual void Draw();
};

void CutFlowManager::Draw()
{
    // Set labels for each bin
    for (int i = 1; i <= AMOUNT_OF_CRITERIA; ++i) {
        cutFlowHistogram->GetXaxis()->SetBinLabel(i, criteriaLabels[i - 1]);
    }
}


#endif //INC_0REAL_CUTFLOWMANAGER_H
