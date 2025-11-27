    // 1. Develop a menu driven program for the following operations of on a Circular as well
    // as a Doubly Linked List.
    // (a) Insertion anywhere in the linked list (As a first node, as a last node, and
    // after/before a specific node).
    // (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
    // deleted may appear as a head node, last node or a node in between.
    // (c) Search for a node.



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int v) {
        Node* n = new Node(v);
        n->next = head;
        if (head) head->prev = n;
        head = n;
    }

    void insertLast(int v) {
        if (!head) { insertFirst(v); return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        Node* n = new Node(v);
        cur->next = n;
        n->prev = cur;
    }

    bool insertAfter(int key, int v) {
        Node* cur = head;
        while (cur) {
            if (cur->data == key) {
                Node* n = new Node(v);
                n->next = cur->next;
                n->prev = cur;
                if (cur->next) cur->next->prev = n;
                cur->next = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool insertBefore(int key, int v) {
        Node* cur = head;
        while (cur) {
            if (cur->data == key) {
                Node* n = new Node(v);
                n->next = cur;
                n->prev = cur->prev;
                if (cur->prev) cur->prev->next = n;
                cur->prev = n;
                if (cur == head) head = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool deleteNode(int key) {
        Node* cur = head;
        while (cur) {
            if (cur->data == key) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    int search(int key) {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) { cout << "List empty\n"; return; }
        Node* cur = head;
        cout << "NULL <-> ";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << " <-> NULL\n";
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = nullptr;
    }

    ~DoublyLinkedList() { clear(); }
};

class CircularDoublyLinkedList {
public:
    Node* head;
    CircularDoublyLinkedList() : head(nullptr) {}

    void insertFirst(int v) {
        Node* n = new Node(v);
        if (!head) {
            n->next = n->prev = n;
            head = n;
            return;
        }
        Node* tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }

    void insertLast(int v) {
        if (!head) { insertFirst(v); return; }
        Node* n = new Node(v);
        Node* tail = head->prev;
        tail->next = n;
        n->prev = tail;
        n->next = head;
        head->prev = n;
    }

    bool insertAfter(int key, int v) {
        if (!head) return false;
        Node* cur = head;
        do {
            if (cur->data == key) {
                Node* n = new Node(v);
                n->next = cur->next;
                n->prev = cur;
                cur->next->prev = n;
                cur->next = n;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    bool insertBefore(int key, int v) {
        if (!head) return false;
        Node* cur = head;
        do {
            if (cur->data == key) {
                Node* n = new Node(v);
                n->next = cur;
                n->prev = cur->prev;
                cur->prev->next = n;
                cur->prev = n;
                if (cur == head) head = n;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    bool deleteNode(int key) {
        if (!head) return false;
        Node* cur = head;
        do {
            if (cur->data == key) {
                if (cur->next == cur) { delete cur; head = nullptr; return true; }
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                if (cur == head) head = cur->next;
                delete cur;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    int search(int key) {
        if (!head) return -1;
        Node* cur = head;
        int pos = 1;
        do {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        } while (cur != head);
        return -1;
    }

    void display() {
        if (!head) { cout << "List empty\n"; return; }
        Node* cur = head;
        cout << "(head) ";
        do {
            cout << cur->data;
            cur = cur->next;
            if (cur != head) cout << " <-> ";
        } while (cur != head);
        cout << " (back to head)\n";
    }

    void clear() {
        if (!head) return;
        Node* cur = head->next;
        while (cur != head) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        delete head;
        head = nullptr;
    }

    ~CircularDoublyLinkedList() { clear(); }
};

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter number: ";
    }
    return x;
}

int main() {
    DoublyLinkedList dll;
    CircularDoublyLinkedList cdll;
    while (true) {
        cout << "\nMain menu:\n1. Doubly Linked List\n2. Circular Doubly Linked List\n3. Exit\nChoice: ";
        int t = readInt();
        if (t == 3) break;
        bool circ = (t == 2);
        while (true) {
            cout << "\n--- " << (circ ? "Circular Doubly Linked List" : "Doubly Linked List") << " Menu ---\n";
            cout << "1. Insert as first node\n2. Insert as last node\n3. Insert after a specific node\n4. Insert before a specific node\n5. Delete a specific node (by value)\n6. Search for a node (by value)\n7. Display list\n8. Change list / Main menu\nChoice: ";
            int op = readInt();
            if (op == 8) break;
            int value, key;
            bool res;
            switch (op) {
                case 1:
                    cout << "Enter value to insert at first: ";
                    value = readInt();
                    if (circ) cdll.insertFirst(value); else dll.insertFirst(value);
                    cout << "Inserted.\n";
                    break;
                case 2:
                    cout << "Enter value to insert at last: ";
                    value = readInt();
                    if (circ) cdll.insertLast(value); else dll.insertLast(value);
                    cout << "Inserted.\n";
                    break;
                case 3:
                    cout << "Enter key (existing node value) after which to insert: ";
                    key = readInt();
                    cout << "Enter value to insert: ";
                    value = readInt();
                    res = (circ ? cdll.insertAfter(key, value) : dll.insertAfter(key, value));
                    cout << (res ? "Inserted after key.\n" : "Key not found. Insert failed.\n");
                    break;
                case 4:
                    cout << "Enter key (existing node value) before which to insert: ";
                    key = readInt();
                    cout << "Enter value to insert: ";
                    value = readInt();
                    res = (circ ? cdll.insertBefore(key, value) : dll.insertBefore(key, value));
                    cout << (res ? "Inserted before key.\n" : "Key not found. Insert failed.\n");
                    break;
                case 5:
                    cout << "Enter value of node to delete: ";
                    key = readInt();
                    res = (circ ? cdll.deleteNode(key) : dll.deleteNode(key));
                    cout << (res ? "Node deleted.\n" : "Node not found.\n");
                    break;
                case 6:
                    cout << "Enter value to search: ";
                    key = readInt();
                    {
                        int pos = (circ ? cdll.search(key) : dll.search(key));
                        if (pos == -1) cout << "Value not found.\n";
                        else cout << "Value found at position " << pos << ".\n";
                    }
                    break;
                case 7:
                    if (circ) cdll.display(); else dll.display();
                    break;
                default:
                    cout << "Invalid option.\n";
            }
        }
    }
    cout << "Exiting...\n";
    return 0;
}
