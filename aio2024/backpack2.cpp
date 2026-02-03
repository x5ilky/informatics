#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> D(n), P(n);
    D[0] = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> D[i+1];
    }
    for (auto& i : P) cin >> i;
    
    vector<int> ps(n+1);
    ps[0] = P[0];
    for (int i = 0; i < n; i++) ps[i+1] = D[i+1] + ps[i];
    
    vector<int> cheapest(n);
    bool best[n] = { 0 };
    fill(cheapest.begin(), cheapest.end(), n);
    int prev = P[0];
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] < P[l]) {
            best[i] = true;
            for (int k = l; k < i; k++) cheapest[k] = i;
            l = i;
        }
    }
    if (l == 0) {
        for (int i = 0; i < n; i++) {
            best[i] = true;
        }
    }

    int ans = 0, holding = 0;
    for (int i = 0; i < n-1; i++) {
        holding -= D[i];
        if (!best[i]) {
            int wantToBuy = D[i+1] - holding;
            ans += wantToBuy * P[i];
            holding += wantToBuy;
            // printf("not best[%d]: buying %d @ %d\n", i, wantToBuy, P[i]);
        } else {
            int wantToBuy = ps[cheapest[i]] - ps[i] - holding;
            int canBuy = min(wantToBuy, k - holding);
            ans += canBuy * P[i];
            holding += canBuy;
            // printf("best[%d]: buying %d @ %d\n", i, canBuy, P[i]);
        }
    }
    printf("%d\n", ans);
}