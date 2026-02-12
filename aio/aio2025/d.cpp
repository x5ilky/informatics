#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main() {
    int N;
    cin >> N;
    vector<pii> D;

    int prev = -1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        if (k == prev) {
            count++;
        } else {
            if (prev != -1)
                D.push_back({prev, count});
            count = 1;
            prev = k;
        }
    }
    D.push_back({prev, count});
    int dd = D.size();
    
    int biggest = prev;
    int ans = 0;

    ans += biggest;
    int l = biggest, r = dd-1;
    while (l > 0 && r >= 0) {
        while (l >= D[r].first && D[r].second > 0) {
            l--;
            D[r].second--;
        }
        r--;
    }
    
    // for (int i = 0; i < dd; i++) {
    //     printf("%d: %d\n", D[i].first, D[i].second);
    // }
    
    l = biggest, r = dd-1;
    while (l > 0 && r >= 0) {
        if (D[r].second <= 0) {
            r--;
            continue;
        }
        l--;
        if (l >= D[r].first) {
            D[r].second--;
        } else {
            l += 2;
            ans++;
            D[r].second--;
        }
    }
    // printf("-----\n");
    // for (int i = 0; i < dd; i++) {
    //     printf("%d: %d\n", D[i].first, D[i].second);
    // }
    // printf("-----\n");
    
    printf("%d\n", ans);

    return 0;
}