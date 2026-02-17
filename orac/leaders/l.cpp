#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N; 
    string s; cin >> s;
    vector<int> V(N); for (int i = 0; i < N; i++) cin >> V[i];
    int lastA = 0, lastB = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') lastA = i+1;
        if (s[i] == 'B') lastB = i+1;
    }
    const int INF = 1e9+7;
    int alead = INF, blead = INF;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            if (V[i] >= lastA) {
                alead = i+1;
            } 
            break;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            if (V[i] >= lastB) {
                blead = i+1;
            } 
            break;
        }
    }
    int ans = alead != INF and blead != INF;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') 
            if (V[i] >= blead and blead > i)
                ans++;
        if (s[i] == 'B') 
            if (V[i] >= alead and alead > i)
                ans++;
    }
    cout << ans << endl;
}
