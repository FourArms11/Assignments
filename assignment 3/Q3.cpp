// Write a program that checks if an expression has balanced parentheses



#include <iostream>
#include <cstring> 
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        } else {
            cout << "Stack Overflow!\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            return '\0'; // return null char if empty
        }
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        else return '\0';
    }
};

// Function to check if parentheses are balanced
bool isBalanced(char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) 
                return false; // closing before opening

            char top = s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false; // mismatch
            }
        }
    }

    // If stack is empty, everything matched properly
    return s.isEmpty();
}

int main() {
    char expr[100];

    cout << "Enter an expression: ";
    cin.getline(expr, 100);

    if (isBalanced(expr))
        cout << "Expression is balanced." << endl;
    else
        cout << "Expression is NOT balanced." << endl;

    return 0;
}
