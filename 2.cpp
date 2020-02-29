// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
// Follow-up: what if you can't use division?
// hard

// thanks to Milo Hou for a hint

#include<iostream>

int main() {
    const unsigned int length = 4;
    const int input[length] = {3, 2, 1, 2};

    int before[length];
    int after[length];

    for(int i = 0; i < length; ++i)
        if(i == 0) {
            before[i] = 1;
            after[length - 1 - i] = 1;
        }
        else {
            before[i] = input[i - 1] * before[i - 1];
            after[length - 1 - i] = input[length - i] * after[length - i];
        }

    for(int i = 0; i < length; ++i)
        std::cout << before[i] * after[i] << " ";
    std::cout << std::endl;
}
