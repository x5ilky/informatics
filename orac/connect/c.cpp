#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    using pii = pair<int, int>;
    vector<pii> starts, ends;
    for (int i = 1; i <= 2*N; i++) {
        int v; cin >> v;
        if (starts[i] == -1) {
            starts[i] = v;
        } else {
            ends[i] = v;
        }
    }
    int wrong = 0;
    for (int i = 1; i <= N; i++) {
    }
}
