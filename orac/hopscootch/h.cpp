#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int N, K; cin >> N >> K;

    vector<int> extras(K+1); for (int i = 1; i <= K; i++) cin >> extras[i];

    vector<vector<int>> values(N);
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= i; k++) {
            int v; cin >> v;
            values[i].push_back(v);
        }
    }

    vector<vector<int>> dp(N, vector(N, 0));
    for (int m = 0; m <= K; m++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                
            }
        }
    }
}
