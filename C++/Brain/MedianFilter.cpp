#include "MedianFilter.h"

/********************************************************************************
* Class Name:       MedianFilter                                                *
* Function Name:    Update()                                                    *
* Function Purpose: Filters the LIDAR scans Temporal Median values. Computes    *
*                   the median value wtih a minimum of 3 history arrays at a    *
*                   time, though during testing this value is random and can    *
*                   range up to 50. The software can handle D values much       *
*                   higher than 50, though an increasing D value increases      *
*                   execution time substantially, and so was kept lower for     *
*                   demonstration purposes.                                     *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
********************************************************************************/
float* MedianFilter::Update(float *Scan) {
    size_t S = HistoryVector.size() + 1; //Sets total number of LIDAR scans to S
    float *FilteredArray = new float[N]; //Allocates memory for float array of size N
    float *CheckArray = new float[D + 1]; // Allocates memory for D history scans and the current value
    if(Scan == NULL) { //Checks for a NULL LIDAR scan, returns NULL and a message if true
        std::cout << "Passed array was empty." << std::endl;
        return NULL;
    }
    for(size_t i = 0; i < N; i++) { //Loop to populate CheckArray with History Vector values for median computation
        for(size_t j = 0; j < S - 1; j++) {
            CheckArray[j] = HistoryVector[j][i];
        }
        CheckArray[S - 1] = Scan[i]; //Sets last CheckArray value as the most recent LIDAR scan for median computation
        std::sort(CheckArray, CheckArray + S); //Sorts history/scan values in ascending order
        if(S % 2 == 0) { //Computes median for even number of elements
            FilteredArray[i] = ((CheckArray[(S/2) - 1] + CheckArray[S/2]) * 0.5);
        }
        else { //Computes median for odd number of elements
            FilteredArray[i] = CheckArray[S/2];
        }
    }
    delete[] CheckArray; //Deletes the temporary CheckArray, frees memory
    float* CopyArray = new float[N]; //Allocates memory for a new float vector of size N
    memcpy(CopyArray, Scan, sizeof(float) * N);  // Add most recent LIDAR scan into CopyArray for HistoryVector inclusion
    HistoryVector.push_back(CopyArray); //Adds most recent LIDAR scan to the HistoryVector
    if(HistoryVector.size() > D) { //Checks that the size of the HistoryVector has exceeded D, or, current history lookback limit...
        CopyArray = *HistoryVector.begin(); //Stores the oldest HistoryVector element in CopyArray
        HistoryVector.erase(HistoryVector.begin()); //Deletes the oldest HistoryVector element
        delete[] CopyArray; //Deletes the temporary CopyArray, frees memory
    }
    return FilteredArray; //Return the median filtered array
}