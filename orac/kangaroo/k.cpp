#include <atcoder/modint.hpp>
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint1000000007;
int main() {
    freopen("kangaroo.in", "r", stdin);
    freopen("kangaroo.out", "w", stdout);
    int N,cs,cf;cin>>N>>cs>>cf;
    if(cs>cf)swap(cs,cf);
    vector<vector<mint>>dp(N+10,vector<mint>(N+10));
    dp[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i<cs){
                dp[i][j]+=dp[i-1][j-1]*j+dp[i-1][j+1]*j;
            } else if(i==cs||i==cf){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            } else if (i<cf) {
                dp[i][j]+=dp[i-1][j-1]*(j-1)+dp[i-1][j+1]*j;
            } else {
                dp[i][j]+=dp[i-1][j-1]*(j-2)+dp[i-1][j+1]*j;
            }
        }
    }
    cout<<dp[N][1].val()<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇義群耗和李和耗奏陽義慶覇覇覇覇覇|
// |覇覇陽耗洪允せビビ火山汎洪労耗群覇覇覇覇|
// |義和汎ビシ一ミ丁シヘヘシ丁火汎李群覇覇覇|
// |洪火ㇵㇸ丁ヘ　一ㇵㇵヘ一　ㇵ丁允和奏陽覇|
// |ミㇸ一ミ　ヘ　一ㇵ　　　ㇸㇵㇵシ火允洪耗|
// |ㇸ一ㇸ　ヘ・ヘ・ㇵ一ㇸシミㇸ　　　一ミせ|
// |火山山火ミ　ヘㇸミ　ミ山洪山シㇸ火丁ヘ　|
// |労耗耗労ビ　ㇵヘヘ一せせ洪奏汎シ一山洪せ|
// |陽覇陽洪ミ一　ビ　ビミ一せ耗李ビ　ビ李李|
// |覇覇和せ・一ミ・丁允せ火労陽洪ミ一山和耗|
// |慶和山シㇵㇵㇵシ汎李労李耗李ビㇸヘせ李耗|
// |李せㇵㇵㇸ丁　ビビ丁ビ火山洪山ミ・ビ洪李|
// |汎シㇸ火ヘヘㇵヘヘ・ミせ汎せシㇸ・一せ李|
// |汎シ一せ山ㇵヘㇵㇵシ山労允ミ　ヘビせ山山|
// |労丁・ビ山ミシㇸ丁・シ火山ヘ一火ビミシミ|
// |和火　ㇸビ丁ビㇵ・ㇵヘ　ㇵㇸシ丁ㇸㇸㇵ一|
// |せ丁・シㇵビㇵ丁ヘ・ㇵ一・ㇸ丁　シせ允山|
// |ㇵㇵシビミヘヘ一シ山允ビ・丁　ビ洪耗奏李|
// |ヘㇵせ丁ビㇸㇵシ汎群労丁丁　ビ李義覇覇耗|
// |允允丁せシシ・丁洪李せ一シヘ允群覇覇慶李|
// +----------------------------------------+
// 2026 (May 14th) 17:43:54
// end signature

