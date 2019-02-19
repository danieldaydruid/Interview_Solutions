#include "MedianFilter.h"

float* MedianFilter::Update(float *Scan) {
    size_t S = HistoryVector.size() + 1;
    float *FilteredArray = new float[N];
    float *TemporaryArray = new float[D + 1]; // Room for D history scans and the current value
    if(Scan == NULL) {
        std::cout << "Passed array was empty." << std::endl;
        return NULL;
    }
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < S - 1; j++) {
            TemporaryArray[j] = HistoryVector[j][i];
        }
        TemporaryArray[S - 1] = Scan[i];
        // Sort values to get meidan
        std::sort(TemporaryArray, TemporaryArray + S); //Sorts by ascending order by default, which  is ideal for this case
        if(S % 2 == 0) {
            FilteredArray[i] = ((TemporaryArray[(S/2) - 1] + TemporaryArray[S/2]) * 0.5);
        }
        else {
            FilteredArray[i] = TemporaryArray[S/2];
        }
    }
    delete TemporaryArray;  
    // Add into History
    float* CopyArray = new float[N];
    memcpy(CopyArray, Scan, sizeof(float) * N);
    HistoryVector.push_back(CopyArray);
    if(HistoryVector.size() > D) {
        CopyArray = *HistoryVector.begin();
        HistoryVector.erase(HistoryVector.begin());
        delete CopyArray;
    }
    return FilteredArray;
}