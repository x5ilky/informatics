#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
signed main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
 
    set<int> bs;
 
    for (int i = k; i < n; i++) {
        bs.insert(b[i-k]);
 
        if (
            (bs.find(b[i]-x) != bs.end()) || 
            (bs.find(b[i]+x) != bs.end()))
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
