// A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
// every pass on the array, and place it at its correct position. The idea is to take also the maximum on
// every pass and place it at its correct position. So in every pass, we keep track of both maximum and
// minimum and array becomes sorted from both ends. Implement this logic.

#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }

        swap(a[left], a[minIndex]);

        if (maxIndex == left) maxIndex = minIndex;

        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {64, 25, 12, 22, 11, 90, 45};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    display(a, n);

    improvedSelectionSort(a, n);

    cout << "Sorted array: ";
    display(a, n);

    return 0;
}
