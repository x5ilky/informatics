#include "silky/stl.hpp"
using namespace std;
#define int long long
const int INF=1e18;
signed main() {
    READ(int,N,M);
    Vec<pii>A(N+1);read(A);
    Vec<pii>B(M+1);read(B);
    Vec<Vec<ai2>>dp(N+1,Vec<ai2>(M+1,{INF,INF}));
    dp[1][0]={0,INF};
    FOR(i,1,N){
        FOR(j,0,M){
            if(i>1)dp[i][j][0]=min(dp[i-1][j][0]+sqdist(A[i-1],A[i]),dp[i-1][j][1]+sqdist(B[j],A[i]));
            if(j>0)chmin(dp[i][j][1],dp[i][j-1][0]+sqdist(A[i],B[j]));
            if(j>1)chmin(dp[i][j][1],dp[i][j-1][1]+sqdist(B[j-1],B[j]));
        }
    }
    cout<<dp[N][M][0]<<endl;
}
