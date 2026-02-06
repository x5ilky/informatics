#include <bits/stdc++.h>

using namespace std;

signed main() {
    int R, C, K; cin >> R >> C >> K;

    vector<vector<int>> cells(R+1, vector<int>(C+1, 0));
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> cells[r][c];
        }
    }

    using pii = pair<int, int>;
    vector<pii> rows(R+1), cols(C+1);

    for (int r = 1; r <= R; r++) {
        
    }
}
