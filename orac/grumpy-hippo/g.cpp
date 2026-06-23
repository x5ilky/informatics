#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint1000000007;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<int>A(N+1),freq(1e6+1,0),sfreq(1e6+2);
    for(int i=1;i<=N;i++)cin>>A[i];
    sort(A.begin()+1,A.end());
    vector<mint>fac(N+1,1);
    for(int i=1;i<=N;i++)freq[A[i]]++;
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i;
    vector<mint>ch(1e6+1,0);
    mint ans=0;
    for(int i=1e6;i>=1;i--)sfreq[i]=sfreq[i+1]+freq[i];
    for(int i=1;i<=1e6;i++){
        if(sfreq[i]==0)break;
        ch[i]=mint(freq[i])/sfreq[i]*(1-ch[i-1]);
        ans+=ch[i];
    }
    cout<<(fac[N]*(ans+accumulate(A.begin()+1,A.end(),mint(0)))).val()<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇慶群耗李洪汎允せ火火せ山允洪和群慶覇|
// |慶群和洪山火丁丁ヘㇵ一一ㇵシ丁せ汎李耗耗|
// |和洪せミㇵ一ㇸ一　　・・ㇸ　一ミせ允汎汎|
// |山丁一ㇸヘ　一ㇵ・　・　　・ㇸヘミミミビ|
// |シㇸㇸㇵㇸㇵ　ㇵシㇵヘミミミシ一　・ㇵ・|
// |ㇸㇸ　　ヘ　ㇸ・・ㇸㇵシビ山火火丁ヘ　・|
// |ビ火ビミヘ一ヘㇵ山李奏李允允山火シ丁ビㇵ|
// |汎労労山シビミ李陽義奏労李耗耗和洪火ヘヘ|
// |奏和允丁せ火奏覇義奏耗李群奏和労洪允ビヘ|
// |耗允丁ㇵ洪慶群耗李労洪洪労汎汎汎山ビミヘ|
// |允ミシ耗群和洪山火ビビ火せ允労汎山火ビ一|
// |ビシ洪耗洪せ丁ヘㇸ一ㇵㇵシビ火ミヘ一ㇸㇸ|
// |ミ丁允洪せシㇸシビ火せせビミヘ　一ヘシシ|
// |ミㇸ丁汎ビ一シ火允汎汎洪山ミ・ㇵ丁せ山允|
// |ビ一・ミビ一ミ山火丁ミビせシ　シ丁シヘシ|
// |ビㇸヘ・シ一ビせシㇸ　　ㇵシ・ミㇸ　ㇸㇸ|
// |丁　ビヘㇸヘせミ　ヘ丁ミㇸ一ヘ・ㇵ丁火ビ|
// |ㇵ丁山ビㇵ一シ　ミ山汎ビ一一　ミ山洪労汎|
// |ㇸ労汎ミ丁丁一ㇵせ労山シ　　ミ允耗群耗洪|
// |ㇵ李允シせビ一ㇵビ火ミ　ㇸㇵせ李陽覇耗汎|
// +----------------------------------------+
// 2026 (June 23rd) 16:39:31
// end signature


