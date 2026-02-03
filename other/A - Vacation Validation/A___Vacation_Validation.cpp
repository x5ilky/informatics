#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    string s;
    cin >> s;
    
    for (int i = l-1; i < r; i++) {
        if (s[i] != 'o') {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}