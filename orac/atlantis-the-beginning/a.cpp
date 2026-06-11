#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C;cin>>R>>C;
    vector<vector<int>>A(R+1,vector<int>(C+1));
    int sr,sc;cin>>sr>>sc;
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)cin>>A[i][j];
    auto id=[&](int r,int c){return ((r-1)*C)+c;};
    vector<vector<int>>g(R*C+1);
    vector<vector<int>>gback(R*C+1);
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(i>1)if(A[i-1][j]<A[i][j])g[id(i,j)].push_back(id(i-1,j));
            if(i<R)if(A[i+1][j]<A[i][j])g[id(i,j)].push_back(id(i+1,j));
            if(j>1)if(A[i][j-1]<A[i][j])g[id(i,j)].push_back(id(i,j-1));
            if(j<C)if(A[i][j+1]<A[i][j])g[id(i,j)].push_back(id(i,j+1));
        }
    }
    vector<int>indeg(R*C+1);
    for(int i=1;i<=R*C;i++)for(auto v:g[i])indeg[v]++;
    for(int i=1;i<=R*C;i++)for(auto v:g[i])gback[v].push_back(i);
    queue<int>dfs;
    for(int i=1;i<=R*C;i++){
        if(indeg[i]==0)dfs.push(i);
    }
    vector<int>topo;
    while(dfs.size()){
        auto u=dfs.front();dfs.pop();
        topo.push_back(u);
        for(auto v:g[u])if(--indeg[v]==0)dfs.push(v);
    }
    vector<int>path(R*C+1);
    reverse(topo.begin(),topo.end());
    for(auto u:topo){
        int mx=0;
        for(auto v:g[u])mx=max(mx,path[v]);
        path[u]=mx+1;
    }
    cout<<path[id(sr,sc)]<<endl;
}
