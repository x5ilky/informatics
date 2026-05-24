// chatgpt code
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, K;
    cin >> R >> C >> K;

    vector<int> a(R * C);

    auto cell = [&](int y, int x) -> int& {
        return a[y * C + x];
    };

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> cell(y, x);
        }
    }

    int W = C + 1;
    int H = R + 1;
    int N = W * H;

    auto id = [&](int y, int x) {
        return y * W + x;
    };

    auto hclear = [&](int y, int x) {
        if (y == 0 || y == R) return true;
        return cell(y - 1, x) != cell(y, x);
    };

    auto vclear = [&](int y, int x) {
        if (x == 0 || x == C) return true;
        return cell(y, x - 1) != cell(y, x);
    };

    vector<unsigned short> TL(N, 0), BR(N, 0);

    for (int y = 0; y <= R; y++) {
        int run = 0;
        for (int x = C - 1; x >= 0; x--) {
            if (hclear(y, x)) run++;
            else run = 0;

            TL[id(y, x)] = run;
        }
    }

    for (int x = 0; x <= C; x++) {
        int run = 0;
        for (int y = R - 1; y >= 0; y--) {
            if (vclear(y, x)) run++;
            else run = 0;

            TL[id(y, x)] = min<int>(TL[id(y, x)], run);
        }
    }

    for (int y = 0; y <= R; y++) {
        int run = 0;
        for (int x = 1; x <= C; x++) {
            if (hclear(y, x - 1)) run++;
            else run = 0;

            BR[id(y, x)] = run;
        }
    }

    for (int x = 0; x <= C; x++) {
        int run = 0;
        for (int y = 1; y <= R; y++) {
            if (vclear(y - 1, x)) run++;
            else run = 0;

            BR[id(y, x)] = min<int>(BR[id(y, x)], run);
        }
    }

    int ans = 0;

    auto process_diag = [&](int sy, int sx) {
        int L = min(R - sy, C - sx) + 1;

        set<int> active;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> expire;

        for (int j = 0; j < L; j++) {
            while (!expire.empty() && expire.top().first <= j) {
                active.erase(expire.top().second);
                expire.pop();
            }

            int y = sy + j;
            int x = sx + j;

            int start_cap = TL[id(y, x)];

            active.insert(j);
            expire.push({j + start_cap + 1, j});

            int end_cap = BR[id(y, x)];
            int need_at_least = j - end_cap;

            auto it = active.lower_bound(need_at_least);

            if (it != active.end()) {
                ans = max(ans, j - *it);
            }
        }
    };

    for (int sx = 0; sx <= C; sx++) {
        process_diag(0, sx);
    }

    for (int sy = 1; sy <= R; sy++) {
        process_diag(sy, 0);
    }

    cout << ans << '\n';
}
