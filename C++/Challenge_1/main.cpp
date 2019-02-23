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
	public:
		CheckArray(size_t N)
		: N(N)
		{}
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
		for(size_t j = 0; j < N; j++) {
			if(n - Scan[i] == Scan[j]) return true;
		}
	}
	//std::cout << "Failure1!" << std::endl;
	return false;
}

bool CheckArray::Update2(int* Scan, int n) { //Update in single pass
    std::sort(Scan, Scan + N);
	size_t i = 0, j = N - 1;
    while ( i < j ) {
        if ( Scan[i] + Scan[j] < n ) i++;
        else if ( Scan[i] + Scan[j] > n ) j--;
        else return true;
    }
	//std::cout << "Failure2!" << std::endl;
    return false;
}

void CheckArray::Print(int* Scan) {
	for(size_t i = 0; i < N; i++) {
		std::cout << Scan[i] << std::endl;
	}
	return;
}

void Test::GenerateTests() {
	size_t S = rand() % 1000, N = rand() % 100;
	CheckArray compute(N);
	for(size_t i = 0; i < S; i++) {
		int TestArray[N];
		int n = rand() % 10;
		std::cout << "Start " << i << "[ ";
		for(size_t j = 0; j < N - 1; j ++) {
			TestArray[j] = rand() % 10;
			std::cout << TestArray[j] << " ";
		}
		std::cout << "] End: " << n << std::endl;
		if( compute.Update1(TestArray, n) ) {
			std::cout << "Update1[" << i << "]:" << n << " found in array of length " << N << "." << std::endl;
		}
		if( compute.Update2(TestArray, n) ) {
			std::cout << "Update2[" << i << "]:" << n << " found in array of length " << N << "." << std::endl << std::endl;
		}

		if( compute.Update1(TestArray, n) && !compute.Update2(TestArray, n) ) {
			exit(1);
		}
	}
	return;
}
