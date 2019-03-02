#include <iostream> 
#include <stdio.h>

struct Node {
    struct Node* next;
    int data;
};

class LinkedList {
    Node* Head;
    public:
        LinkedList() {
            Head = NULL; 
        }
        void Push(int data);
        void Print();
        void Delete(int key);
        void Reverse();
};

void LinkedList::Push(int data) { 
    Node* temp = new Node;
    temp->data = data;
    temp->next = Head;
    Head = temp;
    return;
}

void LinkedList::Print() {
    Node* temp = Head;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    return;
}

void LinkedList::Delete(int key) {
    Node* temp = Head, *prev;
    if(temp != NULL && temp->data == key) {
        Head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
    return;
}

void LinkedList::Reverse() {
    Node *current = Head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Head = prev;
    return;
}
//Worst Access: O(n), Worst Search: O(n), Worst Insert: O(1), Worst Delete: O(1)
//Avg Access: O(n), Avg Search: O(n), Avg Insert: O(1), Avg Delete: O(1)
//Worst Space: O(n)
int main() {
    LinkedList LL;
    for(int i = 0; i < 100; i++) LL.Push(i);
    LL.Print();
    LL.Delete(3);
    LL.Print();
    LL.Reverse();
    LL.Print();
    return 0;
}
