#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>A(N+1),B(N+1);
        for(int i=1;i<=N;i++)cin>>A[i];
        for(int i=1;i<=N;i++)cin>>B[i];
        vector<int>dp(N+1);
        dp[N]=1+(A[N]==B[N]);
        for(int i=N-1;i>=1;i--){
            dp[i]=dp[i+1]+2+(A[i]==B[i+1])+(B[i]==A[i+1]);
        }
        int ans=0,c=0;
        for(int i=1;i<=N;i++){
            ans=max(ans,dp[i]+c);
            c+=1+(A[i]==B[i]);
            if(i!=N)c+=1+(B[i]==A[i+1]);
        }
        cout<<ans<<endl;
    }
}
