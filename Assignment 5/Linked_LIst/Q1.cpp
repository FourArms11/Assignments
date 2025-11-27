// Develop a menu driven program for the following operations on a Singly Linked
// List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    // Insert after first occurrence of target. Returns true if success.
    bool insertAfter(int target, int value) {
        Node* cur = head;
        while (cur) {
            if (cur->data == target) {
                Node* n = new Node(value);
                n->next = cur->next;
                cur->next = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool insertBefore(int target, int value) {
        if (!head) return false;

        if (head->data == target) {
            insertAtBeginning(value);
            return true;
        }

        Node* prev = nullptr;
        Node* cur = head;
        while (cur) {
            if (cur->data == target) {
                Node* n = new Node(value);
                prev->next = n;
                n->next = cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false; // not found
    }

    void display() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* cur = head;
        cout << "List: ";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a specific value\n";
        cout << "4. Insert before a specific value\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) { 
            cout << "Invalid input. Exiting.\n";
            break;
        }

        int val, target;
        bool ok;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                cout << val << " inserted at beginning.\n";
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                cout << val << " inserted at end.\n";
                break;

            case 3:
                cout << "enter target value: ";
                cin >> target;
                cout << "enter value to insert after "<< target <<" ";
                cin >> val;
                ok = list.insertAfter(target, val);

                if (ok) cout << val << " inserted after " << target << endl;
                else cout << "Value " << target << " not found in the list.\n";
                break;

            case 4:
                cout << "enter target value (insert before): ";
                cin >> target;
                cout << "enter value to insert before " << target << ": ";
                cin >> val;

                
                ok = list.insertBefore(target, val);
                if (ok) cout << val << " inserted before " << target << "\n";
                else cout <<"not found\n";
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout << "exit.\n";
                return 0;

            default:
                cout << "invalid\n";
        }
    }

    return 0;
}



