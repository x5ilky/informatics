#include <bits/stdc++.h>

using namespace std;

signed main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[0]) {
                int right = a.length() - i - 1;
                int left = i;
                if (left % 2 == 0 && right % 2 == 0) {
                    printf("YES\n");
                    goto skip;
                }
            }
        }
        printf("NO\n");
    skip:
        ;;
    }

    return 0;
}