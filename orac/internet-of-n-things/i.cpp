#include <bits/stdc++.h>
#include <numeric>
using namespace std;
struct DSU{
    vector<int>h,sz,mn;
    DSU(int N):h(N),sz(N+1,1),mn(N+1,1e9){iota(h.begin(),h.end(),0);}
    int head(int a){
        return h[a]==a?a:h[a]=head(h[a]);
    }
    void join(int a,int b){
        a=head(a),b=head(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        h[b]=a; sz[a]+=sz[b]; mn[a]=min(mn[a],mn[b]);
    }
};
int main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    using pii=pair<int,int>;
    priority_queue<pii>pq{};DSU dsu(N+1);
    for(int i=1;i<=N;i++)pq.push({A[i],i});
    dsu.mn=A;
    const int INF=1e9+7;
    vector<int>ans(N+1,-INF),active(N+1,false);
    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        for(auto v:g[u]){
            if(active[v]) dsu.join(u,v);
        }
        active[u]=true;
        int hu=dsu.head(u);
        ans[dsu.sz[hu]]=max(ans[dsu.sz[hu]],dsu.mn[hu]);
    }
    for(int i=N-1;i>=1;i--)ans[i]=max(ans[i],ans[i+1]);
    for(int i=1;i<=Q;i++){
        int v;cin>>v;
        cout<<ans[v]<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇慶陽耗李労洪汎洪洪李耗群慶覇覇覇覇覇|
// |覇陽耗洪允火ビ丁丁丁火山洪和群慶覇覇覇覇|
// |耗洪せ丁ㇵ一ミビせ山山せせ洪耗義覇覇覇覇|
// |允丁一一丁せ允せ火火火せ山山李耗陽陽陽義|
// |丁ㇸ一ビ山ビシㇵㇸㇸㇸ一シ丁せ汎労労労李|
// |シ・ヘせ丁ㇵ　一ㇵㇸ　・一ㇸㇵミ火火火せ|
// |シ・ㇵ火ヘ　ㇸ　ㇸㇸㇵシシミ火ビシ一ㇸㇸ|
// |ミ・ㇵシㇸ・ㇵヘシシヘ一ㇸ　・ヘミ火ミ一|
// |ヘ一ㇵ　ヘ丁せ山允火丁シㇵㇵㇵ一　ㇵシミ|
// |　・ㇵビ山洪允火シㇸ　一一　・ㇸ一・ㇸ・|
// |・丁山労汎火シㇸㇵシ・ㇸ・　　・ㇵシミシ|
// |ビ汎和允丁ヘ一ヘ一ㇵシシシㇵㇸㇸ一　ヘビ|
// |山和洪ビ一シ　シビせ允允允せビシ・　ㇸ一|
// |允和汎丁・一ㇵㇵ山労和耗耗和労允火シシㇵ|
// |せ李洪ビㇸ一ヘㇸシ山和陽義義義奏李允丁ミ|
// |ビ洪労火ㇸヘ　ミ　シ山労奏群和李労耗汎ビ|
// |火労汎丁　ミㇵ一ヘ・ミ山洪洪允洪和李洪山|
// |山労火一ヘ一ヘ・シ・ㇵミ火火火せせ火汎允|
// |洪山ヘㇵせビミㇸㇸヘ・・一一一ミせ労耗汎|
// |洪ビ・ミ汎洪せミヘㇸ・ㇸㇵシ火允李陽奏汎|
// +----------------------------------------+
// 2026 (April 25th) 16:47:12
// end signature

