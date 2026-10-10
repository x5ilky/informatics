#include <bits/stdc++.h>
using namespace std;
#define int long long
#define printf(...)
signed main() {
    int T;cin>>T;
    while(T--){
        int N,M,K;cin>>N>>M>>K;
        using pii=pair<int,int>;
        vector<pii>E;
        for(int i=1;i<=N;i++){
            int l,r;cin>>l>>r;
            E.push_back({l-1,1});
            E.push_back({r,-1});
            E.push_back({l+M-1,-1});
            E.push_back({r+M,1});
        }
        int m=0,cur=0,v=0;
        sort(E.begin(),E.end());
        for(auto[x,t]:E){
            int dt=x-cur,nv=v+m*dt;
            if(min(nv,v)<=K&&max(nv,v)>=K){
                int d=abs(v-K);
                int pos=cur+d*abs(m)-M+1;
                if(pos>0){
                    cout<<pos<<endl;
                    goto skip;
                }
            }
            cur=x,v=nv,m+=t;
        }
        if(v==K)cout<<cur<<endl;
        else cout<<-1<<endl;
    skip:;
    }
}
