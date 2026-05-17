#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<vector<int>>g(N+1);
    vector<vector<int>>par(N+1,vector<int>(21));
    par[1][0]=1;
    for(int i=2;i<=N;i++){
        int v;cin>>v;g[i].push_back(v);g[v].push_back(i);
        par[i][0]=v;
    }
    for(int k=1;k<=20;k++)for(int i=1;i<=N;i++)par[i][k]=par[par[i][k-1]][k-1];
    vector<int>D(N+1),mnD(N+1,1e9);vector<vector<int>>byD(N+1);
    function<void(int,int)>fdD=[&](int u,int p){byD[D[u]].push_back(u);for(auto v:g[u])if(v!=p)D[v]=D[u]+1,fdD(v,u);};
    function<void(int,int)>fdMnD=[&](int u,int p){
        bool d=false;
        for(auto v:g[u])if(v!=p)d=true,fdMnD(v,u),mnD[u]=min(mnD[u],mnD[v]);
        if(!d)mnD[u]=D[u];
    };
    vector<int>tin(N+1,0),tout(N+1);int t=0;
    function<void(int,int)>fdTour=[&](int u,int p){
        tin[u]=t++;
        for(auto v:g[u])if(v!=p)fdTour(v,u);
        tout[u]=t-1;
    };
    fdD(1,-1);fdMnD(1,-1);fdTour(1,-1);
    function<int(int,int)>lca=[&](int u,int v){
        if(D[u]>D[v])swap(u,v);
        for(int k=20;k>=0;k--){
            if(D[par[v][k]]>=D[u])v=par[v][k];
        }
        if(u==v)return u;
        for(int k=20;k>=0;k--){
            if(par[u][k]!=par[v][k])u=par[u][k],v=par[v][k];
        }
        return par[u][0];
    };
    // for(int i=1;i<=N;i++)printf("%d ",mnD[i]);
    vector<int>best(N+1,1);
    for(int d=0;d<=N;d++){
        struct R{int sort,in,out,u; strong_ordering operator<=>(const R& o){return tie(sort,in,out,u)<=>tie(o.sort,o.in,o.out,o.u);}};
        priority_queue<R,vector<R>,greater<R>>r;
        auto&row=byD[d];
        for(int i=0;i<(int)row.size()-1;i++){
            int anc=lca(row[i],row[i+1]);
            r.push({D[anc],tin[i],tout[i+1],anc});
        }
        if(r.empty())continue;
        while(r.size()>1){
            queue<R>nr;
            while(!r.empty()){
                auto t=r.front();r.pop();
            }
        }
        // printf("best depth %d = %d\n",d,best[d]);
    }
    for(int i=1;i<=N;i++)printf("%d ",best[i]);printf("\n");
    for(int i=1;i<=N;i++){
        best[i]=max(best[i],best[i-1]);
    }
    while(Q--){
        int d;cin>>d;
        cout<<best[d]<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎山火丁ミミ丁ビせせビビ丁ビ|
// |慶奏李汎山火ミヘㇸ　　　・一ヘㇵㇸ・・ㇸ|
// |和汎火ミㇵㇸ・ㇵㇸ　　・ㇸ・　ㇸㇵシシㇵ|
// |山ミ一一・一　　　・・　ㇸ一　・一ㇵミ火|
// |ミㇸ一ㇸㇸ・ㇵミ丁ビ丁ミヘ一シ丁火火火火|
// |ヘ・・ヘ・シビ山汎汎洪汎山火せ允洪労労労|
// |ヘ・ㇸㇵㇵビ允労和耗奏奏耗李汎せ火火山汎|
// |　ㇵ丁ビ火せ洪耗和李労労李和耗労允丁ㇵミ|
// |ヘビせせせ洪李汎允せせせせ山汎労允ビ一　|
// |丁火ㇵビ洪允火丁シㇵㇵㇵヘミビせせシ・一|
// |山ヘビ允ビヘ一　一ㇵㇵ一・・ㇵ丁丁ㇸ　・|
// |ビミ丁シ・ヘ・　ㇸ一一ㇸ　一　一一・ヘㇸ|
// |一・シ　一ㇸヘ・　ㇸ一ㇸ　・　ㇵ　ㇸ丁ㇵ|
// |ㇸ・ㇵㇸ　ヘㇸヘ　一・・ㇸㇵㇸ　・ㇸ一ㇵ|
// |一・ㇵㇸㇸ一一　ㇵ一ヘシシㇵㇸシ丁ビビ丁|
// |・・一　ㇵ　ヘㇸ一丁せ山允せビビシ一ㇸㇸ|
// |・ㇸ・・一一一一ビ允労和和汎ビㇵ　ㇵシヘ|
// |ㇸㇸヘヘ・一一火洪耗陽耗汎丁ㇸㇵビせ山火|
// |シ火せ丁ㇸ一火洪奏覇耗汎丁・シせ労和労允|
// |せ労洪ビㇸミ允耗慶陽李せㇵ一火労群義和允|
// +----------------------------------------+
// 2026 (May 17th) 18:32:06
// end signature
