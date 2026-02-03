#include <bits/stdc++.h>
using namespace std;

int t[100][100];
int c[100];
int main() {
    int H, W, N; cin >> H >> W >> N;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> t[i][j]; 
        }
    }

    for (int i = 0; i < N; i++) {
        int u; cin >> u;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (u == t[i][j]) c[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        ans = max(ans, c[i]);
    }
    cout << ans << endl;
}
