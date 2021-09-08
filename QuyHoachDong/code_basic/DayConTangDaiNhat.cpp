/*
    Bài toán dãy con tăng dài nhất.
    6
    1 2 5 4 6 2
    -> 4 (dãy: 1 2 4 6)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a[1005], dp[1005], ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        dp[i]=1;
        for(int j=1; j<i; j++) {
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        cout << "dp_" << i << "= " << dp[i] << endl;
        ans=max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
