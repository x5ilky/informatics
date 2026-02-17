#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int sum = 0;
    vector<int> V(N+10); for (int i = 1; i <= N; i++) cin >> V[i];
    for (int i = 1; i <= N; i++) sum += V[i];

    vector<int> dp(N+10);
    for (int i = N; i >= 1; i--) {
        dp[i] = max(V[i]-dp[i+1], -(V[i]-dp[i+1]));
    }

    int ans = (sum+dp[1])/2;
    cout << ans << " " << sum-ans << endl;
}
