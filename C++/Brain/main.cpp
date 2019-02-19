#include "Test.h"

int main() {
    //Initialize time for rand() calls
    srand(time(NULL));
    Test Generate;
    Generate.Preface();
    Generate.TestInitialize("Large Scan Value Case");
    Generate.TestInitialize("Random Scan Case");
    Generate.TestInitialize("NULL Scan Case");
    Generate.TestInitialize("Base Scan Case");
    Generate.TestInitialize("20 Scans 20 Elements Random D");
    return 0;
}