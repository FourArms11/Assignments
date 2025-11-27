// Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
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

    void displayWithRepeat() {
        if (!head) return;
        Node* cur = head;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != head);
        cout << head->data << endl; // repeat head
    }
};

int main() {
    CircularList c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);

    c.displayWithRepeat();  
    return 0;
}
