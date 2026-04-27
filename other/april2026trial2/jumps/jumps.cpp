#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>g,liftmx,liftmn,liftl,liftr;vector<int>H;
int N;
using pii=pair<int,int>;
const int INF=1e9+7;
struct segtree{
    vector<int>T;
    segtree(int N):T(N*4,-INF){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr)return void(T[v]=a);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=max(T[v*2],T[v*2+1]);
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2,ans=-INF;
        if(ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};

segtree Hst(1);
void init(int _N,vector<int> _H){
    N=_N,H=_H;
    H.resize(N+1);
    H[N]=INF;

    Hst=segtree(N+1);
    for(int i=0;i<N;i++)Hst.update(1,0,N,i,H[i]);

    g.assign(N+1,{});
    liftmx.assign(N+1,vector<int>(19));
    liftmn.assign(N+1,vector<int>(19));
    liftl.assign(N+1,vector<int>(19));
    liftr.assign(N+1,vector<int>(19));

    for(int i=0;i<=N;i++){
        for(int k=0;k<19;k++){
            liftmx[i][k]=liftmn[i][k]=liftl[i][k]=liftr[i][k]=i;
        }
    }

    stack<pii>st;
    st.push({INF,-1});

    for(int i=0;i<N;i++){
        while(H[i]>st.top().first){
            int x=st.top().second;
            g[x].push_back(i);
            liftr[x][0]=i;
            st.pop();
        }
        st.push({H[i],i});
    }

    while(!st.empty())st.pop();
    st.push({INF,-1});

    for(int i=N-1;i>=0;i--){
        while(H[i]>st.top().first){
            int x=st.top().second;
            g[x].push_back(i);
            liftl[x][0]=i;
            st.pop();
        }
        st.push({H[i],i});
    }

    for(int i=0;i<N;i++){
        int mx=i,mn=i;
        for(auto e:g[i]){
            if(mx==i||H[e]>H[mx])mx=e;
            if(mn==i||H[e]<H[mn])mn=e;
        }
        liftmx[i][0]=mx;
        liftmn[i][0]=mn;
    }

    for(int k=1;k<19;k++){
        for(int i=0;i<=N;i++){
            liftmx[i][k]=liftmx[liftmx[i][k-1]][k-1];
            liftmn[i][k]=liftmn[liftmn[i][k-1]][k-1];
            liftl[i][k]=liftl[liftl[i][k-1]][k-1];
            liftr[i][k]=liftr[liftr[i][k-1]][k-1];
        }
    }
}

int minimum_jumps(int A,int B,int C,int D){
    int U=B,steps=0;
    int mxh=Hst.query(1,0,N,C,D);

    auto fin=[&](){
        return C<=liftr[U][0]&&liftr[U][0]<=D;
    };

    auto jump=[&](vector<vector<int>>&dir){
        for(int k=18;k>=0;k--){
            int v=dir[U][k];
            if(v==U)continue;
            if(v<C&&H[v]<mxh){
                U=v;
                steps+=1<<k;
            }
        }
    };

    for(int k=18;k>=0;k--){
        int v=liftl[U][k];
        if(v==U)continue;
        if(v>=A&&v<C&&H[v]<mxh){
            U=v;
        }
    }

    if(!(U<C&&H[U]<mxh))return -1;
    if(fin())return steps+1;

    jump(liftmx);
    if(fin())return steps+1;

    jump(liftr);
    if(fin())return steps+1;

    return -1;
}
