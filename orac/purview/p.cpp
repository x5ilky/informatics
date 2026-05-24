#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
struct segtree{
    using node=struct{
        int sm,lz,mx;
    };
    int N;vector<node>T;
    segtree(int N):T(N*4,{0,0,-INF}){}
    void push(int v,int tl,int tr){
        int tm=(tl+tr)/2;
        T[v*2].sm+=T[v].lz*(tm-tl+1);
        T[v*2+1].sm+=T[v].lz*(tr-tm);
        T[v*2].mx+=T[v].lz;
        T[v*2+1].mx+=T[v].lz;
        T[v*2].lz+=T[v].lz;
        T[v*2+1].lz+=T[v].lz;
        T[v].lz=0;
    }
    void range_add(int v,int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            T[v].sm+=a*(tr-tl+1);
            T[v].lz+=a;
            T[v].mx+=a;
            return;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(ql<=tm)range_add(v*2,tl,tm,ql,qr,a);
        if(qr >tm)range_add(v*2+1,tm+1,tr,ql,qr,a);
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
        T[v].mx=max(T[v*2].mx,T[v*2+1].mx);
    }
    void set(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v].sm=a;
            T[v].mx=a;
            T[v].lz=0;
            return;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(pos<=tm)set(v*2,tl,tm,pos,a);
        if(pos >tm)set(v*2+1,tm+1,tr,pos,a);
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
        T[v].mx=max(T[v*2].mx,T[v*2+1].mx);
    }
    int range_sum(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v].sm;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2,sm=0;
        if(ql<=tm)sm+=range_sum(v*2,tl,tm,ql,qr);
        if(qr >tm)sm+=range_sum(v*2+1,tm+1,tr,ql,qr);
        return sm;
    }
    int range_max(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v].mx;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2,mx=-INF;
        if(ql<=tm)mx=max(mx,range_max(v*2,tl,tm,ql,qr));
        if(qr >tm)mx=max(mx,range_max(v*2+1,tm+1,tr,ql,qr));
        return mx;
    }
};
signed main() {
    int N,D;cin>>N>>D;
    string S;cin>>S;S.insert(S.begin(),' ');
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i]; 
    vector<int>order;vector<bool>seen(N+1);
    for(int i=1;i<=D;i++){
        int v;cin>>v;
        order.push_back(v);seen[v]=true;
    }
    for(int i=1;i<=N;i++)if(!seen[i])order.push_back(i);
    reverse(order.begin(),order.end());
    using pii=pair<int,int>;
    set<pii>rights;
    segtree stR(N+1);segtree stL(N+1);vector<int>ans(N+1);
    for(auto i:order){
        if(S[i]=='L'){
            stL.set(1,1,N,i,A[i]-stR.range_sum(1,1,N,1,i));
        }
        if(S[i]=='R'){
            int sat=A[i]-stR.range_sum(1,1,N,i,N);int add=0;
            while(sat>0){
                auto it=rights.lower_bound({i,0});
                if(it==rights.begin()){
                    // add
                    stR.range_add(1,1,N,i,i,sat);
                    rights.insert({i,sat});
                    stL.range_add(1,1,N,i,N,-sat);
                    break;
                }
                auto v=*--it;rights.erase(it);int amt=min(v.second,sat);
                sat-=amt;
                if(v.second>amt){
                    rights.insert({v.first,v.second-amt});
                }
                stR.range_add(1,1,N,v.first,v.first,-amt);
                stR.range_add(1,1,N,i,i,amt);
                stL.range_add(1,1,N,v.first,i-1,amt);
                add+=amt;
            }
            if(add)rights.insert({i,add});
        }
        // for(int i=1;i<=N;i++)printf("%d ",stR.range_sum(1,1,N,i,i));printf("\n");
        int l=max(stL.range_max(1,1,N,1,N),0ll),r=stR.range_sum(1,1,N,1,N);
        // printf("add %d l %d r %d ans %d\n",i,l,r,l+r);
        ans[i]=l+r;
    }
    for(int i=N;i>=max(N-D,1ll);i--){
        cout<<ans[order[i-1]]<<endl;
    }
    if(D==N)cout<<0<<endl;
}

// begin signature
// +----------------------------------------+
// |覇慶群耗李洪允允山せビ丁ミミ丁ビせ允洪和|
// |陽耗労允せビミミミㇵㇸ・　　ㇸㇵシビ山洪|
// |労允火ミㇵ一シㇸ・ㇵヘシシヘㇵ・ㇸシ火汎|
// |せミ一ㇸミ一ㇸシシㇵㇵㇵヘミ丁ヘ・一丁山|
// |ミ・ㇸ丁一一シㇸ　ㇸ一一・・ヘ丁ミㇸㇵビ|
// |ヘ　ㇵミ　ヘ一ㇸシ丁ビ火丁シㇸ・ミ丁一一|
// |ヘ・ㇵ丁・ヘㇸㇵシヘヘビ丁シヘㇵ　ヘ火ㇵ|
// |シ　一丁ㇸヘ・ヘ火汎汎允せビシ一一ㇸヘビ|
// |・ㇸ　・　シ・ミ允李洪允山せビミヘ　ヘビ|
// |丁丁シ一一・　ミせ山山火ミ一ヘシヘㇸヘ火|
// |山シシ　丁汎耗群陽陽奏李允ビヘ　一ㇸビシ|
// |・丁ミ労群覇慶陽陽奏和洪允火ミㇵ　シビㇸ|
// |　ミ李義慶群耗和李労允火丁シヘㇵㇸヘミ　|
// |ㇸ山群覇群和労汎山せ火ミ一　・ㇸㇸシㇵ・|
// |丁允陽慶奏労允火ミシヘㇵ　ㇵシㇸ一丁・・|
// |ビ汎義義耗洪火シ一　・・ㇵ一・ㇸシミ・　|
// |シ耗覇奏労せシ・ヘシㇵ一ㇸ一ヘ丁丁一ㇸヘ|
// |李覇群労せシ　一　ㇵシミミミヘ一　ㇵ丁火|
// |慶陽李山シ　ミシㇵ・　　　　ㇸヘ丁せせ丁|
// |慶耗汎ビㇸㇵせせビ丁ミシミ丁ビせせビビ山|
// +----------------------------------------+
// 2026 (May 24th) 17:19:45
// end signature




