// 3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted
// Array
// (a) Linear time
// (b) Using binary search.


#include <bits/stdc++.h>
using namespace std;

int miss_num_linear(int a[], int m, int n){
    for(int i=0;i<m;i++){
        if(a[i]!=i+1) 
            return i+1;
    }
    return n;
}

int miss_num_bin(int a[], int m, int n){
    int l=0,r=m-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==mid+1) l=mid+1;
        else r=mid-1;
    }
    return l+1;
}

int main(){
    int a[]={1,2,3,5,6,7};
    int m=sizeof(a)/sizeof(a[0]);
    int n=7;
    cout<<miss_num_linear(a,m,n)<<endl;
    cout<<miss_num_bin(a,m,n)<<endl;
}
