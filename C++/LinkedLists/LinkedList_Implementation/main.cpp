#include <iostream>
#include <stdio.h>

struct Node {
        struct Node* next;
        int data;
};

void Push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void InsertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        std::cout << "The given previous Node cannot be NULL" << std::endl;
        return;
    } 
    //struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* new_node = new struct Node; //Faster than malloc() because an operator is always faster than a function.
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void Append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data= new_data; 
    new_node->next = NULL;
    if(*head_ref == NULL) { 
        *head_ref = new_node; 
        return;
    }
    while (last->next != NULL) last = last->next; //Travel until last node
    last->next = new_node; //Change next of the last node
    return;
}

void PrintList(struct Node *node) {
    while(node != NULL) {
        std::cout << node->data std::endl;
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL; 
    Append(&head, 6);
    Push(&head, 7);
    Push(&head, 1);
    Append(&head, 4);
    InsertAfter(head->next, 8);

    std::cout << "Created linked list is: ") << std::endl;
    PrintList(head);
    return 0;
}