#include <bits/stdc++.h>

using namespace std;

int a[100020], p[100020];
signed main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) {
        if (i == 0) a[i] = 0;
        else a[i] = 200000;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            a[i] = min(abs(p[i] - p[i-j]) + a[i-j], a[i]);
        }
    }
    printf("%d\n", a[n-1]);

    return 0;
}