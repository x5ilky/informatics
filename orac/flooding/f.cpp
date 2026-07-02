#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
using pii=pair<int,int>;
struct segtree {
    vector<int>T;
    segtree(int N):T(4*N,-INF){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr) return void(T[v]=a);
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos> tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=max(T[v*2],T[v*2+1]);
    }
    int value(int v,int tl,int tr,int pos){
        if(tl==tr) return T[v];
        int tm=(tl+tr)/2;
        if(pos<=tm)return value(v*2,tl,tm,pos);
        if(pos> tm)return value(v*2+1,tm+1,tr,pos);
    }
    int query(int v,int tl,int tr,int a){
        if(tl==tr)return tl;
        int tm=(tl+tr)/2;
        if(T[v*2]>=a)return query(v*2,tl,tm,a);
        else if (T[v*2+1]>=a)return query(v*2+1,tm+1,tr,a);
        return -1;
    };
};
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<int>A(N+1),psA(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    int Q,K;cin>>Q>>K;
    A[0]=INF;
    vector<int>st={0};
    const int M=18;
    vector<vector<int>>ri(N+1,vector<int>(M,0)),lf(N+1,vector<int>(M));
    for(int i=1;i<=N;i++){
        while(A[i]>A[st.back()])ri[st.back()][0]=i,st.pop_back();
        st.push_back(i);
    }
    st.push_back(0);
    for(int i=N;i>=1;i--){
        while(A[i]>A[st.back()])lf[st.back()][0]=i,st.pop_back();
        st.push_back(i);
    }
    for(int k=1;k<M;k++){
        for(int i=1;i<=N;i++){
            lf[i][k]=lf[lf[i][k-1]][k-1];
            ri[i][k]=ri[ri[i][k-1]][k-1];
        }
    }
    vector<int>without(N+1);
    if("without adding"){
        for(int i=1;i<=N;i++){
            if(A[i]<=A[i-1])without[i]=without[i-1];
            else without[i]=without[lf[i][0]]+A[i]*(i-lf[i][0])-(psA[i]-psA[lf[i][0]]);
        }
    }
    auto gt=[&](vector<vector<int>>&v,int i,int K){
        for(int k=M-1;k>=0;k--){
            if(A[v[i][k]]<K)i=v[i][k];
        }
        if(A[i]>K)return i;
        return v[i][0];
    };
    auto contain=[&](int i){
        int lft=gt(lf,i,A[i]+K);
        int a=without[lft]+(A[i]+K)*(i-lft-1)-(psA[i-1]-psA[lft]);
        return a;
    };
    set<array<int,3>>ev;
    for(int i=1;i<=N;i++){
        int a=contain(i);
        int rgt=gt(ri,i,A[i]+K);
        if(rgt==0)rgt=N+1;
        ev.insert({i,a-without[i],1});
        ev.insert({rgt+1,a-without[i],2});
    }
    segtree cap(N+1);
    multiset<int>d;
    for(int i=1;i<=N;i++){
        while(ev.size()&&(*ev.begin())[0]<=i){
            auto [_,v,t]=*ev.begin();ev.erase(ev.begin());
            if(t==1)d.insert(v);
            else d.erase(d.find(v));
        }
        cap.update(1,1,N,i,without[i]+*d.rbegin());
    }
    for(int q=1;q<=Q;q++){
        int w;cin>>w;
        int j=cap.query(1,1,N,w);
        cout<<(j==-1?N:(j-1))<<" ";
    }
    cout<<endl;
}
 
// begin signature
// +----------------------------------------+
// |覇覇覇慶陽耗和労労汎山火火火火山汎李奏慶|
// |覇覇群李汎山火ビビシ一・　・ㇸヘ丁山労奏|
// |群李允ビヘㇵミㇸ　ㇸ一ㇵㇵミヘ・一丁允和|
// |汎ビㇵ一ビ一ㇸシ丁シヘヘミビシミㇸㇵ火洪|
// |ビㇸㇵ火一・丁一　一ㇵㇵㇸ・シビビㇸヘせ|
// |シ・シビ・一丁允労李李允丁・ㇵ一丁ミㇵㇵ|
// |ミ・ヘ火一洪陽義群奏奏奏奏耗允シ一シ火シ|
// |一・　・労和和和ビ洪労李耗李允丁　ㇵビ山|
// |シビビ洪允せ・丁丁丁ビ火山せビビビシㇵ山|
// |洪允火ミヘㇸ　ヘせ洪労李労汎せシ　・ㇵ山|
// |丁ㇵ　・シㇵ山耗群慶耗耗群奏和允ミシシ丁|
// |・・シㇵ一シ汎奏群和李労洪洪労火火・ビヘ|
// |・丁一ㇸシ一せ李労允火丁ミミビ火シ一シせ|
// |ヘミㇵシ一ヘㇸビ山ミ一　ㇸㇸ・・ㇸ一・・|
// |允ミ一ㇵシ　丁・ヘ一ㇸミビせせビシヘ一ㇸ|
// |允シ・ㇸミミ　ミヘ・ミ山労李労せ丁ミㇵ　|
// |せ　・シ・ミヘ・ミ丁允和陽李せ火火ヘ　ミ|
// |ヘ・ヘ火ミ一ミ・丁汎奏義李火ミㇵ　ヘ火允|
// |　ㇵ山洪山火ㇸミ洪群義李火・ㇵミ火汎和洪|
// |・丁洪奏汎シ一せ耗覇奏允ヘㇵ山洪和群陽労|
// +----------------------------------------+
// 2026 (July 2nd) 20:36:40
// end signature


