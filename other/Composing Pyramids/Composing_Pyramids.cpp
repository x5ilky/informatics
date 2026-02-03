#include <bits/stdc++.h>

using namespace std;

#define MAXN 100002

signed main() {
    int n;
    cin >> n;

    int P[MAXN], lowest_chain[MAXN], left_chain[MAXN], right_chain[MAXN];
    for (int i = 0; i < n; i++) cin >> P[i];

    for (int i = 0; i < n; i++) {
        if (lowest_chain[P[i]-1]) {
            left_chain[i] = lowest_chain[P[i]] = lowest_chain[P[i]-1];
        } else {
            left_chain[i] = lowest_chain[P[i]] = P[i];
        }
        // printf("left_chain[%d] = %d\n", i, left_chain[i]);
    }
    for (int i = 0; i < n; i++) lowest_chain[i] = 0;
    for (int i = n-1; i >= 0; i--) {
        if (lowest_chain[P[i]-1]) {
            right_chain[i] = lowest_chain[P[i]] = lowest_chain[P[i]-1];
        } else {
            right_chain[i] = lowest_chain[P[i]] = P[i];
        }
        // printf("right_chain[%d] = %d\n", i, right_chain[i]);
    }
   
    int ans = n;
    for (int i = 0; i < n; i++) {
        int peak = P[i];        
        int mini = max(left_chain[i], right_chain[i]);
        int size = (peak - mini) * 2 + 1;
        ans = min(ans, n - size);
    }
    
    printf("%d\n", ans);
    

    return 0;
}