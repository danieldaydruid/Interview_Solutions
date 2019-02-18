#include "RangeFilter.h"

float* RangeFilter::Update(float *start_array, size_t N) {
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