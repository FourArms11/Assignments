// Write a program to check if a doubly linked list of characters is palindrome or not.


#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char c): data(c), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList(): head(nullptr) {}

    void insertLast(char c) {
        Node* n = new Node(c);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;
        Node* left = head;
        Node* right = head;
        while (right->next) right = right->next; // move to tail
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
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

int main() {
    DoublyLinkedList dl;

    // Example 1: palindrome "radar"
    const char* s1 = "radar";
    for (const char* p = s1; *p; ++p) dl.insertLast(*p);
    cout << "List: ";
    for (const char* p = s1; *p; ++p) cout << *p;
    cout << "\nIs palindrome? " << (dl.isPalindrome() ? "Yes" : "No") << "\n\n";

    dl.clear();

    // Example 2: not palindrome "hello"
    const char* s2 = "hello";
    for (const char* p = s2; *p; ++p) dl.insertLast(*p);
    cout << "List: ";
    for (const char* p = s2; *p; ++p) cout << *p;
    cout << "\nIs palindrome? " << (dl.isPalindrome() ? "Yes" : "No") << "\n\n";

    // Optional: read from user
    // string input;
    // cout << "Enter a string to check (characters will be taken as-is): ";
    // if (getline (cin >> ws, input)) {
    //     dl.clear();
    //     for (char c : input) dl.insertLast(c);
    //     cout << "Is palindrome? " << (dl.isPalindrome() ? "Yes" : "No") << "\n";
    // }

    return 0;
}


