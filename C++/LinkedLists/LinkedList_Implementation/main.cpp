#include <iostream>
#include <stdio.h>

struct Node {
    struct Node* next;
    int data;
};

class LinkedList {
    struct Node* Head;
    public:
        LinkedList() {
            Head = NULL;
        }
        void Push(int data);
        void Print();
};

void LinkedList::Push(int data) {
    struct Node* temp = new struct Node;
    temp->data = data;
    temp->next = Head;
    Head = temp;
    return;
}

void LinkedList::Print() {
    struct Node* temp = Head;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int main() {
    LinkedList LL;
    for(int i = 0; i < 100; i++) LL.Push(i);
    LL.Print();
    return 0;
}