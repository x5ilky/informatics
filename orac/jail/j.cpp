#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N;cin>>N;
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int t=1;
    vector<int>sz(N+1,1),heavy(N+1,-1),tin(N+1,1),head(N+1,-1),depth(N+1,0);
    vector<vector<int>>par(N+1,vector<int>(19));
    function<void(int,int)>dfsh=[&](int u,int p){
        int mx=0;
        for(auto v:g[u]){
            if(v==p)continue;
            par[v][0]=u;
            depth[v]=depth[u]+1;
            dfsh(v,u);
            sz[u]+=sz[v];
            if(sz[v]>mx)mx=sz[v],heavy[u]=v;
        }
    };
    function<void(int,int,int)>decomp=[&](int u,int p,int h){
        head[u]=h,tin[u]=t;t++;
        if(heavy[u]!=-1)decomp(heavy[u],u,h);
        for(auto v:g[u]){
            if(v==p||v==heavy[u])continue;
            decomp(v,u,v);
        }
    };
    dfsh(1,-1);
    decomp(1,-1,1);
    for(int k=1;k<19;k++)
        for(int i=1;i<=N;i++)
            par[i][k]=par[par[i][k-1]][k-1];
    int M;cin>>M;
    vector<vector<int>>g2(2*N+M+1);
    using pii=pair<int,int>;
    struct graphtrick{
        vector<int>T;
        int l,r;bool typ;
        graphtrick(int _l,int _r,bool _t):T((_r-_l+1)*4),l(_l),r(_r),typ(_t){}
        int build(vector<vector<int>>&g2,vector<int>&leaf,int v,int l,int r){
            if(l==r)return T[v]=leaf[l];
            int u=g2.size();
            g2.push_back({});
            T[v]=u;
            int m=(l+r)/2;
            int L=build(g2,leaf,v*2,l,m),R=build(g2,leaf,v*2+1,m+1,r);
            if(!typ){
                g2[u].push_back(L);
                g2[u].push_back(R);
            }else{
                g2[L].push_back(u);
                g2[R].push_back(u);
            }
            return u;
        }
        void attach(vector<vector<int>>&g2,int v,int tl,int tr,int ql,int qr,int u){
            if(ql<=tl&&tr<=qr){
                if(!typ)g2[u].push_back(T[v]);
                else g2[T[v]].push_back(u);
                return;
            }
            int tm=(tl+tr)/2;
            if(ql<=tm)attach(g2,v*2,tl,tm,ql,qr,u);
            if(qr>tm)attach(g2,v*2+1,tm+1,tr,ql,qr,u);
        };
    };
    vector<int>rev(N+1),sf(N+1),sb(N+1);;
    vector<graphtrick>stf(N+1,graphtrick(1,1,0)),stb(N+1,graphtrick(1,1,0));
    for(int i=1;i<=N;i++)rev[tin[i]]=i;
    for(int i=1;i<=N;i++){
        sf[i]=N+rev[i];
        sb[i]=rev[i];
    }
    for(int i=1;i<=N;i++){
        int s=i;
        int h=head[rev[s]];
        while(i+1<=N&&head[rev[i+1]]==h)i++;
        stf[h]=graphtrick(s,i,0);
        stf[h].build(g2,sf,1,s,i);
        stb[h]=graphtrick(s,i,1);
        stb[h].build(g2,sb,1,s,i);
    }
    auto lca=[&](int u,int v){
        if(depth[u]>depth[v])swap(u,v);
        int d=depth[v]-depth[u];
        for(int k=18;k>=0;k--)if((1<<k)&d)v=par[v][k];
        if(u==v)return u;
        for(int k=18;k>=0;k--){
            if(par[u][k]!=par[v][k])u=par[u][k],v=par[v][k];
        }
        return par[u][0];
    };
    vector<pii>edges(M+1);
    for(int i=1;i<=M;i++)cin>>edges[i].first>>edges[i].second;
    auto skip=[&](int u,int v){
        int a=lca(u,v);
        if(a!=u)
            return par[u][0];
        int d=depth[v]-depth[u]-1;
        for(int k=18;k>=0;k--)if(d&(1<<k))v=par[v][k];
        return v;
    };
    for(int i=1;i<=M;i++){
        auto[u,v]=edges[i];
        g2[i+2*N].push_back(u);
        g2[N+v].push_back(i+2*N);
        auto doit=[&](int u,int v,vector<graphtrick>&st,int id){
            while(head[u]!=head[v]){
                if(depth[head[u]]<depth[head[v]])swap(u,v);
                int h=head[u];
                st[h].attach(g2,1,st[h].l,st[h].r,tin[h],tin[u],id);
                u=par[h][0];
            }
            if(depth[u]>depth[v])swap(u,v);
            int h=head[u];
            st[h].attach(g2,1,st[h].l,st[h].r,tin[u],tin[v],id);
        };
        doit(skip(u,v),v,stb,i+2*N);
        doit(u,skip(v,u),stf,i+2*N);
    }
    int N2=g2.size();
    vector<int>deg(N2);deque<int>st;
    vector<vector<int>>revg(N2);
    for(int i=0;i<g2.size();i++){
        if((deg[i]=g2[i].size())==0)st.push_back(i);
        for(auto v:g2[i])revg[v].push_back(i);
    }
    int c=0;
    while(st.size()){
        c++;
        auto v=st.front();st.pop_front();
        for(auto u:revg[v])if(--deg[u]==0)st.push_back(u);
    }
    cout<<(c==N2?"Yes":"No")<<endl;
}
int main() {
    int T;cin>>T;
    while(T--)solve();
}

