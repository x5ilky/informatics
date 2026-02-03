#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T; cin >> N >> T;

    int total = T;
    int last = -200;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        if (t >= last+100) {
            last = t;
            total -= min(100, T-t);
        }
    }
    cout << total << endl;
}
