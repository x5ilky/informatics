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
    dp[N][N]=1;
    for(ll i=N-1;i>=1;i--){
        rat m={A[i+1]-A[i],1};
        if(m.q<0)m.p*=-1,m.q*=-1;
        // printf("i = %3d\n", i);
        for (ll j=i+1;j<=N;j++){
            rat m2={A[j]-A[i],j-i};
            if(m2.q<0)m2.p*=-1,m2.q*=-1;
            if(m2>=m){
                dp[i][j]=max(dp[i][j-1],dp[j]);
            } else {
                dp[i][j]=max(dp[i],dp[j]+1);
            }
            m=max(m,m2);
        }
    }
    return (int)dp[1];
}

// begin signature
// +----------------------------------------+
// |労汎允せ火ビ丁ミミミ丁ビビビビ火せせ山允|
// |允せビ丁シヘㇵㇵㇵㇵヘシヘシシミ丁ビ火せ|
// |火丁シㇵㇸ・一ヘㇵ一ㇸㇸㇸㇸ一ㇵヘシ丁ビ|
// |シㇵ・・ㇵヘ一・　・ㇸㇸㇸ・　・ㇸㇵヘミ|
// |ㇵ　・ㇵ一ㇸ　ㇸㇵヘシシシヘ一一・　ㇸヘ|
// |一　ㇸ一ㇵ　ㇸㇵシ丁ビビビ丁ミミヘㇵ・　|
// |一　ㇸㇵ一　一シ丁火せ山山山せ火ビ丁シ一|
// |一　ㇸヘ一　ㇵミビせ允汎洪洪汎允允せビミ|
// |ㇸ・一ㇵ・ㇸヘ丁せ允洪李和和李労洪汎山ビ|
// |　・ヘ　・ヘ丁せ汎労和奏奏奏耗和李洪山ビ|
// |　一　　ㇵ丁せ汎労耗群義義群群耗李汎せ丁|
// |・・・ㇸシビ山洪和群義覇義慶群耗労允火ミ|
// |　　ㇸㇸシビ山洪李奏陽義陽陽奏和労允火ミ|
// |・・ㇸ　一ミ火山洪李耗奏奏耗耗李労允火丁|
// |ヘ・　一　一シビ山汎労李和李労労洪允せ丁|
// |ミㇵ　　一　一シビせ允汎洪洪汎允允せビミ|
// |丁ヘ・　　ㇸ・ㇵミ火允山山山せ火火丁ミㇵ|
// |丁ヘㇸ　一　一ミ火允允火ビ丁丁ミシヘ一　|
// |丁ヘㇸ　・ㇸシビ山允火ミヘヘㇵ一ㇸ　ㇸㇵ|
// |ビミㇵㇸ　ㇵミ火允山ビシㇸ　　・ㇸㇵシミ|
// +----------------------------------------+
// 2026 (April 8th) 20:03:12
// end signature


