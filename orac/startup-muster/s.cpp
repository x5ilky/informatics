#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    const int INF=1ull<<60;
    using pii=pair<int,int>;
    vector<pii>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i].first>>P[i].second;
    sort(P.begin()+1,P.end(),greater<pii>());
    vector<int>dp(N+1,-INF);dp[0]=0;
    for(int i=1;i<=N;i++){
        vector<int>ndp=dp;
        for(int j=0;j<=N;j++){
            for(int c=1;c<=min(N-j,P[i].second);c++){
                ndp[j+c]=max(ndp[j+c],dp[j]+P[i].first*c-K); 
            }
        }
        dp=ndp;
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=N;j++){
    //         printf("%3lld ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans=-INF;
    for(int i=1;i<=N;i++){
        ans=max(ans,dp[N]);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火ビ丁丁丁丁ビ火せ山汎労和|
// |和労允せビミシヘㇵ一ㇸㇸ一ヘシミビせ允洪|
// |汎せ丁ヘ一ㇸ・　ㇸ一一一・　・一ヘ丁せ汎|
// |ビシㇸㇸ　・ㇸ・一一　・ㇸㇸㇸ　ㇸヘビ山|
// |ヘ・ㇸㇸㇸ　一ㇸ　ㇸ一一一ㇸ　　　・ヘビ|
// |ㇵ　・　ㇵヘ・ㇸヘミ丁丁丁丁シㇵ・ㇸ　ヘ|
// |ㇵ　　　　　　　　ㇸㇵシビ火火火丁ヘ・ㇸ|
// |ヘ　ㇸヘシヘㇵ一ㇸㇵヘヘㇵミせ山允火ミ一|
// |一ㇸㇵビシヘ一ㇸ・・ㇸ一ヘシ丁ビ火山火シ|
// |　・シ一　・一ㇵㇵㇸ　・ㇸㇸ一ヘミビせシ|
// |　一　ㇵシ丁ヘ・　ㇸ一一一ㇸ・　一シビヘ|
// |　一シビシㇸ・ㇵシ丁丁ビ丁ミヘ一　一シㇵ|
// |一ミ火ミ一一シビせ山允允允山火丁ヘ・ㇸヘ|
// |ㇵ丁せミㇸヘビせ汎洪李李李労汎山火ミ一　|
// |ㇵビ山丁一シ火允労和奏奏李汎山ビミシシヘ|
// |ㇵビ山丁一ミせ洪和奏義奏労允ビシ一・　　|
// |シ火せシヘビ允李奏義群和汎火シㇸㇸㇵヘヘ|
// |ビ允丁ㇵビ允李群慶陽和汎火シ　ㇵ丁火火ビ|
// |山火ヘ丁山労奏慶義耗洪せシ　ヘビ允洪允火|
// |山丁ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 24th) 17:50:11
// end signature
