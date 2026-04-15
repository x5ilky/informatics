#include <bits/stdc++.h>
#include <climits>

using namespace std;
#define int long long
#define printf(...)
signed main() {
    cout.tie(nullptr); cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int R, C, Q; cin >> R >> C >> Q;
    vector<vector<int>> grid(R+1, vector<int>(C+1, 0));
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
            cin >> grid[r][c];
    const int INF = LLONG_MAX>>2;
    vector<vector<int>> fastest_from_start(R+1, vector<int>(C+1, INF));
    vector<vector<int>> fastest_from_end(R+1, vector<int>(C+1, INF));

    fastest_from_start[1][1] = grid[1][1];
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (r > 1) {
                fastest_from_start[r][c] = 
                    fastest_from_start[r-1][c] + grid[r][c];
            }
            if (c > 1) {
                fastest_from_start[r][c] = 
                    min(fastest_from_start[r][c], fastest_from_start[r][c-1]+grid[r][c]);
            }
        }
    }
    fastest_from_end[R][C] = grid[R][C];
    for (int r = R; r >= 1; r--) {
        for (int c = C; c >= 1; c--) {
            if (r < R) {
                fastest_from_end[r][c] = 
                    fastest_from_end[r+1][c] + grid[r][c];
            }
            if (c < C) {
                fastest_from_end[r][c] = 
                    min(fastest_from_end[r][c], fastest_from_end[r][c+1]+grid[r][c]);
            }
        }
    }

    // for (int r = 1; r <= R; r++) {
    //     for (int c = 1; c <= C; c++) {
    //         printf("%lld ", fastest_from_start[r][c]);
    //     }
    //     printf("\n");
    // }
    // printf("-------\n");
    // for (int r = 1; r <= R; r++) {
    //     for (int c = 1; c <= C; c++) {
    //         printf("%lld ", fastest_from_end[r][c]);
    //     }
    //     printf("\n");
    // }
    vector<vector<int>> best_ne(R+2, vector<int>(C+2, INF));
    vector<vector<int>> best_sw(R+2, vector<int>(C+2, INF));

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            best_ne[r][c] = min(best_ne[r-1][c], best_ne[r][c+1]);
            best_ne[r][c] = min(best_ne[r][c], fastest_from_start[r][c] + fastest_from_end[r][c] - grid[r][c]);
        }
    }
    for (int r = R; r >= 1; r--) {
        for (int c = C; c >= 1; c--) {
            best_sw[r][c] = min(best_sw[r+1][c], best_sw[r][c-1]);
            best_sw[r][c] = min(best_sw[r][c], fastest_from_start[r][c] + fastest_from_end[r][c] - grid[r][c]);
        }
    }
    for (int q = 1; q <= Q; q++) {
        int r, c, t; cin >> r >> c >> t;
        
        int path_through_rc = fastest_from_start[r][c] + fastest_from_end[r][c] - grid[r][c];
        int target = t-path_through_rc;

        int ne = best_ne[r-1][c+1];
        int sw = best_sw[r+1][c-1];
        bool bypass = (ne == t && sw >= t) or
                      (ne >= t && sw == t);
             
        if (grid[r][c] + target < 0) {
            cout << (bypass ? "YES\n" : "NO\n");
        } else if (
            t <= best_ne[r-1][c+1] and
            t <= best_sw[r+1][c-1]) {
            cout << "YES\n";
        } else {
            cout << (bypass ? "YES\n" : "NO\n");
        }
    }
}
