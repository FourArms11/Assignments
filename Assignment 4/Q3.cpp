// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // sample input
    int a[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
        q.push(a[i]);

    interleave(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

