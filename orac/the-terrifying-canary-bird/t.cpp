#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    freopen("birdin.txt", "r", stdin);
    freopen("birdout.txt", "w", stdout);
    const int MOD=1000003;
    int R,C;cin>>R>>C;
    vector<vector<int>>A(R,vector<int>(C));
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) cin>>A[i][j];
    vector<vector<int>>adj(R*C),rev(R*C);
    for(int y=0;y<R;y++){
        for(int x=0;x<C;x++){
            if(x>0&&A[y][x-1]<A[y][x]){
                adj[y*C+x].push_back(y*C+x-1);
                rev[y*C+x-1].push_back(y*C+x);
            }
            if(x<C-1&&A[y][x+1]<A[y][x]){
                adj[y*C+x].push_back(y*C+x+1);
                rev[y*C+x+1].push_back(y*C+x);
            }
            if(y>0&&A[y-1][x]<A[y][x]){
                adj[y*C+x].push_back((y-1)*C+x);
                rev[(y-1)*C+x].push_back(y*C+x);
            }
            if(y<R-1&&A[y+1][x]<A[y][x]){
                adj[y*C+x].push_back((y+1)*C+x);
                rev[(y+1)*C+x].push_back(y*C+x);
            }
        }
    }
    vector<int>indeg(R*C),order,ω(R*C);
    for(int i=0;i<R*C;i++)for(auto v:adj[i])indeg[v]++;
    queue<int>q;
    for(int i=0;i<R*C;i++)if(indeg[i]==0)q.push(i),ω[i]=1;
    while(!q.empty()){
        auto u=q.front();q.pop();
        order.push_back(u);
        for(auto v:adj[u])if(--indeg[v]==0)q.push(v);
    }
    int ans=0;
    for(auto i:order){
        for(auto&e:rev[i])ω[i]+=ω[e]%MOD;
        ω[i]%=MOD;
        if(adj[i].empty())ans+=ω[i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |ミシヘㇵㇵㇵヘミ丁ビ丁丁シヘㇵㇵヘヘミ丁|
// |ㇸ　・・・　　ㇸㇵ一一ㇸ　　・・　　ㇸㇵ|
// |ヘシミミミヘㇵ・ㇸㇸ・・・ㇸ一ヘヘㇵ・・|
// |火せ山山丁ヘㇸ　ㇸ一　・一ㇵヘㇵㇵミヘㇸ|
// |汎洪山丁ヘ　ㇸㇸ　ㇸ・　　ㇸシビ丁シミシ|
// |李汎火ミㇸㇸㇸ・ㇵ　一ㇵㇸㇸ・シビせビミ|
// |和汎せシㇸ一・一一・シ丁丁ミㇵ　一ミせ山|
// |和汎火シ・ㇸ・ㇵ・一ミ丁ビせビシ一一ㇸ火|
// |労山丁ㇵㇸ一一ㇵ・・ㇸ一ㇵシビビシ一ㇵㇵ|
// |允ビヘミ丁シㇵ　　　・・ㇸ一ㇵヘシ・一ㇵ|
// |ビ丁ミㇵ　ㇸㇸㇸ　・ㇸ一一ㇸ　・ㇵヘヘㇵ|
// |丁ヘ　・・ㇵ・ㇵシミ丁丁丁ミヘ一　ㇸ・一|
// |ヘ　ㇸヘ・ㇸシ丁火山山允山せ火ミヘ・・ㇸ|
// |ㇵ　ヘㇵ　ヘ丁せ允洪労李李労汎山火ミ一　|
// |ㇵ　　一・シ火允労和耗奏李汎山ビミシシヘ|
// |一・一　ㇸミせ汎李奏陽奏労允ビシ一・　　|
// |・ㇵシ　ヘビ允李奏義群和汎火シㇸㇸㇵヘヘ|
// |一ミㇸㇵ丁允李奏慶陽和汎火シ　ㇵ丁火火ビ|
// |ミ一ㇸ丁山労奏慶義耗洪せシ　ヘビ允洪允火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 17th) 20:22:42
// end signature


