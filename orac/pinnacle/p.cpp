#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
using pii=pair<int,int>;
struct segtree{
    vector<pii>T;
    segtree(int N):T(N*4){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr)return void(T[v]={a,pos});
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=max(T[v*2],T[v*2+1]);
    }
    pii query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2;pii ans={-INF,-1};
        if(ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};
struct sumst{
    vector<int>T;
    sumst(int N):T(N*4){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr)return void(T[v]=a);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=T[v*2]+T[v*2+1];
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2,ans=0;
        if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
        return ans;
    }
};
signed main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+10);
    segtree M(N+10);
    sumst S(N+10);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)M.update(1,1,N,i,A[i]),S.update(1,1,N,i,A[i]);
    A[0]=INF;
    A[N+1]=INF;
    vector<vector<pii>>nr(N+10,vector<pii>(26,{N+1,0})),nl(N+10,vector<pii>(26,{0,0}));
    vector<int>s; s.push_back(0);
    for(int i=1;i<=N;i++){
        while(A[s.back()]<=A[i]){
            nr[s.back()][0]=
                {i,A[s.back()]*(i-s.back())-S.query(1,1,N,s.back(),i-1)};
            s.pop_back();
        }
        s.push_back(i);
    }
    s.push_back(0);
    for(int i=N;i>=1;i--){
        while(A[s.back()]<=A[i]){
            nl[s.back()][0]=
                {i,A[s.back()]*(s.back()-i)-S.query(1,1,N,i+1,s.back())};
            s.pop_back();
        }
        s.push_back(i);
    }
    for(int k=1;k<=25;k++){
        for(int i=1;i<=N;i++){
            nr[i][k]={
                nr[nr[i][k-1].first][k-1].first,
                nr[nr[i][k-1].first][k-1].second+nr[i][k-1].second,
            };
            nl[i][k]={
                nl[nl[i][k-1].first][k-1].first,
                nl[nl[i][k-1].first][k-1].second+nl[i][k-1].second,
            };
        }
    }
    // for(int i=1;i<=N;i++)printf("%d,%d ",nl[i][0].first,nl[i][0].second);
    // printf("\n");
    for(int q=1;q<=Q;q++){
        int l,r;cin>>l>>r;
        auto[_,m]=M.query(1,1,N,l,r);
        int ans=0;
        // printf("m=%lld\n",m);
        int p=l;
        for(int b=25;b>=0;b--){
            if(nr[p][b].first<=m){
                ans+=nr[p][b].second;
                p=nr[p][b].first;
            }
            // printf("l=%d ",p);
        }
        // printf("\n");
        p=r;
        for(int b=25;b>=0;b--){
            if(nl[p][b].first>=m){
                ans+=nl[p][b].second;
                p=nl[p][b].first;
            }
            // printf("r=%d ",p);
        }
        // printf("\n");
        cout<<ans<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇覇慶群耗李労労汎山火ビビ火山汎李奏義|
// |覇慶群李汎山火ビビヘ一・　・ㇸヘ丁山労奏|
// |群李允ビヘㇵミㇸㇸヘミ丁丁ミヘ・一丁允李|
// |汎ビㇵ一ビ一ㇸ丁丁シヘヘミビせミㇸㇵ火洪|
// |ビㇸ一火一ㇵ丁一　一ヘㇵㇸ・シせビㇸヘせ|
// |　・ㇵミ・シㇵㇸ　　　　ㇸヘ一一丁せㇵㇵ|
// |丁丁ミㇵ　シㇸㇵ　ㇸㇵㇵヘシミシ・ヘせシ|
// |労労洪允火シㇵ・ㇸ　ㇸㇸ・　・ㇸミㇵㇵせ|
// |陽陽群労火ミ・一シビ火せ火ビシㇸ・ヘ　丁|
// |義耗洪ビヘㇸミ山洪李和和李汎せミㇸ　　丁|
// |労せシ・ヘㇵ山耗群奏和労李李洪せシシ一丁|
// |丁ヘ・ㇵ一シ汎奏陽群耗和汎洪労ビㇸ一シ一|
// |ㇸ一シㇸシ一火労群耗慶義奏和允ミㇸ　シ　|
// |ㇸㇸヘヘ一ヘㇸビ汎和奏奏耗労せシ　シㇸ・|
// |一ㇵ・丁シㇸ丁・ヘビ山汎允せ丁一・シ　ㇸ|
// |ヘ山ㇵ　ミミ　ミヘ　ㇵシシヘ・一ㇸシㇵ　|
// |ビ火ㇵシㇸミヘ・シ丁ヘㇵ一ヘミミ一ヘ　ミ|
// |山ㇵビ火ミ一ミㇵ・ヘミビビビミㇵ　ヘ火せ|
// |ミミ洪洪山火ビ丁ヘㇸ　　　・一ミ火せ洪洪|
// |一火李奏和李労汎山火ビ丁ビ火山洪李耗陽労|
// +----------------------------------------+
// 2026 (April 14th) 16:28:58
// end signature


