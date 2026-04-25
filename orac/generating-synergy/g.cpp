#include <bits/stdc++.h>
using namespace std;
struct order {
    int d,t,c;
    bool operator<(const order&o) const {
        return tie(d,t,c)<tie(o.d,o.t,o.c);
    }
    bool operator>(const order&o) const {
        return tie(d,t,c)>tie(o.d,o.t,o.c);
    }
};
const int INF=1e9;
const int MOD=1e9+7;
// struct segtree{
//     vector<vector<order>>T;
//     segtree(int N):T(N*4){}
//     void push(vector<order>&s,order x){
//         while(!s.empty()&&x.d>=s.back().d){
//             s.pop_back();
//         }
//         s.push_back(x);
//     }
//     void update(int v,int tl,int tr,int ql,int qr,order x){
//         if(ql<=tl&&tr<=qr){
//             push(T[v],x);
//             return;
//         }
//         int tm=(tl+tr)/2;
//         if(ql<=tm)update(v*2,tl,tm,ql,qr,x);
//         if(qr >tm)update(v*2+1,tm+1,tr,ql,qr,x);
//     }
//
//     order query(int v,int tl,int tr,int pos,int d){
//         auto it=lower_bound(T[v].rbegin(),T[v].rend(),order{d,-INF,-INF});
//         order val=it==T[v].rend()?order{-1,-1,1}:*it;
//         if(tl==tr)return val;
//         int tm=(tl+tr)/2;
//         auto merge=pos<=tm?query(v*2,tl,tm,pos,d):query(v*2+1,tm+1,tr,pos,d);
//         if(tie(merge.t,merge.d)>tie(val.t,val.d))val=merge;
//         return val;
//     }
// };
//
// CHATGPT wrote this iterative segtree
// MLE is so fake
// orig is above
struct segtree{
    int n;
    vector<vector<order>>T;

    segtree(int N):n(N),T(2*N+2){}

    void push(vector<order>&s,order x){
        while(!s.empty()&&x.d>=s.back().d){
            s.pop_back();
        }
        s.push_back(x);
    }

    void update(int l,int r,order x){
        for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
            if(l&1)push(T[l++],x);
            if(!(r&1))push(T[r--],x);
        }
    }

    order get(vector<order>&s,int d){
        auto it=lower_bound(s.rbegin(),s.rend(),order{d,-INF,-INF});
        return it==s.rend()?order{-1,-1,1}:*it;
    }

    order query(int pos,int d){
        pos+=n-1;
        order val={-1,-1,1};

        while(pos){
            auto cur=get(T[pos],d);
            if(tie(cur.t,cur.d)>tie(val.t,val.d))val=cur;
            pos>>=1;
        }

        return val;
    }
};
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N,C,Q;cin>>N>>C>>Q;
    vector<vector<int>>g(N+1);
    for(int i=2;i<=N;i++){
        int u;cin>>u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    int timer=1;
    vector<int>in(N+1),out(N+1),depth(N+1);
    function<void(int,int)>dfs=[&](int u,int p){
        in[u]=timer++;
        for(int v:g[u]){
            if(v==p)continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
        out[u]=timer-1;
    };
    dfs(1,-1);
    segtree st(N+2);
    int ans=0;
    for(int q=1;q<=Q;q++){
        int u,d,c;
        cin>>u>>d>>c;
        if(c==0){
            set<order>l;
            int col=st.query(in[u],depth[u]).c;
            ans=(ans+(long long)q*col)%MOD;
        }else{
            st.update(in[u],out[u],{depth[u]+d,q,c});
        }
    }
    cout<<ans<<"\n";
}

// begin signature
// +----------------------------------------+
// |覇陽奏李洪汎允山せ山山允山山允汎洪李耗群|
// |群和洪山火丁ミシシミ丁ミミミ丁ビせ允洪和|
// |洪山ビシ一一シミヘ一・　　・一ヘ丁火允労|
// |火シㇸㇸシミㇵ　ㇸㇵㇵヘヘㇵㇸ　ㇵミせ汎|
// |シ・ㇸミミㇸㇸヘシヘㇵㇵヘミ丁ヘ・一ミせ|
// |ㇵ　ㇵㇵㇵ　ヘㇵ・・ㇸㇸ・　ㇵミミ一・シ|
// |・・ㇸ一ㇸ・シ・ㇸ・・　ㇸㇸㇸ・ㇵ丁シ　|
// |ㇵヘㇵㇵㇵヘミヘㇸ　・・・・・　　一丁シ|
// |　ㇸㇸㇸㇸㇵ・・・ㇸㇸㇸㇸ一一ㇸ・　ヘビ|
// |　・丁ㇵㇸ一一ㇸ・　・ㇸ　　ㇸヘミ　シ丁|
// |　ヘシ　ㇵㇸㇸ　ㇵㇵヘヘㇵ一・・ㇵㇸ丁ヘ|
// |・ミ一ㇵ・・ㇵミビ火火火ビ丁シ一　ㇸ丁一|
// |　シ一一ㇸシビ山汎洪洪洪汎允せ丁ㇵ一シㇸ|
// |ㇸ　ヘ　ヘビ山洪李耗奏奏耗李洪允火ミ丁ㇵ|
// |丁一　　ヘ火汎李奏陽慶陽耗洪山ビミヘビヘ|
// |允丁ㇵ　シせ洪耗陽慶群耗李汎火シㇸヘビㇵ|
// |汎ビ一一ビ允和陽覇群和洪山せシㇸヘビヘ　|
// |火ヘ・丁允李陽覇群李允ビシシシ丁シㇸㇸシ|
// |シ　シ山李群覇陽李允丁ミミシㇵㇸ・ヘビ山|
// |ㇵ一ビ汎耗義慶奏洪火ㇵ・　　ㇸヘ丁せ汎せ|
// +----------------------------------------+
// 2026 (April 25th) 15:40:24
// end signature


