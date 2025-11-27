// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
// inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
// count the number of inversions in an array.






#include <iostream>
using namespace std;

long long mergeAndCount(long long arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long long* L = new long long[n1];
    long long* R = new long long[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i); // all remaining in L[] are > R[j-1]
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;

    return invCount;
}

long long sortAndCount(long long arr[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += sortAndCount(arr, left, mid);
        invCount += sortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    long long arr[100];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long inversions = sortAndCount(arr, 0, n - 1);
    cout << "Number of inversions = " << inversions << endl;

    return 0;
}
