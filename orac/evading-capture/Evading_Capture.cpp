#include <bits/stdc++.h>

using namespace std;

bool seen[100002];
vector<int> adj[100002];

void traverse(int idx, int steps) {
    // printf("steps: %d, idx: %d\n", steps, idx);
    if (steps == 0) {
        seen[idx] = true;
        return;
    }
    for (auto& i : adj[idx]) {
        traverse(i, steps-1);
    }
}

signed main() {
    int n, e, x, k;
    scanf("%d %d %d %d", &n, &e, &x, &k);
    for (int i = 0; i < e; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    traverse(x, k);
    int amt = 0;
    for (int i = 0; i < 100002; i++) {
        if (seen[i]) amt++;
    }
    
    printf("%d\n", amt);

    return 0;
}