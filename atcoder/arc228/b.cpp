#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
struct val{
    int v,m;
    explicit operator int()const{
        return v*m;
    }
    auto operator<=>(const val&other)const {
        return (int)*this<=>(int)other;
    }
};
struct segtree {
    vector<pair<val,int>>T;
    segtree(int N):T(N*4,{{(int)1e18,1},-1}){}
    void update(int v, int tl, int tr, int pos, val a) {
        if(tl==tr){
            T[v]={a,tl};
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=min(T[v*2],T[v*2+1]);
        }
    }
    pair<val,int> query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2;pair<val,int>ans={{(int)1e18,1},-1};
            if (ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
signed main() {
    int N;cin>>N;
    vector<int>P(N+1),A(N+1);
    for(int i=1;i<=N;i++)cin>>P[i];
    for(int i=1;i<=N;i++)cin>>A[i];
    segtree st(N+1);
    vector<int>stk;
    int ans=0;
    for(int i=1;i<=N;i++){
        while(stk.size()&&P[i]>P[stk.back()])stk.pop_back();
        int l=1;
        if(!stk.empty())l=stk.back();
        auto res=st.query(1,1,N,l,N);
        // printf("i = %d, P[i] = %d, left = %lld, min = %lldx%lld:%lld\n",i,P[i],l,res.first.v,res.first.m,P[res.second]);
        st.update(1,1,N,i,{A[P[i]],1});
        if(res.second!=-1){
            ans+=(int)res.first;
            st.update(1,1,N,res.second,{res.first.v,res.first.m+2});
        }
        stk.push_back(i);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火せ山汎洪和奏陽覇覇覇|
// |和労允せビミシヘヘシミ丁火允洪和奏義覇覇|
// |汎せ丁ヘ一ㇸヘミ丁ビ丁丁丁せ允労耗陽覇覇|
// |ビシㇸㇸシ丁火山允允允山火ビ山洪耗陽覇覇|
// |ヘ・ㇸシビ山汎洪汎汎汎汎汎山山允李奏陽義|
// |ㇵ　一丁せ山せ火火ビビ火火せ允洪允李和耗|
// |ㇵ　一丁ビ丁ミシシヘㇵㇵヘシ丁火山汎汎汎|
// |ヘ　一シヘ一ㇸ　・ㇸㇸㇸㇸㇸㇸㇵミビ火火|
// |・・　　　ㇸㇸ一一ㇸㇸㇸ一ㇵㇵㇵ一ヘヘヘ|
// |ミシヘㇵㇸ一一　ㇸ一ヘㇵㇵㇵヘシミㇵ・・|
// |せ丁・一一・ㇵ一・　・・・　　ㇸヘミㇵ　|
// |シㇸ一・一一　一ヘシミミミシㇵㇸ・ㇵシ・|
// |　一ㇸ一ㇸ・ヘミビせ山山せ火ビミㇵ　一ㇵ|
// |　・・ㇵ　ㇵ丁火允汎洪労労洪汎山ビシㇸㇸ|
// |ㇸㇸ　一　ヘビ山洪李耗奏和洪山火丁ミミㇵ|
// |ㇸ一ㇸ　・シ火汎李奏陽奏李允火ミㇵㇸ・・|
// |　一・・ㇵビ允労奏義陽和汎せミ一　一ㇵㇵ|
// |ㇸ一ㇸ一丁允労奏義陽和洪せシ・一ミビビ丁|
// |一・ㇸ丁山労奏慶義耗洪せシ・ㇵビ山山ビシ|
// |一　ヘ火汎和陽覇群李允丁一ㇸ丁せ火丁ミ火|
// +----------------------------------------+
// 2026 (August 30th) 23:02:27
// end signature
