#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

class RangeFilter {
    float MinimumRange;
    float MaximumRange;
    size_t N;    
public:
    RangeFilter(float Min, float Max, size_t NumElements)
        : MinimumRange(Min)
        , MaximumRange(Max)
        , N(NumElements)
    {}
    float* Update(float *Scan);
};