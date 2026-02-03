#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int MAX_N = 200020;
const int L2 = 19;
int lift[MAX_N][L2];

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
            lift[dq.front()][0] = dq.back();
            dq.pop_front();
        }
    }

    for (int k = 1; k < L2; k++) {
        for (int i = 1; i <= N; i++) {
            lift[i][k] = lift[lift[i][k-1]][k-1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;

        int dist = 0;

        int u = a;
        for (int k = L2-1; k >= 0; k--) {
            if (lift[u][k] < b) {
                dist += 1 << k;
                u = lift[u][k]; 
            }
        }
        cout << dist+1 << endl;
    }
}
