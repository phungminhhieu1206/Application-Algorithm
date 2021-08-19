#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector<int> A[N]; // A[v] tap cac dinh ke vs dinh v
int n, m; // so dinh, so canh
int d[N]; // muc cua cac dinh duyet theo BFS
int ans;

void input() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = -1;
    }
}

bool BFS(int u) {
    queue<int> Q;
    Q.push(u); d[u] = 0;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i=0; i<A[x].size(); i++) {
            int v = A[x][i];
            if(d[v] == -1) {
                d[v] = d[x] + 1; Q.push(v);
            } else {
                if((d[v] + d[x]) % 2 == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}


void solve() {
    ans = 1;
    init();
    for(int v=1; v<=n; v++) {
        if(d[v]==-1) {
            bool ok = BFS(v);
            if(!ok) {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();

    return 0;
}

/*
8 7
1 2
1 6
4 3
8 6
4 7
5 3
7 5
*/
