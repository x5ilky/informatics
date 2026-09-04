#include <bits/stdc++.h>
#include "horses.h"
using namespace std;
using ld=long double;

using lint=pair<ld,int>;
struct node{
    lint p={0,1},q={-1e100,0};
};
const int MOD=1e9+7;
struct segtree{
    vector<node>T;
    segtree(int N):T(N*4){}
    node merge(node a,node b){
        return {
            {a.p.first+b.p.first,1ll*a.p.second*b.p.second%MOD},
            max(a.q,{a.p.first+b.q.first,1ll*a.p.second*b.q.second%MOD}),
        };
    }
    void update(int v,int tl,int tr,int pos,int A,int B){
        if(tl==tr)return void(T[v]={{log(A),A%MOD},{log(A)+log(B),1ll*A*B%MOD}});
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,A,B);
        if(pos> tm)update(v*2+1,tm+1,tr,pos,A,B);
        T[v]=merge(T[v*2],T[v*2+1]);
    }

    node query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2;
        if(qr<=tm)return query(v*2,tl,tm,ql,qr);
        if(ql> tm)return query(v*2+1,tm+1,tr,ql,qr);
        return merge(
            query(v*2,tl,tm,ql,qr),
            query(v*2+1,tm+1,tr,ql,qr)
        );
    }
};
segtree st(1);int N;
vector<int>A,B;
int init(int _N, int X[], int Y[]){
    N=_N;
    st=segtree(N+1);
    A.resize(N+1);B.resize(N+1);
    for(int i=0;i<N;i++)A[i+1]=X[i],B[i+1]=Y[i];
    for(int i=1;i<=N;i++)st.update(1,1,N,i,A[i],B[i]);
    auto n=st.query(1,1,N,1,N);
    return n.q.second;
};
int updateX(int pos, int val){
    pos++;
    st.update(1,1,N,pos,A[pos]=val,B[pos]);
    auto n=st.query(1,1,N,1,N);
    return n.q.second;
};
int updateY(int pos, int val){
    pos++;
    st.update(1,1,N,pos,A[pos],B[pos]=val);
    auto n=st.query(1,1,N,1,N);
    return n.q.second;
};

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火火ビビビビ火せ允洪李|
// |和労允せビミシヘヘシヘㇵ一ㇵヘシ丁火山汎|
// |汎せ丁ヘ一ㇸヘㇵㇸ　・ㇸㇸ・　ㇸㇵミ火允|
// |ビシㇸㇸヘㇵ・ㇸㇵシシシミシㇵㇸ・ヘ丁せ|
// |ヘ・ㇸシㇵ　ㇵヘㇸ・　　ㇸㇵヘシ一　ヘビ|
// |ㇵ　一ミㇸㇸヘ・ㇸㇵヘヘㇵㇸ　一ミヘ　ㇵ|
// |ㇵ　一ミㇸㇸ一・ヘミビ火火丁シ一・シシㇸ|
// |　　　・ㇸ一ㇸㇸミ火允せビミシシㇵ　ヘミ|
// |シシシㇵㇸㇵ　ヘビ火ビシㇵㇸ・　　　一丁|
// |せせ火丁シ一　ㇵミヘ一・　・・ㇸㇸ・ㇵ丁|
// |洪洪允せビヘ・一　・一ヘシミミミミシミヘ|
// |耗和労汎せミ一一ヘミビ火せせ山山せせせビ|
// |義群耗李允火ヘミ火山允汎洪洪汎允洪洪洪允|
// |覇覇義群李汎火丁山洪労李労洪洪労和耗耗和|
// |覇覇覇覇群和汎ビ山労耗群奏和汎労奏陽義陽|
// |覇覇覇覇慶奏労山山労奏義慶群和労奏慶覇覇|
// |覇覇覇覇慶奏労山山労奏慶覇群和労奏慶覇覇|
// |覇覇覇覇義耗洪せ汎耗奏群奏和汎李群義慶義|
// |覇覇覇覇群李允允李耗李李労允汎李耗群奏耗|
// |覇覇覇慶奏労せ洪耗李允允せビ山洪労李労汎|
// +----------------------------------------+
// 2026 (September 4th) 15:54:39
// end signature
