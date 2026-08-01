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
#define int long long
using namespace std;
const int INF=1ull<<60;
signed max_score(signed N, signed X, signed Y, long long K,
              std::vector<signed> U, std::vector<signed> V, std::vector<signed> W)
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
    auto precomp=[&](int cost,bool pA,bool pB,map<int,int>&M){
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=1;i<=N;i++){
            if(isl[i])continue;
            pq.push(min(pii{dA[i],0},pii{dB[i],1}));
            // dprint("pushing {}",min(pii{dA[i],0},pii{dB[i],1}));
        }
        int cnt[2]={1,1},c=0;M[0]=0;
        for(int i=1;i;i++){
            if(pq.empty()&&cnt[0]+cnt[1]<=0)break;
            // dprint("top is {}",pq.top());
            if(pq.empty()||(cost<pq.top().first&&cnt[0]+cnt[1]>0)){
                (cnt[0]>0?cnt[0]:cnt[1])--;
                c+=cost;
                M[c]=i;
                // dprint("M[{}]={}",c,i);
            }else{
                auto [d,t]=pq.top();
                if(t==0&&pA||t==1&&pB)cnt[t]++;
                c+=d;pq.pop();
                M[c]=i;
                // dprint("M[{}]={}",c,i);
            }
        }
    };
    precomp(dB[X],0,0,M__);
    precomp(dB[X],1,0,Ma_);
    precomp(dB[X],0,1,M_b);
    precomp(dB[X],1,1,Mab);
    // dcheck(M__);
    // dcheck(Ma_);
    // dcheck(M_b);
    // dcheck(Mab);
    int llen=accumulate(isl.begin()+1,isl.end(),0);
    int M=ln.size();
    ln.push_back(0);
    reverse(ln.begin(),ln.end());
    vector<int>psA(M+1),psB(M+1);int tp=0;
    for(int i=1;i<=M;i++)psA[i]=dA[ln[i]],psB[i]=dB[ln[i]];
    for(int i=1;i<=M;i++)if(!tp&&psA[i]>psB[i])tp=i;
    int ans=0,C=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i=1;i<=M;i++)pq.push({(i<tp?psA:psB)[i],i});
    bool rA=false,rB=false,flip=false;
    int c=0;
    while(true){
        map<int,int>*m=&M__;
        if(rA)m=&Ma_;
        if(rB)m=&M_b;
        if(rA&&rB)m=&Mab;
        int p=0;
        {
            auto it=m->upper_bound(K-C);
            if(it!=m->begin()) p=(--it)->second;
        }
        // dprint("{} costs {}",c,C);
        // dprint("ans chmax {}+{} = {}",c,p,c+p);
        ans=max(ans,c+p);
        if(pq.empty()){
            if(flip)break;
            flip=true;
            for(int i=1;i<=M;i++)pq.push({(i>=tp?psA:psB)[i]-(i<tp?psA:psB)[i], i});
        }
        if(C+pq.top().first>K)break;
        C+=pq.top().first;
        c++;
        if(flip&&pq.top().second==1)rA=true;
        if(flip&&pq.top().second==M)rB=true;
        pq.pop();
    } 
    return ans;
}

// begin signature
// +----------------------------------------+
// |　　　　・一ヘミ丁ミシシミミ丁ビせ山允允|
// |ヘヘㇵㇵㇸ　ㇸㇵㇵ一ㇸㇸ一ㇵヘミ丁ビ火火|
// |ビ丁丁ミヘ一　ㇸㇵヘヘㇵ・　ㇸㇵヘシミ丁|
// |山山せビミヘシシシシシシミヘ・　・ㇸ一ヘ|
// |汎山火丁シヘ一ㇸ一一ㇸㇸㇵヘシ一ㇸ　　・|
// |山火丁シ一ㇵシミ丁丁丁丁ミヘㇸ一ㇵヘ一・|
// |せビミㇵヘミビビビ丁丁丁ビビ丁シㇸ　一ヘ|
// |火ビシㇵミビ丁ミシミ丁丁ㇸㇸㇵヘシ一　　|
// |火ミㇵミビミシ丁ミヘシシシ一　・ㇵシ一　|
// |ミミ丁ビミ丁ビせ允汎汎允山ビシㇸㇸヘㇵ　|
// |ビビ火ビせ汎労労労労労洪允せ丁ヘ・ヘㇵ　|
// |山せ火汎労李洪汎汎汎汎允山火ミヘ一ヘㇵ　|
// |山火洪労洪汎山せせせせ火ビミシシミㇵヘ・|
// |汎汎労労允山山山山山せ山山せ火ビ丁ミヘㇵ|
// |李李李労洪允洪洪労洪洪洪汎山火丁シビシシ|
// |奏奏奏耗李洪李和耗耗和労允火丁ヘㇵ丁ヘシ|
// |義義陽群耗李耗群陽奏李汎せ丁ヘㇸヘㇵ一シ|
// |覇覇慶陽奏群義義奏李汎せ丁ヘ・　　一シㇸ|
// |覇覇覇陽群慶慶群和洪山丁ヘ　ㇸ・ㇵヘㇸㇸ|
// |覇覇慶陽義覇陽奏李允火シㇸ　一ヘㇵ・・・|
// +----------------------------------------+
// 2026 (August 1st) 18:15:23
// end signature




