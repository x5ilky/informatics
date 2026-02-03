#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> D(n-1), P(n);
    for (auto& i : D) cin >> i;
    for (auto& i : P) cin >> i;
    P.push_back(0);
    
    vector<int> sum(n);
    sum[0] = D[0];
    for (int i = 0; i < n-1; i++) sum[i+1] = D[i+1] + sum[i];
    
    int l = 0, r = 0;
    while (r < n-1 && P[r] > P[l]) {
        r++;
    }
    int ans = 0, holding = 0;
    while (l < n-1) {
        if (l > 0) holding -= D[l-1];
        if (holding > 0) {
            while (l < n-1 && holding >= D[l]) {
                holding -= D[l];
                l++;
            }
        }
        if (!(l < n-1)) break;
        if (l < r) { // before

            ans += (D[l] - holding) * P[l];
            holding += D[l];
            l++; 
        } else if (l == r) { // this is the next cheapest
            r = l+1;
            while (r <= n && P[r] > P[l]) {
                r++;
            }
            int iWantToBuy = sum[r-1] - sum[l-1];
            int buy = min(iWantToBuy, k - holding);
            holding += buy;
            ans += buy * P[l];
            l++; 
        }
    }
    printf("%d\n", ans);

    return 0;
}