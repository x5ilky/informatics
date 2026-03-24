#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD=998244353;

struct segtree{
    vector<int>T,lz;
    segtree(int N):T(N*4),lz(N*4,1){}
    void push(int v){
        if(lz[v]!=1){
            T[v*2]*=lz[v];
            T[v*2+1]*=lz[v];
            T[v*2]%=MOD;
            T[v*2+1]%=MOD;
            lz[v*2]*=lz[v];
            lz[v*2+1]*=lz[v];
            lz[v]=1;
            lz[v*2]%=MOD;
            lz[v*2+1]%=MOD;
        }
    }
    void mul(int v,int tl,int tr,int ql,int qr,int m){
        if(ql<=tl&&tr<=qr){
            T[v]*=m;
            T[v]%=MOD;
            lz[v]*=m;
            lz[v]%=MOD;
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(ql<=tm)mul(v*2,tl,tm,ql,qr,m);
        if(qr> tm)mul(v*2+1,tm+1,tr,ql,qr,m);
        T[v]=T[v*2]+T[v*2+1];
        T[v]%=MOD;
    }
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos> tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=T[v*2]+T[v*2+1];
        T[v]%=MOD;
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        push(v);
        int tm=(tl+tr)/2,ans=0;
        if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
        return ans;
    }
};

signed main() {
    int N,M;cin>>N>>M;
    using pii=pair<int,int>;
    vector<pii> R(M+1);
    for(int i=1;i<=M;i++)
        cin>>R[i].first>>R[i].second;
    sort(R.begin()+1,R.end());
    segtree dp(N+1);
    dp.update(1,1,N,1,1);
    for(int i=1;i<=M;i++){
        auto[l,r]=R[i];
        if(l>1) dp.mul(1,1,N,1,l-1,2);
        dp.update(1,1,N,r,
                    (dp.query(1,1,N,r,r)+
                    dp.query(1,1,N,l,r)%MOD)%MOD);
        if(r<N) dp.mul(1,1,N,r+1,N,2);
    }
    // for (int i=0;i<=M;i++){
    //     for(int k=0;k<=N;k++)
    //         cout<<dp.query(1,0,S,idx(i,k),idx(i,k))%MOD<<" ";
    //     cout<<endl;
    // }
    cout<<dp.query(1,1,N,N,N)%MOD<<endl;
}
