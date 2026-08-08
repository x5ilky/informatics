#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N,M;cin>>N>>M;
    string S;cin>>S;
    vector<int>HEAD(N+1);iota(HEAD.begin(),HEAD.end(),0);
    function<int(int)>head=[&](int u){
        return HEAD[u]==u?u:HEAD[u]=head(HEAD[u]);
    };
    auto join=[&](int a,int b){
        a=head(a),b=head(b);
        HEAD[b]=a;
    };
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        join(a,b);
    }
    vector<mint>fact(N+1);
    fact[0]=1;
    for(int i=1;i<=N;i++)
        fact[i]=fact[i-1]*i;
    vector<array<int,26>>cnt(N+1);
    vector<int>sz(N+1);
    for(int i=1;i<=N;i++){
        int r=head(i);
        sz[r]++;
        cnt[r][S[i-1]-'a']++;
    }
    mint ans=1;
    bool dup=false;
    for(int i=1;i<=N;i++){
        if(head(i)!=i)continue;
        ans*=fact[sz[i]];
        for(int c=0;c<26;c++){
            ans/=fact[cnt[i][c]];
            if(cnt[i][c]>=2)dup=true;
        }
    }
    if(!dup)ans/=2;
    cout<<ans.val()<<endl;
}
