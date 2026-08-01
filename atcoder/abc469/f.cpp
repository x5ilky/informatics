#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>HEAD(N+1),sz(N+1,1);
    iota(HEAD.begin(),HEAD.end(),0);
    function<int(int)> head=[&](int u){
        return u==HEAD[u]?u:HEAD[u]=head(HEAD[u]);
    };
    vector<int>ind(1e6+1);
    for(int i=1;i<=N;i++)ind[A[i]]=i;
    auto join=[&](int u,int v){
        u=head(u),v=head(v);
        if(sz[v]<sz[u])swap(u,v);
        HEAD[u]=v;
        sz[v]+=sz[u];
    };
    int e=N-1,ans=0;
    for(int d=1e6;d>=1;d--){
        if(e==0)break;
        int prev=-1;
        for(int v=d;v<=1e6;v+=d){
            if(e==0)break;
            if(ind[v]==0)continue;
            if(prev==-1)prev=ind[v];
            else {
                if(head(prev)!=head(ind[v])){
                    join(prev,ind[v]);
                    ans+=d;
                    e--;
                }
            }
        }
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火丁ミミシミミビ火山汎労労|
// |和労允せビミシヘ一・・・・一ヘミビ山せ山|
// |汎せ丁ヘ一ㇸ　ㇸ一ㇸ・　　・ㇸㇵミミミミ|
// |ビシㇸㇸ　一・　ㇸㇸㇸ・　・ㇵ一・・ㇸ一|
// |ヘ・ㇸ　ㇵㇸㇵシミ丁シシヘ一　ㇸシ一　　|
// |ㇵ　一ㇸㇸヘ丁ミヘ一・　　　・一　ㇵヘ　|
// |ㇵ　ㇸㇸ一ミ丁一一・一ㇵヘヘヘ一・・ㇸミ|
// |ヘ　　ㇵヘビ・ㇵ一一ㇸ　・一ヘ丁ミヘㇸㇸ|
// |一ㇸヘ一　ヘ一ミ一　ㇸヘシミ丁ミ丁ビシ一|
// |　ヘㇸシミ一ㇵ・ㇸシㇵㇵ一ㇵヘシ丁ビ丁ヘ|
// |シ・火ㇵ　ㇸㇸ一・　ㇸㇸㇸ・　ㇸㇵミビヘ|
// |一シシ・・ㇵ・一ヘミミミミシㇵㇸ　ㇵミヘ|
// |　ヘシ　ㇸㇸヘ丁火せ山山山せビミㇵ　一ミ|
// |・　ミㇸ　ㇵ丁せ允洪労労労洪汎山火シ一・|
// |ㇸㇸㇸヘ・ヘビ山洪李耗奏和洪山火丁ミシヘ|
// |ㇵミ一ㇵ一ミせ汎李奏陽奏李允火ミㇵㇸ・・|
// |ㇵヘヘ・ㇵビ允李奏義群和汎火ミ一　一ヘㇵ|
// |ㇵ・一一丁允李奏慶陽和汎火シ・一ミビビ丁|
// |ㇸㇸㇸ丁山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |ㇵ　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (August 1st) 23:19:56
// end signature
