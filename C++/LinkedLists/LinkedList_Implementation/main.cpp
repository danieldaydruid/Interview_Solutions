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

int main() {
    struct Node* head = NULL; 
    
    return 0;
}