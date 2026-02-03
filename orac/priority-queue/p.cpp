#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    int N; cin >> N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        if (c == 0) {
            cout << pq.top() << endl;
            pq.pop();
        } else {
            pq.push(c);
        }
    }
}
