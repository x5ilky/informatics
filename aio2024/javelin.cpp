#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int best = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b > best) {
            best = b;
            ans++;
        }
    }
}