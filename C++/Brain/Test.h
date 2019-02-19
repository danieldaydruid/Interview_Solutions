#pragma once
#include "MedianFilter.h"

#define LENGTHOF(arr) (sizeof(arr)/sizeof(*arr))
class Test {
    public:
        void Preface();
        void TestInitialize(std::string TestName);
        static void RunTest(size_t S, size_t N, size_t D, std::string TestName);
        static void PrintArray(float *values, size_t N, std::string ArrayName, size_t ScanNumber);
};