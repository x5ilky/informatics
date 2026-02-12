#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> locs(N);
    for (auto& i : locs) cin >> i;
    sort(locs.begin(), locs.end());
    int left = *min_element(locs.begin(), locs.end());
    int right = *max_element(locs.begin(), locs.end());
    int mid = L/2;
    int ans = 1e9+7;

    ans = min(ans, L-left);
    ans = min(ans, right);
    
    
    int r = 0;
    for (int mid = 1; mid < L; mid++) {
        while (locs[r] < mid && r < N-1) {
            r++;
        }
        // printf("mid %d, %d\n", mid, r);
        
        
        int ldiff = locs[r-1];
        int rdiff = L-locs[r];
        // printf("lr: %d %d\n", *lefthalfp, *righthalfp);
        
        ans = min(ans, ldiff*2 + rdiff);
        ans = min(ans, rdiff*2 + ldiff);
        // printf("max: %d: %d\n", mid, ans);
    }
    
    
    printf("%d\n", ans);
}