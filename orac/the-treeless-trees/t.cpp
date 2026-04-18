#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
struct segtree{
    vector<int>mn,mx,lz;
    segtree(int N):mn(N*4,0),mx(N*4,0),lz(N*4,0){};
    void push(int v){
        if(lz[v]!=0){
            lz[v*2]+=lz[v];
            lz[v*2+1]+=lz[v];
            mn[v*2]+=lz[v];
            mn[v*2+1]+=lz[v];
            mx[v*2]+=lz[v];
            mx[v*2+1]+=lz[v];
            lz[v]=0;
        }
    }
    void update(int v,int tl,int tr,int ql,int qr,int addend){
        if(ql<=tl&&tr<=qr){
            mn[v]+=addend;
            mx[v]+=addend;
            lz[v]+=addend;
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(ql<=tm)update(v*2,tl,tm,ql,qr,addend);
        if(qr> tm)update(v*2+1,tm+1,tr,ql,qr,addend);
        mn[v]=min(mn[v*2],mn[v*2+1]);
        mx[v]=max(mx[v*2],mx[v*2+1]);
    }
    int query_min(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return mn[v];
        }
        push(v);
        int mn=INF,tm=(tl+tr)/2;
        if(ql<=tm)mn=min(mn,query_min(v*2,tl,tm,ql,qr));
        if(qr >tm)mn=min(mn,query_min(v*2+1,tm+1,tr,ql,qr));
        return mn;
    }
    int query_max(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return mx[v];
        }
        push(v);
        int mx=INF,tm=(tl+tr)/2;
        if(ql<=tm)mx=max(mx,query_max(v*2,tl,tm,ql,qr));
        if(qr >tm)mx=max(mx,query_max(v*2+1,tm+1,tr,ql,qr));
        return mx;
    }
    int zero(int v,int tl,int tr,int ql,int qr){
        if(qr<tl||tr<ql)return -1;
        if(mn[v]>0)return -1;
        if(tl==tr)return tl;
        push(v);
        int tm=(tl+tr)/2;
        int l=zero(v*2,tl,tm,ql,qr);
        if(l!=-1)return l;
        return zero(v*2+1,tm+1,tr,ql,qr);
    }
    int nonzero(int v,int tl,int tr,int ql,int qr){
        if(qr<tl||tr<ql)return -1;
        if(mx[v]<=0)return -1;
        if(tl==tr)return tl;
        push(v);
        int tm=(tl+tr)/2;
        if(mx[v*2]>0)return nonzero(v*2,tl,tm,ql,qr);
        return nonzero(v*2+1,tm+1,tr,ql,qr);
    }
};
signed main() {
    int N;cin>>N;
    segtree st(N+1);for(int i=1;i<=N;i++){int v;cin>>v;st.update(1,1,N,i,i,v);}
    const int INF=1e9+7;
    function<int(int,int)>solve=[&](int l,int r){
        // printf("query %d-%d\n",l,r);
        int mn=st.query_min(1,1,N,l,r);
        assert(mn>0);
        st.update(1,1,N,l,r,-mn);
        // for(int i=1;i<=N;i++)printf("%d ",st.query_min(1,1,N,i,i));
        // printf("\n");
        int ans=mn,ql=st.nonzero(1,1,N,l,r);
        while(ql!=-1){
            int qr=st.zero(1,1,N,ql,r);
            if(qr==-1)qr=r;else qr--;
            ans+=solve(ql,qr);
            ql=st.nonzero(1,1,N,l,r);
        }
        return ans;
    };
    cout<<solve(1,N)<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏李労汎允允せ火丁丁丁丁火せ汎労耗|
// |義奏李汎せビ丁ミミㇵㇸ・　・ㇸㇵミ火允労|
// |李汎火ミㇵ一シㇸ・ㇵシミミシㇵ・ㇸシ火汎|
// |せミ一一ミ一ㇸシシヘㇵㇵヘ丁ミシ・一丁山|
// |ミ・一丁一一ミ一　一ㇵ一・・ㇵ丁ミㇸㇵビ|
// |ヘ・ヘミ・ヘ一ㇸシ丁火火ビシ一・ミ丁一一|
// |ヘ・ㇵ丁・ヘㇸㇵビ山洪労洪汎火シ　ヘ火ㇵ|
// |シ・一ビㇸヘ・ヘせせせせせ山允山ミ・シ火|
// |ㇵㇸヘシ　シ・丁ミヘㇵㇵヘシ丁火火ㇵ一火|
// |一一・　ㇵ・ㇵ・・一一一ㇸ　ㇸヘミㇸヘ火|
// |火ビミヘㇵ・ヘミビ火火ビ丁シ一　一ㇸビシ|
// |洪汎山ビヘビ山汎洪労洪汎允火丁ヘ・シビㇸ|
// |奏洪火ヘ火允労耗和和耗奏和洪山ビミ丁ミ　|
// |奏洪火ミ山労和洪汎允允洪李耗洪山ビビ丁・|
// |群労せミ山李労山ビ山汎洪洪汎允ビ丁丁丁ビ|
// |陽李せミ允和汎火せ洪和奏奏李山丁シシㇸ・|
// |群労火ビ洪労せ丁汎耗陽陽和允丁丁ミㇸ　ヘ|
// |和山ミ允和山ミ允和義義和允丁シ一　ㇵ丁せ|
// |汎ビせ労汎丁せ李陽慶耗允丁　一ヘ丁せ洪山|
// |允ミ山和允ミ山李陽群労せㇵ一火山汎李允丁|
// +----------------------------------------+
// 2026 (April 18th) 16:26:50
// end signature

