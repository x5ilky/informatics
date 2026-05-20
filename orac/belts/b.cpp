#include <bits/stdc++.h>
using namespace std;
#define int long long
int& chmin(int& a,int v){
    return a=min(a,v);
}
signed main() {
    int T,ST,SW,K;cin>>T>>ST>>SW>>K;
    int N;cin>>N;
    vector<int>D(N+1);
    for(int i=1;i<=N;i++)cin>>D[i];
    vector<int>dD(N+1);
    for(int i=1;i<=N;i++)dD[i]=D[i]-D[i-1];
    const int INF=1ull<<60;
    vector<vector<array<int,2>>>dp(N+1,vector<array<int,2>>(K+1,{INF,INF}));
    dp[0][0][0]=0;
    for(int i=1;i<=N;i++){
        for(int c=0;c<=K;c++){
            chmin(dp[i][c][0],dp[i-1][c][0]+dD[i]*ST);
            chmin(dp[i][c][0],(dp[i-1][c][1]-D[i-1]+T-1)/T*T+D[i-1]+dD[i]*ST);
            chmin(dp[i][min(c+dD[i],K)][1],dp[i-1][c][0]+dD[i]*SW);
            chmin(dp[i][min(c+dD[i],K)][1],dp[i-1][c][1]+dD[i]*SW);
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int c=0;c<=K;c++){
    //         if(dp[i][c][0]<INF)printf("dp[%lld][%lld][0]=%lld ",i,c,dp[i][c][0]);
    //         if(dp[i][c][1]<INF)printf("dp[%lld][%lld][1]=%lld ",i,c,dp[i][c][1]);
    //     }
    //     printf("\n");
    // }
    cout<<min(dp[N][K][0],dp[N][K][1])<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏李洪汎山せ火火火ビビミシシシシミビせ|
// |和労允せビミシヘヘヘㇵ一・　　　・一ヘミ|
// |允せ丁ヘ一ㇸㇸ　　・・一ㇵヘヘㇵ一　・ヘ|
// |ビヘㇸㇸ・・一一ㇸヘミビ火火火ビミヘ・ㇸ|
// |ヘ・ㇸ　一一　一シビせ允汎汎山せ火ビシㇸ|
// |一　一・一一・ヘ丁山汎労洪山ビミシヘヘミ|
// |一ㇸ　一シ一　ヘビ允労李汎せ丁ミヘㇸ　　|
// |丁丁シヘシㇸ　ヘビ允李李労洪允ビヘミㇵ　|
// |山山せ丁ㇵ・・シせ洪耗奏奏和洪山丁ヘミ一|
// |李允ビㇵㇸ　ヘビ汎和群慶義耗労せミㇵ丁ㇵ|
// |汎ビヘ一ㇸ一丁山李奏慶慶群李允ビㇵㇵ丁一|
// |せミㇵ　　ヘ火汎和奏群群和汎火シ　ヘミ・|
// |ビヘ　ㇵㇸㇵビ允李和李李洪山ビㇵ　ㇵ丁ㇸ|
// |ビㇵ　ヘシ　ヘビ允李李允山火ミ一ㇸㇵヘヘ|
// |ミヘ　ヘビシ　ㇵ丁山洪李汎火ミ一ヘシシミ|
// |ㇸㇸ　　ㇵ丁ヘ　ㇵ丁せ允洪汎せビシヘㇵㇵ|
// |ㇵㇸ・一　ㇵミㇵ　ㇵミ火山允汎山せビビミ|
// |丁シㇵシㇵㇸㇵ一ㇸヘシミビビビビ丁シㇵ　|
// |せ丁ミビミシ一一ミ火丁ビヘㇵㇵ一ㇸ　一シ|
// |允ビ丁山火シ　ヘ火せビ丁一・・ㇸㇵシ丁火|
// +----------------------------------------+
// 2026 (May 20th) 19:28:56
// end signature
