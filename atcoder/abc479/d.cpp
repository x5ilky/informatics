#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    int N,Q;cin>>N>>Q;
    Vec<int>L(N+1),R(N+1);
    for(int i=2;i<=N;i++)cin>>L[i];
    for(int i=1;i<=N-1;i++)cin>>R[i];
    StableMin l(L),r(R);
    while(Q--){
        int s,t;cin>>s>>t;
        int ans;
        if(s<t)ans=R[s];
        else ans=L[s];
        if(s<t)chmin(ans,L[s]+r.query_min(1,s));
        else chmin(ans,R[s]+l.query_min(s,N));
        cout<<ans<<endl;
    }
}
