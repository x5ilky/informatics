#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == 0) s[i] = s[1];
            else s[i] = s[i-1];
        }
    }
    int prev = s[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == prev) ans++;
        else prev = s[i];
    }
    
    printf("%d\n", ans);

    return 0;
}