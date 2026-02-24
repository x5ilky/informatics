#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    int M,A,B;cin>>M>>A>>B;

    vector<vector<int>>adj(M*M+10);
    for (int x=0;x<=M-1;x++){
        for (int y=0;y<=M-1;y++){
            int z=(x*B+y*A)%M;
            adj[y*M+z].push_back(x*M+y);
        }
    }
    vector<int> seen(M*M+10,false);
    queue<int> q;
    for (int x=0;x<=M-1;x++) {
        for (int y=0;y<=M-1;y++) {
            if (x==0||y==0) {
                int i=x*M+y;
                seen[i]=true;
                q.push(i);
            }
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (auto& e : adj[v]) {
            if (seen[e]) continue;
            seen[e]=true;
            q.push(e);
        }
    }

    int ans=0;
    for (int x=0;x<=M-1;x++) {
        for (int y=0;y<=M-1;y++) {
            if(!seen[x*M+y])ans++;
        }
    }
    cout<<ans<<endl;
}
