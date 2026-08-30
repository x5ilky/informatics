#include <bits/stdc++.h>
using namespace std;
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
int main() {
    int N,M;cin>>N>>M;
}

