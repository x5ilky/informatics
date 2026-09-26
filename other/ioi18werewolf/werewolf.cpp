#include "werewolf.h"
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int>e;
    DSU(int n):e(n,-1){}
    int operator[](int x){return e[x]<0?x:e[x]=(*this)[e[x]];}
    int operator()(int x,int y) {
        x=(*this)[x],y=(*this)[y];
        if(x==y)return 0;
        if(e[x]<e[y]) swap(x, y);
        e[y]+=e[x];
        e[x]=y;
        return 1;
    }
};
struct segtree {
    vector<int>T;
    segtree(int n):T(n*4,0) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=T[v*2]+T[v*2+1];
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=0;
            if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
            if(qr>tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
            return ans;
        }
    }
};
std::vector<int> check_validity(int N, std::vector<int> X, std::vector<int> Y,
                                std::vector<int> S, std::vector<int> E,
                                std::vector<int> L, std::vector<int> R) {
    int M=X.size(),Q=S.size();
    vector<vector<int>>g(N);
    for(int i=0;i<M;i++)g[X[i]].push_back(Y[i]),g[Y[i]].push_back(X[i]);

    vector<vector<int>>t1(N),t2(N);
    vector<int>p1(N,-1),p2(N,-1);

    {
        DSU dsu(N);
        for(int i=0;i<N;i++){
            for(auto v:g[i]){
                if(v>i)continue;
                int r=dsu[v];
                if(r==i)continue;
                dsu.e[r]=i;
                p1[r]=i;
                t1[r].push_back(i);
                t1[i].push_back(r);
            }
        }
    }
    {
        DSU dsu(N);
        for(int i=N-1;i>=0;i--){
            for(auto v:g[i]){
                if(v<i)continue;
                int r=dsu[v];
                if(r==i)continue;
                dsu.e[r]=i;
                p2[r]=i;
                t2[r].push_back(i);
                t2[i].push_back(r);
            }
        }
    }
    vector<array<int,20>>lift1(N),lift2(N);
    for(int i=0;i<N;i++){
        lift1[i][0]=p1[i]==-1?i:p1[i];
        lift2[i][0]=p2[i]==-1?i:p2[i];
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<N;i++){
            lift1[i][j]=lift1[lift1[i][j-1]][j-1];
            lift2[i][j]=lift2[lift2[i][j-1]][j-1];
        }
    }
    auto get1=[&](int u,int r){
        for(int j=19;j>=0;j--){
            int v=lift1[u][j];
            if(v<=r)u=v;
        }
        return u;
    };
    auto get2=[&](int u,int l){
        for(int j=19;j>=0;j--){
            int v=lift2[u][j];
            if(v>=l)u=v;
        }
        return u;
    };
    int t=0;
    vector<int>tin(N),tout(N);
    function<void(int,int)>dfs=[&](int u,int p){
        tin[u]=t++;
        for(auto v:t1[u]){
            if(v==p)continue;
            dfs(v,u);
        }
        tout[u]=t;
    };
    dfs(N-1,-1);
    using pii=pair<int,int>;
    segtree st(N);
    vector<int>sz(N,1);
    function<void(int,int)>dfs2=[&](int u,int p){
        for(auto v:t2[u]){
            if(v==p)continue;
            dfs2(v,u);
            sz[u]+=sz[v];
        }
    };
    function<void(int,int,int)>add=[&](int u,int p,int d){
        st.update(1,0,N-1,tin[u],d);
        for(auto v:t2[u])if(v!=p)add(v,u,d);
    };
    vector<vector<pii>>byR(N);
    for(int i=0;i<Q;i++){
        if(S[i]<L[i]||E[i]>R[i])continue;
        int a=get1(E[i],R[i]);
        int b=get2(S[i],L[i]);
        byR[b].push_back({a,i});
    }
    vector<int>ans(Q);
    function<void(int,int,bool)>solve=[&](int u,int p,bool clear){
        int big=-1,bsz=0;
        for(auto v:t2[u])if(v!=p&&sz[v]>bsz)bsz=sz[v],big=v;
        for(auto v:t2[u])if(v!=p&&v!=big)solve(v,u,true);
        if(big!=-1)solve(big,u,false);
        for(auto v:t2[u])if(v!=p&&v!=big)add(v,u,1);
        st.update(1,0,N-1,tin[u],1);
        for(auto [s,i]:byR[u])
            ans[i]=!!st.query(1,0,N-1,tin[s],tout[s]-1);
        if(clear)add(u,p,0);
    };

    dfs2(0,-1);
    solve(0,-1,false);
    return ans;
}

// begin signature
// +----------------------------------------+
// |和労汎山せ火ビ丁丁丁ビ火せ山汎労李耗奏陽|
// |汎山火ビミシヘㇵㇵㇵヘミ丁火山汎洪李和奏|
// |せ丁シㇵㇸㇸㇵヘシミミシシ丁火山允洪李耗|
// |ミㇵ・・ㇵシシヘㇵ一ㇵㇵヘシ丁火山允洪李|
// |ㇵ・・ヘヘ一・　　　　　・一ヘミビせ允洪|
// |一　一シ一・・一ㇵヘヘㇵ一・　ㇸヘミ火山|
// |一　ㇸヘㇸ　一ヘミミミミミシㇵㇸ　ㇸヘ丁|
// |一　ㇸㇸ・ㇸヘミヘㇵ一一ㇵヘミシ一ㇸ・ㇵ|
// |　・　ㇸ一ヘミㇵ・　・・　・ㇵミシㇸㇸㇸ|
// |ヘヘㇵ一ヘシ一　　　　　　・ㇸヘシㇸ　・|
// |ビ丁ミヘシㇸ・一ㇵヘヘㇵ一ㇸㇸシヘ・ㇸㇸ|
// |せビ一ミ一ㇵシミ丁ビ丁丁シヘ一シㇵ　ㇸ　|
// |火　一シミ丁ビせ山山山せ火丁シシヘ・　　|
// |ビㇸヘミビせ山山山山せ火せ山火ビ丁シㇵ・|
// |ミ一シビせ允汎洪洪洪汎允山山火丁ミシヘシ|
// |ヘㇵミ火允洪李和和和和労允せ丁シシㇵ・・|
// |一シビ山洪李耗群群奏李汎せ丁ヘヘヘ・ㇸ一|
// |シビ山洪和奏陽義奏和洪せ丁ヘシㇵ　一シシ|
// |ビ山洪和群慶慶群和洪山丁ヘㇵ・・ㇵミ火ミ|
// |せ汎李奏義覇陽奏李允火シㇸ　一シ丁せせ丁|
// +----------------------------------------+
// 2026 (September 26th) 17:57:11
// end signature
