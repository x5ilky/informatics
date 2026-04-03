#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,Q;cin>>N>>Q;
    vector<int>HEAD(2*N+1),sz(2*N+1,1),col(2*N+1,0),fl(2*N+1,0),bl(2*N+1,0);
    int ans=0,imp=false;
    for(int i=1;i<=2*N;i++)HEAD[i]=i;

    function<int(int)> head=[&](int n){
        if(HEAD[n]==n){
            if(fl[n])col[n]^=1,fl[n]=0;
            return n;
        }
        int p=HEAD[n],r=head(p);
        if(fl[n])col[n]^=1,fl[n]=0;
        col[n]^=col[p];
        return HEAD[n]=r;
    };
    function<int(int)> color=[&](int n){
        return head(n),col[n];
    };
    function<void(int)> flip=[&](int u){
        fl[u]^=1;
        bl[u]=sz[u]-bl[u];
    };
    function<void(int,int)>join=[&](int u,int v){
        int cu=color(u),cv=color(v);
        u=head(u),v=head(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v),swap(cu,cv);
        if(cu==cv) flip(v);
        sz[u]+=sz[v];
        bl[u]+=bl[v];
        HEAD[v]=u;
        if(sz[u]-bl[u]<bl[u]) flip(u);
    };
    for (int i=1;i<=Q;i++){
        int u,v;cin>>u>>v;
        if(head(u)==head(v+N)||head(v)==head(u+N)){
            ans-=bl[head(u)];
        } else {
            ans-=bl[head(u)];
            ans-=bl[head(v+N)];
        }
        join(u,v+N);
        join(v,u+N);
        ans+=bl[head(u)];

        imp|=head(u)==head(v)||head(u+N)==head(v+N);
        cout<<(imp?-1:ans)<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |奏和労汎允山せ火ビビ丁丁ビ火山汎李耗義覇|
// |汎せビ丁ミヘ一ㇸ・・　　ㇸㇵシビ允労奏義|
// |シ一　　・ㇵヘシシㇸ　・ㇸ・・シ火汎和陽|
// |ㇸシ丁ビビせシヘシシシヘ一　一ヘミ山労群|
// |ビ山汎洪洪允丁せ山允允山火ミㇵ・シ丁允和|
// |允労耗奏洪火允労李和耗和李汎せミㇸㇵビ允|
// |洪耗陽奏洪山汎允山　・・　洪李汎火ヘ・丁|
// |労群奏李汎せビシㇸ一一ㇵヘヘヘ一せシヘ・|
// |耗耗洪山丁　・シ・ㇸ・　　一ヘシシ一ヘ・|
// |李允ビ　　ㇸシ　一一・　　ㇸ・ヘミミㇸ・|
// |火ヘ　ㇸ・一一ㇵシミミミシヘㇸ一ミヘㇸヘ|
// |ㇵ　・シㇸヘ・シ山汎允せミヘ・　ㇵシヘシ|
// |　ㇸミヘ一ㇸヘㇸ丁允李労せビヘヘ火山せ丁|
// |　・ミ一シㇵㇸヘ　シ火允洪洪山丁火允允火|
// |　一　ㇸミ山シ　ㇵ一ㇸシ丁ビ丁火火ビビビ|
// |　ヘヘ　シせ允丁ㇵ　一一　・・ㇸシせヘㇸ|
// |ㇸ丁一ヘ・シ火允火ミㇵ一一ㇵシビ山允ミヘ|
// |シヘㇵビシ一シビせ山火火火せ允労和山允せ|
// |ミㇸビ允火ビ丁ミ丁ビせ允労和奏群労和李允|
// |シヘ山李労汎汎汎汎労李耗陽慶覇耗陽義耗允|
// +----------------------------------------+
// 2026 (April 3rd) 18:07:04
// end signature
