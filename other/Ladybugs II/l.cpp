#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> P(n), D(q);
    vector<int> ans;

    for (auto& i : P) cin >> i;
    for (auto& i : D) cin >> i;
    
    for (auto start : D) {
        if (start <= P[0]) { // left
            int a = P[k-1] - start;
            ans.push_back(a);
        } else if (start >= P[n-1]) { // right
            int a = start - P[n-k];
            ans.push_back(a);
        } else { // middle
            int ahead = lower_bound(P.begin(), P.end(), start) - P.begin();
            int left = start - P[0];
            int right = P[n-1] - start;
            
            int take = ahead;
            int r = P[ahead + k - take - 1];
            int a = left * 2 + r;
            
            int take2 = n - ahead;
            int l = start - P[ahead - (k - take2)];
            int a2 = right * 2 + r;
            ans.push_back(min(a, a2));
        }
    }
    
    for (auto i : ans) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}