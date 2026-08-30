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
    int add_edge(int u,int v,int w){
        edges.push_back({u,v,w});
        edges.push_back({v,u,0});
        g[u].push_back(M++);
        g[v].push_back(M++);
        return M-2;
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
    freopen("caffin.txt","r",stdin);
    freopen("caffout.txt","w",stdout);
    int W,H,N;cin>>W>>H>>N;
    using pii=pair<int,int>;
    vector<pii>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i].first>>A[i].second;
    dinics flow(2*N+2);
    int S=0,T=2*N+1;
#define in(u) (u)
#define out(u) (u+N)
    for(int i=1;i<=N;i++){
        if(A[i].second-100<=0)flow.add_edge(S,in(i),1e9);
        if(A[i].second+100>=H)flow.add_edge(out(i),T,1e9);
        flow.add_edge(in(i),out(i),1);
        for(int j=1;j<=N;j++){
            if(i==j)continue;
            int dy=A[i].second-A[j].second;
            int dx=A[i].first-A[j].first;
            if(dx*dx+dy*dy<=200*200)
                flow.add_edge(out(i),in(j),1e9),
                flow.add_edge(out(j),in(i),1e9);
        }
    }
    cout<<flow.flow(S,T)<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇慶陽耗李労洪汎洪洪李耗群慶覇覇覇覇覇|
// |覇陽耗洪允火ビ丁丁丁火山洪和群慶覇覇覇覇|
// |耗洪せ丁ミ丁ミ火せ山山せせ洪耗義覇覇覇覇|
// |允丁一丁丁山洪李和和和労汎山李群覇覇覇覇|
// |丁ㇸヘビ允李奏陽慶義義陽耗李労和義覇覇覇|
// |シ・ヘせ労奏群耗和和和和耗群義群和義覇覇|
// |シ・ㇵせ労耗労汎允山山山允汎労耗群陽義義|
// |ミ・ㇵせ李洪山ビビ允洪労汎せビ山洪労李李|
// |ヘㇸシ山允火允耗　一一・　　ㇸヘビ火せせ|
// |　ㇸ火せ山奏一ㇸ　ㇸシミㇵㇸ　　・一一一|
// |・ミビ奏ㇸ・一ㇵミシ・　ㇸヘミミヘ一ㇸ一|
// |・ビ洪ㇵㇸミビシ丁丁丁ミㇵ・一ミせ丁ㇵ丁|
// |　ミ　　ミ丁火允汎洪洪允せ丁ㇵ・ミ火ヘㇸ|
// |ㇸ・　・丁せ洪和奏群李労允ビヘ・　ヘせシ|
// |　ㇵ　・丁允李群奏耗和労せシ・ㇵミビ火ビ|
// |火火ㇵ　シせ洪耗労允山允ビ一一丁シㇵㇸ一|
// |ㇸ汎一ヘ・シせ汎火ミヘシヘㇸ丁ㇵ　ㇵシヘ|
// |汎一ㇵビシ一シミㇸㇸ一　ㇸビㇸㇵビ山允せ|
// |・一火允せビシ・丁火ビ一ビ・シ山李耗労せ|
// |　シ允和洪丁　ミ汎労せヘヘㇵせ李和洪火山|
// +----------------------------------------+
// 2026 (August 28th) 20:45:35
// end signature
