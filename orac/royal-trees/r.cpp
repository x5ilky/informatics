#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using mint=atcoder::modint;
int main() {
    int N,A,B,D,M;cin>>N>>A>>B>>D>>M;
    if(D>B-1)return cout<<0<<endl,0;
    mint::set_mod(M);
    vector<mint>fac(1e6+1,1);for(int i=1;i<=1e6;i++)fac[i]=fac[i-1]*i;
    if(D==1)return cout<<(fac[N-1]/(B-1)).val()<<endl,0;
    vector<vector<mint>>f(N+1,vector<mint>(N+1,0)),g(N+1,vector<mint>(N+1,0));
    {
        int k=D-1;
        f[0][1]=1;
        if(k>0)for(int j=B-2;j>=1;j--)f[k-1][j]=f[k-1][j+1]+mint(1)/j;
        for(int i=k-2;i>=0;i--)
            for(int j=B-D+i;j>=1;j--)
                f[i][j]=f[i][j+1]+f[i+1][j+1]/j;
    }
    {
        int k=D-2;
        auto c=[&](int i){
            if(i<A)return 2;
            if(A<i&&i<B)return 1;
            return 0;
        };
        for(int j=0;j<=N;j++)g[k][j]=1;
        for(int i=k-1;i>=0;i--)
            for(int j=B-D+i+1;j>=1;j--)
                g[i][j]=g[i][j+1]+g[i+1][j+1]/j*c(j+1);
    }
    if(A==1){
        cout<<(fac[N-1]/(B-1) * f[0][1]).val()<<endl;
    }else{
        mint s=0;
        for(int r=1;r<=A-1;r++)s+=g[0][r];
        cout<<(fac[N-1]/(B-1)/(A-1)*s + fac[N-1]/(B-1)*f[0][A]).val()<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇慶慶陽耗李　シ丁ビ丁ミヘ一・火せ山汎労|
// |耗耗和洪一火汎汎允せビシㇵㇸ・・　シビ山|
// |允山ㇸ山李李汎汎山火ビシ一・・　　　ㇵ丁|
// |シビ李耗和和耗陽義義義耗汎丁・・　　　ㇸ|
// |ミ和耗群群覇義群奏奏群群群洪火ㇵㇸㇸミヘ|
// |せ群陽陽慶群和労洪汎汎洪李労汎火シ　　シ|
// |汎群義覇陽和労奏義慶慶慶耗洪ビミシㇵㇸ一|
// |耗群覇慶奏耗覇義群奏耗耗奏群和允丁・　　|
// |慶覇覇群陽義奏和李耗耗和李労労汎火シ・一|
// |覇覇陽覇群李李耗奏和和和和耗労せシㇵㇸシ|
// |覇義義耗労允允汎允山せ山允洪汎火ヘ・　ヘ|
// |覇義和允允ミシ丁ミヘせ労山丁シシㇸ　ㇵ　|
// |覇群洪允せㇵヘヘ丁丁汎洪ビシㇸㇸヘ一火ミ|
// |覇慶和山洪火ミミせミ山労労汎火シ　一ㇸ一|
// |覇覇義和山労汎允汎丁火允李允丁ㇸㇸヘミヘ|
// |覇覇覇群労せ労耗汎丁シ允和山シ・シせ允火|
// |群慶覇義和山允汎火ㇵビ允労火一ヘせ洪せシ|
// |群陽奏義和允せ丁一ヘ火洪山丁ㇸㇵビ山允せ|
// |義陽耗群和汎ビ一・丁ビ汎丁・シ山李耗和允|
// |陽耗奏労和労山ミ一丁ビ山ヘㇵせ李陽慶奏汎|
// +----------------------------------------+
// 2026 (June 20th) 21:00:08
// end signature
