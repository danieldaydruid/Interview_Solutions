#include "Test.h"

/********************************************************************************
* Function Name:    main()                                                      *
* Function Purpose: LIDAR Filter Code Sample driver function. Runs various      *
*                   tests of interest for analysis.                             *
* Last-Modified Log: February 19, 2019                                          *
* Notes: Working as Intended - Matthew Killoran                                 *
*                                                                               *
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