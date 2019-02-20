#pragma once

#include "RangeFilter.h"

/********************************************************************************
* Class Name:    MedianFilter                                                   *
* Class Purpose: Contains all Temporal Median filter methods for LIDAR median   *
*                filtering. D is 3 in the prompt, and so the minimum D value in *
*                the tests is 3, though it can be much higher depending on the  *
*                random value determined at compile-time. N and S (Total Scans) *
*                are also random, though these can range from 0 to 1000.        *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
class MedianFilter {
    const size_t N, D;
    std::vector<float*> HistoryVector;
public:
    MedianFilter(size_t N, size_t D) //Overloaded constructor
        : N (N)
        , D (D)
        , HistoryVector()
    {}
    ~MedianFilter() { //Destructor
        for(auto ptr : HistoryVector) {
            delete ptr;
        }
    }
    float* Update(float *Scan);
};