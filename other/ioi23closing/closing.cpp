// Decompose into path a <-> b and subtree of a and subtree of b
// Loop over all cases of connection between a <-> b
// If a path and b path disjoint, precompute most score with <= K budget
// 
// to find cases of connection between a <-> b:
// find the crossing point on prefix sum of a and prefix sum of b
// optimal connection that doesn't reach crossing point can be gotten with dijkstra up to crossing
// else start with crossing point and then dijkstra on modification price after.
//
// precompute most score <= K with: disjoint, b -> st(A), a -> st(B)
#include "closing.h"
#include <bits/stdc++.h>
using namespace std;
int max_score(int N, int X, int Y, long long K,
              std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
    ++X,++Y;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    for(int i=0;i<N-1;i++)g[U[i]+1].push_back({V[i]+1,W[i]}),g[V[i]+1].push_back({U[i]+1,W[i]});
    vector<int>parA(N+1);
    function<void(int,int)>dfs1=[&](int u,int p){
        for(auto [v,_]:g[u]){
            if(p==v)continue;
            parA[v]=u;
            dfs1(v,u);
        }
    };
    vector<short>isl(N+1);
    vector<int>ln;
    parA[X]=-1;dfs1(X,-1);
    if("get a <-> b"){
        int u=Y;
        while(u!=-1){
            ln.push_back(u);
            isl[u]=true;
            u=parA[u];
        }
    }
    function<void(int,int,vector<int>&)>dfsd=[&](int u,int p,vector<int>&d){
        for(auto [v,w]:g[u]){
            if(v==p)continue;
            d[v]=d[u]+w;
            dfsd(v,u,d);
        }
    };
    vector<int>dA(N+1,-1),dB(N+1,-1);
    dA[X]=0,dfsd(X,-1,dA);dB[Y]=0,dfsd(Y,-1,dB);
    map<int,int>M__,Ma_,M_b,Mab;
    auto precomp=[&](int pA,int pB,map<int,int>&M){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<=N;i++){
            if(isl[i])continue;
            if(dA[i]!=-1)pq.push(dA[i]+pA);
            if(dB[i]!=-1)pq.push(dB[i]+pB);
        }
        int C=0,k=0;M[k]=C;
        while(pq.size()){
            auto w=pq.top();pq.pop();
            M[k+=w]=++C;
        }
    };
    precomp(0,0,M__);
    precomp(dB[X],0,Ma_);
    precomp(0,dA[Y],M_b);
    precomp(dB[X],dA[Y],Mab);
    int llen=accumulate(isl.begin()+1,isl.end(),0);
    int M=ln.size();
    ln.push_back(0);
    reverse(ln.begin(),ln.end());
    vector<int>psA(M+1),psB(M+1);int tp=0;
    for(int i=1;i<=M;i++)psA[i]=dA[ln[i]],psB[i]=dB[ln[i]];
    for(int i=1;i<=M;i++)if(!tp&&psA[i]>psB[i])tp=i;
    int ans=0,C=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=M;i++)pq.push((i<tp?psA:psB)[i]);
    bool rA=false,rB=false,flip=false;
    for(int i=2;i<=2*M;i++){
        map<int,int>*m=&M__;
        if(rA)m=&Ma_;
        if(rB)m=&M_b;
        if(rA&&rB)m=&Mab;
        int p=0;
        {
            auto it=m->upper_bound(K-C);
            if(it==m->begin())p=0;
            else p=(--it)->second;
        }
        ans=max(ans,i+p);
        if(!flip&&pq.empty()){
            flip=true;
            for(int i=1;i<=M;i++)pq.push((i>tp?psA:psB)[i]-(i<tp?psA:psB)[i]);
        }
        if(flip&&pq.top()==1)rA=true;
        if(flip&&pq.top()==M)rB=true;
        C+=pq.top();pq.pop();
    } 
    return ans;
}
