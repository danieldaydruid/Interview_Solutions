#include <iostream>

void Swap(int* a, int* b);
int Partition(int Array[], int Low, int High);
void QuickSort(int Array[], int Low, int High);
void PrintArray(int Array[], int size);

int main() {
    int Array[] = {10, 7, 8, 9, 1, 5};
    int N = sizeof(Array)/sizeof(Array[0]);
    QuickSort(Array, 0, N - 1);
    std::cout << "Sorted Array: n" << std::endl;
    PrintArray(Array, N);
    return 0;
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
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
    return;
}

void PrintArray(int Array[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) std::cout << Array[i] << " ";
    std::cout << "]" << std::endl << "N" << std::endl;
    return;
}