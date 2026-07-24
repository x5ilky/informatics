#include <bits/stdc++.h>
using namespace std;
int main () {
    vector<vector<int>>dp(16+1,vector<int>(200));
    for(int i=1;i<=16;i++){
        for(int k=1;k<=32;k++){
            for(int j=1;j<=i-1;j++){
                int dk=(j<=2?2:5);
                if(k-dk<0)continue;
                dp[i][k]=max(dp[i][k],dp[i-j][k-dk]+dk);
            }
            printf("%3d ",dp[i][k]);
        }
        printf("\n");
    }
    return 0;
}
