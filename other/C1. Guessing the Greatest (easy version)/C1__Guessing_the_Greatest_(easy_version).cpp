#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define IINF 0xfffffff

signed main() {
    int n;
    cin >> n;
    int left = 1, right = n;
    while (right - left >= 2) {
        printf("? %d %d\n", left, right);
        fflush(stdout);
        int second; cin >> second;
        int half = (right - left + 1) / 2 + left;
        if (second > half) {
            printf("? %d %d\n", half, right);
            fflush(stdout);
            int answer; cin >> answer;
            if (answer != second) {
                // smaller
                right = half;
            } else {
                left = half;
            }
        } else {
            printf("? %d %d\n", left, half);
            fflush(stdout);
            int answer; cin >> answer;
            if (answer != second) {
                // smaller
                left = half;
            } else {
                right = half;
            }
        }
    }
    if (left == right) {
        printf("! %d\n", left);
    } else {
        printf("? %d %d\n", left, right);
        fflush(stdout);
        int ans; cin >> ans;
        if (ans == left) {
            printf("! %d\n", right);
        } else {
            printf("! %d\n", left);
        }
    }
    

    return 0;
}