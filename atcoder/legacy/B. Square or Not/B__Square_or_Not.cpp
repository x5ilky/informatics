#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        size_t first = s.find('0');
        int rows = first - 1;
        if (n == 4) {
            if (first == std::string::npos) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            if (n == rows * rows) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}