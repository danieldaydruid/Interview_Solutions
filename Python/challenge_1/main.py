'''
This problem was recently asked by Google:

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
'''

def main():
    init = input("Size of array: ")
    checksum = input("Sum of 2 integers to find: ")
    my_list = [init + (i+1) for i in range(10)]
    for j in range(len(my_list)):
        if((checksum - my_list[j]) in my_list):
            print("true")
main()
