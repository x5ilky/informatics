#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
signed main() {
    freopen("nomin.txt", "r", stdin);
    freopen("nomout.txt", "w", stdout);
    int N;cin>>N;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>ps(N+1);for(int i=1;i<=N;i++)ps[i]=ps[i-1]+A[i];
    int ans=0;
    for(int i=1;i<=N;i++){
        auto v=lower_bound(ps.begin()+i+1,ps.end(),2*ps[i]);
        if(v==ps.end())continue;
        else if(*v==2*ps[i])ans=max(ans,ps[i]);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火ビビビ火せ山汎労和和|
// |和労允せビミシヘヘㇵㇵㇵㇵヘミビせ允汎汎|
// |汎せ丁ヘ一ㇸ一　　ㇸㇸ・　・一シビ火火火|
// |ビシㇸㇸㇸ　一・　・・・・ㇸ一ㇵヘヘヘシ|
// |ヘ・ㇸㇸㇸㇸ・ㇵ一・一ㇵヘㇵ一ㇸ　　ㇸ・|
// |ㇵ　一　ㇵ　　・・　・一ヘミ丁ミシ一　・|
// |ㇵ　一　一ㇵヘㇵㇸ・ㇸ一ヘヘシミ火ビシㇸ|
// |ヘ　・ㇸヘ丁ㇵㇸㇸㇵヘミミ丁ビ火ビビせ丁|
// |一ㇸ一ミ丁　　一ミビビ丁丁シㇵシビ山火せ|
// |　一一一・　ヘ丁シㇵ一ㇸㇸ一一一シビせせ|
// |　・　・ㇸシㇵㇸ　ㇸ一一一ㇸ・　一シビ火|
// |・　　ㇸヘ・・ㇵシ丁丁丁丁ミヘ一　一シミ|
// |　　ㇸヘ　一シビせ山允允允山火丁ヘ・ㇸシ|
// |・・一一・ヘビせ汎洪李李李労汎山火ミ一　|
// |ㇸㇸ　一・シ火允労和奏群和洪山ビ丁シシヘ|
// |ㇵ・一　ㇸミせ洪和奏義奏労允火シㇵ・　　|
// |ㇵ・シ　ヘビ允李奏義群和汎火シㇸ・ㇵヘヘ|
// |　ㇵㇸㇵビ允李群慶陽和汎火シ・ㇵミビ火丁|
// |ㇸ一ㇸ丁山労奏慶義耗洪せシ　ヘビ允汎允火|
// |一　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 17th) 19:39:42
// end signature
