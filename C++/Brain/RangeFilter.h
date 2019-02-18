#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <time.h>

class RangeFilter {
    float m_minRange;
    float m_maxRange;
public:
    RangeFilter(float min_range, float max_range)
        : m_minRange (min_range)
        , m_maxRange (max_range)
    {}
    float* Update(float *start_array, size_t N);
};