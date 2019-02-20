#include "RangeFilter.h"

/********************************************************************************
* Class Name:       RangeFilter                                                 *
* Function Name:    Update()                                                    *
* Function Purpose: Range Filter method to filter LIDAR scan minimum (0.03) and *
*                   maximum (50.0) values, and returns a filtered scan array    *
*                   with values falling above or below the thresholds replaced  *
*                   with said thresholds.                                       *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
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