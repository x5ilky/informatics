#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,Q;cin>>N>>Q;
    vector<int>HEAD(2*N+1),sz(2*N+1,1),col(2*N+1,0),bl(2*N+1,0);
    int ans=0,imp=false;
    for(int i=1;i<=2*N;i++)HEAD[i]=i;
    for(int i=N+1;i<=2*N;i++)bl[i]=1;

    function<int(int)> head=[&](int n){
        return HEAD[n]==n?n:HEAD[n]=head(HEAD[n]);
    };
    function<void(int,int)>join=[&](int u,int v){
        u=head(u),v=head(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        sz[u]+=sz[v];
        bl[u]+=bl[v];
        HEAD[v]=u;
    };
    for (int i=1;i<=Q;i++){
        int u,v;cin>>u>>v;
        if(head(u)==head(v+N)||head(v)==head(u+N)){
            ans-=min(bl[head(u)],bl[head(u+N)]);
        } else {
            ans-=min(bl[head(u)],bl[head(u+N)]);
            ans-=min(bl[head(v)],bl[head(v+N)]);
        }
        join(u,v+N);
        join(v,u+N);
        ans+=min(bl[head(u)],bl[head(u+N)]);

        imp|=head(u)==head(v)||head(u+N)==head(v+N);
        cout<<(imp?-1:ans)<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |奏和労洪汎山せビビビビ丁ビ火山汎李奏義覇|
// |汎山火丁ミヘ一ㇸ・・・・ㇸㇵミ火允労奏慶|
// |ミㇵ・　・ㇵシシシㇸ・・一・ㇸシ火汎和陽|
// |ㇸヘミ丁火せシ一ㇸ一ㇸ・　一シヘミ山李群|
// |ビせ允汎汎允丁丁ビ火火ビミㇵ　ㇵビ丁汎和|
// |允労李洪山火・ㇸヘ　ㇵヘヘ一　ㇵ・シビ汎|
// |洪和汎せ丁・・ㇵㇵ　　ㇸㇵシミシ一ㇸㇵ火|
// |労洪せミ　　一シㇸㇵヘヘ一一ㇸシ丁ミㇸ一|
// |労せシ　ㇸヘ・シ・丁山山火ミㇸ一ヘ丁ヘ・|
// |火ㇵ　ヘㇸㇸシ　ミ允和李汎火ヘ一ㇸㇸㇸ一|
// |・ㇸ・一ヘ一一ヘせ李義奏労せヘ・ㇵミミヘ|
// |ㇸㇸミビㇸヘ・シ山李群陽李山丁ミせ汎允ビ|
// |　ミ山せヘ一ヘㇸ丁允李奏奏李山火洪李汎せ|
// |ㇸ・丁汎火ㇵㇸヘ　シ火汎洪洪洪允允汎汎山|
// |・ㇵ　ミ山山シ　ヘ一ㇸシ丁ビビ火火ビ火ビ|
// |・丁ヘ　シせ允丁ㇵ　一一　・・ㇸシせシ一|
// |一火ビヘ・シ火允火ミㇵ一一ㇵシビ山汎丁丁|
// |丁汎山ビシ一シビせ山火火火せ允労和汎洪允|
// |山和洪允火ビ丁ミ丁ビせ允労和奏群和奏耗汎|
// |汎耗奏李労汎汎汎汎労李奏陽慶慶和陽覇耗李|
// +----------------------------------------+
// 2026 (April 3rd) 20:55:37
// end signature

