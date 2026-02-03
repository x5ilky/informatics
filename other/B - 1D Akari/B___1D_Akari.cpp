#include <bits/stdc++.h>

using namespace std;

signed main() {
    string s;
    cin >> s;

    int open = false;
    int seen = false;
    
    
    string N = s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i]; 
        if (c == '.') {
            if (!open) {
                N[i] = 'o';
                open = true;
                seen = false;
            }
            if (open && seen) {
                N[i] = 'o';
                open = true;
                seen = false;
            }
        }
        if (c == '#') seen = true;
    }
    
    cout << N << endl;
    
    return 0;
}