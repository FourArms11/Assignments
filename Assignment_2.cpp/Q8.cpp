// 8) Write a program to count the total number of distinct elements in an array of
// length n




#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for(int i=0;i<n;i++) cin >> a[i];

    int d = 0;

    for(int i=0;i<n;i++){
        bool ok = true;
        for(int j=0;j<i;j++){
            if(a[i] == a[j]){
                ok = false;
                break;
            }
        }
        if(ok) d++;
    }

    cout << d;
    return 0;
}
