#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
signed main() {
    int N,M;cin>>N>>M;
    vector<int>A(N+1),B(M+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=M;i++)cin>>B[i];
    vector<int>C(N+M+1);
    for(int i=1;i<=N;i++)C[i]=A[i];
    for(int i=1;i<=M;i++)C[i+N]=B[i];
    sort(C.begin()+1,C.end());
    vector<int>dp(N+M+1,INF);
    int pi=1,dp1=0,dp2=0,dp1n=-2*C[1],dp2n=-C[1];
    for(int i=1;i<=N+M;i++){
        dp1n=min(dp1n,dp[i-1]-2*C[i]);
        dp2n=min(dp2n,dp[i-1]-C[i]);
        if(pi<=M&&C[i]>=B[pi]){
            pi++;
            dp1=dp1n;
            dp2=dp2n;
            dp1n=INF;
            dp2n=INF;
        }
        if(pi==1)continue;
        int p=B[pi-1];
        dp[i]=min(dp1+p+C[i],dp2-p+2*C[i]);
    }
    cout<<dp[N+M]<<endl;
}
// dp[i] = min_j dp[j-1] + min{ 2(p - j) + i - p, 2(i - p) + p - j }
// dp[i] = min_j dp[j-1] + min{ 2p - 2j + i - p, 2i - 2p + p - j }
// dp[i] = min_j dp[j-1] + min{ p - 2j + i, 2i - p - j }
// let dp1[j] = dp[j-1] - 2j
// let dp2[j] = dp[j-1] - j
// dp[i] = min { min_j(dp1[j]) + p + i, min_j(dp2[j]) - p + 2i } 

// begin signature
// +----------------------------------------+
// |群奏耗和和李労洪汎山せ火ビビ火山汎労耗陽|
// |洪允山山山せビ丁シヘㇵㇸ・ㇸ一シ丁せ洪和|
// |ミシヘㇵヘㇵㇸ　一ㇵシミシヘ一　ㇵ丁山允|
// |ㇸ一ㇵㇵ一一一シ丁シシシミビビシ・ㇵヘミ|
// |ビせせせ火丁丁ㇵ　ㇸ一ㇸ　一ミせミ・一一|
// |洪李和和労山ミㇸ一ヘミ火ビシㇸ一ビビ一・|
// |労洪汎汎洪火ヘㇸシ火允汎允火丁シ　ミせㇵ|
// |火ビ丁ミ丁丁ㇸヘせ洪奏李和労山允丁　ミせ|
// |一一　　　ミ・丁洪奏奏和陽義耗汎せㇵㇵせ|
// |　ㇸビㇸㇵㇸシ允耗群耗義慶陽奏労火ㇸシせ|
// |・ミㇸ・ヘㇵせ李耗和群奏和洪允山シㇸ火ミ|
// |・ミㇵㇵㇸシ允耗奏耗義群労火シㇵ・ミ火一|
// |シミシㇸヘ一火労奏和耗労山丁ヘㇸ・ビビ・|
// |シ・丁ㇵ一ㇵ一ビ汎李和允ビㇵ　ㇵミ丁ビシ|
// |火ㇵ　ミヘㇸシ　シ火山允ミ・ヘビ丁丁ビミ|
// |労せヘ　シヘ・ミ一・ㇵシヘㇸ丁ミシせミ　|
// |耗洪火ヘ・ミㇵㇸミシ一ㇸㇸシミ丁火シ　ヘ|
// |ミ李允ビシ一シㇸㇸヘ丁ビビビミヘ・一丁允|
// |和耗労允せビ丁ミㇵ・　ㇵ丁　ㇸヘ丁山労洪|
// |群義奏和洪ビ汎山火丁・ミヘㇵ火允洪耗奏汎|
// +----------------------------------------+
// 2026 (June 14th) 16:29:54
// end signature

