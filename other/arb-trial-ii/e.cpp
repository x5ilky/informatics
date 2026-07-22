#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<vector<int>>A(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>A[i][j];
    auto solve=[&](int K){
        vector dp(N+1,vector<int>(N+1));
        int ans=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                if(dp[i-1][j]==0&&dp[i][j-1]==0)
                    dp[i][j]=0;
                if(A[i][j]>=K) {
                    dp[i][j]+=1;
                } else dp[i][j]=0;
                ans+=dp[i][j];
                // printf("%d ",dp[i][j]);
            }
            // printf("\n");
        }
        return ans;
    };
    cout<<solve(100)-solve(101)<<endl;
}
