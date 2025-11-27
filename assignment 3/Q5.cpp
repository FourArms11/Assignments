// Write a program for the evaluation of a Postfix expression.




#include <iostream>
using namespace std;

#define MAX 200

// ---------- Simple stack for doubles ----------
class Stack {
    double a[MAX];
    int top;
public:
    Stack(): top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }
    void push(double x) {
        if (!isFull()) a[++top] = x;
        else cout << "Stack Overflow!\n";
    }
    bool pop(double &out) {
        if (!isEmpty()) { out = a[top--]; return true; }
        return false;
    }
    int size() { return top + 1; }
    double peek() { return isEmpty() ? 0.0 : a[top]; }
};

// parse a C-string token into a double (no <cstdlib> used)
bool parseNumber(const char* s, double &val) {
    // handle optional leading sign
    int i = 0, sign = 1;
    if (s[i] == '+') i++;
    else if (s[i] == '-') { sign = -1; i++; }

    bool hasDigit = false;
    long long intPart = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        hasDigit = true;
        intPart = intPart * 10 + (s[i] - '0');
        i++;
    }
    double frac = 0.0, base = 0.1;
    if (s[i] == '.') {
        i++;
        while (s[i] >= '0' && s[i] <= '9') {
            hasDigit = true;
            frac += (s[i] - '0') * base;
            base *= 0.1;
            i++;
        }
    }
    if (!hasDigit || s[i] != '\0') return false; // invalid token
    val = sign * (intPart + frac);
    return true;
}

// integer power without <cmath>
double pow_int(double a, long long b) {
    if (b == 0) return 1.0;
    bool neg = b < 0;
    long long e = neg ? -b : b;
    double res = 1.0;
    while (e > 0) {
        if (e & 1) res *= a;
        a *= a;
        e >>= 1;
    }
    return neg ? (1.0 / res) : res;
}

int main() {
    char line[512];
    cout << "Enter space-separated postfix expression:\n";
    cin.getline(line, 512);

    Stack st;

    // Tokenize manually on spaces
    int p = 0;
    while (line[p] != '\0') {
        // skip spaces
        while (line[p] == ' ' || line[p] == '\t') p++;
        if (line[p] == '\0') break;

        // extract token
        char tok[128];
        int t = 0;
        while (line[p] != '\0' && line[p] != ' ' && line[p] != '\t') {
            if (t < 127) tok[t++] = line[p];
            p++;
        }
        tok[t] = '\0';

        // operator (single char)
        if (tok[1] == '\0' && (tok[0]=='+'||tok[0]=='-'||tok[0]=='*'||tok[0]=='/'||tok[0]=='^')) {
            double b, a;
            if (!st.pop(b) || !st.pop(a)) {
                cout << "Error: insufficient operands.\n";
                return 0;
            }
            double res = 0.0;
            switch (tok[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0.0) { cout << "Error: division by zero.\n"; return 0; }
                    res = a / b; break;
                case '^':
                    // exponent treated as integer for typical postfix labs
                    res = pow_int(a, (long long)(b));
                    break;
            }
            st.push(res);
        } else {
            // number
            double val;
            if (!parseNumber(tok, val)) {
                cout << "Error: invalid token \"" << tok << "\".\n";
                return 0;
            }
            st.push(val);
        }
    }

    if (st.size() != 1) {
        cout << "Error: malformed expression.\n";
        return 0;
    }
    double ans = st.peek();
    cout << "Result = " << ans << "\n";
    return 0;
}
