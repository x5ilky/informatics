#include "circuit.h"
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::static_modint<1000002022>;
struct segtree {
    vector<mint>A,psA;
    vector<mint>T;vector<short>lz;
    segtree(int N,vector<mint>A):A(A),psA(N+1),T(4*N),lz(4*N){
        for(int i=0;i<N;i++)psA[i+1]=psA[i]+A[i];
    }
    mint sum(int l,int r){
        return psA[r+1]-psA[l];
    }
    void push(int v,int tl,int tr){
        if(lz[v]){
            int tm=(tl+tr)/2;
            T[v*2]=sum(tl,tm)-T[v*2];
            T[v*2+1]=sum(tm+1,tr)-T[v*2+1];
            lz[v*2]^=1;
            lz[v*2+1]^=1;
            lz[v]^=1;
        }
    }
    void set(int v,int tl,int tr,int pos,mint a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        push(v,tl,tr);
        if(pos<=tm)set(v*2,tl,tm,pos,a);
        if(pos >tm)set(v*2+1,tm+1,tr,pos,a);
        T[v]=T[v*2]+T[v*2+1];
    }
    void flip(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            lz[v]^=1;
            T[v]=sum(tl,tr)-T[v];
            return;
        }
        int tm=(tl+tr)/2;
        push(v,tl,tr);
        if(ql<=tm)flip(v*2,tl,tm,ql,qr);
        if(qr >tm)flip(v*2+1,tm+1,tr,ql,qr);
        T[v]=T[v*2]+T[v*2+1];
    }
    mint query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2;mint sum=0;
        push(v,tl,tr);
        if(ql<=tm)sum+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)sum+=query(v*2+1,tm+1,tr,ql,qr);
        return sum;
    }
};
segtree st(1,{0});
int N,M;mint prod=1;
void init(int _N, int _M, std::vector<int> P, std::vector<int> A) {
    N=_N,M=_M;
    vector<mint>B(M+1);
    vector<vector<int>>g(N+M+1);
    for(int i=1;i<=N+M;i++){
        g[P[i-1]+1].push_back(i);
    }
    vector<mint>stProd(N+M+1,1);
    function<void(int)>dfs=[&](int u){
        for(auto v:g[u])dfs(v),stProd[u]*=stProd[v];
        if(g[u].size())stProd[u]*=g[u].size();
    };
    function<void(int,mint)>dfs2=[&](int u,mint q){
        int C=g[u].size();
        if(!C)return void(B[u-N]=q);
        vector<mint>M(C,1),pM(C+1,1),sM(C+1,1);
        for(int i=0;i<C;i++)M[i]=stProd[g[u][i]];
        for(int i=0;i<C;i++)pM[i+1]=pM[i]*M[i];
        for(int i=C-1;i>=0;i--)sM[i]=sM[i+1]*M[i];
        for(int i=0;i<C;i++){
            dfs2(g[u][i],pM[i]*sM[i+1]*q);
        }
    };
    dfs(1);dfs2(1,1);
    st=segtree(M+1,B);
    for(int i=1;i<=M;i++)st.set(1,1,M,i,B[i]*A[i-1]);
}

int count_ways(int L, int R) {
    st.flip(1,1,M,L-N+1,R-N+1);
    return (st.query(1,1,M,1,M)).val();
}

// begin signature
// +----------------------------------------+
// |群和労汎允せ火火ビ火火せ允汎労和奏義覇覇|
// |李洪山火丁ミシヘヘヘシ丁火山汎労耗群慶覇|
// |允火ミヘ一ㇸㇵシミ丁ミミミ火山洪和群義覇|
// |丁ヘㇸ・ヘミビせ山山せ火ビ丁せ汎李奏陽慶|
// |ヘ・ㇸヘ丁せ允汎允允允允山せ火山洪李耗群|
// |ㇵ　一ミ火山せ火ビビビビ丁ビビ火山允洪李|
// |・　ㇸ一ヘミ丁ミヘヘㇵㇵㇵㇵㇵヘミ丁火允|
// |ㇵㇵ一ㇸ　ㇸㇵ一・　　・　　ㇸㇵシヘシ丁|
// |ビビ丁ミヘ一　ㇸㇵヘシシシヘ一　ㇸヘミヘ|
// |允允山火丁シヘミビミシシシシミㇵ・ㇸシミ|
// |李労汎允火丁ミシヘㇵシシヘ一一ヘ一・一ㇵ|
// |奏耗李汎せせせ火丁ビ火火丁シ一・ㇵㇸ・・|
// |義陽奏李汎洪洪允せ允汎汎山火ミシヘㇸ　　|
// |覇覇義奏李和耗和洪労李和労汎山せ火丁ヘㇸ|
// |覇覇覇慶奏耗陽陽耗労耗群群和汎せ丁ミシミ|
// |覇覇覇覇陽耗陽覇陽和耗陽慶奏李允ビㇵ・ㇵ|
// |覇覇覇慶群和群陽奏李和奏群耗洪山丁一ㇸ・|
// |覇覇慶群和李和和労洪李李李洪山丁ㇵ　ヘ一|
// |義陽奏李汎汎洪汎洪和汎允山火ミ一・一ミ丁|
// |耗和労汎せせせ允李労山ビ丁シㇸ・一ㇵビビ|
// +----------------------------------------+
// 2026 (July 16th) 18:22:03
// end signature
