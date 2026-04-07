#include <bits/stdc++.h>

using namespace std;

using ll=long long;
template<int MOD, int RT> struct modint {
	static const int mod = MOD;
	static constexpr modint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	modint():v(0) {}
	modint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const modint& o) const {
		return v == o.v; }
	friend bool operator!=(const modint& a, const modint& b) { 
		return !(a == b); }
	friend bool operator<(const modint& a, const modint& b) { 
		return a.v < b.v; }
   
	modint& operator+=(const modint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	modint& operator-=(const modint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	modint& operator*=(const modint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	modint& operator/=(const modint& o) { return (*this) *= inv(o); }
	modint pow(ll p) {
		modint a = *this, ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	modint inv() { assert(v != 0); 
		return pow(MOD-2); }
		
	modint operator-() const { return modint(-v); }
	modint& operator++() { return *this += 1; }
	modint& operator--() { return *this -= 1; }
	friend modint operator+(modint a, const modint& b) { return a += b; }
	friend modint operator-(modint a, const modint& b) { return a -= b; }
	friend modint operator*(modint a, const modint& b) { return a *= b; }
	friend modint operator/(modint a, const modint& b) { return a /= b; }
};
using mint=modint<998244353,-1>;

int main() {
    const int M=310;
    int N;cin>>N;
    vector<int>A(N+1);
    for (int i=1;i<=N;i++)cin>>A[i];

    vector<mint>fac(M+1,1);
    for (int i=1;i<=M;i++)
        fac[i]=fac[i-1]*i;
    auto binom=[&](int n,int k){
        if(k>n)return mint(0);
        return fac[n]*fac[k].inv()*fac[n-k].inv();
    };
    vector<vector<mint>>dp(M+1,vector<mint>(M+1,0)),dp2(M+1,vector<mint>(M+1,0));
    dp[0][0]=1;
    for (int i=1;i<=M;i++){
        for (int j=i;j<=M;j++){
            dp[i][j]=0;
            for (int k=i-1;k<=j-1;k++){
                dp[i][j]+=dp[i-1][k]*binom(j,j-k);
            }
        }
    }
    for (int wildcnt=1;wildcnt<=M;wildcnt++){
        for (int j=0;j<=wildcnt;j++){
            mint cnt=0;
            for (int l=j;l<=wildcnt;l++){
                cnt+=dp[j][l]*binom(wildcnt,l)*((mint(N)-j).pow(wildcnt-l));
            }
            dp2[wildcnt][j]=cnt;
        }
    }
    vector<int>mex(N+1,0);
    { 
        vector<int>cnt(N+2,0);
        int m=0;
        for (int i=1;i<=N;i++) {
            if(A[i]<0)break;
            cnt[A[i]]++;
            while(cnt[m]>0)m++;
            mex[i]=m;
        }
    }

    vector<bool>excluded(N+1,false);
    int wildcnt=0,excludedcnt=0;
    for (int i=1;i<=N;i++){
        if(A[i]==-1)wildcnt++;
        else excluded[A[i]]=true,excludedcnt++;
        int k=0; mint ans=0;
        for(int j=0;j<=wildcnt;j++){
            while(excluded[k])k++;
            ans+=dp2[wildcnt][j]*k;
            k++;
        }
        cout<<((wildcnt==0)?mex[i]:(int)ans)<<" ";
    }
    cout<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇慶陽耗李労洪汎洪洪李耗群慶覇覇覇覇覇|
// |覇陽耗洪允火ビ丁丁丁火山洪和群慶覇覇覇覇|
// |耗洪せ丁ㇵㇵミ火せ山山せせ洪耗義覇覇覇覇|
// |允丁一一丁山洪李和和和労汎山李群慶覇覇覇|
// |丁ㇸ一ビ允李洪允山山山山允汎洪李奏陽義慶|
// |シ・ヘせ労允火丁シヘㇵヘヘシ丁火允労李和|
// |シ・ヘせ允ビヘㇸ・一ㇸ　ㇸ一ㇸ一ヘ丁せせ|
// |ミ・ㇵせ火ヘ　ㇵ一・ㇵミ丁ビ火ビミヘㇵㇵ|
// |ヘㇸシせヘ　ヘ　ㇵヘㇸ　　・ㇵミせせ丁一|
// |　ㇸヘㇵ一ㇸㇸㇸ　ㇵㇸㇸㇵヘㇵヘミ山せシ|
// |　ㇸㇸ・　ㇵ・ヘ一一ヘミ丁ビせ允山せ允ミ|
// |ㇸミ・ㇸミ　ミ・ヘ火火火せ允允允労汎汎丁|
// |・・　ミㇵㇵㇵㇵ火山ビ丁ミミ丁火せ労汎せ|
// |ㇸ一　丁シㇸヘ一火ミ一　・・　ㇸヘビビビ|
// |ㇸㇵ・シ火ㇸシ　ミ一・ヘ丁ビビミヘ　ㇵ・|
// |・シ一　シシㇸヘ一　シ火允洪汎火ミㇵㇸㇸ|
// |ㇸビㇸヘ・シ　シ・シせ労耗洪火ㇵ　ㇵシヘ|
// |丁ヘ一ビシ一・シシ山和奏洪ビㇸㇵビ山允せ|
// |ミ　丁允せシ　シ允耗群洪ビ・シ山允せ李允|
// |・ㇵせ李允シㇸ火労陽和山ヘㇵミミ山李奏汎|
// +----------------------------------------+
// 2026 (April 7th) 16:25:58
// end signature
