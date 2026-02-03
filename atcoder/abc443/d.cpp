#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

#define int long long
using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> V(N+1); for (int i = 1; i <= N; i++) cin >> V[i];
    vector<int> orig = V;
    
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= N; i++) 
        q.push({V[i], i});

    while (!q.empty()) {
        auto [v, top] = q.top();
        q.pop();
        if (v != V[top]) continue;
        if (top > 1) {
            if (V[top-1] - V[top] > 1) {
                q.push({V[top]+1, top-1});
                V[top-1] = V[top]+1;
            }
        }
        if (top < N) {
            if (V[top+1] - V[top] > 1) {
                q.push({V[top]+1, top+1});
                V[top+1] = V[top]+1;
            }
        }
        // printf("d: %d, %d\n", v, top);
        // for (int i = 1; i <= N; i++) {
        //     printf("%d ", V[i]);
        // }
        // printf("\n");
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += orig[i] - V[i];
    }

    cout << ans << endl;
}

signed main() {
    int T; cin >> T;
    while (T--) solve();
}
