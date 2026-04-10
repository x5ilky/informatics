#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

signed main() {
    using pii=pair<int,int>;
    int N,M,S,T;cin>>N>>M>>S>>T;
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=M;i++){
        int U,V;string C;cin>>U>>V>>C;
        int c=C[0]=='B'?-1:1;
        adj[U].push_back({V,c});
        adj[V].push_back({U,c});
    }
    const int INF=1e9;
    vector<vector<int>>dist(N+1,vector<int>(M*2+1,INF));
    queue<pii>q;
    q.push({S,M});
    dist[S][M]=0;
    while(!q.empty()){
        auto [u,c]=q.front();
        q.pop();
        // printf("at %3d diff %d dist %d\n",u,c,dist[u][c]);
        if(abs(c-M)>=M)continue;
        for(auto [v,p]:adj[u]){
            if(dist[v][c+p]<=dist[u][c]+1)continue;
            dist[v][c+p]=dist[u][c]+1;
            q.push({v,c+p});
        }
        if(u==T&&c==M)break;
    }
    if(dist[T][M]>=INF)cout<<"No true path."<<endl;
    else cout<<dist[T][M]<<endl;
}

// begin signature
// +----------------------------------------+
// |洪允山火ビ丁ミミミミミ丁ビビ火ビビビ火火|
// |山せビミシヘㇵ一一ㇵㇵシシシシシシシミ丁|
// |ビミヘ一ㇸ・一一ㇸㇸㇸㇸ一一一ㇸ一一ㇵヘ|
// |シㇵ・・一ㇸ・　　・・・　　　　　　・一|
// |一　・ㇵヘヘヘㇵ一・ㇸ・ㇸ一ㇵㇵㇵㇵ一・|
// |ㇸ　ㇸ・・・・・　・　　　・ㇸ一ヘシシヘ|
// |・・・・ㇸㇸヘミ・・ㇸ一一一ㇸ・　ㇸㇵシ|
// |ヘヘヘㇵヘミ丁シヘㇵ一ㇸㇸㇸ一ヘ一・　一|
// |丁丁丁ミ丁ビビビ丁丁丁丁シㇵ・ㇸㇵㇵㇸ　|
// |せ火ビ火せ山山山允汎汎允火丁ヘㇸㇸヘ一　|
// |ビせ山汎汎洪汎允允山山せ火丁シ一・ㇵ一　|
// |山汎洪労李李労洪允せ火丁シヘㇵㇸ・ㇵ一ㇸ|
// |允洪李耗奏奏耗李洪允火丁ヘㇸ　　　一ㇵ一|
// |允労和奏陽陽群奏李洪允火ミㇵ　ㇸㇸ・ㇵㇵ|
// |山洪李奏陽慶慶陽奏李洪山ビシ一　・・ㇸ一|
// |せ汎労耗群慶覇陽奏和洪允せ丁ㇵ　・ㇸ　　|
// |せ允労和奏陽義群耗李汎山ビシ一　一一ㇵㇵ|
// |せ汎労和耗奏奏耗李洪山ビシ一　一ヘミミシ|
// |汎允洪李和和李労汎山火ミㇵ　一シビ火ビミ|
// |汎山汎洪洪洪汎允山火ミヘㇸ・ヘ丁せ允火ミ|
// +----------------------------------------+
// 2026 (April 10th) 17:28:55
// end signature

