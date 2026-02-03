#include <bits/stdc++.h>

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;
        vector<int> l(m);
        for (auto& i : l) cin >> i;
        // for (int i = 0; i < m; i++) {
        //     printf("%d ", l[i]);
        // }
        // printf("\n");

        int p = l[0];
        for (int i = 0; i < m; i+=2) {
            p = max(p, l[i]);
        }
        cout << p << endl;
    }

    return 0;
}