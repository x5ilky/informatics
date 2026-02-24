#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    cout << "Of";
    cout << (char)(s[0]-('A'-'a'));
    for (int i=1;i<s.size();i++)cout<<s[i];
    cout<<endl;
}
