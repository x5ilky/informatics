#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100010;

int HEAD[MAX_N];
bool works[MAX_N];
bool odd[MAX_N];
bool even[MAX_N];

int head(int x) {
    if (HEAD[x] == x) return x;
    HEAD[x] = head(HEAD[x]);
    return HEAD[x];
}

void join(int u, int v) {
    int ru = head(u);
    int rv = head(v);
    if (ru == rv) return;

    HEAD[ru] = rv;
    works[rv] |= works[ru];
}

int main() {
    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) HEAD[i] = i;
    
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;

        join(a, b);
        if (
                reachable(a, 0) and reachable(b, 0) or 
                reachable(a, 1) and reachable(b, 1)) {
            // cycle found
            works[head(a)] = true;
        }
        if (works[head(a)]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
