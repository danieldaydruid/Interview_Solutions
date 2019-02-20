#include "Test.h"

/********************************************************************************
* Class Name:       Test                                                        *
* Function Name:    Preface()                                                   *
* Function Purpose: Prints a brief preface/introduction of the software to      *
*                   terminal.                                                   *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::Preface() {
    std::cout << "Matthew Killoran - Brain Corp Code Sample\nFebruary 19, 2019\nLIDAR Filters\nThis program provides several filter applications for LIDAR sensor application\nincluding range and temporal median filters.\n\n";
}
/********************************************************************************
* Class Name:       Test                                                        *
* Function Name:    TestInitialize()                                            *
* Function Purpose: Initializes the test runs based on the name of the test     *
*                   being requested.                                            *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::TestInitialize(std::string TestName) {
    if(TestName == "Base Scan Case") { //Checks that current test name matches the function call argument
        size_t S = 5, N = 5, D = MINIMUM_D;
        float Scan[5][5] = { //Recreates LIDAR scan array from prompt
            {0., 1., 2., 1., 3.},
            {1., 5., 7., 1., 3.},
            {2., 3., 4., 1., 0.},
            {3., 3., 3., 1., 3.},
            {10.,2., 4., 0., 0.},
        };
        MedianFilter Median(N, MINIMUM_D);
        RangeFilter Range(MINIMUM_RANGE, MAXIMUM_RANGE, N);
        std::cout << TestName << ": S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        for(size_t i = 0; i < N; ++i) { //Loop for LIDAR scan filtering, assigns filtered arrays to local, temporary arrays
            auto FilteredRangeArray = Range.Update(Scan[i]);
            auto FilteredMedianArray = Median.Update(Scan[i]);
            if(FilteredMedianArray == NULL || FilteredRangeArray == NULL) { //Checks for a NULL filtered array
                return;
            }
            PrintArray(Scan[i], N, "LIDAR Scan", i); //Prints the LIDAR scan and the filtered scans
            PrintArray(FilteredRangeArray, N, "Range Filter", i);
            PrintArray(FilteredMedianArray, N, "Median Filter", i);
            std::cout << std::endl;
            delete[] FilteredRangeArray; //Deletes the temporary filtered arrays, frees memory
            delete[] FilteredMedianArray;
        }
        std::cout << "... Success" << std::endl << std::endl; //Message to indicate the test completed successfully
        return;
    }
    else if(TestName == "NULL Scan Case") { //Checks that current test name matches the function call argument
        size_t S = rand() % MAX_S_AND_N, N = rand() % MAX_S_AND_N, D = rand() % 47 + MINIMUM_D; //Randomly sets LIDAR scan count, scan elements and D history arrays
        std::cout << "NULL Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        float* Scan = new float[N];
        Scan = NULL;
        MedianFilter Median(N, D);
        RangeFilter Range(MINIMUM_RANGE, MAXIMUM_RANGE, N);
        auto FilteredMedianArray = Median.Update(NULL); //Passes NULL in place of float arrays for testings
        auto FilteredRangeArray = Range.Update(NULL);
        PrintArray(Scan, 0, "TestName", 0); //Prints results of NULL case test
        PrintArray(FilteredRangeArray, 0, "Range Filter", 0);
        PrintArray(FilteredMedianArray, 0, "Median Filter", 0);
        std::cout << "... Success" << std::endl << std::endl;
        return;
    }
    else if(TestName == "Large Scan Value Case") { //Checks that current test name matches the function call argument
        size_t S = rand() % MAX_S_AND_N, N = rand() % MAX_S_AND_N, D = rand() % 47 + MINIMUM_D;  //Randomly sets LIDAR scan count, scan elements and D history arrays
        std::cout << "Large Scan Value Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        try { //Error handling for memory allocation failures during test runs
            RunTest(S, N, D, TestName);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Allocation failure: " << e.what() << std::endl;
        }
        std::cout << "... Success" << std::endl << std::endl;
        return;
    }
    else if(TestName == "Random Scan Case") { //Checks that current test name matches the function call argument
        size_t S = rand() % MAX_S_AND_N, N = rand() % MAX_S_AND_N, D = rand() % 47 + MINIMUM_D;  //Randomly sets LIDAR scan count, scan elements and D history arrays
        std::cout << "Random Scan Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        try { //Error handling for memory allocation failures during test runs
            RunTest(S, N, D, TestName);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Allocation failure: " << e.what() << std::endl;
        }
        std::cout << "... Success" << std::endl << std::endl;
        return;
    }
    else if(TestName == "20 Scans 20 Elements Random D") { //Checks that current test name matches the function call argument
        size_t S = 20, N = 20, D = rand() % 17 + MINIMUM_D; //Sets LIDAR scan count to 20, scan elements to 20 and D history to between 3 and 20, for display and analysis
        std::cout << "Random Scan Case: S = " << S << ", N = " << N << ", D =  " << D <<  std::endl;
        try { //Error handling for memory allocation failures during test runs
            RunTest(S, N, D, TestName);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Allocation failure: " << e.what() << std::endl;
        }
        std::cout << "... Success" << std::endl << std::endl;
        return;
    }
}
/********************************************************************************
* Class Name:       Test                                                        *
* Function Name:    RunTest()                                                   *
* Function Purpose: Takes in the prescribed test version, generates the         *
*                   appropriate arrays and the values which fill them and       *
*                   calls the LIDAR filter functions to filter the arrays.      *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::RunTest(size_t S, size_t N, size_t D, std::string TestName) {
    float ElementValue = 0; //Initializes ElementValue for LIDAR scans
    float* Scan = new float[N];
    RangeFilter Range(MINIMUM_RANGE, MAXIMUM_RANGE, N);
    MedianFilter Median(N, D);
    for(size_t i = 0; i < S; i++) { //Loop to populate the newly created LIDAR scan array
        for(size_t j = 0; j < N; j++) {
            if(TestName == "Large Scan Value Case") ElementValue = pow(-1, j) * 1e+38f; //Sets LIDAR scans to either -1e+38 or +1e38
            else ElementValue = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ) + static_cast <float> (rand() % (int) 59 - 5); //LIDAR scan values between -5.0 and 60.0
            Scan[j] = ElementValue; //Sets the correct LIDAR scan element to the newly generated, random ElemenetValue
        }
        float* FilteredRangeArray = Range.Update(Scan); //Initialize temporary filtered arrays
        float* FilteredMedianArray = Median.Update(Scan);
        if(N <= 20 && S <= 20 && N > 0 && S > 0) { //Print the results to the terminal only if they are between 20 or 1 LIDAR scans and elements to reduce terminal clutter
            PrintArray(Scan, N, "LIDAR Scan", i);
            PrintArray(FilteredRangeArray, N, "Range Filter", i);
            PrintArray(FilteredMedianArray, N, "Median Filter", i);
            std::cout << std::endl;
        }
        delete[] FilteredRangeArray; //Delete the temporary filtered arrays, frees memory
        delete[] FilteredMedianArray;
    }
}
/********************************************************************************
* Class Name:       Test                                                        *
* Function Name:    PrintArrayRemake()                                          *
* Function Purpose: Prints the contents of the arrays passed to it.             *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
void Test::PrintArray(float *Scan, size_t N, std::string ArrayName, size_t ScanNumber) {
    std::cout << ArrayName << "[" << ScanNumber << "]" << std::endl;
    for(size_t i = 0; i < N; ++i) { //Loop to output passed array contents to the terminal
        std::cout << std::setw(8) << std::setprecision(2) <<std::fixed << Scan[i];
    }
    std::cout << std::endl;
    return;
}