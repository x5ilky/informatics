#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    if(N==1){
        cout<<(mint(A[1])*A[1]).val()<<endl;
        return 0;
    }
    mint sum=0;
    for(int i=1;i<=N;i++)sum+=A[i];
    mint ans=0;
    vector<mint>fac(N+1,1);
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i;
    auto choose=[&](int n,int k){
        if(n<k)return mint(1);
        return fac[n]/fac[n-k]/fac[k];
    };
    mint g=choose(N,K)*K/N;
    mint f=g*(K-1)/(N-1);
    // cout<<f.val()<<" "<<g.val()<<endl;
    for(int i=1;i<=N;i++){
       ans+=A[i]*((sum-A[i])*f*2+A[i]*g);
       sum-=A[i];
    }
    cout<<ans.val()<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇覇義群奏耗李労労李和奏義覇覇覇覇|
// |覇覇覇群李汎山せビ丁ミミ丁火汎李群覇覇覇|
// |覇奏洪せシㇵㇵ　一ヘヘㇵ・一ミ山李李和耗|
// |李せヘ一ㇸ一ヘ一ㇸ　ㇸㇵヘシㇵミミ丁ビせ|
// |せ一・ㇵ丁せ允ミ・　・　ㇸシせビヘ一一ㇸ|
// |丁・シ山労洪丁　ヘ一一ミビビ丁ビ允せシヘ|
// |シㇸ火労奏允ミ一丁・ビ汎李和李和和労労ビ|
// |ㇵシ允奏耗允ミシヘㇵ山和耗群慶慶覇覇陽和|
// |・せ洪労労ビ　火　ビ丁ビ火允労奏義陽群奏|
// |丁せ洪労ビヘ丁ㇸビシヘヘシシ火允労允山せ|
// |耗奏允シ・ヘヘ・ㇵシミシヘㇸㇸミㇵ・　・|
// |耗せ一シㇸビ・ㇸㇵヘㇵ・ㇸシシㇸ一一ㇸ・|
// |汎シㇵ　ㇸヘヘシ汎汎汎山ビㇵㇸビㇸㇵㇵ火|
// |汎ヘヘㇵㇵㇵシヘㇵせ李奏汎丁ㇸㇸヘシシ一|
// |労ミㇸㇸミ山ミㇸビㇸシせせㇵㇵビ允允山允|
// |和ビㇸ　ビ汎労ビㇸㇵシ　ㇵ　ビ允丁ㇵㇸㇸ|
// |労シ　シ一火洪労せシㇸ　　丁允ヘㇸミビ丁|
// |せ　ヘ山ミヘビ丁　シミㇵミ山ㇸミ允李和労|
// |ㇵ一允李汎山ミㇵ允李汎シ山・ビ李義覇慶耗|
// |・丁李和奏せ　火耗義洪せシヘ洪義覇覇覇耗|
// +----------------------------------------+
// 2026 (August 15th) 22:53:08
// end signature
