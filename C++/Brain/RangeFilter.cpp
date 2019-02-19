#include "RangeFilter.h"

float* RangeFilter::Update(float *Scan) {
    if(Scan == NULL || N == 0) {
        return NULL;
    }    
    float *CopyArray = new float[N];
    if(CopyArray == NULL) {
        return NULL;
    }
    for(size_t i = 0; i < N; i++) {
        if(Scan[i] < MinimumRange) {
            CopyArray[i] = MinimumRange;
        }
        else if(Scan[i] > MaximumRange) {
            CopyArray[i] = MaximumRange;
        }
        else {
            CopyArray[i] = Scan[i];
        }
    }
    return CopyArray;
}