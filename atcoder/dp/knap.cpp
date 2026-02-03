#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[110][100020];
int main() {
    int n, w;
    cin >> n >> w;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= w; k++) {
            if (weight[i-1] > k) dp[i][k] = dp[i-1][k];
            else dp[i][k] = max(
                dp[i-1][k-weight[i-1]] + value[i-1],
                dp[i-1][k]
            );
        } 
    }
    
    printf("%lld\n", dp[n][w]);
}