#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        if (k == 1) a++;
        else if (k == 2) b++;
        
        if (a > b) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}