#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<vector<int>>g(N+1);
        for(int i=1;i<=N-1;i++){
            int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
        }
        if(g[N].size()==1){
            cout<<1<<endl;
            continue;
        }
        vector<vector<int>>par(N+1,vector<int>(20)),pmax(N+1,vector<int>(20));
        int mleaf=0;
        int t=1;
        vector<int>tin(N+1),tout(N+1);
        function<void(int,int)> dfs=[&](int u,int p){
            pmax[u][0]=u;
            tin[u]=t++;
            for(auto v:g[u]){
                if(v==p)continue;
                par[v][0]=u;
                for(int k=1;k<20;k++)par[v][k]=par[par[v][k-1]][k-1];
                dfs(v,u);
            }
            tout[u]=t;
            if(g[u].size()==1&&g[u][0]==p)mleaf=max(mleaf,u);
        };
        for(int i=0;i<20;i++)par[N][i]=N;
        dfs(N,-1);
        for(int k=1;k<20;k++)
            for(int i=1;i<=N;i++)
                pmax[i][k]=max(pmax[i][k-1],pmax[par[i][k-1]][k-1]);

        vector<int>deg(N+1,0);vector<int>used(N+1,0);vector<mint>dp(N+1);mint sum=1;
        dp[N]=1;
        for(int i=1;i<=N;i++)sort(g[i].begin(),g[i].end(),[&](int a,int b){
            return tout[a]<tout[b];
        });
        set<int>leaves={N};
        for(int i=N-1;i>=1;i--){
            int u=i;
            for(int k=19;k>=0;k--)if(pmax[u][k]<=i)u=par[u][k];
            dp[i]=dp[*leaves.rbegin()]*(leaves.size()-1);
            if(leaves.size()>=2)dp[i]+=dp[*----leaves.end()];
            if(deg[N]<2)dp[i]=1;
            auto connection=*partition_point(g[u].begin(),g[u].end(),[&](int u){
                return tout[u]<tout[i];
            });
            if(!used[connection]){
                if(++deg[u]>=2)leaves.erase(u);
                used[connection]=1;
            }
            sum+=dp[i]*(deg[N]>=2);
            leaves.insert(i);
            printf("value %d, sum %d par %d <- %d\n",dp[i].val(),sum.val(),i,u);
        }
        cout<<dp[mleaf].val()<<endl;
    }
}
