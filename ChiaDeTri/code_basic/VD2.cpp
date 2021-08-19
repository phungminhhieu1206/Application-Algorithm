/*
    Tính x^N mod 10^9+7;
*/
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const ull P = 1e9+7;

ull exp(ull x, ull N) {
    x = x%P;
    if(N==1) return x;
    ull t = exp(x, N/2);
    t = (t*t) % P;
    if(N%2 == 1) {
        t = (t*x) %P;
    }
    return t;
}

int main() {
    ull x, N;
    cin >> x >> N;
    cout << exp(x, N);
    return 0;
}
