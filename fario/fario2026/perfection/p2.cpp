#include <bits/stdc++.h>

using namespace std;

// #define printf(...)
#define int long long
const int INF=(1ULL<<60);
signed main() {
    int N,A,D,M;cin>>N>>A>>D>>M;
    vector<int>count(5010,0);
    set<int>Vr{};
    for (int i=1;i<=N;i++){
        int v; cin>>v; count[v]++;
        Vr.insert(v);
    }
    vector<int>V(Vr.begin(),Vr.end());
    int ans=0;
    for (auto v : V) {
        int best=INF;
        if(count[v]>v)best=min(best,D*(count[v]-v));
        best=min(best,D*count[v]);
        if(count[v]<v)best=min(best,A*-(count[v]-v));
        if(count[v]==v)best=0;
        ans+=best;
    }
    cout<<ans<<endl;
}
