#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
 
#define int long long
signed main() {
    int N, M; cin >> N >> M;
    
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    vector<int> earliest(N+1, -1); 
 
    using pii = pair<int, int>;
    vector<pii> ranges;
    for (int i = 1; i <= M; i++) {
        int l, r; cin >> l >> r;
        ranges.emplace_back(l, r);
    }
    sort(ranges.begin(), ranges.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int it = 0;
    for (int i = 1; i <= N; i++) {
        while (it < M and ranges[it].first <= i) pq.push(ranges[it++]);

        while (!pq.empty() && pq.top().second < i) pq.pop();

        if (!pq.empty()) earliest[i] = pq.top().first;
    }
    int ans = 0;
    vector<int> dp(N+1, 0);
    for (int i = 1; i <= N; i++) {
        if (earliest[i] == -1) {
            dp[i] = dp[i-1]+A[i];
        } else {
            dp[i] = max(dp[i-1], dp[earliest[i]-1]+A[i]);
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}
