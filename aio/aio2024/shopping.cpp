#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> a(n);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());
    int ans = 0;
    while (k) {
        ans += a.front();
        a.pop_front();
        a.pop_back();
        k--;
    }
    while (a.size()) {
        ans += a.back();
        a.pop_back();
        a.pop_back();
    }
    printf("%d\n", ans);

    return 0;
}