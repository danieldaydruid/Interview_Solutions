#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
//Headers for rand() testing
#include <stdlib.h>
#include <time.h>

class RangeFilter {
    float m_minRange;
    float m_maxRange;
public:
    RangeFilter(float min_range, float max_range)
        : m_minRange (min_range)
        , m_maxRange (max_range)
    {}
    float* Update(float *start_array, size_t N)
    {
        if(start_array == NULL || N == 0) {
            return NULL;
        }
        
        float *new_array = new float[N];

        if(new_array == NULL) {
            return NULL;
        }

        for(size_t i = 0; i < N; i++) {  //For loop that traverses the array argument
            if(start_array[i] < m_minRange) {//Checks whether the current index is within the minimum range argument limit and replaces it if not
                new_array[i] = m_minRange;
            }
            else if(start_array[i] > m_maxRange) {    //Checks whether the current index is within the maximum range argument limit and replaces it if not
                new_array[i] = m_maxRange;
            }
            else {
                new_array[i] = start_array[i];
            }
        }

        return new_array;
    }
};

class MedianFilter {
    const size_t N, D;
    std::vector<float*> m_history;
public:
    MedianFilter(size_t N, size_t D)
        : N (N)
        , D (D)
        , m_history()
    {}
    ~MedianFilter() {
        for(auto ptr : m_history) {
            delete ptr;
        }
    }

    float* Update(float *start_array) {
        size_t d = m_history.size() + 1;
        float *new_array = new float[N];
        float *values = new float[D + 1]; // Room for D lookback and current value
        if(start_array == NULL) {
            std::cout << "Passed array was empty." << std::endl;
            return NULL;
        }
        for(size_t i = 0; i < N; i++) {
            for(size_t j = 0; j < d - 1; j++) {
                float val = m_history[j][i];
                values[j] = val;
            }
            values[d - 1] = start_array[i];

            // Sort values to get meidan
            std::sort(values, values + d); //Sorts by ascending order by default, which  is ideal for this case

            if(d % 2 == 0) {
                new_array[i] = ((values[(d/2) - 1] + values[d/2]) * 0.5);
            }
            else {
                new_array[i] = values[d/2];
            }
        }
        delete values;
        
        // Add into History
        float* CopyArray = new float[N]; //Can I declare float* CopyArray inside of the memcpy call? Is there a better way than that?
        memcpy(CopyArray, start_array, sizeof(float) * N); //Is this the proper implementation of memcpy? ((maybe sizeof *new_array))
        m_history.push_back(CopyArray);
        if(m_history.size() > D) {
            CopyArray = *m_history.begin();
            m_history.erase(m_history.begin());
            delete CopyArray;
        }

        return new_array;
    }
};

using namespace std;
#define lengthOf(arr) (sizeof(arr)/sizeof(*arr))
static void printArray(float *values, size_t N)
{
    int i = 0;
    for(size_t i = 0; i < N; ++i) {
        float val = values[i];
        if(i > 0 && i % 10 == 0) cout << endl;
        cout << (i ? ' ' : '>') << std::setw(5) << std::setprecision(1) << std::fixed << val;
    }
    cout << endl;
}

bool NullTest() {
    MedianFilter filter(5, 3);
    
    // Test that Update can hangle invalid input.
    filter.Update(NULL);

}
bool BaseTest() {
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
    
    MedianFilter filter(5, 3);
    
    // cout << sizeof(inputs) << ' ' << sizeof(inputs[0]) << ' ' << sizeof(inputs[0][0]) << endl;
    // 100 20 4
    for(size_t i = 0; i < lengthOf(inputs); ++i) {
        auto res = filter.Update(inputs[i]);
        if(res == NULL) {
            return false;
        }
        
        // Check result
        size_t N = lengthOf(inputs[0]);
        printArray(res, N);
        printArray(results[i], N);
        
        for(size_t j = 0; j < N; ++j) {
            if(res[j] != results[i][j]) {
                //printf("Incorrect i: %x, j %x, res[i]: %2.2f, results[i][j]: %2.2f\n", i, j, res[j], results[i][j]);
                std::cout << std::setprecision(2) << "Incorrect i: " << i << "j: " << j << "res[j]: " << res[j] << ", results[i][j]: " << results[i][j] << std::endl;
                delete res;
                return false;
            }
        }

        delete res;
    }
    
    return true;
}

//Range Filter class declaration
class range_filter {
    private:
    public:
        float* update_range(float *start_array, size_t size_of_array, float min_range, float max_range, bool first_pass);
};
//Temporal Median Filter class declaration
class temporal_median_filter {
    private:
        std::vector<std::vector<float> > history_vector;
    public:
        //Create a default constructor 
        temporal_median_filter();
        void update_history(float *start_array, size_t size_of_array);
        float* update_median(float *start_array, size_t array_size);
        ~temporal_median_filter();
};

bool RandomTest(size_t D, size_t N) {
    std::cout << "Random Test: D = " << D << ", N = " << N << std::endl;
    RangeFilter input(0.03, 50.0);
    MedianFilter med(N, D);
    for(size_t i = 0; i <= D; i++) {    //Generates the number of arrays to test (between 100 and 300 individual arrays)
        size_t array_size = N;        //Generates the size of the array, between 200 and 1000
        float *start_array = new float[array_size];        //Creates the new float array of the requisite size
        for(size_t j = 0; j < array_size; j++) {        //Generates the values in the new array
            float range_value = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) ) + static_cast <float> (rand() % 59);            //Creates a random float value between 0.0 and 60.0
            start_array[j] = range_value;             //Populates array index with randomly generated range value
        }
        float min_range = ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 5.0);        //Creates a randomized minimum acceptable range between 5.0 and 6.0
        float max_range = static_cast <float> (rand() % 10 + 40);        //Creates a randomized maximum acceptable range between 40.0 and 50.0
        //std::cout << "Test #" << i+1 << std::endl;        //Output to track number of tests run
        float *filtered_range_array = input.Update(start_array, array_size);
        float *filtered_temporal_median_array = med.Update(start_array);
        /*std::cout << "[ ";
        for(size_t k = 0; k < N; k++) {
            std::cout << std::setprecision(2) << filtered_temporal_median_array[k] << " ";
        }
        std::cout << " ]" << std::endl;*/
    }
    return true;
}

int main() {
    BaseTest();
    NullTest();
    RandomTest(0, 0);
    RandomTest(5, 5);
    RandomTest(20, 20);
    RandomTest(200, 200);
    RandomTest(1000, 1000);
    return 0;
}