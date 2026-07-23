#include "nile.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct segtree {
    vector<int>T;
    segtree(int N):T(N*4,1ull<<60){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr)return void(T[v]=a);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=min(T[v*2],T[v*2+1]);
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2,ans=1ull<<60;
        if(ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};

std::vector<long long> calculate_costs(std::vector<signed> W, std::vector<signed> A,
                                       std::vector<signed> B, std::vector<signed> E) {
    int Q = (int)E.size();int N=W.size();
    std::vector<long long> R(Q, 0);
    using ai3=array<int,3>;
    priority_queue<ai3,vector<ai3>,greater<ai3>>pq;
    priority_queue<ai3,vector<ai3>,greater<ai3>>pq2;
    int tot=0;
    vector<ai3>C(N+1);
    segtree st0(N+1),st1(N+1);
    for(int i=1;i<=N;i++)C[i]={W[i-1],A[i-1],B[i-1]},tot+=A[i-1];
    sort(C.begin()+1,C.end());
    for(int i=1;i<=N;i++){
        (i%2==0?st0:st1).update(1,1,N,i,C[i][1]-C[i][2]);
        if(i>1&&i<N)pq2.push({C[i+1][0]-C[i-1][0],i});
    }
    vector<int>psD(N+1);
    for(int i=1;i<=N;i++)psD[i]=psD[i-1]+C[i][1]-C[i][2];
    for(int i=1;i<=N-1;i++)pq.push({C[i+1][0]-C[i][0],i,i+1});
    struct DSU{
        vector<int>H,l,r;
        DSU(int N):H(N),l(N),r(N){
            iota(H.begin(),H.end(),0);
            iota(l.begin(),l.end(),0);
            iota(r.begin(),r.end(),0);
        }
        int head(int u){return u==H[u]?u:H[u]=head(H[u]);}
        void join(int a,int b){
            a=head(a),b=head(b);
            l[a]=min(l[a],l[b]);
            r[a]=max(r[a],r[b]);
            H[b]=a;
        }
    }dsu(N+1);
    int cur=0;
    auto get=[&](int l,int r){
        if((r-l+1)%2==1)return psD[r]-psD[l-1]-(l%2==0?st0:st1).query(1,1,N,l,r);
        return psD[r]-psD[l-1];
    };
    vector<ai3>ev(Q);for(int i=0;i<Q;i++)ev[i]={E[i],i};
    sort(ev.begin(),ev.end());
    for(auto [V,i,_]:ev){
        while(pq2.size()&&pq2.top()[0]<=V){
            auto [_,i,_2]=pq2.top();pq2.pop();
            cur-=get(dsu.l[dsu.head(i)],dsu.r[dsu.head(i)]);
            (i%2==0?st1:st0).update(1,1,N,i,C[i][1]-C[i][2]);
            cur+=get(dsu.l[dsu.head(i)],dsu.r[dsu.head(i)]);
        }
        while(pq.size()&&pq.top()[0]<=V){
            auto [w,l,r]=pq.top();pq.pop();
            if(dsu.head(l)==dsu.head(r))continue;
            cur-=get(dsu.l[dsu.head(l)],dsu.r[dsu.head(l)]);
            cur-=get(dsu.l[dsu.head(r)],dsu.r[dsu.head(r)]);
            dsu.join(l,r);
            cur+=get(dsu.l[dsu.head(r)],dsu.r[dsu.head(r)]);
        }
        R[i]=tot-cur;
    }
    return R;
}

// begin signature
// +----------------------------------------+
// |陽群奏耗和労汎允允允汎労李奏陽覇覇覇覇覇|
// |労洪汎汎山ビ丁ミミ丁ビせ允労耗陽慶覇覇覇|
// |火丁丁ミㇵ一シビ火火火火火汎労和群慶覇覇|
// |ㇸ・　　・一シヘㇵㇵㇵヘミビ山洪和奏群義|
// |ヘシミミシㇵ　ㇸ一ㇵ一ㇸ　一ミせ汎洪労和|
// |火山山ミㇵ・ヘ丁火火火ビミヘ　ㇵ丁丁火山|
// |汎洪せ　・ㇵ丁山せビビビ火山ビヘ　シヘヘ|
// |耗洪火一　シせ火シ一ㇸㇸ一シビせミ・ヘㇵ|
// |李山　一ㇵ火火ヘ　一シシㇵ　ㇵビせヘㇸ　|
// |允ミㇵ一火ビ一一丁せ山せビㇵ・ミせヘㇸ　|
// |丁ヘㇸビビㇸヘ火允火丁シㇵㇵㇸ丁ビㇸヘ・|
// |・・シせㇵ一火ビシ一　ㇸㇵㇵ一火ミ　ヘㇸ|
// |　・シせㇵ一ビㇵ　ㇵミビ火せ火ビミ一　・|
// |・・ㇸビ丁・シ・ㇵ丁せ汎洪労労洪允せミ一|
// |火ㇸ　ㇸビ丁・　シせ汎李奏耗労允せビ丁ビ|
// |せヘシヘ一ビ丁ㇸ丁允李群群李允ビ火ㇵ・・|
// |ビ山山せ丁シ火ミせ労群義和允丁せシ　シシ|
// |労和李洪せシ丁せ労群義和允火丁ㇵ・ミ山せ|
// |陽義奏労せヘ火労群慶耗汎丁一　ヘビ汎李允|
// |覇覇群労火ミ允耗慶陽労せㇵ一丁山洪耗和允|
// +----------------------------------------+
// 2026 (July 23rd) 23:20:32
// end signature

