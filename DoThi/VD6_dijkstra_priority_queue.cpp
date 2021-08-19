# include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
const int INF = 1e9;
typedef pair<int, int> Element;

struct Arc{
    int node;
    int w;
    Arc(int _node, int _w) {
      node = _node;
      w = _w;
    };
};
int n,m;
int s, t;
vector<Arc> A[N];
int d[N]; // d[v] is distance from s to v

void input() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
    cin >> s >> t;
}

void solve() {
    for(int v=1; v<=n; v++) d[v] = INF;
    priority_queue<Element, vector<Element>, greater<Element>> pq;
    d[s] = 0; pq.push(make_pair(d[s], s));
    while(!pq.empty()) {
        Element p = pq.top(); pq.pop();
        int u = p.second;
        if(u == t) break;
        for(int i=0; i<A[u].size(); i++) {
            Arc a = A[u][i];
            int v = a.node;
            int w = a.w;
            if(w + d[u] < d[v]) {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[t] << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}

/*
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

*/


















