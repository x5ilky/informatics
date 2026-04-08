#include <bits/stdc++.h>

using namespace std;

using ll=long long;
struct rat{
    ll p,q;
#define op(_o) \
    bool operator _o (const rat& other) const { \
        return p*other.q _o other.p*q; \
    }
    op(<) op(<=) op(==) op(>) op(>=)
};

int maximum_deevs(vector<int>y) {
    ll N=y.size();
    vector<ll> A(N+1);
    for(ll i=1;i<=N;i++)A[i]=y[i-1];
    vector<vector<ll>>dp(N+1,vector<ll>(N+1));
    for(int i=1;i<=N;i++)dp[i][i]=1;
    for(int r=2;r<=N;r++){
        dp[r-1][r]=1;
        int left=r-1,sum=0;
        for (int l=r-2;l>=1;l--){
            if(rat{A[left]-A[l],left-l}<=rat{A[r]-A[l],r-l}){
                sum+=dp[l+1][left-1];
                left=l;
            }
            dp[l][r]=max(dp[l][r-1],1+sum+dp[l][left-1]);
        }
    }
    return dp[1][N];
}

// begin signature
// +----------------------------------------+
// |覇覇覇慶群耗李労労労李耗群慶覇覇覇覇覇覇|
// |覇慶群李汎山火ビビビせ允労耗和耗奏群義覇|
// |群李允ビヘㇵ丁せ山允允山山せせ山汎労耗陽|
// |汎ビㇵ一ビせ丁ミシシ丁ヘ一一ㇵヘ丁せ汎李|
// |ビㇸ一火シ丁火火丁一・一ㇸ・・ㇵ　一丁火|
// |シ・シ丁山洪允丁ㇵ・　　　ㇵミシㇸ一・　|
// |ミ・ヘせ山ビシㇵ・ㇸヘシヘㇸㇸㇸ丁ミㇸㇵ|
// |ミ・ㇵ山ミ一・　一丁山山允せミㇸㇸヘせヘ|
// |シ一シミ　ヘ一ㇸビ汎和和労洪汎丁　　丁火|
// |　ㇸヘㇸシ一・ビ労労允火ビミミミ　　ビ山|
// |・一ヘシ一　ビ洪せミㇵ　・ㇸㇸ　一一丁火|
// |ㇸㇵ丁　・ㇵ山ミㇸ一ミビ火せ火ビシㇸ一丁|
// |　シㇸヘㇸ一ミ　シㇸヘビ火汎李労允火ヘ・|
// |ㇸ一　ミ丁　ㇵ一一ヘ火ビㇵヘ火洪洪汎允丁|
// |せㇵㇸミ汎丁　ㇵ　ミ允ミ　シ　ミビミシミ|
// |労ビ　　丁せ一一　ビせㇵ一丁ㇵ・一・一ㇸ|
// |和せㇵシㇸミ・ㇸヘ山丁　・・ヘ　ヘ火せせ|
// |和せシ火ミ・　一せビ　　　ㇸヘ丁汎和和労|
// |和山火山ㇵ・　火せ一シビ火山せ労群覇義李|
// |奏洪山ビ　一ヘ允丁・火労李洪山耗覇覇陽労|
// +----------------------------------------+
// 2026 (April 8th) 21:55:26
// end signature




