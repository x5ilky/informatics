#include <bits/stdc++.h>
using namespace std;
int main(){
    int R,C,K;cin>>R>>C>>K;
    vector<char>T(R*C+1);
    int S;
    for(int i=0;i<R;i++){string s;cin>>s; for(int j=0;j<C;j++) {T[i*C+j]=s[j]; if(s[j]=='$')S=i*C+j;}}
    vector<int>dist(R*C+1,1e9); queue<int>q; q.push(S); dist[S]=0;
    while(!q.empty()){
        auto t=q.front(); q.pop(); vector<int>adj;
        if(t%C>0)adj.push_back(t-1); if(t%C<C-1)adj.push_back(t+1);
        if(t/C>0)adj.push_back(t-C); if(t/C<R-1)adj.push_back(t+C);
        for(auto e:adj)if(T[e]!='#'&&dist[t]+1<dist[e])dist[e]=dist[t]+1,q.push(e);
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(T[i*C+j]=='#'||T[i*C+j]=='$')cout<<T[i*C+j];
            else cout<<(dist[i*C+j]<=K?'*':'.');
        }
        cout<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |丁シㇵ一一ㇵヘミビ火ビミヘㇵㇵヘシ丁せ允|
// |　ㇸㇵヘヘㇵㇸ　一ㇸ・・一ㇵ一ㇸ　ㇸシビ|
// |ビせ山山せ火丁ㇵㇵヘミミミㇵ一ㇸㇸ一・シ|
// |労李和洪山ミヘㇸヘシㇵ　・一　ㇵヘ一　一|
// |群耗汎火シ山李奏群群奏労山シ　ㇸ　　ㇵ一|
// |陽李山せ李和李火丁ヘ・ㇵㇵ・せヘ　シヘ・|
// |陽李允労李和和李労允火ヘ　シ丁シㇸ一一ビ|
// |陽労李奏陽義義群耗李労山丁ㇸㇵシㇸ・ㇸㇸ|
// |奏和群覇慶群和洪允山せせ山ミ　ヘミ・一ㇸ|
// |耗義覇群和洪山ビシㇵㇵㇵシミ　一ヘㇸㇸミ|
// |慶陽和汎せミ一　一ㇵㇵ一・・・ヘ一・ㇵビ|
// |群李山丁一ヘ・シせせ火ビ丁ヘ・　シ　ヘせ|
// |和允丁ㇸ一一ㇵㇸ丁允労洪汎せミ一　ㇸㇵせ|
// |李山シ　シㇵㇸヘ　シ火汎洪洪汎火ヘㇵ・ミ|
// |和山シ　ミ山シ　ヘ一ㇸシ丁ビビ火火ビ一ㇸ|
// |和山シ　シせ允丁ㇵ　一一　・・ㇸシせミ・|
// |労火一ㇵ・シ火允火ミㇵ一ㇸㇵシビ山労火丁|
// |山シㇸビシ一シビせ山火火火せ允洪和汎洪允|
// |丁　ミ允火ビ丁ミ丁ビせ允労和奏陽和群耗汎|
// |ヘ一火労労汎汎汎汎労李奏陽慶覇群陽覇耗汎|
// +----------------------------------------+
// 2026 (April 12th) 15:53:17
// end signature

