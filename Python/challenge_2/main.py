'''
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
'''

def main():
    running_total = 0
    size_of_array = input("Enter size of array: ")
    array = [i+1 for i in range(size_of_array)]
    for j in range(size_of_array):
        running_total = running_total + array[j]
        print(sum(array) - running_total)
main()
