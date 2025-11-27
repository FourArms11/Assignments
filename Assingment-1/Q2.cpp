// Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should contain the unique elements.

#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {1, 1, 3, 4, 6, 7, 3, 4};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && j != i)
            {
                for (int k = j; k < n; k++)  //then delete that element
                {
                    arr[k] = arr[k + 1];
                }
                n--; 
            }
        }
    }
    cout<<"after deletion:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}