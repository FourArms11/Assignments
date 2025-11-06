// Develop a menu driven program for the following operations on a Singly Linked 
// List. 
// (a) Insertion at the beginning. 
// (b) Insertion at the end. 
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a 
// new Node 35 before/after the Node 30'). 
// (d) Deletion from the beginning. 
// (e) Deletion from the end. 
// (f) Deletion of a specific node, say 'Delete Node 60'). 
// (g) Search for a node and display its position from head. 
// (h) Display all the node values. 


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
    Node* head = nullptr;

public:
    ~LinkedList() { clear(); }

    void insert_begin(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insert_end(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    bool insert_before_value(int val, int x) {
        if (!head) return false;
        if (head->data == val) { insert_begin(x); return true; }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (!cur->next) return false;
        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        return true;
    }

    bool insert_after_value(int val, int x) {
        Node* cur = head;
        while (cur && cur->data != val) cur = cur->next;
        if (!cur) return false;
        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        return true;
    }

    bool delete_begin() {
        if (!head) return false;
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }

    bool delete_end() {
        if (!head) return false;
        if (!head->next) { delete head; head = nullptr; return true; }
        Node* cur = head;
        while (cur->next && cur->next->next) cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
        return true;
    }

    bool delete_value(int val) {
        if (!head) return false;
        if (head->data == val) { Node* t = head; head = head->next; delete t; return true; }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (!cur->next) return false;
        Node* t = cur->next;
        cur->next = t->next;
        delete t;
        return true;
    }

    int search_value(int val) {
        int pos = 1;
        Node* cur = head;
        while (cur) {
            if (cur->data == val) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* n = cur->next;
            delete cur;
            cur = n;
        }
        head = nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList list;
    int choice, x, val;

    while (true) {
        cout << "\nSingly Linked List Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search for a value\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                list.insert_begin(x);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> x;
                list.insert_end(x);
                break;
            case 3:
                cout << "Insert what value: ";
                cin >> x;
                cout << "Before which value: ";
                cin >> val;
                if (!list.insert_before_value(val, x)) cout << "Target value not found\n";
                break;
            case 4:
                cout << "Insert what value: ";
                cin >> x;
                cout << "After which value: ";
                cin >> val;
                if (!list.insert_after_value(val, x)) cout << "Target value not found\n";
                break;
            case 5:
                if (!list.delete_begin()) cout << "List is empty\n";
                break;
            case 6:
                if (!list.delete_end()) cout << "List is empty\n";
                break;
            case 7:
                cout << "Delete which value: ";
                cin >> val;
                if (!list.delete_value(val)) cout << "Value not found\n";
                break;
            case 8: {
                cout << "Search which value: ";
                cin >> val;
                int pos = list.search_value(val);
                if (pos == -1) cout << "Not found\n";
                else cout << "Found at position " << pos << " from head\n";
                break;
            }
            case 9:
                list.display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
