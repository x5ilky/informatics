#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>g,liftb,liftl,liftr;vector<int>H;
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
        if(tl==tr)return T[v];
        int tm=(tl+tr)/2,ans=-INF;
        if(ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};

segtree Hst(1);
void init(int _N, vector<int> _H) {
    N=_N,H=_H;
    Hst=segtree(N+1);
    for(int i=0;i<N;i++)Hst.update(1,0,N,i,H[i]);
    H.resize(N+1);
    g.resize(N+1); 
    liftb.resize(N+1,vector<int>(19,N)); 
    liftl.resize(N+1,vector<int>(19,N)); 
    liftr.resize(N+1,vector<int>(19,N)); 
    for(int i=0;i<=N;i++)liftl[i][0]=liftr[i][0]=N;
    H[N]=INF;
    stack<pii>st;
    st.push({INF,-1});
    for(int i=0;i<N;i++){
        while(H[i]>st.top().first){
            g[st.top().second].push_back(i);
            liftr[st.top().second][0]=i;
            st.pop();
        }
        st.push({H[i],i});
    }
    st.push({INF,-1});
    for(int i=N-1;i>=0;i--){
        while(H[i]>st.top().first){
            g[st.top().second].push_back(i);
            liftl[st.top().second][0]=i;
            st.pop();
        }
        st.push({H[i],i});
    }
    for(int i=0;i<N;i++){
        int nxt=i;
        for(auto e:g[i])if(H[e]>H[nxt])nxt=e;
        liftb[i][0]=nxt;
    }
    for(int k=1;k<19;k++){
        for(int i=0;i<N;i++){
            liftb[i][k]=liftb[liftb[i][k-1]][k-1];
            liftl[i][k]=liftl[liftl[i][k-1]][k-1];
            liftr[i][k]=liftr[liftr[i][k-1]][k-1];
        }
    }
    // for(int k=0;k<19;k++){
    //     for(int i=0;i<N;i++){
    //         printf("%d ",liftb[i][k]);
    //     }
    //     printf("\n");
    // }
}

int minimum_jumps(int A, int B, int C, int D) {
    if(A!=B||C!=D)return -1;
    int U=A,V=C,steps=0,ch=false;vector<vector<int>>&dir=liftb;
    // printf("query = %d, hv = %d\n", Hst.query(1,0,N,U,V),H[V]);
    if(Hst.query(1,0,N,U,V)>H[V])return -1;
    for(int i=1;i<=3;i++){
        for(int k=18;k>=0;k--){
            assert(steps<=N+10);
            if(dir[U][k]==U)continue;
            if(H[dir[U][k]]<H[V]){
                U=dir[U][k];
                steps+=(1<<k);
            }
        }
        if(liftl[U][0]==V||liftr[U][0]==V){
            return ++steps;
        }
        if(H[liftb[U][0]]<H[V])dir=liftb;
        else if(H[liftl[U][0]]<H[V])dir=liftl;
        else if(H[liftr[U][0]]<H[V])dir=liftr;
        else return -1;
    }
    return -1;
}
