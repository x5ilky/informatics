#include <bits/stdc++.h>
#include <vector>

using namespace std;

using pii = pair<int, int>;
int main() {
    int N, A, K; cin >> N >> A >> K;

    vector<pii> items(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> items[i].first >> items[i].second;
    }
    vector<vector<int>> dp(N+1, vector<int>(K+1));

    for (int i = 1; i <= N; i++) {
        for (int k = 0; k <= K; k++) {
            dp[i][k] = dp[i-1][k];
            if (k >= items[i].first)
                dp[i][k] = min(max(dp[i][k], dp[i-1][k-items[i].first]+items[i].second), K);
        }
    }

    int d = 1, p = A;
    while (true) {
        if (p >= K) {
            cout << d << endl;
            return 0;
        }
        p += dp[N][min(p, K)];
        d++;
    }
}
