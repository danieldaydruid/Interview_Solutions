#include <iostream>
#include <stdio.h>

struct Node {
        Node* Next;
        int Data;
};

class LinkedList {
    Node *Head, *Tail;
    public:
        LinkedList() {
            Head = NULL;
            Tail = NULL;
        }
};

int main() {

    return 0;
}