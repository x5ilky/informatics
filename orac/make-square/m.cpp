#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
    int R, C, K; cin >> R >> C >> K;

    vector<vector<int>> cells(R+2, vector<int>(C+2, 0));
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> cells[r][c];
        }
    }

    using pii = pair<int, int>;
    vector<set<pii>> rows(R+1), cols(C+1);


    for (int r = 0; r <= R-1; r++) {
        int cnt = 0, prev = 0;
        for (int c = 0; c <= C; c++) {
            bool all_same = (
                cells[r][c] == cells[r][c] &&
                cells[r][c] == cells[r+1][c] &&
                cells[r][c] == cells[r][c+1] &&
                cells[r][c] == cells[r+1][c+1]
            );
            if (all_same) {
                cnt = 0;
            } else if (cells[r+1][c+1] != prev) {
                prev = cells[r+1][c+1];
                rows[r].insert({c, cnt});
                
                if (cells[r][c+1] == prev) {
                    cnt = 0;
                } else {
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
    }
    {
        int r = R;
        int cnt = 0, prev = 0;
        for (int c = 0; c <= C; c++) {
            if (cells[r][c+1] != prev) {
                prev = cells[r][c+1];
                rows[r].insert({c, cnt});
            }
            cnt++;
        }
    }
    for (int c = 0; c <= C; c++) {
        int cnt = 0, prev = 0;
        for (int r = 0; r <= R; r++) {
            bool all_same = (
                cells[r][c] == cells[r][c] &&
                cells[r][c] == cells[r+1][c] &&
                cells[r][c] == cells[r][c+1] &&
                cells[r][c] == cells[r+1][c+1]
            );
            if (all_same) {
                cnt = 0;
            } else if (cells[r+1][c] != prev) {
                prev = cells[r+1][c];
                cols[c].insert({r, cnt});
                
                if (cells[r+1][c+1] == prev) {
                    cnt = 0;
                } else {
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
    }
    {
        int c = 0;
        int cnt = 0, prev = 0;
        for (int r = 0; r <= R; r++) {
            if (cells[r+1][c+1] != prev) {
                prev = cells[r+1][c+1];
                cols[c].insert({r, cnt});
            }
            cnt++;
        }
    }

    printf("COLS\n");
    for (int c = 0; c <= C; c++) {
        printf("%d: ", c);
        for (auto& [y, l] : cols[c]) {
            printf("%d,%d ", y, l);
        }
        printf("\n");
    }
    printf("ROWS\n");
    for (int r = 0; r <= R; r++) {
        printf("%d: ", r);
        for (auto& [y, l] : rows[r]) {
            printf("%d,%d ", y, l);
        }
        printf("\n");
    }
    for (int r = 0; r <= R; r++) {
        for (auto& [x, len] : rows[r]) {
            printf("{%d, %d, %d}\n", x, r, len);
            if (len <= 0 or x >= C) continue;

            auto colp = cols[x-len].lower_bound({r+len, 0});
            if (colp == cols[x-len].end()) continue;
            if (colp->first != r+len) continue;
                
             

            if (auto col = cols[x-len].find({r+len, len}); col != cols[x-len].end()) {
                printf("%d %d candidate\n", x, r);
                // works
                auto col2 = cols[x].find({r+len, len});
                auto row2 = rows[r+len].find({x, len});
                printf("col2 works = %d\n", col2 != cols[x].end());
                printf("row2 works = %d\n", row2 != rows[r+len].end());
                if (col2 != cols[x].end() and row2 != rows[r+len].end()) {
                    printf("%d %d works\n", x, r);
                }
            }
        }
    }
}
