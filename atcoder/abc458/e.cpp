#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint.hpp>
using mint=atcoder::modint998244353;
signed main(){
    int x1,x2,x3;cin>>x1>>x2>>x3;
    int N=x1+x2+x3;
    vector<mint>fac(N+1,1);
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i;
    auto choose=[&](int n,int k){
        if(n<0||k<0||n<k)return mint(0);
        return fac[n]/fac[k]/fac[n-k];
    };
    mint ans=0;
    int tot=x1+x3;
    for(int i=1;i<=x1;i++){
        mint part=choose(x1-1,i-1);
        ans+=part*choose(x3-1,i-2)*choose(x2-(2*i-2)+tot,tot);
        ans+=2*part*choose(x3-1,i-1)*choose(x2-(2*i-1)+tot,tot);
        ans+=part*choose(x3-1,i)*choose(x2-(2*i)+tot,tot);
    }
    cout<<ans.val()<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇陽奏和李李洪汎汎洪労和群慶覇覇覇|
// |覇覇群和洪山火ビビミシミ丁火山労耗義覇覇|
// |陽李允ビヘㇵㇸ　ㇸ一一ㇸ　一ミせ労奏覇覇|
// |洪ビㇵㇸㇸ一丁丁ミㇵ　・ㇸㇸㇸミ山和義覇|
// |ビㇸㇸ　シ火洪労汎山丁一ㇵミせせ火允耗覇|
// |ミ・ヘ一ヘ山和陽陽奏労山シ・ビ丁山洪允耗|
// |ミ・ㇸㇵㇵ山汎汎労耗慶奏洪ビ・ミ汎火せ允|
// |ㇵㇸシ丁ㇵせミシ丁せ李陽陽労ビ　丁汎山汎|
// |一ビビㇸシヘ・ㇵ・ヘ山耗覇耗山一シ汎李せ|
// |せミ　・ヘㇵせ火ヘㇵ山奏慶李火　丁労耗山|
// |ㇵㇵㇸミㇸミㇸ・ㇵビ李義奏允ヘㇸビ洪李火|
// |ㇸ丁・シ・ㇵ・・ミ汎群義労ビヘ　シせ汎丁|
// |　ビ・丁シㇸㇸシせ李義奏汎ミㇸミㇸヘシ丁|
// |ㇸㇸヘ一火山火山洪耗慶耗允ミㇸㇸㇵヘヘㇸ|
// |一一ㇸ・　ビ洪和耗陽群李山シ一丁せせ火せ|
// |　ビ一　ミ　丁汎耗和労允ビ一丁せミ一・ㇸ|
// |　丁　ヘ一ヘㇸビせせビヘ　ミせㇵㇸシ丁ミ|
// |ヘㇸㇵビヘヘ・ㇸㇸヘシ一シ火ㇸシせ洪労允|
// |ㇵㇸ火汎せビシ一せ汎山ヘ火・丁洪奏義群労|
// |　ミ山耗李火　ビ労奏允ビヘㇵ允奏覇覇義労|
// +----------------------------------------+
// 2026 (May 16th) 23:38:51
// end signature
