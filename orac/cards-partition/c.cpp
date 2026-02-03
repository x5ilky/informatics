#include <bits/stdc++.h>

using namespace std;

#define int long long
#define printf(...)
void solve() {
    int N, K; cin >> N >> K;
    vector<int> count;
    int sm = 0;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        sm += a;
        count.push_back(a);
    }
    sort(count.rbegin(), count.rend());

    int over = 0;
    int prog = sm;
    // for (int i = N-1; i >= 0; i--) {
    //     prog += min(count[i], mxPairs);
    //     if (count[i] > sm) {
    //         int over_by = count[i]-mxPairs;
    //         over += over_by;
    //         mxOver = max(mxOver, over_by);
    //     }
    // }

    int ans = 0;
    int it = 0;
    for (int m = 1; m <= N; m++) {
        int mxPairs = sm / m;

        while (it < N and count[it] > mxPairs) {
            over += count[it] - mxPairs;
            prog -= count[it] - mxPairs;
            it++;
        }
        printf("mxPairs: %lld\n", mxPairs);

        int currentOver = over;
        int mxOver = max(count[0] - mxPairs, 0LL);
        if (prog > mxPairs*m) {
            int over_by = prog-mxPairs*m;
            int need_k = mxOver*m - over;
            if (over_by > need_k) {
                mxOver = max(mxOver, (over+over_by+m-1)/m);
            }
            currentOver += over_by;
        }

        printf("mxOver: %lld, m: %lld, currentOver: %lld\n", mxOver, m, currentOver);
        int need_k = mxOver*m - currentOver;
        if (prog < mxPairs*m) {
            need_k += mxPairs*m-prog;
        }
        if (need_k <= K) {
            ans = max(ans, m);
        } 
        int nextMxPairs = sm / (m+1);
        over += it*(mxPairs-nextMxPairs);
        prog -= it*(mxPairs-nextMxPairs);
    }
    cout << ans << endl;
}
signed main() {
     int T; cin >> T;
     while (T--) solve();
}
