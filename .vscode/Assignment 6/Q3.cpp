// Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyList {
public:
    Node* head;
    DoublyList() : head(nullptr) {}

    void insertLast(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }

    int size() {
        int cnt = 0;
        Node* cur = head;
        while (cur) {
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() : head(nullptr) {}

    void insertLast(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* cur = head;
        while (cur->next != head) cur = cur->next;
        cur->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;
        int cnt = 0;
        Node* cur = head;
        do {
            cnt++;
            cur = cur->next;
        } while (cur != head);
        return cnt;
    }
};

int main() {
    DoublyList dl;
    dl.insertLast(10);
    dl.insertLast(20);
    dl.insertLast(30);

    CircularList cl;
    cl.insertLast(5);
    cl.insertLast(15);
    cl.insertLast(25);
    cl.insertLast(35);

    cout << "Size of Doubly Linked List: " << dl.size() << endl;
    cout << "Size of Circular Linked List: " << cl.size() << endl;

    return 0;
}


