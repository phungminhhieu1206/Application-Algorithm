#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int x[N];
int n;
int F[N];
int ans;
int start_index[N];
int end_point;

void input() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> x[i];
    }
}

void solve() {
    F[1] = x[1];
    start_index[1] = 1;
    ans = F[1];
    end_point = 1;

    for(int i=2; i<=n; i++) {
        if(F[i-1]>0) {
            F[i] = F[i-1]+x[i];
            start_index[i] = start_index[i-1];
        } else {
            F[i] = x[i];
            start_index[i] = i;
        }
        if(F[i] > ans) {
            ans = F[i];
            end_point = i;
        }
    }
    cout << "max = " << ans << endl;
    cout << "from index: " << start_index[end_point] << " to index: " << end_point << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;


}
