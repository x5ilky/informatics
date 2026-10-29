#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
const int INF=1ull<<60;
signed main(){
    fastio();
    READ(int,N,M,Q);
    Vec<Vec<ai3>>g(N+1);
    Vec<ai3>E(M+1);
    FOR(i,1,M){
        READ(int,u,v,w);
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
        E[i]={u,v,w};
    }
    Vec<int>d1(N+1,INF),dN(N+1,INF);
    Graph<0>t1(N),tN(N);
    Vec<int>par(N+1),pe(N+1);
    {
        PQGT<pii>pq;
        d1[1]=0;pq.push({0,1});
        while(pq.size()){
            auto [d,u]=pq.top();pq.pop();
            if(d>d1[u])continue;
            for(auto [v,w,i]:g[u]){
                if(d+w<d1[v]){
                    par[v]=u;pe[v]=i;
                    d1[v]=d+w;
                    pq.push({d+w,v});
                }
            }
        }
    }
    if(d1[N]==INF){
        while(Q--){
            int m,w;cin>>m>>w;
            cout<<-1<<'\n';
        }
        return 0;
    }
    FOR(i,1,N)if(par[i])t1(par[i],i,pe[i]);

    Vec<int>anc1(N+1,-1),ancN(N+1,-1);
    Vec<int>P,R;
    function<bool(int,int)>dfs1=[&](int u,int p)->bool{
        bool path=u==N;
        for(auto [v,i]:t1[u]){
            if(v==p)continue;
            bool d=dfs1(v,u);
            path|=d;
            if(d)R.push_back(i);
        }
        if(path){
            anc1[u]=u;
            ancN[u]=u;
            if(p!=-1)tN(u,p);
            P.push_back(u);
        }
        return path;
    };
    dfs1(1,-1);
    P.reverse(0);
    P.insert(P.begin(),0);
    R.reverse(0);
    Vec<int>uP(N+1),uR(M+1);
    for(int i=1;i<P.size();i++)uP[P[i]]=i;
    for(int i=1;i<=R.size();i++)uR[R[i-1]]=i;

    {
        PQGT<ai3>pq;
        FOR(i,1,N)if(anc1[i]==i){
            dN[i]=d1[N]-d1[i];
            pq.push({dN[i],i,0});
        }
        while(pq.size()){
            auto [d,u,p]=pq.top();pq.pop();
            if(d>dN[u])continue;
            if(p)tN(u,p);
            for(auto [v,w,i]:g[u]){
                if(d+w<dN[v]){
                    dN[v]=d+w;
                    pq.push({d+w,v,u});
                }
            }
        }
    }
    function<void(int,int)>dfs2=[&](int u,int p){
        if(anc1[u]!=u)anc1[u]=anc1[p];
        for(auto [v,_]:t1[u]){
            if(v==p)continue;
            dfs2(v,u);
        }
    };
    dfs2(1,-1);
    function<void(int,int)>dfs3=[&](int u,int p){
        if(ancN[u]!=u)ancN[u]=ancN[p];
        for(auto [v,_]:tN[u]){
            if(v==p)continue;
            dfs3(v,u);
        }
    };
    dfs3(1,-1);

    multiset<pair<int,pii>>CHMIN;
    FOR(i,1,M){
        if(uR[i])continue;
        auto [u,v,w]=E[i];
        for(auto [u,v]:{pii{u,v},{v,u}}){
            if(anc1[u]==-1||ancN[v]==-1)continue;
            int a1=uP[anc1[u]];
            int aN=uP[ancN[v]];
            if(a1>=aN)continue;
            int d=d1[u]+dN[v]+w;
            CHMIN.insert({a1,{1,d}});
            CHMIN.insert({aN,{-1,d}});
        }
    }
    multiset<int>mn;
    Vec<int>ans(M+1,INF);
    FOR(i,1,R.size()){
        while(CHMIN.size()&&CHMIN.begin()->first==i){
            auto [type,x]=CHMIN.begin()->second;
            if(type==1)mn.insert(x);
            else mn.erase(mn.find(x));
            CHMIN.erase(CHMIN.begin());
        }
        ans[i]=mn.size()?*mn.begin():INF;
    }
    while(Q--){
        int m,w;cin>>m>>w;
        if(uR[m]==0){
            auto [u,v,_]=E[m];
            cout<<min({d1[u]+dN[v]+w,dN[u]+d1[v]+w,d1[N]})<<endl;
        }else{
            auto [u,v,W]=E[m];
            cout<<min(ans[uR[m]],d1[N]-W+w)<<endl;
        }
    }
}
