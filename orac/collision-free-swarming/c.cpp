#include <algorithm>
#include <bits/stdc++.h>
#include <map>

using namespace std;

using pii = pair<int, int>;
int main() {
    int N, R, C; cin >> N >> R >> C;
    map<int, int> xpos_to_coord;
    map<int, int> coord_to_xpos;
    map<int, int> ypos_to_coord;
    map<int, int> coord_to_ypos;

    int X = xpos_to_coord.size();
    int Y = ypos_to_coord.size();

    vector<vector<int>> y_per_col(X+1), x_per_row(Y+1);
    vector<pii> cells;
    {
        set<int> xs, ys;
        for (int i = 1; i <= N; i++) {
            int r, c; cin >> r >> c;
            xs.insert(c);
            ys.insert(r);
            cells.push_back({r, c});
        }

        int xc = 1, yc = 1;
        for (auto& x : xs) coord_to_xpos[xpos_to_coord[x] = xc++] = x;
        for (auto& y : ys) coord_to_ypos[ypos_to_coord[y] = yc++] = y;
        for (auto& cell : cells) {
            cell.first = xpos_to_coord[cell.first];
            cell.second = ypos_to_coord[cell.second];
            y_per_col[cell.first].push_back(cell.second);
            x_per_row[cell.second].push_back(cell.first);
        }
    }

    map<int, int> col_up, col_down, row_left, row_right;
#define chexists(col, f, fn, v) col[f] = col.count(f) ? fn(col[f], (v)) : (v)
    for (auto& u : cells) {
        auto [r, c] = u;
        for (auto& v : cells) {
            if (u == v) continue;
            auto [r2, c2] = v;

            if ((r2+c2)%2 != (r+c)%2) continue;
            if (c2 < c) continue;
            if (r2 < r) continue;
            if (r == r2) {
                int mid = (coord_to_xpos[c] + coord_to_xpos[c2])/2;
                int ts = coord_to_ypos[r];
                chexists(col_up, mid, max, ts-1);
                chexists(col_down, mid, min, ts+1);
                continue;
            }
            else if (c == c2) {
                int mid = (coord_to_ypos[r] + coord_to_ypos[r2])/2;
                int ts = coord_to_xpos[c];
                chexists(row_right, mid, max, ts-1);
                chexists(row_left, mid, min, ts+1);
                continue;
            }
        }
    }
}
