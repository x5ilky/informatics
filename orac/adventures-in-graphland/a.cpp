#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0); cout.tie(0)->sync_with_stdio(0);
    int N,M,A,B,C;cin>>N>>M>>A>>B>>C;
    vector<int>S(N+1); vector<vector<int>>adj(N+1);
    for(int i=1;i<=N;i++)cin>>S[i];
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<vector<int>>>dist(N+1,vector<vector<int>>(N+1,vector<int>(N+1,1e9))); vector<array<int,3>>q;
    q.reserve(N*N*N);
    int head=0;
    q.push_back({A,B,C}),dist[A][B][C]=0;
    while(head<(int)q.size()){
        auto [a,b,c]=q[head++];
        if(a==b&&b==c)break;
        int d=dist[a][b][c],s=S[a]+S[b]+S[c];
        if(s%3==0){
            for(auto e:adj[a]){
                if(d+1<dist[e][b][c]){
                    dist[e][b][c]=d+1;
                    q.push_back({e,b,c});
                }
            }
        }else if(s%3==1){
            for(auto e:adj[b]){
                if(d+1<dist[a][e][c]){
                    dist[a][e][c]=d+1;
                    q.push_back({a,e,c});
                }
            }
        }else if(s%3==2){
            for(auto e:adj[c]){
                if(d+1<dist[a][b][e]){
                    dist[a][b][e]=d+1;
                    q.push_back({a,b,e});
                }
            }
        }
    }
    int m=1e9;
    for(int i=1;i<=N;i++){
        m=min(m,dist[i][i][i]);
    }
    if(m<1e9)cout<<m<<endl;
    else cout<<-1<<endl;
}

// begin signature
// +----------------------------------------+
// |火丁ミシシミ丁ビ火ビ丁丁丁ビせビ丁ミミ丁|
// |一・　・・　・ㇵ一・　　・一ㇵㇸ　　　　|
// |ヘミ丁丁丁シㇵ・ㇸ一一ㇸㇸㇸㇸㇸㇸ一ヘヘ|
// |山汎汎汎允火ミヘㇸ　ㇸㇵㇵㇵ一・・　　ㇸ|
// |和耗労山ビヘㇸㇵシミヘ・　ㇸシミㇵ　　一|
// |陽耗汎火ビ火洪和ヘㇸ・和允丁ㇸ丁丁丁ㇵ・|
// |義耗汎允汎洪洪汎允火ミ一・一　ビ一允せミ|
// |義耗汎李耗奏群奏耗李和李汎ビㇵ・一ヘ　ビ|
// |陽李耗陽慶覇陽奏李労汎允允山火ビㇸ・ㇵ一|
// |和群慶覇陽耗労汎せせせ火ビミ丁ㇵㇵ・　　|
// |陽覇義奏労允汎汎允山山せせ火丁ヘ　ㇵㇸ　|
// |覇陽和汎労汎せビミヘヘシミビ丁ヘㇸシヘ　|
// |陽和洪労允ビヘㇸ　ㇸㇸㇸ　ㇸ一ㇸㇸ　　ㇸ|
// |陽李労洪火シㇸヘ　シビビ丁シㇵヘㇵㇸ　シ|
// |陽李李汎ビㇵ・　ヘ一ㇸシ丁ビ丁ビ火ビミㇸ|
// |群李和汎丁ㇸㇵ丁一　一ㇸ　ㇸㇸㇸシ火允丁|
// |李労労せヘㇸ丁山ビシㇵㇸㇸ一ヘ丁せ洪労火|
// |李和山シ・ㇸシビせせ火ビビ火山洪李奏洪山|
// |和汎ミ　ミ丁ミシミ丁火山洪李耗群義耗李允|
// |李せㇵ一火允允允允洪労和群陽慶覇陽義和允|
// +----------------------------------------+
// 2026 (April 12th) 18:00:50
// end signature






