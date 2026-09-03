#include <bits/stdc++.h>
using namespace std;

std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> _W) {
#define int long long
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    for(int i=0;i<N-1;i++)g[U[i]+1].push_back({V[i]+1,_W[i]}),g[V[i]+1].push_back({U[i]+1,_W[i]});
    for(int i=1;i<=N;i++)sort(g[i].begin(),g[i].end(),[&](pii a,pii b){return g[a.first].size()>g[b.first].size();});
    struct twm {
        multiset<int>lo,hi;
        int sm=0,k=0;
        void fix(){
            while((int)lo.size()>k){
                auto it=prev(lo.end());
                int x=*it;lo.erase(it);
                sm-=x;hi.insert(x);
            }
            while((int)lo.size()<k&&hi.size()){
                auto it=hi.begin();
                int x=*it;hi.erase(it);
                lo.insert(x);sm+=x;
            }
        }
        void add(int v){
            if(v>=0)return;
            if(!lo.empty()&&v<*lo.rbegin()){
                auto it=prev(lo.end());
                int x=*it;
                lo.erase(it);sm-=x;
                hi.insert(x);
                lo.insert(v);sm+=v;
            }else hi.insert(v);
            fix();
        }
        void remove(int v){
            if(v>=0)return;
            auto it=lo.find(v);
            if(it!=lo.end()){
                sm-=v;lo.erase(it);
            }else{
                it=hi.find(v);
                if(it!=hi.end())hi.erase(it);
            }
            fix();
        }
    };
    vector<int>bs(N+1),dif(N+1),ord(N),par(N+1,-1);
    function<void(int,int)>dfs=[&](int u,int p){
        for(auto [v,w]:g[u]){
            if(v==p)continue;
            par[v]=u;
            dfs(v,u);
        }
    };
    dfs(1,-1);
    vector<twm>difs(N+1);
    array<vector<int>,2>dp{vector<int>(N+1),vector<int>(N+1)};
    iota(ord.begin(),ord.end(),1);
    sort(ord.begin(),ord.end(),[&](int a,int b){return g[a].size()>g[b].size();});
    map<int,vector<int>>bydeg;
    for(int i=1;i<=N;i++)bydeg[g[i].size()].push_back(i);
    vector<int>seen(N+1),ans(N);
    ans[0]=accumulate(_W.begin(),_W.end(),0LL);
    for(int k=1;k<=N-1;k++){
        for(int u:bydeg[k]){
            for(auto [v,w]:g[u]){
                if(par[u]==v&&k>1&&g[v].size()>k)
                    difs[v].remove(-w-dif[u]);
                bs[v]+=w;
                difs[v].add(-w);
            }
        }
        function<void(int)>dfs=[&](int u){
            seen[u]=k;
            difs[u].k=k;difs[u].fix();
            int base=bs[u];
            for(auto [v,w]:g[u]){
                if(g[v].size()<=k)break;
                if(par[v]!=u)continue;
                if(k>1)difs[u].remove(-w-dif[v]);
                dfs(v);
                base+=w+dp[0][v];
                difs[u].add(-w-dif[v]);
            }
            dp[0][u]=base+difs[u].sm;
            dp[1][u]=base+difs[u].sm-(difs[u].lo.size()>=k?*difs[u].lo.rbegin():0);
            dif[u]=dp[0][u]-dp[1][u];
        };
        int cur=0;
        for(int u:ord){
            if(g[u].size()<=k)break;
            if(par[u]!=-1&&g[par[u]].size()>k)continue;
            dfs(u);
            cur+=dp[0][u];
        }
        ans[k]=cur;
    }
    return ans;
}

// begin signature
// +----------------------------------------+
// |和労汎山せ火ビ丁丁ミミミミ丁ビ火山允洪李|
// |汎山火ビミシヘㇵㇵ一一一一ㇵシ丁ビせ汎洪|
// |せ丁シㇵㇸㇸㇸ　・・・・　・一シ丁火山山|
// |ミㇵ・・・　一ㇵヘシシヘ一・・ㇵシ丁ビビ|
// |ㇵ・・・ㇸㇵミミシヘシミミヘㇸ　ㇵヘヘシ|
// |一　ㇸ　ㇵシシㇵㇸ・・ㇸㇵシシ一　　　・|
// |一　　　ㇵミヘㇸㇵㇵヘㇵㇵ一ㇵミㇵㇵㇵ一|
// |　・ㇵ　ㇵミㇵヘㇵ一・　　　　一シヘミミ|
// |ㇵㇵ一ㇸヘシヘㇸ・　ㇸㇵㇵㇵ一　ヘシ一シ|
// |丁丁ミシミ一　　ㇸ一ㇵヘシシ一・ヘㇵシヘ|
// |せビシシㇵ　・・・　　・ㇸㇸ　ㇵシㇸ一ヘ|
// |丁ヘ一ミ一ヘヘシヘヘ一ㇸㇸㇸㇸシㇵ　　一|
// |ㇵ一一シミ丁ビビビ丁ミヘシシシシㇵㇸ　　|
// |　一シ丁火せ山允允山せビビ火火ビ丁シㇵㇸ|
// |　一ミビせ允洪労労労洪允山山ビ丁シヘヘヘ|
// |　ㇵ丁せ允洪李和耗耗和労允火丁ヘ一・　　|
// |一シ火允洪和奏群陽奏李汎せ丁ヘㇸ　一ㇵ一|
// |シビ允洪和群義義奏李汎せ丁ヘ　ㇸヘミ丁シ|
// |ビ山洪和群慶慶群和洪山丁ヘ　一ミ火せ火丁|
// |せ汎李奏義覇陽奏労允火シㇸㇸシ火允汎せ丁|
// +----------------------------------------+
// 2026 (September 3rd) 21:18:42
// end signature

#include <cassert>
#include <cstdio>

#include <vector>

#undef int 
int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
    U[i]--,V[i]--;
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}
