#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, C; cin >> N >> C;
    vector<vector<bool>> wall(N+1, vector<bool>(N+1, false));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) 
        {
            string s; cin >> s;
            wall[i][j] = s == "#";
        }
    }

    vector<vector<bool>> destroyable(N+2, vector<bool>(N+2, true));
    vector<vector<bool>> reachable(N+2, vector<bool>(N+2, false));

    for (int i = 1; i <= N; i++) destroyable[N+1][i] = true;
    reachable[N][C] = true;
    for (int row = N; row >= 1; row--) {
        for (int col = 1; col <= N; col++) {
            int can_reach = reachable[row+1][col];
            if (col > 1) can_reach |= reachable[row+1][col-1];
            if (col < N) can_reach |= reachable[row+1][col+1];
            if (row == N and col == C) can_reach = true;
            
            if (wall[row][col]) {
                if (destroyable[row+1][col])
                    destroyable[row][col] = can_reach;
            } else destroyable[row][col] = destroyable[row+1][col];
        }
        for (int col = 1; col <= N; col++) {
            int can_reach = reachable[row+1][col];
            if (col > 1) can_reach |= reachable[row+1][col-1];
            if (col < N) can_reach |= reachable[row+1][col+1];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", (int)destroyable[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T; cin >> T; 
    while (T--) solve();
}
