#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, W; cin>>N>>W;
    vector<int> rw(N+1),rv(N+1);
    for(int i=1;i<=N;i++) cin>>rw[i]>>rv[i];

    vector<vector<int>> v(W+1);
    for (int i=1;i<=N;i++){
        v[rw[i]].push_back(rv[i]);
    }
    vector<vector<int>>dp(W+1,vector<int>(W+1));
    for (int i=1;i<=W;i++){
        for (int c=1;c<=W;c++){
            dp[i][c]=dp[i-1][c];
            for(int k=1;k<=W;k++){
                if(i*k>W)break;
                if(c>=i*k)
                    dp[i][c]=max(dp[i][c],dp[i-1][c-i*k]+v[i]*k-k*k);
            }
        }
    }
    for (int i=1;i<=W;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i=1;i<=W;i++){
        for (int c=1;c<=W;c++){
            printf("%d ", dp[i][c]);
        }
        printf("\n");
    }
    cout << dp[W][W] << endl;
}
