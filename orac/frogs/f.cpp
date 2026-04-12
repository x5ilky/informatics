#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("frogsin.txt","r",stdin);
    freopen("frogsout.txt","w",stdout);
    int N,M;cin>>N>>M;
    vector<vector<int>>adj(2*N+1);
    int A,B;cin>>A>>B;
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v+N);
        adj[u+N].push_back(v);
        adj[v].push_back(u+N);
        adj[v+N].push_back(u);
    }
    const int INF=1e9;
    vector<int>dist(2*N+1,INF); queue<int>q;
    q.push(A);dist[A]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(dist[u]+1<dist[v]){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    vector<int>dist2(2*N+1,INF); queue<int>q2;
    q2.push(B);dist2[B]=0;
    while(!q2.empty()){
        int u=q2.front();
        q2.pop();
        for(auto v:adj[u]){
            if(dist2[u]+1<dist2[v]){
                dist2[v]=dist2[u]+1;
                q2.push(v);
            }
        }
    }
    int b=INF,n=0;
    for(int i=1;i<=2*N;i++){
        if(dist[i]!=INF&&dist2[i]!=INF){
            int d=max(dist[i],dist2[i]);
            if(d<b){
                b=d;
                n=i>N?i-N:i;
            }
        }
    }
    if(b>=INF){
        cout<<"Broken heart\n";
    } else {
        cout<<b<<" "<<n<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎允山せせ山允汎労和群慶慶|
// |義群李汎山火丁ミシヘㇵヘヘミビ山洪和耗耗|
// |李汎せミㇵ一一　ㇸ一一ㇸ　・ヘ丁山允允汎|
// |せミ一一ㇸㇸ一・・ㇵ一一一一一ヘミミミ丁|
// |ヘ・　ㇸㇵ一ㇸ一ㇸ一・・　・一・　・　・|
// |　ㇵミビ火火火丁シシミ丁丁ミヘㇸ一丁ヘミ|
// |ㇵ丁せ汎洪労労洪允せ丁一一ㇵミ火ミ一ヘビ|
// |ミ山洪和奏群群奏ㇸㇵビ　　　シㇵ・火シㇵ|
// |山労奏義義奏・シㇵシミ丁ミヘ・一　ㇸ　ヘ|
// |李群慶群和ミ允労労洪允火ミㇵ・ㇸㇸ　　　|
// |義陽和火和義慶群李允火シㇸ　ㇸㇵㇸヘㇵㇸ|
// |群李李慶覇慶奏労せミㇸㇸシ丁ヘ・　せ火丁|
// |耗労覇覇義奏李山ミ・ㇵ丁山允火シ・ㇵ労汎|
// |和耗覇慶奏李汎せヘ　シせ洪洪洪允ビ一一汎|
// |耗耗覇慶耗洪せミㇵ一ㇸシ丁ビ丁ビビミヘ・|
// |耗耗覇義和允丁一・　一一　・・ㇸシせせヘ|
// |和義覇群労火ㇵㇸ丁シㇵ一一ㇵシ丁山洪允ミ|
// |奏覇陽李せヘ一ビ火せ火火火丁丁汎和李汎山|
// |覇義和山シㇸミミ丁ビせ允山ビ允耗奏奏和汎|
// |覇群労火一ヘせ允汎洪李労せ火労群陽慶耗允|
// +----------------------------------------+
// 2026 (April 12th) 16:25:49
// end signature

