#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    using pii=pair<int,int>;
    vector<pii>pts(N+1);
#define x first
#define y second
    for(int i=1;i<=N;i++)cin>>pts[i].x>>pts[i].y;
    vector<vector<int>>col(10001);
    for(int i=1;i<=N;i++)col[pts[i].x].push_back(pts[i].y);
    for(int i=0;i<=10000;i++)sort(col[i].begin(),col[i].end());
    
    const int INF=1ull<<60;
    vector<array<int,2>>dp(10001,{INF,INF});
    int p=-1;
    for(int i=0;i<=10000;i++){
        if(col[i].empty())continue;
        int gap=col[i].back()-col[i].front();
        if(p==-1)dp[i][0]=dp[i][1]=gap;
        else {
            dp[i][0]=min(dp[p][0]+gap+i-p+abs(col[i].back()-col[p].front()),
                         dp[p][1]+gap+i-p+abs(col[i].back()-col[p].back()));
            dp[i][1]=min(dp[p][0]+gap+i-p+abs(col[i].front()-col[p].front()),
                         dp[p][1]+gap+i-p+abs(col[i].front()-col[p].back()));
        }
        p=i;
    }
    cout<<min(dp[p][0],dp[p][1])<<endl;
}
