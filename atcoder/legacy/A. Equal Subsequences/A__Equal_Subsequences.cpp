#include <bits/stdc++.h>

using namespace std;

signed main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n <= 3) {
            for (int i = 0; i < k; i++) printf("1");
            for (int i = k; i < n; i++) printf("0");
        } else {
            if (k == 0) {
                for (int i = 0; i < n; i++) printf("0"); 
            } else {
                printf("1");
                if (n - k < 2) {
                    for (int i = 1; i < k; i++) printf("1");
                    for (int i = k; i < n; i++) printf("0");
                } else {
                    for (int i = k; i < n-1; i++) printf("0");
                    for (int i = 1; i < k; i++) printf("1");
                    printf("0");
                }
            }
        }
        printf("\n");
    }

    return 0;
}