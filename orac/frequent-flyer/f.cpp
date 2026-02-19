#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    int N; cin >> N;
    using pii=pair<int,int>;
    vector<vector<pii>> adj(N+1);
    for (int r=1;r<=N;r++) {
        for (int c=1;c<=N;c++) {
            int w;cin>>w;
            if (w!=-1)adj[r].push_back({c,w});
        }
    }

    for (int u=1;u<=N;u++) {
        const int INF=1e9+7;
        vector<int>dist(N+1,INF);
        vector<int>back(N+1,-1);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,1});
        while (!pq.empty()) {
            auto [d,u]=pq.top();
            pq.pop();
            if (d>dist[u])continue;
            for (auto&[v,w]:adj[u]){
                if (d+w<dist[v]) {
                    back[v]=u;
                    dist[v]=d+w;
                    pq.push({d+w,v});
                }
            }
        }
        vector<int>path;
        int p=N;
        while (p!=1){
            path.push_back(p);
            p=back[p];
        }
        path.push_back(p);
        reverse(path.begin(),path.end());
        for (auto&v:path) printf("%d ",v);
        printf("\n");
    }
}
