#include <bits/stdc++.h>
using namespace std;
struct segtree{
    using ai2=array<int,2>;
    vector<ai2>T;
    segtree(int N):T(N*4){}
    ai2 compose(ai2 a,ai2 b){
        ai2 o={ b[a[0]], b[a[1]] };
        return o;
    }
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a?ai2{1,1}:ai2{1,0};
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=compose(T[v*2],T[v*2+1]);
    }
    ai2 query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2;ai2 l,r;
        if(ql<=tm)l=query(v*2,tl,tm,ql,qr);
        if(qr >tm)r=query(v*2+1,tm+1,tr,ql,qr);
        if(ql<=tm&&qr>tm)return compose(l,r);
        if(ql<=tm)return l;
        if(qr> tm)return r;
        assert(false);
    }
};
int main(){
    int N;cin>>N;
    segtree st(N+1);vector<int>A(N+1);
    for(int i=1;i<=N;i++){
        cin>>A[i];
        st.update(1,1,N,i,A[i]);
    }
    int Q;cin>>Q;
    for(int i=1;i<=Q;i++){
        int l,r;cin>>l>>r;
        if(l==r)cout<<A[l]<<endl;
        else cout<<st.query(1,1,N,l+1,r)[A[l]]<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇慶陽耗李労洪汎洪労李耗群慶覇覇覇覇覇|
// |覇陽耗洪允火ビ丁丁丁火山洪和群慶覇覇覇覇|
// |耗洪せ丁ㇵㇵミ火せ山山せせ洪耗義覇覇覇覇|
// |允丁一一丁山洪李和和和労汎山李群覇覇覇覇|
// |丁ㇸ一ビ允李奏陽慶慶義陽耗李労和義覇覇覇|
// |シ・ヘせ労奏慶陽群群奏群陽義陽群和義覇覇|
// |シ・ㇵせ労群奏和労洪汎汎洪労和奏陽群義覇|
// |ミ・ㇵせ山洪洪允せビ丁丁丁ビせ允労耗群群|
// |・ㇸㇸ一シビ火ミㇵシせ允汎山ビミせ汎洪洪|
// |ミミシ一　ㇵ一允洪允山せせ山汎允丁ビビビ|
// |汎允せビㇵ労汎せミヘㇵㇵヘミ火允火シ・一|
// |奏和洪せ労せミㇸ・ㇵ・・ㇸ・ヘ丁ミヘㇸ一|
// |陽李ビ李山ミ　ㇵ一ㇸシビ火ビ火火火ヘㇸ・|
// |群労丁汎せヘㇸシ　シせ汎労労洪労労允火ミ|
// |陽労　ミ山シㇸシ・ミ允李奏陽奏労山火ビ火|
// |陽労ヘ　シミ・シㇸビ洪耗義群和李労允丁・|
// |奏汎火ヘ・ヘ一ㇵㇵせ和和李洪允洪耗労火シ|
// |洪火允ビシ・ミ　丁山山山火允李群群労允せ|
// |一耗労山ヘ一ㇵ一丁ビせ汎李奏慶覇耗耗李汎|
// |せ義李山ヘ一ヘㇸ丁允李奏群奏群陽奏李洪汎|
// +----------------------------------------+
// 2026 (April 24th) 16:54:52
// end signature
