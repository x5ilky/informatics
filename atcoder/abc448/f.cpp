#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    using pii=pair<int,int>;
    int N;cin>>N;
    vector<pii> loc(N+1);
    for (int i=1;i<=N;i++){
        int x,y;cin>>x>>y;
        loc.push_back({x,y});
    }
}
