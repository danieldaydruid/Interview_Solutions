#pragma once

#include "MedianFilter.h"

#define MINIMUM_RANGE          0.03f
#define MAXIMUM_RANGE          50.0f
#define MAX_S_AND_N            1000
#define MINIMUM_D              3
#define LENGTHOF               (arr) (sizeof(arr)/sizeof(*arr))
/********************************************************************************
* Class Name:    Test                                                           *
* Class Purpose: Contains all Test methods for software validation. Handles     *
*                multiple tests, including a randomized number of scans between *
*                0 and 1000, a randomized number of scan elements between 0 and *
*                1000, a randomized D (history array) value for Temporal Median *
*                filter purposes, between 3 and 50. Also tests with the prompt  *
*                base case scan, a scan filled with maximum and minimum         *
*                allowable float values (+/-1e38).                              *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
class Test {
    public:
        Test(){}
        void Preface();
        void TestInitialize(std::string TestName);
        static void RunTest(size_t S, size_t N, size_t D, std::string TestName);
        static void PrintArray(float *values, size_t N, std::string ArrayName, size_t ScanNumber);
        ~Test(){}
};