#include "bike.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// BEGIN DEBUG
#define __t template
#define __T typename
#define _U(a,b) using _ ## a = b;
_U(OS,ostream)_U(S,string)_U(F,false_type)_U(T,true_type);
__t<class A,class B>_OS& operator<<(_OS& o,const pair<A,B>& p){return o<<'('<<p.first<<","<<p.second<<')';}__t<int I,class...Ts>__T enable_if<I==sizeof...(Ts),void>::type _pt(_OS&,const tuple<Ts...>&){}__t<int I,class...Ts>__T enable_if<I<sizeof...(Ts),void>::type _pt(_OS& o,const tuple<Ts...>& t){if(I) o<<",";o<<get<I>(t);_pt<I+1>(o,t);}__t<class...Ts>_OS& operator<<(_OS& o,const tuple<Ts...>& t){o<<'(';_pt<0>(o,t);return o<<')';}__t<class T>struct _is:_F{};
#define _T_(d,c) __t<d>struct _is<c>:_T{};
_T_(,_S);_T_(,char*);_T_(,const char*);_T_(size_t N,char[N]);_T_(size_t N,const char[N]);
#undef _T_
__t<class T>struct is_iterable{__t<class U>static auto test(int) ->decltype( begin(declval<const U&>()),end(declval<const U&>()),_T{});__t<class>static _F test(...);static const bool value = decltype(test<T>(0))::value;};__t<class T>__T enable_if< is_iterable<T>::value && !_is<__T decay<T>::type>::value,_OS& >::type operator<<(_OS& o,const T& v){o<<'[';bool f=0;for(const auto& x:v) o<<(f?",":""),f=1,o<<x;return o<<']';}namespace dbg{inline void _fs(_OS &os,const _S &fmt){os << fmt;}__t <__T T,__T... Rest>void _fs(_OS &os,const _S &fmt,const T &value,const Rest &...rest){size_t pos = fmt.find("{}");if (pos == _S::npos){throw runtime_error("too many arguments for format _S");}os << fmt.substr(0,pos);os << value;_fs(os,fmt.substr(pos + 2),rest...);}__t <__T... Args>void print(_OS &os,const _S &fmt,const Args &...args){
#ifdef DEBUG
_fs(os,fmt,args...);
#endif // DEBUG
}__t <__T... Args>void println(_OS &os,const _S &fmt,const Args &...args){print(os,fmt,args...);os << '\n';}__t <__T... Args>void print(const _S &fmt,const Args &...args){print(cerr,fmt,args...);}__t <__T... Args>void println(const _S &fmt,const Args &...args){println(cerr,fmt,args...);}}
#define dprint(...) dbg::println(__VA_ARGS__)
#define dcheck(v) dbg::println("{} = {}", #v, v)
// END DEBUG
pair<vector<int>, vector<long long>>
find_rebalancing_strategy(int N, vector<int> A, vector<int> B, vector<int> U, vector<int> V) {
    using ll=long long;
    vector<vector<int>>g(N+1);for(int i=0;i<N-1;i++){
        g[U[i]+1].push_back(V[i]+1);
        g[V[i]+1].push_back(U[i]+1);
    }
    vector<ll>surp(N+1),surp2(N+1);for(int i=0;i<N;i++)surp2[i+1]=A[i]-B[i];
    const ll INF=1ull<<60;
    using pii=pair<ll,int>;
    vector<array<pii,2>>dp(N+1,{pii{INF,-1},pii{INF,-1}});
    vector<int>sum(N+1,0),zero(N+1,0);
    auto dfs=[&](int u,int p){
        stack<pii>s;s.push({u,p});
        while(!s.empty()){
            auto [u,p]=s.top();s.pop();
            if(u>0){
                zero[u]=surp[u]==0;
                sum[u]=surp[u];
                s.push({-u,p});
                for(auto v:g[u])if(v!=p)s.push({v,u});
            } else {
                u*=-1;
                for(auto v:g[u])if(v!=p)sum[u]+=sum[v],zero[u]&=zero[v];
            }
        }
    };
    auto solve=[&](int u,int p){
        stack<pii>s;s.push({u,p});
        while(!s.empty()){
            auto [u,p]=s.top();s.pop();
            if(u>0){
                if(zero[u]){
                    dp[u][0]={INF,-1},dp[u][1]={0,-1};
                } else {
                    s.push({-u,p});
                    for(auto v:g[u])if(v!=p)s.push({v,u});
                }
            } else {
                u*=-1;
                int s=1;
                for(auto v:g[u])if(v!=p)s+=dp[v][1].first;
                if(sum[u]<=0){ 
                    dp[u][0]={s,u};
                    for(auto v:g[u])if(v!=p)dp[u][0]=min(dp[u][0],{s-dp[v][1].first+dp[v][0].first,v});
                }
                dp[u][1]={s+1,-1};
            }
        }
    };
    auto lpath=[&](int u,int p,vector<signed>&path){
        stack<pii>s;s.push({u,p});
        while(!s.empty()){
            auto [u,p]=s.top();s.pop();
            if(u>0){
                path.push_back(u);
                for(auto v:g[u]){
                    if(v==p||zero[v])continue;
                    s.push({-u,p});
                    s.push({v,u});    
                }
            } else {
                path.push_back(-u);
            }
        }
    };
    auto recons=[&](int s)->pair<vector<signed>,vector<ll>>{
        int u=s,p=-1;vector<signed>path;
        while(true){
            path.push_back(u);
            // dprint("at {} {}",u,dp[u]);
            sort(g[u].begin(),g[u].end(),[&](int a,int b){return sum[a]>sum[b];});
            for(auto v:g[u]){
                if(v==p||zero[v])continue;
                if(v==dp[u][0].second)continue;
                lpath(v,u,path);
                path.push_back(u);
            }
            if(u==dp[u][0].second)break;
            if(dp[u][0].second==-1)return {{},{}};
            p=u;
            u=dp[u][0].second;
        }
        ll sur=0;
        vector<ll>P;
        for(auto p:path){
            if(surp[p]>0){
                sur+=surp[p];P.push_back(-surp[p]);surp[p]=0;
            }else{
                ll r=min(sur,-surp[p]);
                surp[p]+=r;
                sur-=r;
                P.push_back(r);
            }
        }
        for(auto&p:path)p--;
        return make_pair(path,P);
    };
    pair<vector<signed>,vector<ll>> ans={};
    for(int i=1;i<=N;i++){
        // dprint("at {}",i);
        if(surp2[i]<=0)continue;
        fill(dp.begin(),dp.end(),array<pii,2>{pii{INF,-1},pii{INF,-1}});
        surp=surp2;
        dfs(i,-1);
        // dprint("pos dfs {}",i);
        solve(i,-1);
        // dprint("pos solve {}",i);
        auto p=recons(i);
        // dprint("pos recons {}",i);
        if(p.first.empty())assert(false);
        if(ans.first.empty()||p.first.size()<ans.first.size())ans=p;
    }
    // for(int i=1;i<=N;i++)dprint("{} - {} {}",i,dp[i][0],dp[i][1]);
    return ans;
}
