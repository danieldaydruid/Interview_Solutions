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

int main() {
    struct Node* head = NULL;
    
    return 0;
}