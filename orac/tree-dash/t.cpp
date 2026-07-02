#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
#define int long long
using pii=pair<int,int>;
const int INF=1e9;
signed main() {
    int N,R;cin>>N>>R;
    vector<int>tin(N+1),tout(N+1),depth(N+1),up(N+1,-1),post(N+1);
    vector<vector<int>>down(N+1);
    if("movement graph"){
        vector<vector<int>>g(N+1);
        for(int i=1;i<=N;i++){
            int p;cin>>p;
            if(i!=R)g[p].push_back(i);
        }
        int t=0;
        vector<int>mnAnc(N+1),mxAnc(N+1),mnDesc(N+1),mxDesc(N+1);
        function<pii(int,int,int,int)>dfs=[&](int u,int p,int mxanc,int mnanc){
            int mndesc=INF,mxdesc=-INF;
            tin[u]=++t;
            for(auto v:g[u]){
                if(v==p)continue;
                depth[v]=depth[u]+1;
                auto [mn,mx]=dfs(v,u,max(mxanc,u),min(mnanc,u));
                mndesc=min(mndesc,mn);
                mxdesc=max(mxdesc,mx);
            }
            tout[u]=t;
            mnAnc[u]=mnanc;
            mxAnc[u]=mxanc;
            mnDesc[u]=mndesc;
            mxDesc[u]=mxdesc;
            return pii{min(mndesc,u),max(mxdesc,u)};
        };
        depth[R]=0;dfs(R,-1,-INF,INF);
        for(int i=1;i<=N;i++){
            if(mnAnc[i]!=INF){
                up[i]=depth[mnAnc[i]]>depth[mxAnc[i]]?mnAnc[i]:mxAnc[i];
            }
            if(mnDesc[i]!=INF){
                if(mnDesc[i]==mxDesc[i]){
                    down[i].push_back(mnDesc[i]);
                } else {
                    if(tin[mxDesc[i]]<=tin[mnDesc[i]]&&tin[mnDesc[i]]<=tout[mxDesc[i]]){
                        down[i].push_back(mxDesc[i]);
                    } else if(tin[mnDesc[i]]<=tin[mxDesc[i]]&&tin[mxDesc[i]]<=tout[mnDesc[i]]){
                        down[i].push_back(mnDesc[i]);
                    } else {
                        down[i].push_back(mnDesc[i]);
                        down[i].push_back(mxDesc[i]);
                    }
                }
            }
        }
        t=0;
        deque<int>bfs;bfs.push_back(R);
        while(bfs.size()){
            auto u=bfs.front();bfs.pop_front();
            post[u]=t++;
            for(auto v:g[u])bfs.push_back(v);
        }
    }
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    atcoder::scc_graph scc(N);    
    for(int i=1;i<=N;i++){
        if(up[i]!=-1)scc.add_edge(i-1,up[i]-1);
        for(auto v:down[i])scc.add_edge(i-1,v-1);
    }
    auto components=scc.scc();int M=components.size();
    for(auto&v:components)for(auto&u:v)u++;
    vector<int>comp(N+1),comptop(M,INF),compsum(M),compsz(N+1);
    for(int i=0;i<M;i++){
        for(auto&u:components[i]){
            comptop[i]=min(comptop[i],depth[u]);
            compsum[i]+=A[u];
            compsz[i]++;
            comp[u]=i;
        }
    }
    vector<int>sccPar(M,-1);
    vector<vector<int>>out(N+1),g2(N+1);
    for(int u=1;u<=N;u++){
        vector<int>g=down[u];
        if(compsz[comp[u]]==1)continue;
        if(up[u]!=-1)g.push_back(up[u]);
        for(auto v:g){
            int cu=comp[u],cv=comp[v];
            if(cu!=cv){
                if(compsz[cu]>=2&&compsz[cv]>=2){
                    if(sccPar[cu]==-1||comptop[cv]>comptop[sccPar[cu]])
                        sccPar[cu]=cv;
                } else assert(false); // impossible
            }
        }
    }
    for(int u=1;u<=N;u++){
        vector<int>g=down[u];
        if(compsz[comp[u]]!=1)continue;
        for(auto v:g){
            int cu=comp[u],cv=comp[v];
            if(cu!=cv){
                if(compsz[cu]==1&&compsz[cv]>=2)out[u].push_back(cv);
                else g2[u].push_back(v);
            }
        }
    }
    vector<int>sccPathSum(M);
    int ans=0;
    if("calc the path sum along scc tree"){
        vector<vector<int>>g2(M);
        for(int i=0;i<M;i++){
            if(compsz[i]<=1)continue;
            else if(sccPar[i]!=-1) g2[sccPar[i]].push_back(i);
        }
        function<void(int)>dfs=[&](int u){ 
            sccPathSum[u]=(sccPar[u]==-1?0:sccPathSum[sccPar[u]])+compsum[u];
            for(auto v:g2[u])dfs(v);
        };
        dfs(comp[R]);
        for(int i=0;i<M;i++){
            if(compsz[i]<=1)continue;
            ans+=compsum[i]*sccPathSum[i];
            for(auto v:components[i])ans-=A[v]*A[v];
        }
    }
    vector<int>single;
    for(int i=1;i<=N;i++)if(compsz[comp[i]]==1)single.push_back(i);
    sort(single.begin(),single.end(),[&](int a,int b){
        return post[a]>post[b];
    });
    using pbi=pair<bool,int>;
    vector<int>ws(N+1),wr(N+1);
    auto weight=[&](pbi u){
        if(!u.first)return wr[u.second];
        else return sccPathSum[u.second];
    };
    for(auto u:single){
        vector<pbi>edges;
        for(auto v:g2[u]){
            edges.push_back({false,v});
        }
        for(auto v:out[u]){
            edges.push_back({true,v});
        }
        if(edges.size()>=2&&edges[0].first&&edges[1].first&&edges[0].second==edges[1].second){
            edges.pop_back();
        }
        ws[u]=A[u];
        for(auto [s,v]:edges){
            if(!s)ws[u]+=ws[v];
        }
        int base=sccPathSum[comp[up[u]]];
        if(edges.size()==0)wr[u]=base;
        else if(edges.size()==1)wr[u]=weight(edges[0]);
        else wr[u]=weight(edges[0])+weight(edges[1])-base;
        ans+=A[u]*(wr[u]+ws[u]-A[u]);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |洪允山せビ丁　ㇸ一ㇵㇵㇵ一一・シ一・　　|
// |火丁ミヘ　・・ㇸ一ㇸ一ㇸㇸㇸㇸ・一ㇵヘシ|
// |ㇵㇸ　　・ㇸヘシミシシヘヘㇵㇵミビ火せせ|
// |ㇸ・ㇸ一ヘㇵ一ㇵヘㇵ一一ㇵシミビビ火せ允|
// |・・一・・ㇸヘㇸ　ㇸㇸㇸ・・ㇵミヘヘミビ|
// |ㇸㇸ・一　ㇵㇸ・一ㇸ　　　　　ㇸシミㇸ一|
// |ミ丁ミシ　ㇵ・ㇸ一一一一ㇸ・ㇵㇸ　ㇵ丁ㇵ|
// |火山山火・ㇵㇵㇵ一ミミヘ丁ビビ丁シ　ㇵ丁|
// |允洪允　一ヘシ・シビ火ビビ火火せ丁一ㇸ丁|
// |洪山ㇸㇵㇵ・ㇵビ丁シヘヘㇵヘシミミㇸㇵ丁|
// |火シヘ　一ㇸヘㇵㇸ　　・・　・一ㇵㇸミヘ|
// |シ一一ㇸ・一　ㇸㇵシシミシヘ一・　ヘミㇸ|
// |・ヘㇵ・一・ㇵミビ火せせせ火丁シ一シシ　|
// |・・シ一ㇸㇵミ火山汎洪労洪洪允せビシシ・|
// |　ㇸ　ㇵ　ヘビ山洪李和耗和洪允火丁ミミㇵ|
// |・ミ一　・シ火汎李耗群奏李汎火ミヘ丁ㇵㇸ|
// |ㇵ火シ・ㇵビ允労奏陽陽和汎せミシシ一　ㇵ|
// |火ミㇸ一丁山労奏義陽耗洪せシヘ一　一シ丁|
// |丁一ㇸミ山労奏慶義耗洪せシ・ㇸㇵシビ山ビ|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ丁ビせ允汎火|
// +----------------------------------------+
// 2026 (July 2nd) 19:32:27
// end signature
