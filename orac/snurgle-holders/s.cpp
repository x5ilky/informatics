#include <bits/stdc++.h>
#include <cstdio>
#include <functional>

using namespace std;

const int MAX_N = 100010;
vector<int> children[MAX_N];

int take[MAX_N];
int notake[MAX_N];

int main() {
    freopen("snurgle.in", "r", stdin);
    freopen("snurgle.out", "w", stdout);
    int N; cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int v; cin >> v;
        children[v].push_back(i);
    }

    function<void (int)> dp = [&](int node){
        int t = 0, nt = 0;
        for (auto& c : children[node]) {
            dp(c);
            t += notake[c];
            nt += max(take[c], notake[c]);
        }
        t += 1;
        take[node] = t;
        notake[node] = nt;
    };

    dp(N);
    // for (int i = 1; i <= N; i++) {
    //     printf("%d %d\n", take[i], notake[i]);
    // }
    cout << max(take[N], notake[N]) << endl;
}
