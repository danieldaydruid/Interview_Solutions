#include <iostream>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
#define lengthOf(arr) (sizeof(arr)/sizeof(*arr))

static void print(float *values, size_t N);
float clamp(float val, float min, float max) {
    return val < min ? min : (val > max ? max : val);
}

template<size_t N>
class RangeFilter {
    float range_min, range_max;
public:
    RangeFilter(float min, float max)
        : range_min (min)
        , range_max (max)
    { }
    std::unique_ptr<float[]> Update(const float (&values)[N])
    {
        std::unique_ptr<float[]> res(new float[N]);
        for(size_t i = 0; i < N; ++i) {
            res[i] = clamp(values[i], range_min, range_max);
        }
        return res;
    }
};


template<size_t N, size_t D>
class MedianFilter {
    float  hist[D][N];
    size_t histIdx;
    size_t histSize;
public:
    MedianFilter()
        : histIdx(0)
        , histSize(0)
    {
        memset(hist, 0, sizeof(hist));
    }
    std::unique_ptr<float[]> Update(const float (&input)[N])
    {
        float past[D + 1], median = 0;
        auto d = histSize + 1;
        std::unique_ptr<float[]> res(new float[N]);
        
        
        for(size_t i = 0; i < N; ++i) {
            for(size_t j = 0; j < histSize; ++j) {
                past[j] = hist[j][i];
            }
            past[histSize] = input[i];
            //print(past, d);
            
            // Sort values to get median
            std::sort(std::begin(past), std::begin(past) + (d));
            if(d % 2) { // Odd - use middle value
                median = past[d / 2];
            } else { // Even - average middle value
                median = (past[d / 2] + past[d / 2 - 1]) / 2.f;
            }
            
            // Set output value
            res[i] = median;
        }
        
        // Save input
        memcpy(hist[histIdx], input, sizeof(float) * N);
        histIdx = (histIdx + 1) % D;
        if(histSize < D) histSize++;
        
        return res;
    }
};

static float randf(float min, float max) {
    return min + (max - min) * (rand() / (float)RAND_MAX);
}
static void print(float *values, size_t N)
{
    int i = 0;
    for(size_t i = 0; i < N; ++i) {
        float val = values[i];
        if(i > 0 && i % 10 == 0) cout << endl;
        cout << (i ? ' ' : '>') << std::setw(5) << std::setprecision(1) << std::fixed << val;
    }
    cout << endl;
}

bool test1() {
    float inputs[5][5] = {
        {0, 1, 2, 1, 3},
        {1, 5, 7, 1, 3},
        {2, 3, 4, 1, 0},
        {3, 3, 3, 1, 3},
        {10,2, 4, 0, 0},
    };
    float results[5][5] = {
        {0, 1, 2, 1, 3},
        {0.5, 3, 4.5, 1, 3},
        {1, 3, 4, 1, 3},
        {1.5, 3, 3.5, 1, 3},
        {2.5, 3, 4, 1, 1.5},
    };
    
    MedianFilter<5, 3> filter;
    
    // cout << sizeof(inputs) << ' ' << sizeof(inputs[0]) << ' ' << sizeof(inputs[0][0]) << endl;
    // 100 20 4
    for(size_t i = 0; i < lengthOf(inputs); ++i) {
        auto res = filter.Update(inputs[i]);
        if(!res) {
            return false;
        }
        
        // Check result
        size_t N = lengthOf(inputs[0]);
        print(res.get(), N);
        print(results[i], N);
        
        for(size_t j = 0; j < N; ++j) {
            if(res[j] != results[i][j]) {
                printf("Incorrect i: %u, j %u, res[i]: %2.2f, results[i][j]: %2.2f\n", i, j, res[j], results[i][j]);
                return false;
            }
        }
    }
    
    return true;
}

#include <assert.h>
int main() {
    assert(test1());
    
    
    #define N 30
    #define D 4
    
    float inputs[N];
    for(size_t i = 0; i < N; i++) {
        inputs[i] = randf(-3.f, 60.f);
    }
    print(inputs, N);
    {
        RangeFilter<N> filter(0.3, 50);
        auto res = filter.Update(inputs);
        if(res) print(res.get(), N);
    }
    {
        MedianFilter<N, 4> filter;
        auto res = filter.Update(inputs);
        if(res) print(res.get(), N);
    }
    
    return 0;
}