#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

void readSparse(Element s[]) {
    cout << "Enter rows, cols, and number of non-zero elements: ";
    cin >> s[0].row >> s[0].col >> s[0].val;

    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= s[0].val; i++) {
        cin >> s[i].row >> s[i].col >> s[i].val;
    }
}

void printSparse(Element s[]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= s[0].val; i++) {
        cout << s[i].row << "\t" << s[i].col << "\t" << s[i].val << endl;
    }
}

void transpose(Element a[], Element b[]) {
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= a[0].val; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

void add(Element a[], Element b[], Element c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n";
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;
    int i = 1, j = 1, k = 1;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if ((a[i].row < b[j].row) || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k - 1;
}

void multiply(Element a[], Element b[], Element c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible\n";
        return;
    }

    Element bt[50];
    transpose(b, bt);

    int k = 1;
    c[0].row = a[0].row;
    c[0].col = b[0].col;

    for (int i = 1; i <= a[0].row; i++) {
        for (int j = 1; j <= b[0].col; j++) {
            int sum = 0;
            for (int p = 1; p <= a[0].val; p++) {
                if (a[p].row == i) {
                    for (int q = 1; q <= bt[0].val; q++) {
                        if (bt[q].row == j && bt[q].col == a[p].col) {
                            sum += a[p].val * bt[q].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                c[k].row = i;
                c[k].col = j;
                c[k].val = sum;
                k++;
            }
        }
    }
    c[0].val = k - 1;
}

int main() {
    Element a[50], b[50], c[50];

    cout << "--- Sparse Matrix A ---\n";
    readSparse(a);
    printSparse(a);

    cout << "\n--- Transpose of A ---\n";
    Element t[50];
    transpose(a, t);
    printSparse(t);

    cout << "\n--- Sparse Matrix B ---\n";
    readSparse(b);
    printSparse(b);

    cout << "\n--- Addition (A + B) ---\n";
    add(a, b, c);
    printSparse(c);

    cout << "\n--- Multiplication (A * B) ---\n";
    multiply(a, b, c);
    printSparse(c);
    return 0;
}
