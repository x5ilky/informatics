#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    long long n = 0;
    for (int i = 1 ; i <= N; i++) {
        int v; cin >> v;
        if (v % K == 0) n += v;
    }
    cout << n << endl;
}
