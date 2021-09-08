#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t;
int F[N][N] = {0};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        memset(F, 0, sizeof(F));
        int ans = -1;
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    F[i][j] = F[i-1][j-1]+1;
                } else {
                    F[i][j] = max(F[i-1][j], F[i][j-1]);
                }
                ans = max(ans, F[i][j]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
/*
Input:
2
AGGTAB
GXTXAYB
AA
BB
*/
/*
Output:
4
0
*/
