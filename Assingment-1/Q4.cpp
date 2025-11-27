// 4) Implement the logic to
// a. Reverse the elements of an array

#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < n / 2; i++) // middle element do not need to swap
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// b. Find the matrix multiplication
#include <iostream>
using namespace std;
int main()
{
    int n = 2;
    int arr1[n][n];
    int arr2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int arr3[n][n];

    // multiplication
    int i, j;
    int r, c;
    int ele;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            ele = 0;
            for (int k = 0; k < n; k++)
            {
                ele += arr1[k][j] * arr2[i][k];
            }
            arr3[i][j] = ele;
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}

// c. Find the Transpose of a Matrix
