/*
    Tìm kiếm nhị phân: cho dãy tăng dần. tìm phần tử có giá trị key cho trước;
*/
#include <iostream>
using namespace std;

int bSearch(int x[], int start, int finish, int key) {
    if(start == finish) {
        if(x[start] == key)
            return start;
        else
            return -1;
    } else {
        int mid = (start+finish)/2;
        if(x[mid] == key)
            return mid;

        if(x[mid] > key)
            bSearch(x, start, mid, key);
        else
            bSearch(x, mid+1, finish, key);

    }
}

int main() {
    int x[] = {-2, 3, 4, 6, 7, 10, 22, 25, 44, 53, 69};
    int n = sizeof(x)/sizeof(int);
    int key = 69;
    int index = bSearch(x, 0, n-1, key);
    cout << index;
    return 0;

}
