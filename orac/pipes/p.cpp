#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    freopen("pipesin.txt", "r", stdin);
    freopen("pipesout.txt", "w", stdout);
    int W,H,X,Y,N;cin>>W>>H>>X>>Y>>N;
    using pii=pair<int,int>;
    vector<pii>C(2*N+1);
    for(int i=1;i<=N;i++){
        int x,y;cin>>x>>y;
        C[i]={x%W,y%H};
        C[i+N]={y%W,x%H};
    }
    const int INF=1e9;
    vector<vector<int>>δ(W+1,vector<int>(H+1,INF));
    using state=pair<int,pii>;
    priority_queue<state,vector<state>,greater<state>>pq;
    δ[X%W][Y%H]=0; pq.push({0,{X%W,Y%H}});
    while(!pq.empty()){
        auto [d,π]=pq.top(); auto [x,y]=π;
        pq.pop();
        if(d>δ[x][y])continue;
        for(int i=1;i<=2*N;i++){
            auto [x2,y2]=C[i];
            const pii dirs[4]={{1,1},{1,-1},{-1,1},{-1,-1}};
            for(auto [dx,dy]:dirs){
                int rx=x+x2*dx,ry=y+y2*dy;
                rx+=W;rx%=W;
                ry+=H;ry%=H;
                if(d+1<δ[rx][ry]){
                    pq.push({d+1,{rx,ry}});
                    δ[rx][ry]=d+1;
                }
            }
        }
    }
    int ans=INF;
    for(int i=0;i<W;i++)ans=min(ans,δ[i][0]);
    for(int i=0;i<H;i++)ans=min(ans,δ[0][i]);
    if(ans>=INF)cout<<"No\n";
    else cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |汎山せ火火せ山允允山山山山允洪李耗陽陽陽|
// |ミヘㇵ一ㇵㇵシミミヘヘヘシ丁火允労李労労|
// |・一ㇵㇵㇵㇸ　　・　　　　一シ火せ火火せ|
// |ビ火せ丁ㇵ　一ヘシㇵ一ㇵㇵ一ㇸシㇵ一ㇵヘ|
// |洪山ミㇸㇸシㇸミビ火丁ㇵ一・・ㇵㇵ一　ㇸ|
// |洪火ヘㇵㇵ山労汎允山山せせ火ミㇵ　ㇵビシ|
// |洪火丁一汎洪山火丁シシシシヘヘ丁ビヘ　シ|
// |洪山ミ山洪山火ビヘ一ㇸㇸㇵシ丁ビビビミ・|
// |汎ビ火洪せビ汎汎ビㇵ・・　　　・一ヘ丁シ|
// |火山汎火ビ汎せミㇵ一ㇸㇸ・・　・ㇸ一ㇵシ|
// |洪山せビ山丁ヘㇸ　一ㇵヘㇵ一・　一シミヘ|
// |火火火せシヘ・シ丁火せ山せ火シㇸ　一丁丁|
// |山火允ミ・一ㇵㇸ丁允李李李洪允火ㇵ　一丁|
// |山山山ミ　ㇵㇸヘ　シ火允洪洪洪労汎ミ・・|
// |せ山汎丁　シシ　ヘ一ㇸシ丁ビビ火火ビ火一|
// |山山汎丁・シせ丁一　ㇵㇸ　ㇸㇸㇸシ火洪せ|
// |山汎允シ・シ火山ビシㇵㇸㇸ一ヘ丁せ洪耗汎|
// |山洪ビㇸヘㇸシビせせ火ビビせ山洪和群和允|
// |労せヘ一火丁ミミミ丁火允洪李耗群慶群和汎|
// |洪ビㇸヘ山汎允允汎洪李耗群義覇覇慶慶耗允|
// +----------------------------------------+
// 2026 (April 17th) 18:16:14
// end signature


