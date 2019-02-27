#include <iostream>
#include <algorithm>
#include <time.h>

/* How do you find the missing number in a given integer array of 1 to 100 */

int FindMissingInteger(int* Array, size_t N);

int main() {
    srand(time(NULL));
    size_t N = 100;
    int Array[100];
    for (int i = 0; i < N; i++) {
        Array[i] = i + 1;
    }
    Array[rand() % 100] = rand() % 100;
    std::cout << FindMissingInteger(Array, N) << std::endl;
    return 0;
}

int FindMissingInteger(int* Array, size_t N) {
    std::cout << "[ ";
    for (size_t i = 0; i < N; i++) {
        std::cout << Array[i] << " ";
        if (Array[i] + 1 != Array[i+1]) {
            std::cout << Array[i + 1] << " ]" << std::endl;
            return Array[i] + 1;
        }
        else continue;
    }
    return -1;
}