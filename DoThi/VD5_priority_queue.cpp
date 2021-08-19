#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Element;

int main() {
    priority_queue<Element, vector<Element>, greater<Element>> pq;
    pq.push(make_pair(2, 1)); // first is key, second is value
    pq.push(make_pair(1, 2));
    pq.push(make_pair(10, 3));
    pq.push(make_pair(6, 4));
    while(!pq.empty()) {
        Element e = pq.top(); pq.pop();
        cout << "pop (" << e.first << "," << e.second << ")" << endl;
    }
}
