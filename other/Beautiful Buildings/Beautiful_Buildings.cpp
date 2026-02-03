#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& i : h) cin >> i;

    int diffs[n];
    int total_diff = 0;
    for (int i = 1; i < n; i++) {
        total_diff += diffs[i] = abs(h[i] - h[i-1]);
    }

    int best = total_diff;
    
    for (int i = 2; i < n; i++) {
        int middle = (h[i-2] + h[i]) / 2;
        int diff = abs(h[i-2] - h[i]);
        int now = total_diff - diffs[i-1] - diffs[i] + diff;
        // printf("now: %d, change to %d\n", now, middle);
        best = min(best, now);
    }
    
    {
        int now = total_diff - diffs[1];
        best = min(best, now);
        // printf("LEFT: %d\n", now);
    }
    {
        int now = total_diff - diffs[n-1];
        best = min(best, now);
        // printf("RIGHT: %d\n", now);
    }
    printf("%d\n", best);
    

    return 0;
}