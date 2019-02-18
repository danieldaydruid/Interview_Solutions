#pragma once
#include "RangeFilter.h"

class MedianFilter {
    const size_t N, D;
    std::vector<float*> m_history;
public:
    MedianFilter(size_t N, size_t D)
        : N (N)
        , D (D)
        , m_history()
    {}
    ~MedianFilter() {
        for(auto ptr : m_history) {
            delete ptr;
        }
    }

    float* Update(float *start_array);
};