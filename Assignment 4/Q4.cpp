// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
// b c Sample O/P: a -1 b b

#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s = "aabc";   // sample input
    queue<char> q;
    int freq[256] = {0};

    for (char c : s) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
