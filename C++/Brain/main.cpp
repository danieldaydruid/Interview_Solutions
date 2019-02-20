#include "Test.h"

/********************************************************************************
* Function Name:    main()                                                      *
* Function Purpose: LIDAR Filter Code Sample driver function. Runs various      *
*                   tests of interest for analysis.                             *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
* Build Instructions: Explained in the README, however an up to date version of *
*                     g++ is required. A makefile is provided and the command   *
*                     sequence to compile and run is: make && ./LidarFilter     *
********************************************************************************/
int main() {
    srand(time(NULL)); //Initialize time for rand() calls
    Test Generate; //Initialize Test object
    Generate.Preface(); //Prints test preface to terminal
    Generate.TestInitialize("Large Scan Value Case"); //Begin test calls
    Generate.TestInitialize("Random Scan Case");
    Generate.TestInitialize("NULL Scan Case");
    Generate.TestInitialize("Base Scan Case");
    Generate.TestInitialize("20 Scans 20 Elements Random D"); //End test calls
    return 0;
}