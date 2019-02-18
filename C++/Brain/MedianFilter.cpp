#include "MedianFilter.h"

float* MedianFilter::Update(float *start_array) {
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