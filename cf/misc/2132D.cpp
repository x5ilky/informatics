#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int64_t k; cin >> k;
        int64_t e = 1, ten = 1;
        int64_t a = -1;
        while (k > ten*9*e) {
            k -= ten*9*e;
            e++;
            ten *= 10;
        }
        a = ten + k / e - 1;

        int64_t ans = 0;

        if (k % e > 0) {
            int64_t l = k % e;
            int64_t p = a+1;
            string s = to_string(p);
            for (int i = 0; i < l; i++) ans += s[i] - '0';
        }
        printf("out: %ld, %ld\n", a, k % e);
    }

    return 0;
}
