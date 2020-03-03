//Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// You can assume that the messages are decodable. For example, '001' is not allowed.
// medium

#include<iostream>
#include<string>
#include<vector>

std::string to_character(std::string digits) {
    return std::string(1, (char) (std::stoi(digits) + 96));
}

void decode(std::vector<std::string> &decodings, std::string digits, std::string prev_decoding) {
    if(digits == "") {
        std::cout << "Reached end!\n";
        decodings.push_back(prev_decoding);
        return;
    }

    // break off the first digit
    std::string first = digits.substr(0, 1);
    std::cout << "Breaking off first digit: " << first << " and next analyzing " << digits.substr(1) << std::endl;
    decode(decodings, digits.substr(1), prev_decoding + to_character(first));

    // break off the first two digits
    if(digits.length() == 1)
        return;
    std::string first_two = digits.substr(0, 2);
    if(std::stoi(first_two) > 26)
        return;
    std::cout << "Breaking off first two digits: " << first_two << " and next analyzing " << digits.substr(2) << std::endl;
    decode(decodings, digits.substr(2), prev_decoding + to_character(first_two));
}


int main() {
    const std::string input_string = "hell";
    std::string digits;
    for(char c : input_string)
        digits += std::to_string(((int) c) - 96);
    std::cout << "Processing... " << digits << std::endl;

    std::vector<std::string> decodings;
    decode(decodings, digits, "");

    std::cout << "Decodings: " << decodings.size() << std::endl;
    for(std::string s : decodings)
        std::cout << s << std::endl;
}
