#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int N, K; cin >> N >> K;
    vector<int> V(N+2);
    vector<int> B(N+2);
    for (int i = 1; i <= N; i++) cin >> V[i];
    for (int i = 1; i <= N; i++) B[i] = V[i];

    for (int i = 1; i <= N; i++)
        B[i] = max(V[i], B[i-1] - K);
    for (int i = N; i >= 1; i--)
        B[i] = max(B[i], B[i+1] - K);

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += B[i] - V[i];
    cout << ans << endl;
} 
