#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int n, b;
int a[N], c[N];
int kg;
int gt;
int x[N];
int maxx;
int c_maxx;

void input() {
    cin >> n >> b;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
        c_maxx = max(c_maxx, c[i]);
    }
}

void solution() {
    if(kg <= b) {
        maxx = max(maxx, gt);
    }
}

void Try(int k) {
    for(int v=0; v<=1; v++) {
        if(true) {
            x[k] = v;
            kg += x[k] *a[k];
            gt += x[k] * c[k];
            if(k==n) solution();
            else {
                if(kg <= b && (n-k)*c_maxx + gt > maxx) {
                    Try(k+1);
                }
            }
            kg -= x[k] *a[k];
            gt -= x[k] * c[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    kg = 0;
    c_maxx = 0;
    gt = 0;
    maxx = 0;
    input();
    Try(1);
    cout << maxx << endl;
    return 0;
}
