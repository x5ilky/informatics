#include <bits/stdc++.h>
using namespace std;
#define int long long
int&chmax(int&a,int v){
    a=max(a,v);
    return a;
}
signed main() {
    const int INF=1ull<<60;
    int N,K;cin>>N>>K;
    vector<int>R(K+2);for(int i=1;i<=K;i++)cin>>R[i];
    vector<vector<int>>A(N+2,vector<int>(N+2,0));
    for(int i=1;i<=N;i++)for(int j=1;j<=i;j++)cin>>A[i][j];
    vector<vector<vector<int>>>dp(N+2,vector<vector<int>>(N+2,vector<int>(N+2,-INF)));
    for(int i=1;i<=N+1;i++)for(int j=1;j<=N+1;j++)dp[i][j][0]=0;
    for(int i=N;i>=1;i--){
        for(int j=1;j<=i;j++){
            for(int t=1;t<=N;t++){
                dp[i][j][t]=max(dp[i+1][j][t],dp[i+1][j+1][t]);
                int below=max(dp[i+1][j][t-1],dp[i+1][j+1][t-1]);
                chmax(dp[i][j][t],A[i][j]+below);
            }
        }
    }

    sort(R.begin()+1,R.end()-1);
    reverse(R.begin()+1,R.end()-1);
    int ans=dp[1][1][N],s=0;
    for(int t=1;t<=K;t++){
        s+=R[t];
        chmax(ans,dp[1][1][N-t]+s);
    }
    // for(int t=1;t<=N;t++){
    //     printf("t=%d\n",t);
    //     for(int i=1;i<=N;i++){
    //         for(int j=1;j<=i;j++){
    //             printf("%2lld ", dp[i][j][t]);
    //         }
    //         printf("\n");
    //     }
    // }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏李洪汎山せ火火火ビビ丁ミシシミ丁ビせ|
// |和労允せビミシヘヘヘㇵㇵㇸ・・・ㇸㇵヘ丁|
// |允せ丁ヘ一ㇸ一・　・・一ㇵㇵㇵㇵㇸ　ㇸヘ|
// |ビヘㇸㇸㇸ　一・・ㇵミ丁ビビビ丁シㇵ・ㇸ|
// |ヘ・ㇸ・ㇸ・一ㇸシビせ允汎汎山せ火丁ヘ・|
// |一　一　ㇸ一ㇵㇵ丁せ汎労洪山ビミヘヘヘシ|
// |・ㇸㇸ一シミシヘビ山労李汎せ丁ㇵヘㇵㇵㇵ|
// |シミ丁ミシビヘヘビ允李李労洪允ビヘ・　・|
// |火山せミビミㇸシせ洪耗奏奏和労山丁一ㇸミ|
// |汎山丁丁丁一ヘビ汎和群慶義耗労せミ・ㇵビ|
// |允ビシビシㇵ丁允李奏慶覇群李允ビㇵ・ミ火|
// |火ビ丁丁一ヘ火汎和奏群群和汎火シ・ㇸシミ|
// |火ミシビヘㇵビ允李和李李洪山火丁シㇸ・シ|
// |火シ・ヘビシビ山汎李李和李洪允せ火丁ㇵ　|
// |火シ　ㇵ一シ火允労和奏奏李汎せ丁シヘㇵヘ|
// |火シ　ㇵ一ミせ洪和群陽耗労洪山ビミヘㇵㇵ|
// |ビㇵ・ㇸヘ火汎李群義群李允允汎允せ火ビミ|
// |ヘ　ㇵㇵビ允李群慶陽和汎火ビ火ビ丁ミㇵ・|
// |・一ㇸ丁山労奏慶陽和洪火シヘヘㇵㇸ　ㇸヘ|
// |　一ヘ火汎和陽慶群李允丁一　・ㇸㇵシ丁火|
// +----------------------------------------+
// 2026 (April 17th) 21:59:51
// end signature

