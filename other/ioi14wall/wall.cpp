#include "wall.h"
#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int INF=1e9;
struct segtree {
    vector<pii>T;
    segtree(int N):T(N*4,{-INF,INF}){}
    void push(int v){
        T[v*2].first=max(T[v].first,min(T[v].second,T[v*2].first));
        T[v*2].second=max(T[v].first,min(T[v].second,T[v*2].second));
        T[v*2+1].first=max(T[v].first,min(T[v].second,T[v*2+1].first));
        T[v*2+1].second=max(T[v].first,min(T[v].second,T[v*2+1].second));
        T[v]={-INF,INF};
    }
    void chmin(int v,int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            T[v].second=min(T[v].second,a);
            if(T[v].second<T[v].first)T[v].first=T[v].second;
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(ql<=tm)chmin(v*2,tl,tm,ql,qr,a);
        if(qr >tm)chmin(v*2+1,tm+1,tr,ql,qr,a);
    }
    void chmax(int v,int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            T[v].first=max(T[v].first,a);
            if(T[v].first>T[v].second)T[v].second=T[v].first;
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(ql<=tm)chmax(v*2,tl,tm,ql,qr,a);
        if(qr >tm)chmax(v*2+1,tm+1,tr,ql,qr,a);
    }
    pii query(int v,int tl,int tr,int pos){
        if(tl==tr)return T[v];
        push(v);
        int tm=(tl+tr)/2;
        if(pos<=tm)return query(v*2,tl,tm,pos);
        if(pos >tm)return query(v*2+1,tm+1,tr,pos);
        assert(0);
    }
};

void buildWall(int N, int Q, int op[], int left[], int right[], int height[], int finalHeight[]){
    segtree st(N+1);
    for(int i=0;i<Q;i++){
        if(op[i]==1)st.chmax(1,0,N,left[i],right[i],height[i]);
        if(op[i]==2)st.chmin(1,0,N,left[i],right[i],height[i]);
    }
    for(int i=0;i<N;i++){
        pii clamp=st.query(1,0,N,i);
        finalHeight[i]=max(clamp.first,min(clamp.second,0));
    }
}


// begin signature
// +----------------------------------------+
// |覇覇陽奏李洪汎允允山火ビビビビせ山汎李奏|
// |義奏李汎せビ丁ミミシㇵㇸㇸㇸ一ヘ丁火允李|
// |李汎火ミㇵ一シ一　一ヘヘヘㇵㇸ　一ミせ洪|
// |せミ一ㇸミㇵ・ㇸミ　ㇸヘミシ丁ヘ　ㇵビ允|
// |ミㇸㇸ丁ㇵㇸ一ㇵ　・ㇸㇸ　ㇸㇵ丁シ・ヘ火|
// |ヘ　ㇵ丁・ㇵㇵ　ヘミビビ丁ヘ・ㇸ丁丁ㇸㇵ|
// |ヘ　ㇵ丁ㇸㇵ一一丁せ汎洪汎允火ヘ　シビㇵ|
// |シ　ㇵビㇸㇵㇸヘ火汎和奏奏耗労山ミ　シビ|
// |ㇵㇸヘ丁　シ　ミ允和群慶覇義耗洪火ㇵ一火|
// |　　ㇸㇵ一ㇸヘ山李耗義陽義慶奏洪ビㇸヘ火|
// |シシㇵ・ㇵ一火洪李奏奏奏奏陽李せヘㇸビシ|
// |山せㇵ一ㇸヘせ李労洪汎洪労耗汎丁・シビㇸ|
// |和・ヘㇸㇵ一ビ汎允汎汎汎山洪せシ・丁丁・|
// |李・ヘㇵ一一一丁山洪李和労汎火ヘ・シミㇸ|
// |和允一　ㇵㇸヘ　ヘビせ山山火ミ一ㇸミㇸㇸ|
// |和允火ミ・ㇵ・ミㇸ・ㇵシシヘ一　ヘビㇸ　|
// |李李洪火ヘㇸ一ㇸシヘ一・・ㇸㇵミビヘ・ㇵ|
// |陽奏洪ビ一ㇸシㇸㇸヘミ丁丁丁ミㇵ・一ミせ|
// |奏労せヘㇸ丁ミシ一　・ㇸ・　・ㇵミ火汎李|
// |洪山ミ　シ山允火丁ミシヘシミビせ允労和陽|
// +----------------------------------------+
// 2026 (August 16th) 13:58:14
// end signature
