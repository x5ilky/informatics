#include "island.h"
#include <bits/stdc++.h>
using namespace std;
void solve(int N, int L) {
    vector<bool>seen(N+1);
    vector<pair<int,int>>e;
    function<void(int,int)> dfs=[&](int u,int p){
        seen[u]=true;
        int f=query(u,1),s=query(u,2);
        if(s==query(f,1))return;
    };
    dfs(N,-1);
    printf("%d\n",e.size());
    for (auto [u,v]:e) {
        printf("%d <-> %d\n",u,v);
        answer(u,v);
    }
}
