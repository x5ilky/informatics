#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;cin>>S;
    if(S.back()!='e')S+="e";
    if(S.back()=='e')S+="r";
    cout<<S<<endl;
}
