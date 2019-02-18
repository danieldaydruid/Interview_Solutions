#include "Test.h"

#define LENGTHOF(arr) (sizeof(arr)/sizeof(*arr))


static void PrintArray(float *values, size_t N) {
    for(size_t i = 0; i < N; ++i) {
        std::cout << std::setw(5) << std::setprecision(1) <<std::fixed << values[i];
    }
    std::cout << std::endl;
    return;
}

void BaseTest() {
    float BaseCase[5][5] = {
        {0., 1., 2., 1., 3.},
        {1., 5., 7., 1., 3.},
        {2., 3., 4., 1., 0.},
        {3., 3., 3., 1., 3.},
        {10.,2., 4., 0., 0.},
    };
    MedianFilter filter(5, 3);
    std::cout << "Example Base Case: S = 5, N = 5, D = 3" << std::endl;
    for(size_t i = 0; i < LENGTHOF(BaseCase); ++i) {
        auto res = filter.Update(BaseCase[i]);
        if(res == NULL) {
            return;
        }
        size_t N = LENGTHOF(BaseCase[0]);
        PrintArray(res, N);
        delete res;
    }
    std::cout << "... Complete" << std::endl << std::endl;
    return;
}

void NullTest() {
    std::cout << "NULL Case: S = 1000, N = 0, D = 3" << std::endl;
    MedianFilter Filter(1000, 3);
    Filter.Update(NULL);
    PrintArray(NULL, 0);
    return;
}

void RandomTest(size_t S, size_t N, size_t D) {
    std::cout << "Random Fill Test: S = " << S << ", N = " << N << ", D = " << D << std::endl;
    RangeFilter r_Filter(0.03, 50.0);
    MedianFilter m_Filter(N, D);
    for(size_t i = 0; i <= S; i++) {
        float *start_array = new float[N];
        for(size_t j = 0; j < N; j++) {
            float range_value = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ) + static_cast <float> (rand() % (int) 59);
            start_array[j] = range_value;
        }
        float *filtered_range_array = r_Filter.Update(start_array, N);
        float *filtered_temporal_median_array = m_Filter.Update(start_array);
        if(S <=20 && S > 0) {
            std::cout << "Scan[" << i << "]" << std::endl;
            PrintArray(start_array, N);
            std::cout << "Range Filtered[" << i << "]" << std::endl;
            PrintArray(filtered_range_array, N);
            std::cout << "Median Filtered[" << i << "]" << std::endl;
            PrintArray(filtered_temporal_median_array, N);
            std::cout << std::endl;
        }
    }
    std::cout << "... Complete" << std::endl << std::endl;
    return;
}
