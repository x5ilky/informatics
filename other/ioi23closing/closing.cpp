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
    auto precomp=[&](int pA,int pB,map<int,int>&M){
        vector<int>a(1),b(1);
        for(int i=1;i<=N;i++){
            if(isl[i])continue;
            auto [d,p]=min<pii>({dA[i],pA},{dB[i],pB});
            (p?b:a).push_back(d+p);
        }
        sort(a.begin()+1,a.end());
        sort(b.begin()+1,b.end());
        for(int i=1;i<a.size();i++)a[i]+=a[i-1];
        for(int i=1;i<b.size();i++)b[i]+=b[i-1];

        int A=a.size()-1,B=b.size()-1;
        vector<int>dp(A+2*B+1,INF);
        for(int r=0;r<=1;r++){
            int y=0;
            for(int s=r;s<=A+2*B;s+=2){
                int l=max(0ll,(s>A?(s-A+1)/2:0));
                int h=min(B,s/2);
                if(l>h)continue;
                y=min(max(y,l),h);
                while(y<h&&b[y+1]+a[s-2*(y+1)]<=b[y]+a[s-2*y])y++;
                dp[s]=b[y]+a[s-2*y];
            }
        }
        for(int s=0;s<=A+2*B;s++)
            if(dp[s]!=INF)M[dp[s]]=max(M[dp[s]],s);
        int mx=0;
        for(auto &[c,s]:M)s=mx=max(mx,s);
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
// |ヘヘヘシミ丁ビ丁丁丁ミミ丁丁ビ火せ允洪李|
// |・・・ㇸ一ヘヘㇵ　・・・ㇵヘシミビせ允洪|
// |一一ㇸ・　ㇸヘミミ丁丁ミシㇵ・ヘミビ山允|
// |ミシ一ㇵミ丁ビビビビビビビ丁ヘ・ヘ丁ビ火|
// |シ一ヘ丁ビ丁ミ丁丁ビビ丁丁ビミㇵ・ㇵヘミ|
// |シ一ミビ丁ミビ火せ火火ビ火ビミヘ一・・ㇸ|
// |シヘ丁ビシ丁火ビ丁ミㇸヘシㇵ・　　　　　|
// |ミビ丁丁丁ビ丁ミ一ヘシシシ一　一ㇵㇵㇸ・|
// |火ビ火火火丁ヘ丁せ山山山允火ミㇵヘミヘ・|
// |山允山ビシせ汎労労労労労汎山ビシシビヘ・|
// |汎せ丁せ洪労労労労労労洪允火丁シ丁ミ一・|
// |せせ汎労李労洪汎允允汎山せ火ミシミㇵ　　|
// |洪允労労汎允山火火火火火ビビ丁シㇵㇸ　ㇸ|
// |洪洪労洪允山山允允山山允允山せ火丁ミヘㇸ|
// |和和李労洪允洪労労労洪労汎せビミシヘㇵヘ|
// |群群群耗和労李和耗耗和労允火ミヘ一・　　|
// |慶慶義陽奏和奏群陽奏李汎せ丁ヘ・・一ㇵㇵ|
// |覇覇覇義奏群義義奏李汎せ丁ㇵ　一シミ丁ミ|
// |覇覇覇陽群慶慶群和洪山丁ヘ　ㇵミ火せ火丁|
// |覇覇慶群義覇陽耗労允火シㇸㇸシ火允汎せ丁|
// +----------------------------------------+
// 2026 (July 31st) 16:04:09
// end signature



