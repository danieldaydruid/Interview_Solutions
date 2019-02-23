#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

/* PROMPT
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/
class CheckArray {
	size_t N;
	size_t TrackFailures = 0;
	public:
		CheckArray(size_t N)
		: N(N)
		{}
		void IncrementFailures();
		size_t GetFailures();
		bool Update1(int* Scan, int n);
		bool Update2(int* Scan, int n);
		void Print(int* Scan);
};

class Test {
	public:
		void GenerateTests();
};

int main() {
	srand(time(NULL));
	int TestArray[4] = {10, 15, 3, 7};
	CheckArray Try(sizeof(TestArray)/sizeof(*TestArray));
	Try.Update1(TestArray, 17);
	Try.Update2(TestArray, 17);
	Test t;
	t.GenerateTests();
	return 0;
}

bool CheckArray::Update1(int* Scan, int n) { //Update in nested passes
	for(size_t i = 0; i < N; i++) {
		for(size_t j = 1; j < N; j++) {
			//if(n - Scan[i] == Scan[j]) return true;
			if(Scan[i] + Scan[j] == n) {
				std::cout << "Found " << n << " with: " << Scan[i] << " + " << Scan[j] << std::endl;
				return true;
			} 
		}
	}
		std::cout << "Update1 did not find " << n << "." << std::endl;
	return false;
}

bool CheckArray::Update2(int* Scan, int n) { //Update in single pass
    std::sort(Scan, Scan + N);
	size_t i = 0, j = N;
    while ( i < j ) {
        if ( Scan[i] + Scan[j] < n ) i++;
        else if ( Scan[i] + Scan[j] > n ) j--;
        else {
			std::cout << "Found " << n << " with: " << Scan[i] << " + " << Scan[j] << std::endl;
			return true;
		}
    }
	std::cout << "Update2 did not find " << n << "." << std::endl;
		std::cout << "Last checks: Scan[" << i << "] = " << Scan[i] << " + " << "Scan[" << j << "] = " << Scan[j] << std::endl;
    return false;
}

void CheckArray::Print(int* Scan) {
	for(size_t i = 0; i < N; i++) {
		std::cout << Scan[i] << std::endl;
	}
	return;
}

void Test::GenerateTests() {
	size_t S = rand() % 100, N = rand() % 100;
	CheckArray compute(N - 1);
	for(size_t i = 0; i < S; i++) {
		int* TestArray = new int[N];
		int n = rand() % 10;
		std::cout << "Array " << i << "[ ";
		for(size_t j = 0; j < N; j ++) {
			TestArray[j] = rand() % 10;
			std::cout << TestArray[j] << " ";
		}
		std::cout << "] Find n = " << n << std::endl;
		if( compute.Update1(TestArray, n) ) {
			std::cout << "Update1[" << i << "]:" << n << " found in array of length " << N << "." << std::endl;
		}
		else {
			compute.IncrementFailures();
		}
		if( compute.Update2(TestArray, n) ) {
			std::cout << "Update2[" << i << "]:" << n << " found in array of length " << N << "." << std::endl << std::endl;
		}
		else {
			compute.IncrementFailures();
		}
	}
	std::cout << S << " total tests run with array size " << N << "." << std::endl;
	std::cout << "Total failures recorded: " << compute.GetFailures() << std::endl;
	return;
}

void CheckArray::IncrementFailures() {
	TrackFailures++;
	return;
}
size_t CheckArray::GetFailures() {
	return TrackFailures;
}