#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, b;
int a[N], c[N];
int tong;
int kg;
bool visited[N];
int x[N];
int maxx;
int c_maxx;
int a_min;

void input() {
    cin >> n >> b;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
        c_maxx = max(c_maxx, c[i]);
        a_min = min(a_min, a[i]);
    }
}

void solution() {
    maxx = max(tong, maxx);
}

bool check(int v, int k) {
    if(kg+a[v] > b) {
        solution();
        return false;
    }
    if(visited[v]) return false;
    return true;
}

void Try(int k) {
    for(int v=1; v<=n; v++) {
        if(check(v, k)){
            x[k] = v;
            tong += c[x[k]];
            visited[v] = true;
            kg += a[x[k]];
            if(k==n) solution();
            else {
                if(kg+a_min <= b && (n-k)*c_maxx + tong > maxx) {
                    Try(k+1);
                } else {
                    solution();
                }
            }
            tong -= c[x[k]];
            visited[v] = false;
            kg -= a[x[k]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    c_maxx = 0;
    a_min = 1e6+1;
    input();
    tong = 0;
    kg=0;
    maxx = 0;
    for(int v=1; v<=n; v++) visited[v] = false;
    Try(1);
    cout << maxx << endl;
    return 0;
}
