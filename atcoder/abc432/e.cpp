#include <bits/stdc++.h>

using namespace std;
#define int long long

struct node{
    int cnt,sum;
    node& operator+=(const node& other) {
        cnt+=other.cnt;
        sum+=other.sum;
        return *this;
    }
    friend node operator+(node lhs, const node& rhs){
        return lhs += rhs;
    }
};
struct segtree{
    vector<node>T;
    segtree(int N):T(N*4){}
    void add(int v,int tl,int tr,int pos,int addend) {
        if(tl==tr) return T[v]+={addend,pos*addend},void();
        int tm=(tl+tr)/2;
        if (pos<=tm)add(v*2,tl,tm,pos,addend);
        if (pos >tm)add(v*2+1,tm+1,tr,pos,addend);
        T[v]=T[v*2]+T[v*2+1];
    }
    node query(int v,int tl,int tr,int ql,int qr) {
        if(ql<=tl&&tr<=qr) return T[v];
        int tm=(tl+tr)/2;node ans={0,0};
        if (ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
        if (qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
        return ans;
    }
};
signed main() {
    int N,Q;cin>>N>>Q;
    vector<int> A(N+1);
    segtree st(500050);
    for (int i=1;i<=N;i++){
        int v;cin>>v; st.add(1,0,500010,v,1); A[i]=v;
    }
    for (int q=1;q<=Q;q++){
        int t;cin>>t;
        if(t==1){
            int x,y;cin>>x>>y;
            st.add(1,0,500010,A[x],-1);
            st.add(1,0,500010,A[x]=y,1);
        } else {
            int l,r;cin>>l>>r;
            if(l>=r){
                cout<<l*N<<endl;
                continue;
            }
            int ans=0;
            if(l>0)ans+=st.query(1,0,500010,0,l-1).cnt*l;
            ans+=st.query(1,0,500010,r+1,500010).cnt*r;
            ans+=st.query(1,0,500010,l,r).sum;
            cout<<ans<<endl;
        }
    }
}

// begin signature
// +----------------------------------------+
// |覇義奏和労汎允山山山允汎労和奏陽覇覇覇覇|
// |群和洪允火丁ミシシミ丁火山汎李奏義覇覇覇|
// |洪山ビシㇵ一シ丁ビ火火ビビ山洪耗陽覇覇覇|
// |火シㇸㇸシビ山汎洪洪汎允せ火汎李群覇覇覇|
// |シ・ㇸミせ汎労洪汎汎汎汎洪汎允洪耗義義慶|
// |ㇵ　ㇵビ允允山火ビ丁丁ビ火せ允洪洪和和耗|
// |ㇵ・一ミビ火丁シㇵㇵㇵㇵㇵヘミビ山汎汎汎|
// |ㇸㇸ・　ㇸヘㇵㇵ・一ㇸ・　・・一シビ丁丁|
// |丁ミㇵ・・一ㇸㇸ　ㇸㇵヘシヘㇵㇵ一一ㇸㇸ|
// |ㇵ　一シミ丁丁丁丁ビ火せせ火ビシ一　・　|
// |　シ火山允汎允山汎洪労労允火ビ丁シㇸ・ㇸ|
// |・ミ允李和和李李李和汎せせせせせビㇵ　ㇸ|
// |　シせ労奏義陽群李労允洪労洪労労山丁一・|
// |ㇸ・ミ山労奏義覇群労洪和奏奏耗奏労山ビ一|
// |丁一　シ火汎和奏義和洪耗耗耗耗和李労山ミ|
// |允丁ㇵ　ヘビ允洪和耗洪耗耗李洪汎允李洪火|
// |汎山丁ㇵ　ヘビせ允洪洪洪汎山火山労耗洪火|
// |労汎火ミヘㇸヘミビ火火火丁せ汎李奏李山火|
// |和労允せビミシシミ丁ビせ汎汎汎洪汎山ビビ|
// |和耗李洪允山山山山允洪山ビ丁火火ビミ火せ|
// +----------------------------------------+
// 2026 (April 1st) 14:58:48
// end signature

