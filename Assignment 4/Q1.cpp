// Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

class Queue {
public:
    int size, front, rear;
    int *arr;

    Queue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = x;
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter queue size: ";
    cin >> size;

    Queue q(size);

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check Empty\n";
        cout << "4. Check Full\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 5:
                q.peek();
                break;
            case 6:
                q.display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}

