// Implement priority queues using heaps.

#include <iostream>
using namespace std;

class MaxPQ {
public:
    int arr[100];
    int size;

    MaxPQ() { size = 0; }

    void push(int val) {
        arr[size] = val;
        int i = size;
        size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i]) {
                int t = arr[parent];
                arr[parent] = arr[i];
                arr[i] = t;
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;

            if (l < size && arr[l] > arr[largest]) largest = l;
            if (r < size && arr[r] > arr[largest]) largest = r;

            if (largest != i) {
                int t = arr[i];
                arr[i] = arr[largest];
                arr[largest] = t;
                i = largest;
            } else break;
        }
    }

    void pop() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    bool empty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class MinPQ {
public:
    int arr[100];
    int size;

    MinPQ() { size = 0; }

    void push(int val) {
        arr[size] = val;
        int i = size;
        size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] > arr[i]) {
                int t = arr[parent];
                arr[parent] = arr[i];
                arr[i] = t;
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int smallest = i;

            if (l < size && arr[l] < arr[smallest]) smallest = l;
            if (r < size && arr[r] < arr[smallest]) smallest = r;

            if (smallest != i) {
                int t = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = t;
                i = smallest;
            } else break;
        }
    }

    void pop() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    bool empty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int data[] = {20, 5, 15, 22, 40, 3, 8};
    int n = 7;

    cout << "Max-Priority Queue Demo:\n";
    MaxPQ maxpq;
    for (int i = 0; i < n; i++) maxpq.push(data[i]);

    cout << "Heap internal array: ";
    maxpq.display();

    cout << "Pop elements (descending order): ";
    while (!maxpq.empty()) {
        cout << maxpq.top() << " ";
        maxpq.pop();
    }
    cout << "\n\n";

    cout << "Min-Priority Queue Demo:\n";
    MinPQ minpq;
    for (int i = 0; i < n; i++) minpq.push(data[i]);

    cout << "Heap internal array: ";
    minpq.display();

    cout << "Pop elements (ascending order): ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n\n";

    cout << "Interactive MaxPQ:\n";
    MaxPQ pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(7);

    cout << "Top: " << pq.top() << ", size: " << pq.size << endl;
    pq.pop();
    cout << "After pop, top: " << pq.top() << ", size: " << pq.size << endl;

    return 0;
}
