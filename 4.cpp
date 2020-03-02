//Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
//For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
//You can modify the input array in-place.
// hard

// thanks to Milo Hou and Prashan Dharmasena for explaining the answer to me

#include<iostream>

void selfIndex(int* input, int length) {
    for(int i = 0; i < length; ++i) {
        if(input[i] > 0 and input[i] < length + 1) {
            int temp = input[input[i] - 1];
            input[input[i] - 1] = input[i];
            input[i] = temp;
        }
    }
}

void sortInPlace(int* input, int length) {
    for(int i = 0; i < length; ++i) {

    }
}

int findMissing(int* input, int length) {
    for(int i = 0; i < length; ++i) {
        if(input[i] != i + 1)
            return i + 1;
    }
    return length + 1;
}

int main() {
    int input1[] = {3, 4, -1, 1};
    int input2[] = {1, 2, 0};

    selfIndex(input1, 4);
    selfIndex(input2, 3);
    for(int i = 0; i < 4; ++i) {
        std::cout << input1[i] << std::endl;
    }

    std::cout << "Missing: " << std::endl;
    std::cout << findMissing(input1, 4) << std::endl;
    std::cout << findMissing(input2, 3) << std::endl;
}
