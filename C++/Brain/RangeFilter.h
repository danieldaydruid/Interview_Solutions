#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/********************************************************************************
* Class Name:       RangeFilter                                                 *
* Function Purpose: Contains all Range Filter methods to filter LIDAR scans.    *
*                   All values filtered based on a minimum and a maximum        *
*                   threshold. In this case the program will use the prompt-    *
*                   assigned values, 0.03(minimum) and 50.0 (maximum).          *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
class RangeFilter {
    float MinimumRange; //Minimum, maximum filter range and number of scan elements set on object initialization
    float MaximumRange;
    size_t N;    
public:
    RangeFilter(float Min, float Max, size_t NumElements) //Overloaded constructor
        : MinimumRange(Min)
        , MaximumRange(Max)
        , N(NumElements)
    {}
    float* Update(float *Scan);
    ~RangeFilter(){}
};