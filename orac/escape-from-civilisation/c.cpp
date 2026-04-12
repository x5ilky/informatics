#include <bits/stdc++.h>
using namespace std;
int main(){
    int R,C;cin>>C>>R;
    vector<short>T(R*C+1);
    int S;
    vector<int>dist(R*C+1,1e9); queue<int>q; 
    for(int i=0;i<R;i++){for(int j=0;j<C;j++) {int v;cin>>v;T[i*C+j]=v; if(v==1)q.push(i*C+j),dist[i*C+j]=0;}}
    while(!q.empty()){
        auto t=q.front(); q.pop(); vector<int>adj;
        if(t%C>0)adj.push_back(t-1); if(t%C<C-1)adj.push_back(t+1);
        if(t/C>0)adj.push_back(t-C); if(t/C<R-1)adj.push_back(t+C);
        for(auto e:adj)if(T[e]!=1&&dist[t]+1<dist[e])dist[e]=dist[t]+1,q.push(e);
    }
    int md=0,ans=0;
    for(int i=0;i<R*C;i++)md=max(md,dist[i]);
    cout<<md<<endl;
}

// begin signature
// +----------------------------------------+
// |丁シㇵ一一ㇵヘミミシヘㇵㇵヘミビせ汎労耗|
// |　・一ㇵㇵ一・・　ㇸ一一ㇸ・・ㇵミ火允李|
// |ミビ火火火丁シシ丁ビ丁ヘ一ㇸㇸ　一丁山洪|
// |汎洪労洪洪允せビミシミシヘㇸ　ㇵ・ヘ火汎|
// |耗奏和汎せ丁ヘミビ火丁ヘ一ヘヘ・一ㇵシせ|
// |陽耗洪山丁山李奏群群群和汎火ㇵㇵㇵ・ミシ|
// |陽和汎火允奏和李労・ㇸ一ㇸ・汎ビㇵㇵ　シ|
// |陽和允せ和労汎ヘㇸㇵミミ丁丁ミシ一ヘㇸ　|
// |奏洪山労允・・ヘ・ㇵㇵㇵシミビ丁一・　一|
// |労洪汎せㇸ・ヘㇸㇸㇸ一ㇸ　ㇸヘ丁シ　ㇵ一|
// |洪せ・ㇸ　一一　ㇵヘㇵㇸ　ㇸ・ヘシ　ヘシ|
// |火　　　ㇸヘㇵヘ・・ㇸ・・ㇸㇵ・　　ヘ丁|
// |シ　　ヘㇵㇸㇵ・　一ヘシシヘ一　ㇵ・一丁|
// |ビㇸㇸミ・　ㇸㇵヘ丁火せ山せ火ミㇵ　ㇸ　|
// |允ミ　シ・ㇸ　一丁山汎労李李洪山火丁シ一|
// |労火ㇵ　　ㇸ　シ火汎和奏奏労山丁ヘㇸ・・|
// |汎せシ　・一ㇵビ汎和陽陽李允丁一・ㇵシヘ|
// |せせヘ・・一ビ汎耗義陽和允ミ・ㇵ丁せ山火|
// |ミ火ヘ・・丁汎耗慶義和允ミ・シせ洪李労山|
// |一シミ・ヘせ労群覇群労火ㇵ一火洪奏陽李山|
// +----------------------------------------+
// 2026 (April 12th) 16:13:21
// end signature
