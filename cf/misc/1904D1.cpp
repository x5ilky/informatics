#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;

        for (int i = 0; i < n; i++) {
            bool s = false;
            for (int j = i; j < n; j++) {
                if (a[j] > b[i]) {
                    break;
                }
                if (b[j] < b[i]) break;
                if (a[j] == b[i]) {
                    s = true;
                    break;
                }
            }
            for (int j = i; j >= 0; j--) {
                if (a[j] > b[i]) {
                    break;
                }
                if (b[j] < b[i]) break;
                if (a[j] == b[i]) {
                    s = true;
                    break;
                }
            }
            if (!s) {
                printf("NO\n");
                goto next;
            }
        }
        printf("YES\n");
        next: ;
    }
}

