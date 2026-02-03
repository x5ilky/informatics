#include <bits/stdc++.h>

using namespace std;

int main() {
     int N, K; cin >> N >> K;
     int i = 0;
     int total = 0;
     while (total < K) {
         total += N+i;
         i++;
     }
     cout << i-1 << endl;
}
