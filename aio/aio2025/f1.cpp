#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (auto& i : T) cin >> i;
    int M;
    cin >> M;
    vector<int> S(M);
    for (auto& i : S) cin >> i;

    int count = 0;
    for (auto& i : S) {
        if (i == 1) count++;
        else break;
    }
    if (count > 1) {
        printf("NO\n");
        return 0;
    }
    
    count = 0;
    int prev = S[0];
    for (auto& i : S) {
        if (i - prev == 1) {
            prev = i;

            if (count % 2 == 0) {
                printf("NO\n");
                return 0;
            }
            count = 1;
        } else if (i == prev) {
            count++;    
        } else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}