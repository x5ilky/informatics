#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
// struct node{
//     node*l,*r;int cnt,sum;
//     node(int cnt,int sum):l(nullptr),r(nullptr),cnt(cnt),sum(sum){}
//     node(node*l,node*r):l(l),r(r),sum(0),cnt(0){
//         if(l)sum+=l->sum;
//         if(r)sum+=r->sum;
//         if(l)cnt+=l->cnt;
//         if(r)cnt+=r->cnt;
//     }
//     void fix(){
//         if(!l)l=new node(0ll,0ll);
//         if(!r)r=new node(0ll,0ll);
//     }
//     node*add(int tl,int tr,int pos,int a){
//         if(tl==tr)return new node(cnt+a,(cnt+a)*tl);
//         int tm=(tl+tr)/2;fix();
//         if(pos<=tm)return new node(l->add(tl,tm,pos,a),r);
//         if(pos >tm)return new node(l,r->add(tm+1,tr,pos,a));
//         assert(0);
//     };
//     int range_sum(int tl,int tr,int ql,int qr){
//         if(ql<=tr&&tr<=qr)return sum;
//         int tm=(tl+tr)/2,ans=0;fix();
//         if(ql<=tm)ans+=l->range_sum(tl,tm,ql,qr);
//         if(qr >tm)ans+=r->range_sum(tm+1,tr,ql,qr);
//         return ans;
//     };
// };

// chatgpt array pseg, im not tryna memory optimise
struct __attribute__((packed)) node{
    unsigned l:24=0,r:24=0;
    unsigned cnt:17=0;
    unsigned int sum:47=0;
};

vector<node> T(1); // 0 = null node

int new_leaf(unsigned cnt,unsigned int sum){
    T.push_back({0,0,cnt,sum});
    return T.size()-1;
}

int new_parent(unsigned l,unsigned r){
    T.push_back({
        l,r,
        (unsigned)T[l].cnt+T[r].cnt,
        T[l].sum+T[r].sum
    });
    return T.size()-1;
}

int add(int v,int tl,int tr,int pos,int a){
    if(tl==tr){
        int cnt=T[v].cnt+a;
        return new_leaf(cnt,cnt*tl);
    }

    int tm=(tl+tr)/2;
    int l=T[v].l,r=T[v].r;

    if(pos<=tm) l=add(l,tl,tm,pos,a);
    else r=add(r,tm+1,tr,pos,a);

    return new_parent(l,r);
}

int range_sum(int v,int tl,int tr,int ql,int qr){
    if(qr<tl||tr<ql)return 0;
    if(ql<=tl&&tr<=qr)return T[v].sum;

    int tm=(tl+tr)/2;
    return range_sum(T[v].l,tl,tm,ql,qr)
         + range_sum(T[v].r,tm+1,tr,ql,qr);
}
long long findMaxAttraction(signed N, signed S, signed D, signed _A[]) {
    int tl=0,tr=1e9;
    vector<int>segs(N+1);segs[0]=new_leaf(0ll,0ll);S++;
    for(int i=1;i<=N;i++)segs[i]=add(segs[i-1],tl,tr,_A[i-1],1);
    function<int(int,int,int,int,int)>qry=[&](int L,int R,int tl,int tr,int K)->int{
        if(K<=0)return 0ll;
        if(tl==tr)return min<int>(K,T[R].cnt-T[L].cnt)*tl;
        int tm=(tl+tr)/2;
        int rc=T[T[R].r].cnt-T[T[L].r].cnt;
        if(rc<K)return T[T[R].r].sum-T[T[L].r].sum+qry(T[L].l,T[R].l,tl,tm,K-rc);
        if(rc==K)return T[T[R].r].sum-T[T[L].r].sum;
        return qry(T[L].r,T[R].r,tm+1,tr,K);
    };
    int ans=0;
    {
        vector<int>dp(N+1);
        function<void(int,int,int,int)>dnc=[&](int l,int r,int optl,int optr){
            if(l>r)return;
            int mid=(l+r)/2;
            pair<int,int>ans={-1e9,-1};
            for(int k=optl;k<=optr;k++)
                ans=max(ans,{qry(segs[k-1],segs[mid],tl,tr,D-((S-k)*2+mid-S)),k});
            dp[mid]=ans.first;
            dnc(l,mid-1,optl,ans.second);
            dnc(mid+1,r,ans.second,optr);
        };
        dnc(S,N,1,S);
        for(int i=1;i<=N;i++)ans=max(ans,dp[i]);
    }
    {
        vector<int>dp(N+1);
        function<void(int,int,int,int)>dnc=[&](int l,int r,int optl,int optr){
            if(l>r)return;
            int mid=(l+r)/2;
            pair<int,int>ans={-1e9,-1};
            for(int k=optl;k<=min(mid,optr);k++)
                ans=max(ans,{qry(segs[k-1],segs[mid],tl,tr,D-((S-k)+(mid-S)*2)),k});
            dp[mid]=ans.first;
            dnc(l,mid-1,optl,ans.second);
            dnc(mid+1,r,ans.second,optr);
        };
        dnc(S,N,1,S);
        for(int i=1;i<=N;i++)ans=max(ans,dp[i]);
    }
    T.resize(1);
    return ans;
}

// begin signature
// +----------------------------------------+
// |允山火ビ丁ミシシシ　　・　ヘヘヘヘシミビ|
// |火丁シヘ一　　・・ㇸ一ㇵ一ㇸ　・・一ㇵシ|
// |ヘ一・　・一ヘシシヘㇵ一一一一一ㇸ　・ㇵ|
// |　・・ㇵミビビミシㇵヘシミミミシヘ一　ㇸ|
// |一ㇵシ火せビミヘヘミビ火せせ火ビ丁シㇵ・|
// |ミ丁火山せ丁ヘ一シビせ山山せビ丁ミシシヘ|
// |ビ火せ允せ丁ヘヘミ火山汎せ山火丁ミシシヘ|
// |せせ山允火ミヘミビ火允汎允せ丁シㇵㇸㇸ一|
// |汎允洪山ビシ丁火山山洪汎山山せ丁シ一　　|
// |汎汎允火ミビ山火せ汎洪山火せせビシㇵ　　|
// |汎汎火ミ火火丁火允洪允火丁ビミㇵ一　　　|
// |洪山丁火火ミ丁せ洪汎允山火ミ一ヘ・・ㇸ・|
// |洪山ビせ丁ビ火山汎労労山ビミミシヘ一ㇸ　|
// |汎允火火火山允允汎李李允山せ火ビ丁ミヘㇸ|
// |せ洪允火山汎洪労労労和労汎せビミヘㇵㇵヘ|
// |允山洪せ允労李耗耗耗和洪允山ビミヘㇵ一一|
// |允火汎允労和奏群陽耗李汎允山せ火丁ミミヘ|
// |山火允労和群義義奏李汎せ山せビビ丁ミヘヘ|
// |山山洪和群慶慶群和洪山ビビ火ビビ丁シㇵㇸ|
// |山汎李奏義覇陽耗労允火ミミミシヘ一・　・|
// +----------------------------------------+
// 2026 (August 19th) 21:41:33
// end signature

