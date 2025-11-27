// Write a program to implement a stack using (a) Two queues and (b) One Queue.

#include <iostream>
#include <queue>
using namespace std;

// Stack using two queues (push O(n), pop O(1))
class StackTwoQueues {
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() const {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool empty() const { return q1.empty(); }
};

// Stack using one queue (push O(n), pop O(1))
class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() const {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() const { return q.empty(); }
};

int main() {
    cout << "Stack implemented with two queues:\n";
    StackTwoQueues s2;
    s2.push(10); s2.push(20); s2.push(30);
    cout << "Top: " << s2.top() << "\n"; // 30
    s2.pop();
    cout << "Top after pop: " << s2.top() << "\n"; // 20
    s2.push(40);
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << "\n\n";

    cout << "Stack implemented with one queue:\n";
    StackOneQueue s1;
    s1.push(10); s1.push(20); s1.push(30);
    cout << "Top: " << s1.top() << "\n"; // 30
    s1.pop();
    cout << "Top after pop: " << s1.top() << "\n"; // 20
    s1.push(40);
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";

    return 0;
}
