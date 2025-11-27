// Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”




#include <iostream>
#include <cstring> // for strlen()
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }
};

int main() {
    Stack s;
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);

    // Push
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    // Pop to get reversed string
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << endl;
    return 0;
}
