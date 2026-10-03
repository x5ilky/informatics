#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>W(N+1);
    for(int i=1;i<=N;i++)cin>>W[i];
    vector<array<int,4>>dp(K+1);
    for(int i=1;i<=N;i++){
        for(int k=3;k>=1;k--)
            for(int j=1;j<=K;j++)
                if(j-i>=0)dp[j][k]=max(dp[j][k],dp[j-i][k-1]+W[i]);
    }
    int mx=0;
    for(int i=0;i<=K;i++)mx=max(mx,dp[i][3]);
    cout<<mx<<endl;
}
