// Implement the binary search algorithm regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int *sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

void binary_search(int a[], int n, int value)
{
    int *ptr = sort(a, n);
    int start = 0;
    int end = n - 1;
    bool found = false;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (ptr[mid] == value)
        {
            cout << "Element found at position: " << mid << endl;
            found = true;
            break;
        }
        else if (value > ptr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    if (!found)
        cout << "element not found" << endl;
}
int main()
{
    int n = 5;
    int val;
    cout << "enter the value to search: ";
    cin >> val;
    int arr[n] = {5, 3, 2, 4, 1};
    binary_search(arr, n, val);
}
