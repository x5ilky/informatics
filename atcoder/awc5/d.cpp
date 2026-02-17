#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    int N, K; cin >> N >> K;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    int lo = 1, hi = 1e16;
    while (lo+1 < hi) {
        int mid = (lo+hi+1)/2;

        int v = 0, segs = 0;
        for (int i = 1; i <= N; i++) {
            if (v+A[i] <= mid) v += A[i];
            else {
                v = A[i]; segs++;
            }
        }
        segs++;
        if (segs <= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
}
