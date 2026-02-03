#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("budgin.txt", "r", stdin);
    freopen("budgout.txt", "w", stdout);
    vector<int> v;
    while (true) {
        int c; cin >> c;
        if (c == -1) break;
        v.push_back(c);
    }

    if (v.empty()) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp;
    for (auto &h : v) {
        auto it = upper_bound(dp.begin(), dp.end(), h, greater<int>());
        if (it == dp.end())
            dp.push_back(h);
        else
            *it = h;
    }
    cout << dp.size() << endl;
}
