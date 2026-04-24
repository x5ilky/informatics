#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
signed main() {
    int N,C;cin>>N>>C;
    using pii=pair<int,int>;
    vector<pii>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i].first>>P[i].second;
    // const int INF=1ull<<60;
    const int INF=1ull<<60;
    sort(P.begin()+1,P.end(),greater<pii>());
    vector<vector<int>>dp(N+10,vector<int>(N+10,-INF));
    int ans=-INF;
    dp[1][N+1]=0;
    for(int g=1;g<=N;g++){
        vector<vector<int>>ndp(N+10,vector<int>(N+10,-INF));
        for(int pf=1;pf<=N;pf++){
            for(int sf=pf+1;sf<=N+1;sf++){
                int c=min(P[pf].second,sf-pf);
                // printf("dp[%d][%d][%d]=%d+%d*%d\n",g,pf+1,sf-(c-1),dp[g-1][pf][sf],P[pf].first,c);
                ndp[pf+1][sf-(c-1)]=max(ndp[pf+1][sf-(c-1)],
                        dp[pf][sf]+P[pf].first*c);
            }
        }
        dp=ndp;
        for(int i=1;i<=N;i++){
            ans=max(ans,dp[i][i]-g*C);
        }
    }
    cout<<ans<<endl;
}
