#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int NaN = 1e9+1;
int n, m;
int x[N];
int c[N][N];
bool visited[N];
int cost = 0;
int cost_min = NaN;
int c_min = NaN;
void input() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v >> c[u][v];
        if(c[u][v] < c_min) {
            c_min = c[u][v];
        }
    }
}

bool check(int v, int k) {
    if(visited[v] == true) return false;
    if(c[x[k-1]][v] == NaN) return false;
    return true;
}

void solution() {
    if(cost + c[x[n]][x[1]] < cost_min) cost_min = cost + c[x[n]][x[1]];
}

void Try(int k) {
    for(int v = 2; v<=n; v++) {
        if(check(v, k)) {
            x[k] = v;
            cost += c[x[k-1]][x[k]];
            visited[v] = true;
            if(k == n) solution();
            else {
                int g_min = cost + c_min;
                if(g_min < cost_min) {
                    Try(k+1);
                }
            }
            cost -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            c[i][j] = NaN;
        }
    }
    input();
    for(int v=1; v<=n; v++) visited[v] =  false;
    visited[1] = true;
    x[1] = 1;
    cost = 0;
    Try(2);
    cout << cost_min;
    return 0;
}
