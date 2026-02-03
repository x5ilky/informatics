#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int N; cin >> N;vector<int> V(N+1); for (int i = 1; i <= N; i++) cin >> V[i];

    vector<int> left(N+1);
    left[1] = V[1];
    for (int i = 2; i <= N; i++) {
        left[i] = min(V[i], left[i-1]+1);
    }
    vector<int> right(N+1);
    right[N] = left[N];
    for (int i = N-1; i >= 1; i--) {
        right[i] = min(left[i], right[i+1]+1);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += V[i] - right[i];
    }
    
    cout << ans << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}
