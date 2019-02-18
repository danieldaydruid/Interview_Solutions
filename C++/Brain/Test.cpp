#include "test.h"

#define lengthOf(arr) (sizeof(arr)/sizeof(*arr))

static void PrintArray(float *values, size_t N) {
    int i = 0;
    for(size_t i = 0; i < N; ++i) {
        float val = values[i];
        if(i > 0 && i % 20 == 0) std::cout << std::endl;
        std::cout << (i ? ' ' : ' ') << std::setw(5) << std::setprecision(1) << std::fixed << val;
    }
    std::cout << std::endl << "... Finished" << std::endl;;
}

void NullTest() {
    std::cout << "NULL Case: S = 1000, N = 0, D = 3" << std::endl;
    MedianFilter filter(1000, 3);
    filter.Update(NULL);
    PrintArray(NULL, 0);
    return;
}

void BaseTest() {
    float BaseCase[5][5] = {
        {0, 1, 2, 1, 3},
        {1, 5, 7, 1, 3},
        {2, 3, 4, 1, 0},
        {3, 3, 3, 1, 3},
        {10,2, 4, 0, 0},
    };
    MedianFilter filter(5, 3);
    std::cout << "Example Base Case: S = 5, N = 5, D = 3" << std::endl;
    for(size_t i = 0; i < lengthOf(BaseCase); ++i) {
        auto res = filter.Update(BaseCase[i]);
        if(res == NULL) {
            return;
        }
        size_t N = lengthOf(BaseCase[0]);
        PrintArray(res, N);
        delete res;
    }
    return;
}

void RandomTest(size_t S, size_t N, size_t D) {
    std::cout << "Random Fill Test: S = " << S << ", N = " << N << ", D = " << D << std::endl;
    RangeFilter RangeInput(0.03, 50.0);
    MedianFilter MedianInput(N, D);
    for(size_t i = 0; i <= S; i++) {
        float *start_array = new float[N];
        for(size_t j = 0; j < N; j++) {
            float range_value = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ) + static_cast <float> (rand() % (int) 59);
            start_array[j] = range_value;
        }
        float *filtered_range_array = RangeInput.Update(start_array, N);
        float *filtered_temporal_median_array = MedianInput.Update(start_array);
        if(S <=20 && S > 0) {
            //std::cout << "Filtered Range Array:" << std::endl;
            std::cout << "Scan[" << i << "]" << std::endl;
            PrintArray(start_array, N);
            std::cout << "Range Filtered[" << i << "]" << std::endl;
            PrintArray(filtered_range_array, N);
            std::cout << "Median Filtered[" << i << "]" << std::endl;
            PrintArray(filtered_temporal_median_array, N);
            std::cout << std::endl;
            //std::cout << "Filtered Temporal Median Array:" << std::endl;
            //PrintArray(filtered_temporal_median_array, N);
        }
    }
    return;
}