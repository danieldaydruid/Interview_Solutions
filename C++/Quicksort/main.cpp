#include <iostream>

void Swap(int* a, int* b);
int Partition(int Array[], int Low, int High);
void QuickSort(int Array[], int Low, int High);
void PrintArray(int Array[], int size);

int main() {
    int Array[] = {10, 7, 8, 9, 1, 5};
    int N = sizeof(Array)/sizeof(Array[0]);
    QuickSort(Array, 0, N - 1);
    std::cout << "Sorted Array: n";
    PrintArray(Array, N);
    return 0;
}

