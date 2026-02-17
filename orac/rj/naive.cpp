#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int MAX_N = 200020;
int reaches[MAX_N];

signed main() {
    int N, Q; cin >> N >> Q;
    
    deque<int> dq;
    string s;
    cin >> s;
    int r = 1;
    for (auto& c : s) {
        if (c == 'L') {
            dq.push_back(r++);
        } else {
            reaches[dq.front()] = dq.back();
            dq.pop_front();
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;

        int dist = 0;

        int u = a;
        while (u < b) {
            u = reaches[u];
            dist++;
        }
        cout << dist << endl;
    }
}
