#include <bits/stdc++.h>

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int S; cin >> S;
        string s;
        cin >> s;
        char prev = '0';
        int ans = 0;
        for (char& c : s) {
            if (c != prev) {
                prev = c;
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}