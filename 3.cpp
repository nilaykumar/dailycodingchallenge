#include<iostream>
#include<string>

struct Vertex {
    std::string value;
    Vertex* left;
    Vertex* right;

    Vertex(std::string value, Vertex* left = nullptr, Vertex* right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

std::string serialize(Vertex* root) {
    std::string s("(" + root->value);
    if(root->left != nullptr)
        s += serialize(root->left);
    else
        s += "()";
    if(root->right != nullptr)
        s += serialize(root->right) + ")";
    else
        s+= "())";
    return s;
}

// the input must start with (
int getFirstMatchingCloseParen(std::string data) {
    int diff = 0;
    for(int i = 0; i < data.length(); ++i) {
        if(data.at(i) == '(')
            diff += 1;
        if(data.at(i) == ')')
            diff -= 1;
        if(diff == 0)
            return i;
    }
    return -1;
}

Vertex* deserialize(std::string data) {
    // the data will be of the form (value(...)(...))

    // base case
    if(data == "()") {
        return nullptr;
    }

    // strip the surrounding parens
    data = data.substr(1, data.length() - 2);
    int firstOpenParen = data.find("(");
    // get the value of the root vertex
    std::string value = data.substr(0, firstOpenParen);

    int firstMatchingCloseParen = getFirstMatchingCloseParen(data.substr(firstOpenParen));

    // get the left child's data
    std::string leftChild = data.substr(firstOpenParen, firstMatchingCloseParen + 1);
    Vertex *left = deserialize(leftChild);
    // get the right child's data
    std::string rightChild = data.substr(firstOpenParen + firstMatchingCloseParen + 1);
    Vertex *right = deserialize(rightChild);

    // TODO I never delete this vertex
    Vertex* root = new Vertex(value, left, right);
    return root;
}

int main() {
    Vertex leftleft("ll");
    Vertex left("l", &leftleft);
    Vertex right("ri");
    Vertex root("ro", &left, &right);

    std::cout << "Serialized: " << serialize(&root) << std::endl;
    Vertex* deserialized = deserialize(serialize(&root));
    std::string serdeser = serialize(deserialized);
    std::cout << "Deserialized then serialized: " << serdeser << std::endl;
    std::cout << "Do these match? " << (serdeser == serialize(&root)) << std::endl;
}
