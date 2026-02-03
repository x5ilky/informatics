#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    
    int left = 1, right = L;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;

        left = max(left, l);
        right = min(right, r);
    }
    
    cout << max(right - left + 1, 0) << endl;
}
