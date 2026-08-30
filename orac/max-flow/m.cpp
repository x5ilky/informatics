#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dinics{
    vector<vector<int>>g;
    struct edge{
        int u,v,cap,flow=0;
        edge(int u,int v,int cap):u(u),v(v),cap(cap){}
    };
    vector<edge>edges;
    vector<int>level,ptr;
    int N,M;
    dinics(int N):N(N),g(N),M(0),level(N,-1),ptr(N,-1){};
    void add_edge(int u,int v,int w){
        edges.push_back({u,v,w});
        edges.push_back({v,u,0});
        g[u].push_back(M++);
        g[v].push_back(M++);
    }
    bool bfs(int s,int t){
        queue<int>q;q.push(s);
        while(q.size()){
            int u=q.front();q.pop();
            for(auto e:g[u]){
                if(edges[e].cap==edges[e].flow)continue;
                if(level[edges[e].v]!=-1)continue;
                level[edges[e].v]=level[u]+1;
                q.push(edges[e].v);
            }
        }
        return level[t]!=-1;
    }
    int dfs(int u,int mn,int t){
        if(mn==0)return 0;
        if(u==t)return mn;
        for(int&i=ptr[u];i<g[u].size();i++){
            int e=g[u][i];
            int v=edges[e].v;
            if(level[u]+1!=level[v])continue;
            if(edges[e].cap==edges[e].flow)continue;
            int f=dfs(v,min(mn,edges[e].cap-edges[e].flow),t);
            if(f==0)continue;
            edges[e].flow+=f;
            edges[e^1].flow-=f;
            return f;
        }
        return 0;
    }
    int flow(int s,int t){
        int f=0;
        while(1){
            fill(level.begin(),level.end(),-1);
            level[s]=0;
            if(!bfs(s,t))break;
            fill(ptr.begin(),ptr.end(),0);
            while(int p=dfs(s,1e9,t))f+=p;
        }
        return f;
    }
};
signed main() {
    int N,M;cin>>N>>M;
    dinics flow(N+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        flow.add_edge(u,v,w);
        flow.add_edge(v,u,w);
    }
    cout<<flow.flow(1,N)<<endl;
}


// begin signature
// +----------------------------------------+
// |覇慶群耗李洪允允山允允洪李耗群慶覇覇覇覇|
// |陽耗労允せビミミミミ丁火允洪和群慶覇覇覇|
// |労允火ミビミシ丁火火火ビビ允労奏義覇覇覇|
// |せミㇵビミ火允汎労労洪汎山火汎和陽覇覇覇|
// |ミ・シ丁山洪李耗奏群奏耗李洪汎労奏慶覇覇|
// |ヘ　ㇵビ汎和群義覇慶陽群奏奏奏和労奏覇覇|
// |ヘ・ㇵビ汎耗陽義陽群耗奏陽義慶慶陽耗奏覇|
// |シ・一ビ汎耗群耗和李労労李李耗奏群陽奏群|
// |ㇵㇸヘせ労和労汎允せせせせ山汎洪労李和耗|
// |　・丁汎洪允火丁シヘヘヘシミビせせ山汎労|
// |・シ山山ビシ一　・ㇸ・　　ㇸㇵヘシ丁火山|
// |・丁火シㇸ・ㇸ　一ㇵヘヘㇵ・　　　一シビ|
// |　シシ・一　ㇵシㇵㇸ・・一ヘヘ・ㇸㇵ　ㇵ|
// |ㇸ・ヘ・・一シㇸ・ㇵ　ㇸ一一一・・ㇸヘ一|
// |ビ一　・　ヘヘ　ヘ・一ミビヘ　一シ丁丁丁|
// |允ビㇵㇸ　ミ一ㇸㇵ・シ火丁ㇸ一ミヘ一ㇸㇸ|
// |汎丁ㇸㇸ　ヘ　シ　ヘㇵヘㇵㇸミㇵ　ㇵヘヘ|
// |火ㇵ一一ヘ・ヘ　・ㇸ一　・丁ㇸㇵ丁せせ火|
// |シ・・丁一ㇵㇸ・ミビ丁一丁・ヘせ洪李洪山|
// |一ㇸヘ丁・シ　シ山汎ビヘㇵ一ビ洪耗耗汎山|
// +----------------------------------------+
// 2026 (August 28th) 18:29:34
// end signature
