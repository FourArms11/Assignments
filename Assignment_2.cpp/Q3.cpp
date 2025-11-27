// 3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted
// Array
// (a) Linear time
// (b) Using binary search.


#include <iostream>
using namespace std;

int miss_num_linear(int a[], int m){
    int start = a[0];
    for(int i = 0; i < m; i++){
        if(a[i] != start + i)
            return start + i;
    }
    return a[0] + m;
}


int miss_num_bin(int a[], int m){
    int l=0, h=m-1;
    int start = a[0];  

    while(l<=h){
        int mid=(l+h)/2;
        if(a[mid] == start + mid)
            l = mid + 1;
        else
            h = mid - 1;
    }
    
    return start + l;
}


int main(){
    int a[]={12,13,15,16,17,18};
    int m=sizeof(a)/sizeof(int); //size of array
    int n=7; // total number of elements
    cout<<miss_num_linear(a,m)<<endl;
    cout<<miss_num_bin(a,m)<<endl;
}
