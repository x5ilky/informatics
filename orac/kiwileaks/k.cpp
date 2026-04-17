#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    freopen("leakin.txt", "r", stdin);
    freopen("leakout.txt", "w", stdout);
    int N,K;cin>>N>>K;
    vector<int>key(N+1),p(N+1,-1);for(int i=1;i<=N;i++)cin>>key[i];
    vector<int>pass(K+1);for(int i=1;i<=K;i++)cin>>pass[i];
    for(int i=1;i<=N;i++){
        int a=i;
        for(int j=1;j<=N;j++){
            a=key[a];
            if(a==i){
                p[i]=j;
                break;
            }
        }
    }
    using ll=long long;
    function<ll(ll,ll)> gcd=[&](ll a,ll b){
        return b?gcd(b,a%b):a;
    };
    ll ans=1;
    for(int i=1;i<=K;i++){
        ans=p[pass[i]]/gcd(ans,p[pass[i]])*ans;
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |奏和労汎山せ火火火火せせせ山允洪労和奏陽|
// |労允せビ丁シヘヘヘシシシミ丁火せ允労和奏|
// |せ丁シ一・　　　　・・・一ㇵシビせ汎労和|
// |シㇸ　一ㇵヘシシヘㇵ・ㇸㇸ　一シビ山汎労|
// |・ㇸヘ丁ビ火丁ヘㇸ・ㇸ　　ㇸㇵ一シ丁火山|
// |・ヘ丁せ山丁ヘ・ㇵ　ㇸヘシヘヘシㇵ一ヘミ|
// |ㇸシ火允火丁ㇵㇸ一・ㇸㇸ一ㇵシ丁火丁ヘ・|
// |一丁せ火丁ヘㇸㇵㇸㇸ一一一・　ㇸヘ丁火ミ|
// |ヘ火火ミㇵ　・ㇵㇸ　・ㇸㇸ・　・　ㇵミ火|
// |ビ火シㇸ一ヘㇵ　ㇵㇸ・　ㇸ一ㇵシㇸ・ヘ丁|
// |丁ㇵㇵシㇸㇸㇸ　ㇸㇵヘシヘヘ一ㇸㇵ　ㇸシ|
// |ㇵシヘ　・ㇵ一シ丁ビ火火火ビミヘㇸㇵ　一|
// |シシ・一　ヘ丁火山汎汎洪汎允山ビミ一ヘ　|
// |シシ・ㇸㇸミ火允洪李和耗李汎山火ビ丁ヘヘ|
// |シミㇸㇸ一ミせ汎李耗群耗労允火ミヘㇵ一ㇵ|
// |シ丁一　一丁山洪耗群陽耗洪山丁ㇵ・・ㇸㇸ|
// |シミ・　ヘ火汎和群慶奏李允ビヘ　ㇵシミミ|
// |ビㇵ・ㇵビ允李群慶群和汎ビヘ　ヘビせ山火|
// |シ　一丁山労奏慶陽和汎火ヘ　ヘ火汎労洪せ|
// |ヘ　ヘ火汎和陽慶群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 17th) 20:41:45
// end signature

