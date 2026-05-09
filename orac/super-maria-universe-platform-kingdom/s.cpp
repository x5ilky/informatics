#include <bits/stdc++.h>
using namespace std;
#define int long long
struct plat {
    int h,l,r,c;vector<int>g;
    strong_ordering operator<=>(const plat&o)const{
        return tie(h,l,r,c)<=>tie(o.h,o.l,o.r,o.c);
    }
};
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<plat>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i].h>>P[i].l>>P[i].r>>P[i].c;
    sort(P.begin()+1,P.end());
    using pt=pair<int,int>;
    set<pt>u;
    for(int i=N;i>=1;i--){
        for (auto it=u.lower_bound({P[i].l,0});it!=u.end()&&it->first<=P[i].r;it=u.erase(it)){
            P[it->second].g.push_back(i);
        }
        u.insert({P[i].l-1,i});
        u.insert({P[i].r+1,i});
    }
    for (auto it:u){
        P[it.second].g.push_back(0);
    }
    vector<int>dp(N+1,-1);
    dp[N]=P[N].c;
    for(int i=N;i>=1;i--){
        if(dp[i]==-1)continue;
        for(auto v:P[i].g){
            dp[v]=max(dp[v],dp[i]+P[v].c);
        }
    }
    cout<<dp[0]<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇義奏和李労洪洪労和耗奏群義覇覇覇覇|
// |覇義奏労允せビ丁丁ビ火山山汎労和群慶覇覇|
// |奏労山丁ヘㇵ丁ミヘㇵㇵㇵシ丁せ汎和群覇覇|
// |允丁一一丁ㇵ一一・　　ㇸ・ㇸシ火汎耗陽慶|
// |丁ㇸ一ミシㇸㇸㇵ　一ヘヘヘヘ一ミビ汎労和|
// |シ・ヘミㇸㇸ・ㇸヘミ丁ビ丁シ一　ㇵ火せせ|
// |ミ・ヘシ　ㇸㇸヘヘミ火允洪汎山ビヘ　ミ允|
// |ミ・ㇵㇵ・　一一・ㇵビ山允汎汎允允丁一シ|
// |ヘ一シ　　ミㇸ丁労陽慶和和奏奏耗和汎丁ㇸ|
// |　ㇸ・　丁ミ耗覇義群耗和李和和和群洪火一|
// |・ㇸ　ㇸ李覇陽耗労允せ山洪山山李李洪ビシ|
// |　・丁陽慶奏洪せ丁ヘ一ミ山山火せせせ丁丁|
// |　　洪群奏洪火ミ火火火ミシビシㇵ一一ㇵミ|
// |　・ビ洪耗汎丁山洪労労允丁一・ㇵシシヘ一|
// |ヘㇸ　丁汎汎丁汎汎せ汎山シ　シ火火丁ミ丁|
// |火ㇸヘ　ミ山ビ洪火せ火火一ㇵ火丁ㇵ　・　|
// |山ヘ火ヘ・ミせせ丁シ山シ・ビ丁ㇸㇵ丁火ビ|
// |火せ汎火シ一ミヘシ允丁　ビ丁　ミ山労労汎|
// |シ奏李汎せ火ヘㇵビビ　丁ビ　丁汎奏義群労|
// |ビ慶群李せビ　丁允シ一せヘㇵ山和慶覇群洪|
// +----------------------------------------+
// 2026 (May 9th) 18:25:47
// end signature



