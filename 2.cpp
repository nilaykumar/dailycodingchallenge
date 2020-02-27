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
