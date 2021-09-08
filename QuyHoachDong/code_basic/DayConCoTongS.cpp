/*
    Bài toán tìm dãy con có tổng là S (biết trước). Nếu tìm được in ra YES, ngược lại in ra NO
    2
    5 6
    1 2 4 3 5
    10 15
    2 2 2 2 2 2 2 2 2 2
    ->
    YES
    NO
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s; // s < 1e5+1
        int a, dp[N] = {0};
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            cin >> a;
            dp[a] = 1; // vì ít nhất có 1 dãy con có tổng là a chính là dãy {a}
            for(int j=s; j>=a; j--) {
                if(dp[j-a]==1) dp[j] = 1;
            }

        }
        if(dp[s]==1) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
