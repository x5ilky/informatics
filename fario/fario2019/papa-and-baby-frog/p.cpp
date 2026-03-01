#include <bits/stdc++.h>

using namespace std;

int main() {
    const int INF=1e9+7;
    int N,K;cin>>N>>K;
    vector<int> H(N+2);
    for (int i=1;i<=N;i++) cin>>H[i];
    vector<vector<int>>adj(N+1);

    using pii=pair<int,int>;
    {
        set<pii> s,t;
        for (int i=1;i<=N;i++) {
            s.insert({H[i],i}); 
            t.insert({i,H[i]}); 
        }
        auto it=s.rbegin();
        while (it!=s.rend()) {
            auto i=it;
            int v=it->first;
            while (it!=s.rend()&&it->first==v) {
                t.erase({it->second,it->first});
                it++;
            }
            if (t.empty()) break;
            int val=t.rbegin()->first;
            while (i!=s.rend()&&i->first==v) {
                s.erase(i);
                it++;
            }

            it++;
        }
    }



    vector<int>dist(N+1,INF);
    function<void(int)>dfs=[&](int node) {
        for (auto&e:adj[node]){
            if(dist[e]!=INF) continue;
            if((dist[e]=dist[node]+1)>K) continue;
            dfs(e);
        }
    };
    vector<set<int>>isee(N+1);
    for (int i=1;i<=N;i++){
        fill(dist.begin(),dist.end(),INF);
        dist[i]=0;
        dfs(i);
        for(int k=1;k<=N;k++) {
            if(k==i)continue;
            if(dist[k]<=K)
                isee[i].insert(k);
        }
    }
    string str{};
    for (int i=1;i<=N;i++){
        bool works=false;
        printf("i=%d\n",i);
        for (auto j:isee[i]){
            printf("\tj=%d\n",j);
            if(isee[j].find(i) != isee[j].end()) {
                works=true; break;
            }
        }
        str+=works?"1":"0";
    }
    cout<<str<<endl;
}
