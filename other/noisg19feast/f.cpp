#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    auto solve=[&](int lam){
        using pii=pair<int,int>;
        vector<array<pii,2>>dp(N+1);
        dp[0][1]={-1ull<<60,-1};
        for(int i=1;i<=N;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=max(
                pii{dp[i-1][0].first-lam+A[i],dp[i-1][0].second+1},
                pii{dp[i-1][1].first+A[i],dp[i-1][1].second}
            );
        }
        return max(dp[N][0],dp[N][1]);
    };
    int lo=0,hi=1e18;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        (solve(mid).second>=K?lo:hi)=mid;
    }
    cout<<solve(lo).first+K*lo<<endl;
}
