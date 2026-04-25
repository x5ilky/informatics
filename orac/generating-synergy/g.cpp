#include <bits/stdc++.h>
using namespace std;
using pii=array<int,3>;
struct segtree{
    vector<pii>T;
    segtree(int N):T(N*4,{-1,-1,1}){}
    void update(int v,int tl,int tr,int ql,int qr,pii chmax){
        if(ql<=tl&&tr<=qr){
            T[v]=max(T[v],chmax);
            return;
        }
        int tm=(tl+tr)/2;
        T[v*2]=max(T[v*2],T[v]);
        T[v*2+1]=max(T[v*2+1],T[v]);
        if(ql<=tm)update(v*2,tl,tm,ql,qr,chmax);
        if(qr >tm)update(v*2+1,tm+1,tr,ql,qr,chmax);
    }
    pii query(int v,int tl,int tr,int pos){
        if(tl==tr)return T[v];
        int tm=(tl+tr)/2;
        return max(T[v],pos<=tm?query(v*2,tl,tm,pos):query(v*2+1,tm+1,tr,pos));
    }
};
int main() {
    int N,C,Q;cin>>N>>C>>Q;
    vector<vector<int>>g(N+1);
    for(int i=2;i<=N;i++){
        int u;cin>>u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    int time=1;
    vector<int>in(N+1),out(N+1),depth(N+1);
    function<void(int,int)>dfs=[&](int u,int p){
        in[u]=time++;
        for(auto v:g[u]){
            if(v==p)continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
        out[u]=time;
    };
    depth[1]=0;dfs(1,-1);
    segtree st(time+1);
    int ans=0;
    for(int q=1;q<=Q;q++){
        // printf("qurie %d\n",q);
        int u,d,c;cin>>u>>d>>c;
        if(c==0){
            auto [d,_,c]=st.query(1,1,time,u);
            if(d==-1||d>=depth[u])ans+=q*c;
            ans%=(int)1e9+7;
            // cout<<d<<" "<<depth[u]<<endl;
        }else{
            st.update(1,1,time,in[u],out[u],{depth[u]+d,q,c});
        }
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火せ山汎洪李奏陽義慶覇|
// |和労允せビミシヘヘシミ丁火允洪和耗奏群群|
// |汎せ丁ヘ一ㇸヘミ丁ビ丁丁丁せ允汎洪李李李|
// |ビシㇸㇸヘ丁火山山せ火ビビビ火せ山允允允|
// |ヘ・ㇸ一ㇵヘミ丁丁シヘㇵㇵㇵヘシ丁丁丁丁|
// |　・ㇸㇸㇸ　・一一ㇸ　・ㇸㇸ・　ㇸㇵ一一|
// |ㇵシミミ丁ミヘ一ㇸㇸ・　　・　　ㇸㇸㇸ一|
// |ㇵ一ㇸㇸㇸ一ヘㇸ　・　　　ㇸ・・一一ㇵヘ|
// |・・一ㇵ一ㇸ　　　　・・・　・ㇸ一一ㇸ　|
// |　・ミビ丁ミヘㇸ・ㇵ　ㇸㇸ一ㇵヘヘ丁ミヘ|
// |　ヘ火允ビㇵ　ㇵ・・一一一ㇸ　・一シビ丁|
// |・シせ丁ㇵ　ヘㇵシミ丁丁丁ミヘ一　一シ火|
// |　ヘビヘ・一シ丁火山允允山せ火丁ヘ・ㇸシ|
// |・・シ一　ヘ丁せ汎洪労李李労汎山火ミ一・|
// |ミㇸ　一・シ火允労和奏奏李汎山ビミシヘヘ|
// |せミ一　ㇸミせ汎和奏陽耗労允ビシ一・　　|
// |汎火シ　ヘビ允李奏義群和汎火シㇸㇸㇵシヘ|
// |山ミㇸㇵビ允李奏慶陽和汎火シ　ㇵ丁火火ビ|
// |丁一ㇸ丁山労奏慶義耗洪火シ　ヘビ丁丁山火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ一ヘビ山汎火|
// +----------------------------------------+
// 2026 (April 25th) 12:41:35
// end signature

