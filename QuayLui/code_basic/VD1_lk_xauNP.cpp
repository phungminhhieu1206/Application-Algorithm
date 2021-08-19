// liệt kê xâu nhị phân
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int x[N];
int n; // kích thước bộ output mong muốn

bool check(int v, int k) {
    // Trong bài này tất cả các giá trị 0, 1 gán cho mỗi xi đểu thỏa mãn nên luôn return true
    return true;
}

void solution() {
    for(int i=1; i<=n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int k) {
    for(int v=0; v<=1; v++) { // bộ giá trị thử cho mỗi x[i] là tập {0; 1}
        // Thử giá trị v_current cho x_k, nếu vượt qua điều kiện thì gán v cho x_k
        if(check(v, k)) {
            x[k] = v;
            if(k==n) solution();
            else Try(k+1);
        }

    }
}

int main() {
    n = 3;
    Try(1);
    return 0;
}
