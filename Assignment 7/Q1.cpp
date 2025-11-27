// Write a program to implement following sorting techniques:
// a. Selection Sort

#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(a[i], a[minIndex]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    display(a, n);
    selectionSort(a, n);
    cout << "Sorted array: ";
    display(a, n);
    return 0;
}



//  Insertion Sort

#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {29, 10, 14, 37, 13};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    display(a, n);

    insertionSort(a, n);

    cout << "Sorted array: ";
    display(a, n);
    return 0;
}


// Bubble Sort

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {45, 12, 8, 33, 22};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    display(a, n);

    bubbleSort(a, n);

    cout << "Sorted array: ";
    display(a, n);

    return 0;
}


// Merge Sort

#include <iostream>
using namespace std;

void mergeArr(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[100], right[100];
    for (int i = 0; i < n1; i++) left[i] = a[l + i];
    for (int j = 0; j < n2; j++) right[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArr(a, l, m, r);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    display(a, n);

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    display(a, n);

    return 0;
}

// Quick Sort

#include <iostream>
using namespace std;

int partitionArr(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partitionArr(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {50, 23, 9, 18, 61, 32};
    int n = sizeof(a) / sizeof(int);

    cout << "prev array: ";
    display(a, n);

    quickSort(a, 0, n - 1);

    cout << "after sort array: ";
    display(a, n);

    return 0;
}
