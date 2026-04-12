#include <bits/stdc++.h>
using namespace std;
signed main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    int R,C,K;cin>>R>>C>>K;
    vector<char>T(R*C+1);
    int U,V;
    for(int i=0;i<R;i++){string s;cin>>s; for(int j=0;j<C;j++) {T[i*C+j]=s[j]; if(s[j]=='C')U=i*C+j;if(s[j]=='B')V=i*C+j;}}
    using pii=pair<int,int>;
    using state=pair<int,pair<int,pii>>;
    vector<vector<array<int,2>>>dist(R*C+1,vector<array<int,2>>(K+1,{(int)1e9,(int)1e9})); priority_queue<state,vector<state>,greater<state>>q; q.push({0,{U,{K,false}}}); dist[U][K][false]=0;
    while(!q.empty()){
        auto [d,r]=q.top(); q.pop(); vector<int>adj;
        auto [t,_k]=r;
        auto [k,u]=_k;
        // printf("at %d,%d with %d,%d\n",t/C,t%C,k,u);
        if(t%C>0)adj.push_back(t-1); if(t%C<C-1)adj.push_back(t+1);
        if(t/C>0)adj.push_back(t-C); if(t/C<R-1)adj.push_back(t+C);
        if(!u) if(d*3<dist[t][K][true])dist[t][K][true]=d*3,q.push({d*3,{t,{K,true}}});
        for(auto e:adj) {
            if(T[e]=='.')continue;
            int d=dist[t][k][u]+1;
            if(T[e]=='*'){
                if(k>=1) {
                    if(d<dist[e][k-1][u])dist[e][k-1][u]=d,q.push({d,{e,{k-1,u}}});
                }
            } else {
                if(d<dist[e][k][u])dist[e][k][u]=d,q.push({d,{e,{k,u}}});
            }
        }
    }
    int m=1e9;
    for(int i=0;i<=K;i++){
        for(int k=false;k<=true;k++)
            m=min(m,dist[V][i][k]);
    }
    if(m<1e9)return cout<<m<<endl,0;
    cout<<"Give up!\n";
}

// begin signature
// +----------------------------------------+
// |丁ミヘㇵㇵヘシミビ火ビミシヘヘヘミ丁火允|
// |・　ㇸ一一ㇸ　ㇸㇵ一ㇸ　・ㇸㇸ・　一シビ|
// |ミ丁ビビビミヘㇸ一一一ㇵヘヘㇵ一一・ㇸシ|
// |允汎山丁ヘㇸ　　ㇸ一一一・ㇸㇵㇵ一ㇸ　一|
// |洪せミ一一ㇵ火允洪洪汎火シ　・　　・　　|
// |汎ビシ丁火労李李李ㇸ　耗李允丁ㇸㇸヘヘシ|
// |允ビ火山労洪汎汎山火ミ一・・ㇵ火ミビせせ|
// |允せ汎労和耗奏耗和労允火ヘ　ヘシヘ汎洪労|
// |せ洪和群義陽奏和労汎允允火ヘ・ミㇵㇸ・洪|
// |労奏義義奏李汎山火丁ミミミシ　ミシ　一せ|
// |群慶奏李汎山允山火丁ヘ一・ㇸ　　ㇵ　ㇵミ|
// |義耗洪允洪允せミㇵ　ㇸㇵシㇵ一ㇸ　　ヘ丁|
// |奏労汎労洪せミㇸㇸシ丁火せ火ミビㇵ　ㇵ火|
// |奏洪洪和汎火ヘ　ヘビ山山汎汎允火丁ヘ・ミ|
// |奏労労労汎ビㇵㇸミせ洪労汎せ丁丁ビ丁ㇵㇸ|
// |和労李汎汎ビ一一ビせビ火せ汎汎山山山火ㇵ|
// |労汎労汎山ミ　シ丁ヘ一ㇵシ火せ允李李山ミ|
// |洪李山汎丁ㇸヘヘ　一ㇵ　シせ洪和群労山せ|
// |李允洪火一ㇵㇵㇸミ丁・ヘせ李奏慶耗和労山|
// |労せ允ミ　ミ　シせヘㇸ丁汎耗慶義奏陽李山|
// +----------------------------------------+
// 2026 (April 12th) 17:27:56
// end signature



