#include <bits/stdc++.h>
using namespace std;
#define int long long
struct lb{int s,e;bool f;};
signed main(){
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<lb>a(N);
        int mn=LLONG_MAX;
        for(auto&x:a){
            int p,q,r;cin>>p>>q>>r;
            x.s=p+q+r;mn=min(mn,x.s);
            if(p==q&&q==r)x={x.s,0,1};
            else if(p<=q&&q<=r)x={x.s,2*(min(q-p,r-q)+1),0};
            else x={x.s,0,0};
        }
        auto good=[&](int S){
            int z=0;
            for(auto x:a)if(S>x.s){
                if(x.f)return false;
                int c=S-x.s+x.e;
                if(c>K-z)return false;
                z+=c;
            }
            return true;
        };
        int l=mn,r=mn+K+1;
        while(l+1<r){
            int m=(l+r)/2;
            (good(m)?l:r)=m;
        }
        cout<<l<<endl;
    }
}
