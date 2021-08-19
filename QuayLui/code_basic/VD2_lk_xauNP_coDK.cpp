// liệt kê xâu nhị phân trong đó 2 bits 1 không đứng cạnh nhau
// thêm điều kiện => chỉnh sửa hàm check(v, k)
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int x[N];
int n; // kích thước bộ output mong muốn

bool check(int v, int k) {
    // Nếu k=1, thì return true;
    // Nếu k>1, tức đã xét được giá trị cho x_(k-1) rồi, khi đó ta cần so sánh v (giá trị định gán cho x_k) với x_(k-1)
        // Nếu x_(k-1) = 0 return true;
        // Nếu x_(k-1) = 1 và v = 1 thì return false;
    if (k>1 && x[k-1] == 1 && v ==1) return false;
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
    n = 5;
    Try(1);
    return 0;
}
