#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define IINF 0xfffffff

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    string s;
    cin >> s;

    int l = 0;
    int r = n-1;
    for (char c : s) {
        if (c == 'L') l++;
        if (c == 'R') r--;
    }
    
    vector<int> solution;
    int M = 1;
    reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == 'L') {
            M *= a[--l];
            M %= m;
            solution.push_back(M);
        } 
        if (c == 'R') {
            M *= a[++r];
            M %= m;
            solution.push_back(M);
        } 
    }
    reverse(solution.begin(), solution.end());
    for (auto c : solution) {
        printf("%d ", c);
    }
    printf("\n");
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}