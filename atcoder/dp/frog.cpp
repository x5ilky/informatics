#include <bits/stdc++.h>

using namespace std;

int a[100020], p[100020];
signed main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) {
        if (i == 0) a[i] = 0;
        else if (i == 1) a[i] = abs(p[i] - p[0]);
        else {
            a[i] = min(
                abs(p[i] - p[i-2]) + a[i-2], 
                abs(p[i] - p[i-1]) + a[i-1]);
        }
    }
    printf("%d\n", a[n-1]);

    return 0;
}