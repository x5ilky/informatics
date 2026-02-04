#include <bits/stdc++.h>
#include <map>

using namespace std;

using pii = pair<int, int>;
int main() {
    int N, R, C; cin >> N >> R >> C;
    map<int, int> pos_to_coord;
    map<int, int> coord_to_pos;

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
        for (auto& x : xs) coord_to_pos[pos_to_coord[x] = xc++] = x;
        for (auto& y : ys) coord_to_pos[pos_to_coord[y] = yc++] = y;
        for (auto& cell : cells) {
            cell.first = pos_to_coord[cell.first];
            cell.second = pos_to_coord[cell.second];
        }

    }
}
