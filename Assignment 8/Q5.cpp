// 5. Implement Heapsort (Increasing/Decreasing order)


#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i) {
    while (true) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest != i) {
            int t = a[i]; a[i] = a[largest]; a[largest] = t;
            i = largest;
        } else break;
    }
}

void heapifyMin(int a[], int n, int i) {
    while (true) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && a[l] < a[smallest]) smallest = l;
        if (r < n && a[r] < a[smallest]) smallest = r;
        if (smallest != i) {
            int t = a[i]; a[i] = a[smallest]; a[smallest] = t;
            i = smallest;
        } else break;
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapifyMax(a, n, i);
    for (int end = n - 1; end > 0; --end) {
        int t = a[0]; a[0] = a[end]; a[end] = t;
        heapifyMax(a, end, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapifyMin(a, n, i);
    for (int end = n - 1; end > 0; --end) {
        int t = a[0]; a[0] = a[end]; a[end] = t;

