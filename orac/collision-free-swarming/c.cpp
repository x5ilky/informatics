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

    vector<vector<int>> exists_cols(X+1), exists_rows(Y+1);
    {
        set<int> xs, ys;
        vector<pii> cells;
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
            exists_cols[cell.first].push_back(cell.second);
            exists_rows[cell.second].push_back(cell.first);
        }
    }

    map<int, int> col_top, col_bot, row_start, row_end;
    
}
