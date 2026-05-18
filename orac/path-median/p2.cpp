#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int>L,sz;
    DSU(int N):L(N+1),sz(N+1,1){
        iota(L.begin(),L.end(),0);
    }
    int head(int u){
        return L[u]==u?u:L[u]=head(L[u]);
    }
    void join(int a,int b){
        a=head(a);b=head(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        sz[a]+=sz[b];L[b]=a;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,M,K;cin>>N>>M>>K;
    using pii=pair<int,int>;
    using ai3=array<int,3>;
    vector<vector<pii>>g(N+1);vector<ai3>edges(M+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edges[i]={u,v,w};
    }
    {
        // odd case
        // possible iff there exists an edge with weight K in component of 1 and N
        DSU odd(2*N+1);
        for(int i=1;i<=M;i++){
            auto [u,v,w]=edges[i];
            odd.join(u,v+N);
            odd.join(u+N,v);
        }
        auto path=[&](int s,int t,int want,DSU&dsu,vector<int>&p){
            vector<int>back(2*N+1,-1);
            queue<int>q;q.push(s);back[s]=s;

            while(!q.empty()){
                auto u=q.front();q.pop();
                for(auto [v,_]:g[u>N?u-N:u]){
                    int flipped=(u>N?v:v+N);
                    if(dsu.head(flipped)!=dsu.head(s))continue;
                    if(back[flipped]==-1){
                        back[flipped]=u;
                        q.push(flipped);
                    }
                }
            }
            int i=t+want*N;
            if(back[i]==-1)return false;
            vector<int>l;
            while(i!=s){
                l.push_back(i>N?i-N:i);
                i=back[i];
            }
            l.push_back(s);
            for(int i=(int)l.size()-1;i>=0;i--)p.push_back(l[i]);
            return true;
        };
        auto construct=[&](int i){
            vector<int>p;
            auto [u,v,w]=edges[i];
            if(!path(1,u,1,odd,p))return;
            for(int j=1;j<=2*N;j++){
                p.push_back(v);
                p.push_back(u);
            }
            p.push_back(v);
            if(!path(u,N,1,odd,p))return;
            assert(p.size()%2==1);
            cout<<p.size()<<endl;
            for(auto v:p)cout<<v<<" ";
        };
        if(odd.head(1)==odd.head(N+N)){
            for(int i=1;i<=M;i++){
                auto [u,v,w]=edges[i];
                if(w!=K)continue;
                if(odd.head(u)==odd.head(1)){
                    cout<<"YES\n";
                    construct(i);
                    return 0;
                }
            }
        }
    }
    {
        // even case
        // for a given P, there must exist K-P and K+P as edge weights
        // if so, you can use these edges to make an average of K
        // however, you cannot have any numbers in between, or else it is not the average
        // therefore, you add the edges in order of decreasing P
        sort(edges.begin()+1,edges.end(),[&](ai3 a,ai3 b){
            return abs(a[2]-K)>abs(b[2]-K);
        });
        DSU even(2*N+1);
        int i=1;
        set<int,greater<int>>pq;
        for(int i=1;i<=M;i++){
            auto [u,v,w]=edges[i];
            pq.insert(abs(w-K));
        }
        while(!pq.empty()){
            auto P=*pq.begin();pq.erase(pq.begin());
            // printf("P = %d,i = %d\n",P,i);
            vector<int>si,bi;
            while(i<=M&&abs(edges[i][2]-K)>=P){
                auto [u,v,w]=edges[i];
                even.join(u,v+N);
                even.join(u+N,v);
                if(edges[i][2]-K==-P)si.push_back(i);
                if(edges[i][2]-K==P)bi.push_back(i);
                i++;
            }
            bool small=false,big=false;
            if(even.head(1)==even.head(N)){
                for(auto i:si){
                    auto [u,v,w]=edges[i];
                    // printf("si = %d, %d %d %d\n",i,u,v,w);
                    if(even.head(u)==even.head(1)||even.head(v)==even.head(1)){
                        small=true;
                        break;
                    }
                }
                for(auto i:bi){
                    auto [u,v,w]=edges[i];
                    // printf("bi = %d, %d %d %d\n",i,u,v,w);
                    if(even.head(u)==even.head(1)||even.head(v)==even.head(1)){
                        big=true;
                        break;
                    }
                }
                // printf("small = %d, big = %d\n",small,big);
                if(small&&big){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
}

// begin signature
// +----------------------------------------+
// |和労汎山せ火ビ丁丁丁ビ火せせ山允汎労李耗|
// |洪山火ビミシヘㇵㇵㇵヘミミ丁ビ火山汎洪李|
// |せ丁シㇵㇸㇸㇵㇵ一一一一ㇵヘミ丁火山汎洪|
// |ミㇵ・・ㇵ一・ㇵシシヘ一　ㇸㇵシ丁火せ山|
// |ㇵ・・ㇵヘビ山允汎汎允せ丁ヘ　ㇵヘミ丁ビ|
// |一　一シせ洪李労労洪洪洪允火ミㇵ　一ㇵヘ|
// |一　ㇸ火洪李洪汎允山山山せ火丁ミヘㇸ・　|
// |一　シ允李洪允山せ山允允せ丁丁丁ミヘㇸㇵ|
// |ㇸ一山李洪允允洪李労労労洪允火せ火ビシㇸ|
// |一山李洪允労労洪汎允允允山火ビミシヘヘ一|
// |山李汎労洪汎山せ火ビビ火丁シシミヘ一　ㇸ|
// |労汎李汎山せせビ丁ミミミミビ火ビビシ・一|
// |李李洪允汎汎汎允せ火せせ火ビミミミヘヘㇸ|
// |李李洪洪労李李労汎山允汎汎山せビ丁丁丁シ|
// |耗奏耗李和奏奏奏和洪洪労汎せビミヘㇵㇵㇵ|
// |陽義陽奏和群義義奏和労洪允火ミㇵㇸ　　　|
// |慶覇慶陽耗陽慶慶群和李汎せ丁ㇵ・・ㇵㇵㇵ|
// |覇覇覇陽耗群陽群耗労汎せ丁ㇵ　一シミ丁ミ|
// |覇覇陽奏和耗耗李洪洪山丁ㇵ　ㇵミ火せ火丁|
// |慶陽奏和労労労汎山允火シㇸㇸシ火允汎せ丁|
// +----------------------------------------+
// 2026 (May 18th) 21:44:46
// end signature


