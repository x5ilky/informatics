#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<vector<int>>A(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>A[i][j];
    vector<vector<array<int,2>>>dp(N+1,vector<array<int,2>>(N+1));
    int ans=0;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
        if(A[i][j]<100)dp[i][j][0]=dp[i][j][0]=0;
        else {
            dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0]+1;
            dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1];
            if(A[i][j]==100)dp[i][j][1]=dp[i][j][0];
            ans+=dp[i][j][1];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) printf("%d,%d ",dp[i][j][0],dp[i][j][1]);
        printf("\n");
    }
    cout<<ans<<endl;
}
