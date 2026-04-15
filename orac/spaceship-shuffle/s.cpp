#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    long long ans = 0;
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
    }
    
    int need = 0;
    int have = 0;
    int rem = 0;
    while (need < n) {
        while (diff[have] >= 0 && have < n) { // find first more
            have++;
        }
        if (have >= n) break;
        rem = -diff[have];
        while (rem > 0) {
            if (diff[need] > 0) {
                int max_i_can_give = min(rem, diff[need]);
                ans += (need - have) * max_i_can_give;
                rem -= max_i_can_give;
                diff[need] -= max_i_can_give;
            } else {
                need++;
            }
        }
        have++;
    }
    printf("%lld\n", ans);
}