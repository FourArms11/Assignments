// Write a program to convert an Infix expression into a Postfix expression.


#include <iostream>
using namespace std;

#define MAX 200

// -------- Simple char stack (array-based) --------
class CharStack {
    char a[MAX];
    int top;
public:
    CharStack() : top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }
    void push(char x) {
        if (!isFull()) a[++top] = x;
        else cout << "Stack Overflow!\n";
    }
    char pop() {
        if (!isEmpty()) return a[top--];
        return '\0';
    }
    char peek() {
        if (!isEmpty()) return a[top];
        return '\0';
    }
};

// -------- Helpers --------
bool isOperand(char c) {
    // treat letters and digits as operands
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
int precedence(char op) {
    if (op=='+' || op=='-') return 1;
    if (op=='*' || op=='/') return 2;
    if (op=='^')           return 3;
    return 0;
}
bool isRightAssoc(char op) {
    return op == '^';
}

// -------- Infix to Postfix --------
bool infixToPostfix(const char infix[], char postfix[]) {
    CharStack st;
    int k = 0; // index for postfix output

    for (int i = 0; infix[i] != '\0'; ++i) {
        char ch = infix[i];

        // ignore spaces/tabs
        if (ch == ' ' || ch == '\t') continue;

        if (isOperand(ch)) {
            postfix[k++] = ch;           // output operand
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            // pop until '('
            bool foundOpen = false;
            while (!st.isEmpty()) {
                char t = st.pop();
                if (t == '(') { foundOpen = true; break; }
                postfix[k++] = t;
            }
            if (!foundOpen) return false; // mismatched parenthesis
        }
        else if (isOperator(ch)) {
            // pop while top has higher precedence
            // or same precedence and current op is left-associative
            while (!st.isEmpty() && isOperator(st.peek())) {
                char topOp = st.peek();
                int pTop = precedence(topOp), pCur = precedence(ch);
                bool shouldPop =
                    (pTop > pCur) ||
                    (pTop == pCur && !isRightAssoc(ch));
                if (shouldPop) {
                    postfix[k++] = st.pop();
                } else break;
            }
            st.push(ch);
        }
        else {
            // invalid character
            return false;
        }
    }

    // pop remaining operators
    while (!st.isEmpty()) {
        char t = st.pop();
        if (t == '(' || t == ')') return false; // mismatched
        postfix[k++] = t;
    }

    postfix[k] = '\0';
    return true;
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    cout << "Enter infix expression: ";
    cin.getline(infix, MAX);

    if (infixToPostfix(infix, postfix)) {
        cout << "Postfix: " << postfix << "\n";
    } else {
        cout << "Invalid expression (mismatched parentheses or invalid character).\n";
    }
    return 0;
}
