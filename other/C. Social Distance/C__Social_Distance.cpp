#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;

    vector<int> parts;
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            parts.push_back(len);
            len = 0;
            continue;
        }
        len++;
    }
    parts.push_back(len);
    
    for (int i = 0; i < parts.size(); i++) {
        int len = parts[i];
        if (i != 0) len -= k;
        if (i != parts.size()-1) len -= k;
        ans += (len + k) / (k+1);
    }
    
    printf("%d\n", ans);
}

signed main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();

    return 0;
}