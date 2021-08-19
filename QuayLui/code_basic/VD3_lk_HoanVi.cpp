// liệt kê hoán vị của 1,2,3,4,...,n
// nhận thấy cần điều kiện: mỗi số xuất hiện đúng 1 lần trong 1 hoán vị -> kỹ thuật đánh dấu (đã thăm)
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n;
int cnt; // đếm số solution tìm được
int x[N];
bool visited[N];

void solution() {
    cnt++;
    cout << cnt << ": ";
    for(int i=1; i<=n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
// Nếu k=1 rõ ràng chưa có điều kiện gì
// Nếu k>1 đảm bảo x_k sẽ khác giá trị các x_1, x_2, ..., x_(k-1)
    // Khi đó cần kiểm tra visited[v] ?
    return !visited[v];
}

void Try(int k) { // x_k
    for(int v=1; v<=n; v++) { // try v to x_k
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if(k == n) solution();
            else Try(k+1);
            visited[v] = false;        }
    }
}

int main() {
    n = 3;
    cnt=0;
    for(int v=1; v<=n; v++) visited[v] = false;
    Try(1);
    return 0;
}
