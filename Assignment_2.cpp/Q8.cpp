// 8) Write a program to count the total number of distinct elements in an array of
// length n





#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // Check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct)
            distinctCount++;
    }

    cout << "Total number of distinct elements = " << distinctCount << endl;

    return 0;
}
