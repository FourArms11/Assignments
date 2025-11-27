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

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[],int l , int h){
    int pivot = A[l];
    int i = l, j = h;
    do {
        do { i++; } while(A[i] <= pivot);
        do { j--; } while(A[j] > pivot);
        if(i < j){
            swap(&A[i], &A[j]);
        }
    } while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int l , int h){
    int j;
    if(l < h){
        j = partition(A, l, h);
        quick_sort(A, l, j);
        quick_sort(A, j+1, h);
    }
}

int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3,INT32_MAX};
    int n = 11; // includes sentinel
    
    quick_sort(A, 0, n-1);

    for(int i = 0; i < n-1; i++){ // exclude sentinel
        cout << " " << A[i] << " ";
    }
    cout << endl;
    return 0;
}
