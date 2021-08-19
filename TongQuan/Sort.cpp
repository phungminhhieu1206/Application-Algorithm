#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;

void paint_array(int arr[]) {
    for (int i=0; i<n; i++) {
        if(i==n-1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << ", ";
    }
}
int main() {
    n = 6;
    for(int i=0; i<n; i++) {
        a[i] = 10-i;
    }
    paint_array(a);
    sort(a, a+n);
    paint_array(a);
}
