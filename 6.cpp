// An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
// hard




#include<iostream>
#include<string>

struct node {
    std::string value;
    node* both;

    node() {
        this->value = "";
        this->both = nullptr;
    }
};

node* take_xor(node* a, node* b) {
   return (node*) ( (unsigned long) a xor (unsigned long) b);
}

void print_node(node* head) {
    std::cout << "node[" << head << "] = (" << head->value << ", " << head->both << ")\n";
}

// note that we need to pass head by reference as otherwise we are working with a copy of head
void add(node* &head, std::string value) {
    // add as head if the list is empty
    if(head == nullptr) {
        head = new node();
        head->value = value;
        return;
    }
    // if head is the only node, add a second node
    if(head->both == nullptr) {
        node* second = new node();
        second->value = value;
        head->both = second;
        return;
    }
    // if there are at least 2 nodes, traverse until the end
    node* current = head;
    node* prev = nullptr;
    while(current->both != nullptr) {
        node* next = take_xor(current->both, prev);
        prev =  current;
        current = next;
    }
    // at this point current points to the last node and prev to the one before that
    node* next = new node();
    next->value = value;
    current->both = take_xor(prev, next);
}

std::string get(node* head, int i) {
    node* current = head;
    node* prev = nullptr;
    int j = 0;
    while(j < i) {
        node* next = take_xor(current->both, prev);
        prev = current;
        current = next;
        ++j;
    }
    return current->value;
}

int main() {
    node* head = nullptr;
    add(head, "first");
    add(head, "second");
    add(head, "third");
    add(head, "fourth");
    std::cout << get(head, 2) << std::endl;
    // I guess I should probably delete...
}

