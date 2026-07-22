#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N,M,K;cin>>N>>M>>K;
        using pii=pair<int,int>;
        vector<vector<array<int,3>>>g(N+1);
        priority_queue<array<int,4>>pq;
        for(int i=1;i<=M;i++){
            int u,v,w;cin>>u>>v>>w;
            pq.push({w,u,v,i});
            g[u].push_back({v,w,i});
            g[v].push_back({u,w,i});
        }
        const int INF=1e9;
        vector<int>dist(N+1,INF);
        int tot=0;
        vector<int>HEAD(N+1);
        iota(HEAD.begin(),HEAD.end(),0);
        function<int(int)>head=[&](int u){
            return HEAD[u]==u?u:HEAD[u]=head(HEAD[u]);
        };
        auto join=[&](int u,int v){
            u=head(u),v=head(v);
            HEAD[u]=v;
        };
        for(int i=1;i<=N;i++){
            for(auto [v,w,_]:g[i]){
                if(w==0&&head(i)!=head(v))join(i,v);
            }
        }
        vector<int>HEAD2(N+1);
        iota(HEAD2.begin(),HEAD2.end(),0);
        function<int(int)>head2=[&](int u){
            return HEAD2[u]==u?u:HEAD2[u]=head2(HEAD2[u]);
        };
        auto join2=[&](int u,int v){
            u=head2(u),v=head2(v);
            HEAD2[u]=v;
        };
        vector<int>edges;
        for(int i=1;i<=N;i++){
            for(auto [v,w,j]:g[i]){
                if(w==1&&head(i)!=head(v)){
                    edges.push_back(j);
                    join(i,v);
                    join2(i,v);
                    tot++;
                }
            }
        }
        while (pq.size()){
            auto [w,u,v,i]=pq.top();pq.pop();
            if(head2(u)==head2(v))continue;
            if(tot>=K){
                if(w==1)continue;
                edges.push_back(i);
                join2(u,v);
            } else {
                if(w==0)continue;
                edges.push_back(i);
                join2(u,v);
                tot++;
            }
        }
        if(tot!=K||edges.size()!=N-1)cout<<-1;
        else for(auto v:edges)cout<<v<<" ";cout<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |陽耗李洪允山せ火丁ミシシシミ丁火山汎労和|
// |和洪允せビミシㇵ一・　　・ㇸㇵシビせ汎労|
// |允火丁ヘ一ㇸ　ㇸ一一一ㇸ・・　一シビ山允|
// |ビヘㇸㇸ　一・　ㇸ一ㇸㇸ一・・　ㇵミ丁火|
// |ヘ・ㇸ　ㇵ　　・　ㇸㇸㇸ・　・　　ㇸㇵシ|
// |ㇵ　・ㇸ一・　ㇸㇵシミミミシヘヘヘㇵㇸ　|
// |ㇵ　・ㇸㇵ・一シ丁ビせ山せ火ミビ火ビ丁ヘ|
// |ㇵ　・ㇸ一ヘミ山洪労李労労洪山山汎汎允火|
// |・一シヘミ山李奏群奏奏奏奏和洪洪和和労允|
// |ㇵ丁シせ李群奏和李和群義陽耗労耗陽群和汎|
// |ビミ労群耗耗群奏奏奏慶慶群李耗義義奏労山|
// |ビ李群耗群耗李労李奏群群和労耗奏耗李允ビ|
// |汎群耗奏和労汎允李群慶陽耗洪労労洪汎せミ|
// |汎群群耗労允せ允労奏義群耗労允允山せせ丁|
// |山奏群和洪山ビせ山労奏奏李洪山火丁ミシミ|
// |ビ和群和汎山丁丁山汎李和労允火ミㇵㇸ・・|
// |せ奏耗労山汎火シせ洪耗李汎火シㇸ　一ㇵㇵ|
// |労奏李允火允せ丁せ洪労汎火シ・一ミビビ丁|
// |奏和汎ビビ允山火火允洪火シ　ㇵビ山汎允火|
// |奏李允ビミ火允汎允労允丁一ㇸ丁山労李汎火|
// +----------------------------------------+
// 2026 (July 19th) 21:48:14
// end signature
