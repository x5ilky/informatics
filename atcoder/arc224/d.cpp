#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    auto sum=[&](int l){
        int ten=1,d=1,ans=0;
        while(ten<=l/10){
            ans+=9*ten*d;
            ten*=10;d++;
        }
        ans+=(l-ten+1)*d;
        return ans;
    };
    auto choose=[&](int n,int k,int c){
        __int128 ans=1;
        for(int i=1;i<=k;i++){
            ans=ans*(n-k+i)/i;
            if(ans>=c)return c;
        }
        return (int)ans;
    };
    while(T--){
        int N,K;cin>>N>>K;
        if(N<20&&K>(1ull<<N)){
            cout<<-1<<endl;
            continue;
        }
        int s=0,ans=0;
        K--;
        for(int i=1;i<=N;i++){
            int b=choose(N,i,K-s+1);
            ans+=(sum(K-s)-sum(max(K-s-b,0ll)))*i;
            // printf("i = %d, ans = %d inner = %d b = %d\n",i,ans,sum(min(s+b,K))-sum(s),b);
            if(b+s>=K)break;
            s+=b;
        }
        cout<<ans<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |群耗李洪允山せ火ビ丁ミミミ丁ビ火山せせせ|
// |和洪允せビミシヘㇵㇸㇸㇸㇸㇵヘミミミミミ|
// |允火丁ヘ一ㇸ・　ㇸ一ㇸㇸㇸ　ㇸㇵㇵㇸㇸ一|
// |丁ヘㇸㇸ・ㇸㇸ　ㇸ一一一ㇸ　・・ヘシ一　|
// |ヘ・ㇸ　一　ㇸ一ㇸㇸ・　　一ㇸ・・ヘシ一|
// |ㇵ　一・ㇸヘ火火ビビビ火丁ㇵ　一　　ヘ丁|
// |ㇵ　一・ミビミシヘ丁火火火ビビヘ・ㇸ　ㇵ|
// |ㇵ　ㇸヘ丁ヘ一一ミ火允汎洪允せ丁シ一ㇸ　|
// |一・ヘミㇵ　　ヘビ允労和和李汎せミㇸ・　|
// |　ミヘㇸㇸ・ㇵビ允李奏陽群和洪せシㇸ　　|
// |ミ一ㇵ・一ㇸミ山労奏義慶群李允ビミシㇵ・|
// |ㇸ・ㇸ一・ㇵビ允労奏陽群和汎せ山せ火ミㇵ|
// |　　一ㇸ・ㇸミせ汎李和李洪山洪労洪允火ミ|
// |　　・ㇸ　ヘ丁せ允汎労労労洪汎山せせせせ|
// |・ㇸ　　ㇸヘビ山洪李耗奏李汎山ビ丁シシミ|
// |ㇸ一一　ㇸシ火汎李耗群耗労山ビシㇵㇸ・・|
// |・ㇵシ　ㇵビ允労耗陽奏李允火シㇸ・一ㇵㇵ|
// |・ミㇸ一丁山労奏義群李汎火シ・一ミビビ丁|
// |丁一ㇸミ山労耗義陽和汎火シ　ㇵ丁山允山ビ|
// |シ　ヘビ汎和群慶奏労山丁一ㇸミ山労李汎ビ|
// +----------------------------------------+
// 2026 (July 12th) 21:08:47
// end signature
