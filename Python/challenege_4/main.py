'''
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
'''
def main():
    check = False
    test_array = sorted([3, 4, -1, 1])
    #test_array = sorted([1, 2, 0])
    for i in range(len(test_array)):
        if( i+1 < len(test_array) and test_array[i+1] != test_array[i]+1 and test_array[i] > 0):
            print("Between " + str(test_array[i]) + " and " + str(test_array[i+1]) + " there is a missing " + str(test_array[i]+1) + " between them!")
            check = True
    if(not check):
        print("After " + str(test_array[i]) + " the list is missing a " + str(test_array[i]+1) + "!")
main()
