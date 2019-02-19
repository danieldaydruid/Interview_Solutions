#include "Test.h"
/********************************************************************************
* Class Name: Test                                                              *
* Function Name: Preface()                                                      *
* Function Purpose: Prints a brief preface/introduction of the software to      *
*                   terminal.                                                   *
* Last-Modified Log: February 18, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::Preface() {
    std::cout << "Matthew Killoran - Brain Corp Code Sample\nFebruary 19, 2019\nLIDAR Filters\nThis program provides several filter applications for LIDAR application\nincluding range and temporal median filters.\n\n";
}
/********************************************************************************
* Class Name: Test                                                              *
* Function Name: TestInitialize()                                               *
* Function Purpose: Initializes the test runs based on the name of the test     *
*                   that is needed.                                             *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::TestInitialize(std::string TestName) {
    if(TestName == "Base Scan Case") {
        size_t S = 5, N = 5, D = 3;
        float Scan[S][N] = {
            {0., 1., 2., 1., 3.},
            {1., 5., 7., 1., 3.},
            {2., 3., 4., 1., 0.},
            {3., 3., 3., 1., 3.},
            {10.,2., 4., 0., 0.},
        };
        MedianFilter Median(N, 3);
        RangeFilter Range(0.03, 50.0, N);
        std::cout << TestName << ": S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        for(size_t i = 0; i < N; ++i) {
            auto FilteredRangeArray = Range.Update(Scan[i]);
            auto FilteredMedianArray = Median.Update(Scan[i]);
            if(FilteredMedianArray == NULL) {
                return;
            }
            PrintArray(Scan[i], N, "LIDAR Scan", i);
            PrintArray(FilteredRangeArray, N, "Range Filter", i);
            PrintArray(FilteredMedianArray, N, "Median Filter", i);
            std::cout << std::endl;
            delete FilteredRangeArray;
            delete FilteredMedianArray;
        }
        std::cout << "... Complete" << std::endl << std::endl;
        return;
    }
    else if(TestName == "NULL Scan Case") {
        size_t S = rand() % 1000, N = rand() % 1000, D = rand() % 47 + 3;
        std::cout << "NULL Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        MedianFilter Median(N, D);
        Median.Update(NULL);
        PrintArray(NULL, 0, "NULL Case", 0);
        std::cout << "... Complete" << std::endl << std::endl;
        return;
    }
    else if(TestName == "Large Scan Value Case") {
        size_t S = rand() % 1000, N = rand() % 1000, D = rand() % 47 + 3;
        std::cout << "Large Scan Value Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        RunTest(S, N, D, TestName);
        std::cout << "... Complete" << std::endl << std::endl;
        return;
    }
    else if(TestName == "Random Scan Case") {
        size_t S = rand() % 1000, N = rand() % 1000, D = rand() % 47 + 3;
        std::cout << "Random Scan Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        RunTest(S, N, D, TestName);
        std::cout << "... Complete" << std::endl << std::endl;
        return;
    }
    else if(TestName == "20 Scans 20 Elements Random D") {
        size_t S = 20, N = 20, D = rand() % 17 + 3;
        std::cout << "Random Scan Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        RunTest(S, N, D, TestName);
        std::cout << "... Complete" << std::endl << std::endl;
        return;
    }
}
/********************************************************************************
* Class Name: Test                                                              *
* Function Name: RunTest()                                                      *
* Function Purpose: Takes in the prescribed test version, generates the         *
*                   appropriate arrays and the values which fill them and       *
*                   calls the LIDAR filter functions to filter the arrays.      *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::RunTest(size_t S, size_t N, size_t D, std::string TestName) {
    float ElementValue = 0;
    float* Scan = new float[N];
    RangeFilter Range(0.03, 50.0, N);
    MedianFilter Median(N, D);
    for(size_t i = 0; i < S; i++) {
        for(size_t j = 0; j < N; j++) {
            if(TestName == "Large Scan Value Case") ElementValue = pow(-1, j) * 1e+38;
            else ElementValue = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ) + static_cast <float> (rand() % (int) 59 - 5); //Between -5.0 and 60.0
            Scan[j] = ElementValue;
        }
        float* FilteredRangeArray = Range.Update(Scan);
        float* FilteredMedianArray = Median.Update(Scan);
        if(N <= 20 && S <= 20 && N > 0 && S > 0) {
            PrintArray(Scan, N, "LIDAR Scan", i);
            PrintArray(FilteredRangeArray, N, "Range Filter", i);
            PrintArray(FilteredMedianArray, N, "Median Filter", i);
            std::cout << std::endl;
        }
        delete FilteredRangeArray;
        delete FilteredMedianArray;
    }
}
/********************************************************************************
* Class Name: Test                                                              *
* Function Name: PrintArrayRemake()                                             *
* Function Purpose: Prints the contents of the arrays passed to it              *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::PrintArray(float *Scan, size_t N, std::string ArrayName, size_t ScanNumber) {
    std::cout << ArrayName << "[" << ScanNumber << "]" << std::endl;
    for(size_t i = 0; i < N; ++i) {
        std::cout << std::setw(8) << std::setprecision(2) <<std::fixed << Scan[i];
    }
    std::cout << std::endl;
    return;
}