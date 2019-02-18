#include "Test.h"

int main() {
    srand(time(NULL));
    //Run slate of tests:
    RandomTest(0, 0, 0);
    RandomTest(100, 200, 3);
    RandomTest(100, 1000, 3);
    RandomTest(200, 100, 3);
    RandomTest(1000, 1000, 10);
    RandomTest(rand() % 1000, rand() % 1000, rand() % 50);
    BaseTest();
    NullTest();
    RandomTest(5, 5, 3);
    RandomTest(10, 20, 3);

    return 0;
}