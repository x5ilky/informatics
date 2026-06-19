#include "maze.h"
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) printf(__VA_ARGS__)
#else
#define dbg(...)
#endif
void map_maze(int N)
{
    vector<vector<int>>adj(N+1);
    int components=N;
    vector<int>HEAD(N+1);for (int i=1;i<=N;i++)HEAD[i]=i;

    function<int(int)> head=[&](int u){
        if(HEAD[u]==u)return u;
        return HEAD[u]=head(HEAD[u]);
    };
    auto join=[&](int u,int v){
        if ((u=head(u))==(v=head(v))) return;
        components--;
        HEAD[u]=v;
    };

    function<void(int,int)> map=[&](int u,int v) {
        if(head(u)==head(v))return;
        dbg("map %d %d\n",u,v);
        int idx=query(u,v);

        if (idx==-1){
            join(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            map(u,idx);map(idx,v);
            join(u,v);
        }
    };
    function<int(int,int)>split=[&](int lo,int hi) {
        dbg("split %d %d\n",lo,hi);
        if (lo==hi) return head(lo);
        if (lo+1==hi){
                map(lo,hi);
            return head(lo);
        }
        int mid=(lo+hi)/2;
        int left=split(lo,mid);
        int right=split(mid+1,hi);
        if(head(left)!=head(right))
            map(left,right);
        return head(left);
    };
    split(1,N);

    for(int i=1;i<=N;i++){
        auto sorted=set<int>(adj[i].begin(),adj[i].end());
        adj[i]=vector<int>(sorted.begin(),sorted.end());
    }
    function<void(int,int)> dfs=[&](int node,int p){
        for (auto& e : adj[node]){
            if(e!=p) {
                dbg("edge: %d %d\n",node,e);
                report_passageway(node,e);
                dfs(e,node);
            }
        }
    };
    dfs(1,-1);
}
