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
    if(Scan == NULL || N == 0) { //Checks for a NULL LIDAR Scan array, returns NULL if true
        return NULL;
    }    
    float *FilteredArray = new float[N]; //Allocates a float array of the requisite size to accept LIDAR scan elements
    if(FilteredArray == NULL) { //Checks whether a NULL array was created, and returns NULL if true
        return NULL;
    }
    for(size_t i = 0; i < N; i++) { //Loop through the LIDAR Scan array checking for minimum and maximum range measurement violations
        if(Scan[i] < MinimumRange) {
            FilteredArray[i] = MinimumRange; //Replaces minimum range violations if found
        }
        else if(Scan[i] > MaximumRange) {
            FilteredArray[i] = MaximumRange; //Replaces maximum range violations if found
        }
        else {
            FilteredArray[i] = Scan[i]; //If no range violations are detected, the value is accepted into the FilteredArray
        }
    }
    return FilteredArray;
}