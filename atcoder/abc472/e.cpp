#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N,M;cin>>N>>M;
        vector<vector<int>>g(N+1);
        for(int i=1;i<=M;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int>dist(N+1,-1),back(N+1,-1);
        vector<int>cycle;
        bool done=false;
        function<void(int,int)>dfs=[&](int u,int p){
            for(auto v:g[u]){
                if(done)break;
                if(v==p)continue;
                if(dist[v]!=-1){
                    if(dist[v]%2==dist[u]%2){
                        done=true;
                        int x=u,y=v;
                        vector<int>a,b;
                        while(dist[x]>dist[y])a.push_back(x),x=back[x];
                        while(dist[y]>dist[x])b.push_back(y),y=back[y];
                        while(x!=y){
                            a.push_back(x);b.push_back(y);
                            x=back[x];y=back[y];
                        }
                        a.push_back(x);
                        cycle=a;
                        reverse(b.begin(),b.end());
                        for(auto i:b)cycle.push_back(i);
                        return;
                    }
                    continue;
                }
                back[v]=u;dist[v]=dist[u]+1;
                dfs(v,u);
            }
        };
        dist[1]=0;dfs(1,-1);
        if(!done)cout<<-1<<endl;
        else{
            cout<<cycle.size()<<endl;
            for(auto i:cycle)cout<<i<<" ";
            cout<<endl;
        }
    }
}
