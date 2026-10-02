#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;cin>>Q;
    string S,T;cin>>S>>T;
    vector<int>st(S.size()+1);
    for(int i=0;i<S.size();i++){
        if(!(i+T.size()-1<S.size()))break;
        st[i+1]=1;
        for(int j=0;j<T.size();j++){
            if(S[i+j]!=T[j])st[i+1]=0;
        }
    }
    for(int i=1;i<=S.size();i++)st[i]+=st[i-1];
    while(Q--){
        int l,r;cin>>l>>r;
        int right=r-T.size()+1;
        if(right>=l&&(st[right]-st[l-1])>0)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
