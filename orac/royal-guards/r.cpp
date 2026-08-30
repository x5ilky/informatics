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
    freopen("royalin.txt","r",stdin);
    freopen("royalout.txt","w",stdout);
    int R,C;cin>>R>>C;
    int c=2;
    vector<vector<int>>rowid(R+1,vector<int>(C+1,-1));
    vector<vector<int>>colid(R+1,vector<int>(C+1,-1));
    vector<vector<int>>A(R+1,vector<int>(C+1,-1));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>A[i][j];
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(A[i][j]==2)c++;
            else rowid[i][j]=c;
        }
        c++;
    }
    for(int j=1;j<=C;j++){
        for(int i=1;i<=R;i++){
            if(A[i][j]==2)c++;
            else colid[i][j]=c;
        }
        c++;
    }
    dinics flow(c);
    vector<short>added(c+1);
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(A[i][j]==2)continue;
            if(!added[rowid[i][j]]){
                flow.add_edge(0,rowid[i][j],1);
                added[rowid[i][j]]=true;
            }
            if(!added[colid[i][j]]){
                flow.add_edge(colid[i][j],1,1);
                added[colid[i][j]]=true;
            }
        }
    }
    map<int,pair<int,int>>M;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(A[i][j]==0)
                M[flow.add_edge(rowid[i][j],colid[i][j],1)]={i,j};
        }
    }
    cout<<flow.flow(0,1)<<endl;
    for(auto [k,v]:M){
        if(flow.edges[k].flow==1)cout<<v.first<<" "<<v.second<<endl;
    }
}


// begin signature
// +----------------------------------------+
// |覇慶群耗李洪允允山允允洪労耗群慶覇覇覇覇|
// |陽耗労允せビミミミミ丁火允洪和群慶覇覇覇|
// |労允火ミㇵシシ丁火火火ビビ允労耗奏群陽慶|
// |せミ一ヘミ火允汎労労洪汎山火汎洪労李和奏|
// |シ・一丁ビ火山汎允允せ火ビビビビ火山汎労|
// |・　　ㇸㇸㇵシ丁丁ミミヘ一ㇸㇸㇸㇵシ丁火|
// |丁シㇵ一ㇸ一ㇸ　ㇸ　　　一ㇵヘヘㇵㇸ　一|
// |一・ㇸ一ㇵㇵㇵㇸ　ㇸ・　　　・一シビミヘ|
// |一ㇸヘ火火せ火ビミㇵシミミミヘ一　一ミ火|
// |　・丁汎労労洪允せ火允洪洪允火シ・　ㇵビ|
// |・シ山李群和労労労群耗労山火丁丁ミㇸㇸ丁|
// |・丁允和労李陽奏和耗汎山允山允山丁ヘ・ミ|
// |　シ山洪和慶慶群和労洪労汎山火丁シㇵㇸ　|
// |ㇸ・ミ山李群群和労李労汎せ丁ヘㇸ　・ㇸ・|
// |ビ一　シせ洪耗労労洪汎允丁ヘ　ㇵㇵ・ミビ|
// |允ビㇵ　ヘ火允洪山火ビビ火丁ㇵ　ㇸヘ　ㇸ|
// |労山丁ㇵ　ヘビせミㇵミビ火ビビ一　ㇵヘㇵ|
// |和汎せ丁ヘㇸヘシㇵビせ火ビせビㇵ丁火せビ|
// |耗汎汎せビ丁シヘミ丁火山汎汎ビ火汎山丁火|
// |李耗和労汎ビ一丁允汎労允火丁ビビ丁ビ山山|
// +----------------------------------------+
// 2026 (August 28th) 19:49:10
// end signature