// begin signature
// +----------------------------------------+
// |李洪允せ火火火せ火丁ミミミ丁火ビミヘ一ㇸ|
// |せ丁シㇵ一一ㇵヘㇸ　　　　ㇸㇵㇸ・一ヘシ|
// |一　ㇸㇵㇵㇵㇸ一ヘシシシㇵㇸㇵミビせ山山|
// |ヘ丁火せ丁ヘㇸ　・　　　・ㇵシビ山労和李|
// |せ汎火ヘ・・　一一一ヘミミミヘㇵ丁山允労|
// |火ビミ・ㇸㇸㇵ　ㇵ丁ミシヘヘミ丁シヘミビ|
// |ヘㇵㇸ　　ㇵ　ㇸㇵㇸ　・ㇸㇸ・　ㇸシㇸ・|
// |せせビシ　一ㇸ　・ㇵミ丁ビビビ丁シ一・　|
// |労李洪火ㇵ一ビシ・ㇸヘビ允洪洪汎山ビヘヘ|
// |陽群労火一一ㇸㇸ火允山山允汎洪李労山せせ|
// |陽和山シ一ㇵミ丁ミシシシミビせ汎允せ火ビ|
// |労允せ丁ヘシ一　・ㇸㇸ　・ㇵミ火山火シヘ|
// |耗和労汎ㇵ　ㇵㇸ　・ㇸ・　一　ヘシヘヘㇵ|
// |慶義陽奏　ヘ・一一　　・　ㇸㇸ・　ㇸㇸㇸ|
// |覇覇慶奏・ㇵㇸㇵ・ヘミ丁丁シ一ヘシ丁丁ビ|
// |覇覇慶耗ㇵ・ヘ　ヘビ山汎汎允せビシ一ㇸ一|
// |覇覇陽　ㇵ一ㇸㇵ火汎李耗和汎ビㇵ　ㇵヘヘ|
// |覇義和ヘㇸ・ㇵ火労奏義耗汎丁ㇸㇵ丁せ山火|
// |慶耗シ・・ミ火労群慶耗汎丁・シせ労和労山|
// |陽ㇸㇸ・シ丁允耗慶陽李せㇵ一火労群群労允|
// +----------------------------------------+
// 2026 (September 11th) 19:39:48
// end signature
