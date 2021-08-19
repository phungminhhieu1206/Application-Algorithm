// Cho M, n nguyên dương
// Cho phương trình x_1+x_2+x_3+...+x_n = M
// Tìm các bộ x_1->x_n nguyên dương thỏa mãn
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, M;
int x[N];
int t;
int cnt;

void solution() {
    cnt++;
    cout << cnt << ": ";
    for(int i=1; i<=n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
    // Đang xét giá trị v cho x_k
    if(k==n && v != M-t) return false;
    return true;

}

void Try(int k) {
    int maxValue = M-t-n+k;
    for(int v = 1; v<=maxValue; v++) {
        if(check(v, k)) {
            x[k] = v;
            t = t+v;
            if(k == n) solution();
            else Try(k+1);
            t = t-v;
        }
    }
}

int main() {
    n = 5;
    M = 10;
    t = 0;
    cnt = 0;
    Try(1);
    return 0;
}
