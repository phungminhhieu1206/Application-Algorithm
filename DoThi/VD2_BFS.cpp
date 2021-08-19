#include <bits/stdc++.h>
using namespace std;

struct Arc {
    int node;
    int w;
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

const int N = 1e5;
vector<Arc> A[N];
int n;

void input() {
    int m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
}

void paint(vector<Arc> Arr[]) {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<Arr[i].size(); j++) {
            cout << "(" << i << "," << Arr[i][j].node << "," << Arr[i][j].w << ") ";
        }
        cout << endl;
    }
}

bool visited[N] = {false};
int dem = 0;

void BFS(int u) {
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        // tham v
        cout << "Dinh " << dem++ << ": " << v << endl;
        for(int j=0; j < A[v].size(); j++) {
            if(!visited[A[v][j].node]) {
                Q.push(A[v][j].node);
                visited[A[v][j].node] = true;
            }
        }
    }
}

void BFS_Graph(int dinhs, vector<Arc> Arr[]) {
    for (int i=1; i <= dinhs; i++) visited[i] = false;
    for(int i=1; i<=dinhs; i++) {
        if(!visited[i]) {
            BFS(i);
        }
    }
}

void DFS(int u, vector<Arc> Arr[]) {

}


int main() {
    input();
    paint(A);
//    BFS(1);
    BFS_Graph(n, A);
    return 0;
}
