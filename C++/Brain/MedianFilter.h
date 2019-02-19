#pragma once
#include "RangeFilter.h"

class MedianFilter {
    const size_t N, D;
    std::vector<float*> HistoryVector;
public:
    MedianFilter(size_t N, size_t D)
        : N (N)
        , D (D)
        , HistoryVector()
    {}
    ~MedianFilter() {
        for(auto ptr : HistoryVector) {
            delete ptr;
        }
    }

    float* Update(float *Scan);
};