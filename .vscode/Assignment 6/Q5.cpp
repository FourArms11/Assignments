// Write a program to check if a linked list is Circular Linked List or not.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* cur = head->next;
    while (cur && cur != head)
        cur = cur->next;
    return (cur == head);
}

void testCircularList() {
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = nullptr;

    cout << "List 1: " << (isCircular(head1) ? "Circular" : "Not Circular") << endl;

    Node* head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(25);
    head2->next->next->next = head2;

    cout << "List 2: " << (isCircular(head2) ? "Circular" : "Not Circular") << endl;
}

int main() {
    testCircularList();
    return 0;
}
