#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int>HEAD,sz,mx;
    DSU(int N):HEAD(N+1),sz(N+1,1),mx(N+1,1){
        iota(HEAD.begin(),HEAD.end(),0);
    }
    int head(int a){
        return HEAD[a]==a?a:HEAD[a]=head(HEAD[a]);
    }
    void join(int a,int b){
        a=head(a),b=head(b);
        if(a==b)return;
        sz[a]+=sz[b];
        mx[a]=max(mx[a],mx[b]);
        HEAD[b]=a;
    }
};
int main() {
    int L,S,N;cin>>L>>S>>N;S++;
    if(N==2)return (cout<<0<<endl),0;
    using pii=pair<int,int>;
    vector<pii>pos(N+1);
    for(int i=1;i<=N;i++)cin>>pos[i].first>>pos[i].second;
    vector<pii>d;
    for(int dx=-L;dx<=L;dx++)for(int dy=-L;dy<=L;dy++)if(dx*dx+dy*dy<=L*L&&__gcd(abs(dx),abs(dy))==1) d.push_back({dx,dy});
    int W=2*S;
    vector<vector<int>>dist(2*W+1,vector<int>(2*W+1,-1));
    queue<pii>q;q.push({0,0});dist[W][W]=0;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(auto [dx,dy]:d){
            if(x+dx>=-W&&x+dx<=W&&y+dy>=-W&&y+dy<=W&&dist[x+dx+W][y+dy+W]==-1){
                dist[x+dx+W][y+dy+W]=dist[x+W][y+W]+1;
                q.push({x+dx,y+dy});
            }
        }
    }
    using ai3=array<int,3>;
    priority_queue<ai3,vector<ai3>,greater<ai3>>edges;
    for(int u=1;u<=N;u++){
        auto [x,y]=pos[u];
        for(int v=u+1;v<=N;v++){
            auto [x2,y2]=pos[v];
            edges.push({dist[x2-x+W][y2-y+W],u,v});
        }
    }
    DSU dsu(N+1);
    while (!edges.empty()){
        auto [d,u,v]=edges.top();edges.pop();
        if(dsu.head(u)==dsu.head(v))continue;
        dsu.join(u,v);
        dsu.mx[dsu.head(u)]=max(dsu.mx[dsu.head(u)],d);
        if(dsu.sz[dsu.head(u)]>=(N+1)/2){
            cout<<dsu.mx[dsu.head(u)]<<endl;
            return 0;
        }
    }
}

// begin signature
// +----------------------------------------+
// |和和和和労洪允山山山允汎労和和李李李李和|
// |允允允允せビミミシミ丁火山允山山山山允汎|
// |ミ丁丁シㇵ一シ丁丁ミミ丁ビミシシシミ丁火|
// |　・一ㇸミミㇵㇸ・　・ㇸㇸ　　・　・一シ|
// |シヘ一・ㇸ　ㇸ一・　ㇸㇸㇸ　・　　一一　|
// |山火ヘ　・ㇵ一・・　　一ヘミシㇵ　ㇸ　ㇵ|
// |汎ビㇵシ丁丁丁ミシㇵㇸㇸㇸ　・ヘ丁ㇵ　ヘ|
// |汎ビ丁せ山ビシ一・ヘㇸ一　　ㇸヘミミミㇸ|
// |山火允せミ一ㇵ火汎労李李汎火シㇸㇵㇵヘシ|
// |山允ビヘミ洪奏義慶覇覇覇群労山ミ・　・・|
// |山ミシ労陽覇義陽群奏奏耗李洪山丁ㇵ　シㇸ|
// |ミせ奏覇義奏和李労洪労汎山火火丁ㇵ・ミヘ|
// |丁耗覇陽耗労洪洪洪汎せ山汎労洪汎せヘヘ丁|
// |火群慶群奏李汎せ火ビビ丁丁せ汎汎允山シミ|
// |丁奏慶奏耗洪せ丁ヘヘシヘㇵ一丁せビミミ丁|
// |丁奏慶奏李允ビㇵシ火山山火シ・シㇵ・　　|
// |せ陽義和洪火ヘヘ火汎李労汎ビㇵㇸㇸヘシシ|
// |耗慶耗洪火丁丁火洪奏陽李山ミ・ㇵ丁せ山火|
// |慶群労せせ汎ビ汎耗陽和允ミ　シせ汎李労山|
// |慶耗汎ビ火火ビ汎李耗洪火ㇵ一ビ洪耗群李山|
// +----------------------------------------+
// 2026 (May 18th) 20:06:44
// end signature




