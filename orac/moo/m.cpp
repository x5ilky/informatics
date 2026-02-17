#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        string s; cin >> s;

        bool works = false;

        int changeamt = 2;
        if (s.length() >= 3) {
            for (int i = 0; i < s.length()-2; i++) {
                if (s[i+1] == 'O') works = true;
                if (s[i] == 'M' and s[i+1] == 'O') changeamt = min(changeamt, 1);
                if (s[i+1] == 'O' and s[i+2] == 'O') changeamt = min(changeamt, 1);
                if (s[i] == 'M' and s[i+1] == 'O' and s[i+2] == 'O') changeamt = min(changeamt, 0);
            }
        }

        cout << (works ? static_cast<int>(s.length())-3+changeamt : -1) << endl;
    }
}
