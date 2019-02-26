#include <iostream>
#include <algorithm>
#include <string>

/* PROMPT
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i. 

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If your input was [3, 2, 1], the expected output would be [2, 3, 6]. 

Follow-up: what if you can't use division? 
*/

class ArrayFilter {
	const size_t N;
	public:
		ArrayFilter(size_t N) //Overloaded constructor
			:N (N)
		{}
		int* Update(int* Input);
		void Print(int* Input, std::string Prefix);
};

int main() {
	int TestArray[5]; //Declares empty base array for testing
	ArrayFilter Filter((sizeof(TestArray)/sizeof(*TestArray))); //Declares an object of type ArrayFilter with initial filtered array size equal to TestArray's size.
	size_t n = 0; //Initializes incrementer n to traverse TestArray
	for(int i = 1; i <= 101; i++) { //For loop to add values into TestArray, 5 values at a time, from 1 to 100 (0 is omitted as products of 0 are not good testing values)  
		if(n < 5) { //Ensures that TestArray's bounds are not surpassed while adding values to TestArray
			TestArray[n] = i; //Assigns TestArray's nth element to i
			n++;
		}
		else {
			Filter.Print( TestArray, "Unfiltered Array" ); //Prints TestArray to be filtered
 			Filter.Print( Filter.Update(TestArray), "Filtered Array" ); //Prints filtered TestArray 
			 std::cout << std::endl;
			n = 0; //Resets n in order that bounds of TestArray are not surpassed in the next loop 
			i--;
		}
	}
	return 0;
} 
int* ArrayFilter::Update(int* Input) {
	if(Input == NULL) return NULL; //Checks for NULL arrays being passed in
	int* FilteredArray = new int[N]; //Declares a new array of size N for FilteredArray
	std::fill_n(FilteredArray, N, 1); //Fills FilteredArray with 1s so no zero products occur
	for(size_t i = 0; i < N; i ++) { //Nested for loop to check
		for(size_t j = 0; j < N; j ++) {
			if(i != j) {
				FilteredArray[i] *=  Input[j]; //Computes the product of all Input array elements excluding the current Input array element
			}
		}
	}
	return FilteredArray;
}

void ArrayFilter::Print(int* Input, std::string Prefix) {
	std::cout << Prefix << ": [ ";
	for(size_t i = 0; i < N; i++) { //Prints the contents of the passed arrays in a readable format
		std::cout << Input[i] << " ";
	}
	std::cout << "]" << std::endl;
	return;
}
