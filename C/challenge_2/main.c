/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

int main() {
	int check_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int new_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i = 0;
	int j = 0;
	for(i; i < 10; i++) {
		for(j = i; j < 10; j++) {
			new_array[i] += check_array[j]; //Seg fault?
		}
	}
	return 0;
}
