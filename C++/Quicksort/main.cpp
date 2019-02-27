#include <iostream>
#include <algorithm>
#include <time.h>

void Swap(int* a, int* b);
int Partition(int Array[], int Low, int High);
void QuickSort(int Array[], int Low, int High);
void PrintArray(int Array[], int size);

int main() {
    srand(time(NULL));
    size_t size = rand() % 50;
    int Array[size];
    for (size_t i = 0; i < size; i++) Array[i] = rand() % 100;
    int N = sizeof(Array)/sizeof(Array[0]);
    std::cout << "Unsorted Array of size " << N << ":" << std::endl;
    PrintArray(Array, N);
    QuickSort(Array, 0, N - 1);
    std::cout << "Sorted Array of size " << N << ":" << std::endl;
    PrintArray(Array, N);
    return 0;
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int Array[], int Low, int High) {
    int pivot = Array[High];
    int i = Low - 1;
    for (int j = Low; j <= High - 1; j++) {
        if(Array[j] <= pivot) {
            i++;
            Swap(&Array[i], &Array[j]);
        }
    }
    Swap(&Array[i + 1], &Array[High]);
    return (i + 1);
}

void QuickSort(int Array[], int Low, int High) {
    if (Low < High) {
        int Pi = Partition(Array, Low, High);
        QuickSort(Array, Low, Pi - 1);
        QuickSort(Array, Pi + 1, High);
    }
}

void PrintArray(int Array[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) std::cout << Array[i] << " ";
    std::cout << "]" << std::endl;
}