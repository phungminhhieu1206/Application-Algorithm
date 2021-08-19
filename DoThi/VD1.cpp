#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
struct Arc {
    int node;
    int w;
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

vector<Arc> A[N];
int n; // so dinh
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
    for(int i=1; i <= n; i++) {
        for(int j=0; j < Arr[i].size(); j++) {
            cout << "(" << i << ", " << Arr[i][j].node << ", " << Arr[i][j].w << ") ";
        }
        cout << endl;
    }
}

int main() {
    input();
    paint(A);
    return 0;
}

/* data_test
6 8
6 1 2
3 1 7
2 4 9
5 2 6
2 6 4
4 3 7
3 6 5
5 4 2

*/
