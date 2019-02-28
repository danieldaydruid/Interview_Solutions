#include <iostream>
#include <stdio.h>

//Attempt 1

struct Node {
    struct Node* next;
    int data;
};

void Push(struct Node** Head, int data) {
    struct Node* new_node = new struct Node;
    new_node->data = data;
    new_node->next = *Head;
    *Head = new_node;
}

void PrintList(struct Node** Head) {
    struct Node* temp = *Head;
    while(temp->next != NULL) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    return;
}

int main() {
    struct Node* Head = NULL;
    Push(&Head, 1);
    PrintList(&Head);
    return 0;
}