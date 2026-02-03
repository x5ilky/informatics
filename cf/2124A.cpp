#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                printf("YES\n");

                printf("2\n%d %d\n",a[i], a[i+1]);

                goto next;
            }
        }
        printf("NO\n");
next:;
    }
    return 0;
}
