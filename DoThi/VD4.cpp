#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n,m;
int d[N] = {0};
vector<int> A[N];
vector<int> L;


void input() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        d[v] += 1;
    }
}

vector<int> topo(int k) {
    queue<int> Q;
    for (int v=1; v<=k; v++) {
        if(d[v] == 0) Q.push(v);
    }
    vector<int> ds;
    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        ds.push_back(v);
        for(int i=0; i<A[v].size(); i++) {
            int x = A[v][i];
            d[x] = d[x] - 1;
            if(d[x] == 0) {
                Q.push(x);
            }
        }
    }
    return ds;
}

int main() {
    input();
    L = topo(n);
    if(L.size() < n) {
        cout << "Do thi co chu trinh !" << endl;
    } else {
        for(int i=0; i<L.size(); i++) {
            cout << L[i] << ", ";
        }
        cout << endl;
    }

    return 0;
}

/*
6 10
1 3
2 1
2 3
2 5
2 6
4 1
4 5
5 1
6 4
6 5

*/
