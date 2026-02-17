#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> S(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    for (int i = 1; i <= M; i++) {
        int p, v; cin >> p >> v;
        S[p] = v;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (S[i] < K) ans++;
    }
    cout << ans << endl;
}
