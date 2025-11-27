#include <iostream>
using namespace std;
void SWAP(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void CREATE(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "enter the element\n";
        cin >> p[i];
    }
}
void DISPLAY(int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
}
void INSERT(int *p, int *size, int num, int pos)
{
    *size++;
    for (int i = *size; i >= pos; i--)
    {
        p[i] = p[i - 1];
    }
    p[pos] = num;
}
void DELETE(int *p, int *size, int pos)
{
    for (int i = pos; i < *size; i++)
    {
        p[i] = p[i + 1];
    }
    *size--;
}
void LINEAR_SEARCH(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            cout << "element found at pos" << i;
            break;
        }
    }
}
void BINARY_SEARCH(int arr[], int size, int num)
{
    int start = arr[0], end = arr[size - 1], mid;
    while (mid != num)
    {
        mid = (start + end) / 2;
        if (num > mid)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << "element found at " << mid << endl;
}
void BUBBLE_SORT(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                SWAP(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
    int pos;
    int num;
    int size, a;
    bool flag = true;
    cout << "enter the number of elements" << endl;
    cin >> size;
    
    int arr[size];
    while (flag == true)
    {
        cout << "-----MENU-----" << endl;
        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.LINEAR_SEARCH" << endl;
        cout << "6.BINARY_SEARCH" << endl;
        cout << "7.BUBBLE_SORT" << endl;
        cout << "8.EXIT" << endl
             << endl;
        cout << "Enter your choice" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            CREATE(arr, size);
            break;
        case 2:
            DISPLAY(arr, size);
            break;
        case 3:
            cin >> num >> pos;
            INSERT(arr, &size, num, pos);
            break;
        case 4:
            cin >> pos;
            DELETE(arr, &size, pos);
            break;
        case 5:
            cin >> num;
            LINEAR_SEARCH(arr, size, num);
            cout << endl;
            break;
        case 6:
            cin >> num;
            BUBBLE_SORT(arr, size);
            BINARY_SEARCH(arr, size, num);
            break;
        case 7:
            BUBBLE_SORT(arr, size);
            cout << "sorted array is ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            break;
        case 8:
            cout << "STOP";
            flag = false;
            break;
        default:
            cout << "entered num is invalid ";
            break;
        }
    }
}