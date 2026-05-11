#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    vector<int>B(N+1);for(int i=1;i<=N;i++)cin>>B[i];
    using pii=pair<int,int>;
    vector<vector<int>>g(N+1);
    for(int i=1;i<=M;i++){ int u,v;cin>>u>>v;g[u].push_back(v); }
    int lo=-1,hi=2e9;
    while(lo+1<hi){
        int mid=(int64_t(lo)+hi)/2;
        priority_queue<pii,vector<pii>,greater<pii>>pq;pq.push({B[1],1});
        vector<int>mn(N+1,2e9);
        mn[1]=B[1];
        while(!pq.empty()){
            auto [b,u]=pq.top();pq.pop();
            if(b>mn[u])continue;
            for(auto v:g[u]){
                int nb=max(b,B[v]);
                if(b-B[v]>mid)continue;
                if(nb<mn[v]){
                    mn[v]=nb;
                    pq.push({nb,v});
                }
            }
        }
        (mn[N]!=2e9?hi:lo)=mid;
    }
    cout<<hi<<endl;
}

// begin signature
// +----------------------------------------+
// |義群耗労洪允山火ビ丁ミミミ丁火せ汎労和群|
// |耗李汎山火丁シヘ一ㇸ・・ㇸㇵシ丁火允労李|
// |汎せ丁シ一ㇸ　　・ㇸ・・　　ㇸヘ丁せ允允|
// |ビシㇸㇸ　　　・一ㇵ一ㇵヘヘㇵ一シビ丁丁|
// |シ・ㇸ　　・ヘㇸ　ㇸ・　　・ㇵシㇵ一一一|
// |ㇵ　ㇸ・　ㇵ一・ㇵ　一ヘシシシシㇵㇸ・一|
// |ㇵ　ㇸ・　ㇸシ火允　ㇵㇵ一・ㇸビビミシ一|
// |ヘ　一　・火洪ㇵ一・　・ㇸ・　一一火火ミ|
// |ㇵㇸㇸヘ允丁ビビ丁ミシミミミヘ・ㇸシ丁火|
// |・シビ洪山允火シミビせ山山せ丁ヘ　ㇸㇵヘ|
// |丁允允洪せミㇵビ山洪李李洪允火ヘ一一　・|
// |汎洪洪せミㇵビ允李奏群奏和汎火シヘシミミ|
// |汎李汎ビヘシせ汎耗陽覇義奏労山丁火せ山山|
// |允李洪火ヘヘ火汎李群慶群和労允火ビ丁ビ火|
// |汎労李允丁ㇸミ山汎和陽群李汎せ丁シヘㇵヘ|
// |せ汎和洪火ヘヘ火汎労奏奏労允ビヘㇸ　ㇸ・|
// |山汎和洪火ヘヘ火汎労耗和汎火ヘ　一シミミ|
// |火汎和汎ビㇵシせ山汎洪汎火ヘ　ヘビ山山せ|
// |火汎李允ビㇵミせビせ火せシ　シ火汎李洪せ|
// |ビ山洪汎火シシ火火允火ビ一一丁允李耗洪せ|
// +----------------------------------------+
// 2026 (May 11th) 16:10:17
// end signature

