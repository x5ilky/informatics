#include "wombats.h"
#include <bits/stdc++.h>
using namespace std;

const int B=15;
int R,C,(*H)[200],(*V)[200];
struct segtree {
    using blk=vector<vector<int>>;
    vector<blk>T;int N;
    segtree(int _N):N((_N+B-1)/B),T((_N+B-1)/B*4,vector(C,vector<int>(C))){}
    blk merge(const blk&a,const blk&b){
        blk n=vector(C,vector(C,0));
        for(int i=0;i<C;i++){
            function<void(int,int,int,int)>dnc=[&](int l,int r,int optl,int optr){
                if(l>r)return;
                int mid=(l+r)/2;
                pair<int,int>ans={a[i][optl]+b[optl][mid],optl};
                for(int k=optl+1;k<=optr;k++)ans=min(ans,{a[i][k]+b[k][mid],k});
                n[i][mid]=ans.first;
                dnc(l,mid-1,optl,ans.second);
                dnc(mid+1,r,ans.second,optr);
            };
            dnc(0,C-1,0,C-1);
        }
        return n;
    }
    void build(int v,int tl,int tr){
        if(tl==tr)return;
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    void update(int v,int tl,int tr,int pos,const blk& a){
        if(tl==tr)return void(T[v]=a);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    void refresh(int r){
        if(r>=R-1)return;
        int b=r/B;
        blk out(C,vector(C,(int)0));
        for(int r=0;r<B;r++){
            if(b*B+r>=R-1)break;
            blk nn=vector(C,vector(C,0));
            vector<int>ps(C);
            for(int i=1;i<=C-1;i++)ps[i]=ps[i-1]+H[b*B+r][i-1];
            for(int i=0;i<C;i++)for(int j=0;j<C;j++)nn[i][j]=abs(ps[j]-ps[i])+V[b*B+r][j];
            if(r==0)out=nn;
            else out=merge(out,nn);
        }
        update(1,0,N-1,b,out);
    }
    int query(int v1,int v2){
        int ans=1e9;
        vector<int>ps(C);
        for(int i=1;i<=C-1;i++)ps[i]=ps[i-1]+H[R-1][i-1];
        for(int i=0;i<C;i++)ans=min(ans,abs(ps[v2]-ps[i])+T[1][v1][i]);
        return ans;
    }
};

segtree st(1);
void init(int _R, int _C, int _H[5000][200], int _V[5000][200]) {
    R=_R,C=_C,H=_H,V=_V;
    st=segtree(R-1);
    for(int i=0;i<st.N;i++)st.refresh(i*B);
    st.build(1,0,st.N-1);
}
void changeH(int P, int Q, int W) { H[P][Q]=W;st.refresh(P); }
void changeV(int P, int Q, int W) { V[P][Q]=W,st.refresh(P); }
int escape(int V1, int V2) { return st.query(V1,V2); }

// begin signature
// +----------------------------------------+
// |ヘ一ㇸ・・ㇸ一ㇵシ丁ミシシシミ丁ビせ允洪|
// |　ㇸㇵㇵㇵ一ㇸ　ㇸ一ㇸ　　　・一ヘミ火允|
// |ミ丁ビビビミヘ一ㇸ一ㇵヘㇵㇵ一　ㇸヘ丁せ|
// |山允せ丁ヘ・ㇵヘヘㇵ一ヘㇵシシㇵ・ㇸシ火|
// |洪山丁ㇵㇸヘミビミ一ㇸㇸㇸヘ一シヘ・一ミ|
// |洪せミ一ヘ丁火山山丁ミ丁ミヘㇵ・シミㇸㇸ|
// |労山丁一シ火允洪労允せ山山火丁ヘ・ㇵ丁一|
// |李允丁一ミせ汎李奏李汎労労洪允ビヘ一シ丁|
// |労山ミㇵビ允李奏陽和李奏奏耗労山丁シヘミ|
// |汎火ヘ丁山労奏義群李群慶義耗労せミ一ㇵ丁|
// |山ミ丁せ労奏義義耗奏慶覇群李允ビㇵ・ミヘ|
// |せ山山允和群慶奏李奏群群和汎火シシシミㇸ|
// |洪労允允李群義耗労労李李洪山ビミ丁ミシ　|
// |耗和労汎洪和群耗洪山允允山允允山せビシ一|
// |陽陽群耗労李李和洪山せ汎労洪山ビ丁シシミ|
// |覇覇覇義奏李李洪允火汎労労允火ミヘㇵㇵ・|
// |覇覇覇覇陽和洪山ビ允労和汎火シシヘ・　ㇵ|
// |覇覇覇覇群和汎ビ允李和汎火シㇵㇸㇵ　シ丁|
// |覇覇覇義耗洪せ山労耗洪せシ　ㇸ一一一丁火|
// |覇覇慶群李允火汎和李允丁一ㇸ・ㇵ・ㇵビ火|
// +----------------------------------------+
// 2026 (August 17th) 21:45:28
// end signature

