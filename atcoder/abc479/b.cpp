#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string S;cin>>S;
    int c=0,mx=0;
    for(int i=0;i<N;i++){
        if(S[i]=='R')c++;
        else c=0;
        mx=max(mx,c);
    }
    cout<<mx<<endl;
}
