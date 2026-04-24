#include <bits/stdc++.h>
using namespace std;
#define int long long
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
#define dprint(...) dbg::print(__VA_ARGS__)
#define dtprint(...) dbg::print("[{}]{}:{}: ",__PRETTY_FUNCTION__,__FILE__,__LINE__),dbg::print(__VA_ARGS__),dbg::print("\n")
// END DEBUG
#include <bits/stdc++.h>
using namespace std;
signed main() {
    int N,K;cin>>N>>K;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    const int INF=1ull<<60;
    vector<int>sz(N+1,0),gone(N+1,false),dstr(N+1,INF);vector<vector<pii>>dstc(N+1);
    function<void(int,int)>fsz=[&](int u,int p){
        sz[u]=1;
        for(auto [v,w]:g[u]){
            if(v==p||gone[v])continue;
            fsz(v,u);
            sz[u]+=sz[v];
        }
    };
    function<int(int,int,int)>fcentr=[&](int u,int s,int p){
        for(auto [v,_]:g[u]){
            if(gone[v]||v==p)continue;
            if(sz[v]*2>s)return fcentr(v,s,u);
        }
        return u;
    };
    function<void(int,int,int,int)>sdst=[&](int u,int p,int c,int d){
        dstc[u].push_back({c,d});
        for(auto [v,w]:g[u]){
            if(gone[v]||v==p)continue;
            sdst(v,u,c,d+w);
        }
    };
    function<void(int)>build=[&](int u){
        fsz(u,-1);
        int cent=fcentr(u,sz[u],-1);
        dprint("build centroid at {}\n",cent);
        sdst(cent,-1,cent,0);
        gone[cent]=true;
        for(auto [v,w]:g[cent]){
            if(gone[v])continue;
            build(v);
        }
    };
    function<void(int)>update=[&](int u){
        dprint("dstc[{}]={}\n",u,dstc[u]);
        for(auto [c,d]:dstc[u]){
            dstr[c]=min(dstr[c],d);
        }
    };
    function<int(int)>query=[&](int u){
        int ans=INF;
        for(auto [c,d]:dstc[u]){
            ans=min(ans,d+dstr[c]);
        }
        return ans;
    };
    build(1);

    vector<int>D(N+1,-1),p(N+1);
    priority_queue<pii>pq;
    function<void(int)>dfs=[&](int u){
        pq.push({D[u],u});
        for(auto [v,w]:g[u]){
            if(D[v]==-1){
                p[v]=u; D[v]=D[u]+w;
                dfs(v);
            }
        }
    };
    p[1]=-1;
    D[1]=0;dfs(1);
    vector<int> ans;
    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        dprint("dist[{}] = {} <= {}\n",u,query(u),K);
        if(query(u)<=K)continue;
        while(u!=1&&D[u]>=d-K){
            if(D[p[u]]>=d-K)u=p[u];
            else break;
        }
        dprint("u = {}\n",u);
        update(u);
        ans.push_back(u);
    }
    cout<<ans.size()<<endl;
    for(auto u:ans)cout<<u<<" ";
    cout<<endl;
}

// begin signature
// +----------------------------------------+
// |せ火せ山汎労李労ㇵミビビミㇸ火火せ山汎李|
// |ㇸㇸ一ヘミヘ山労耗奏群群奏李火一一ヘ丁山|
// |ミミヘミ洪耗群陽群群陽慶覇群洪ビヘ・一丁|
// |洪汎山和群和労洪李李李和耗李汎火ビミ一一|
// |群奏和和洪せ山せ火ビ火せ允洪洪允火ミ・一|
// |覇慶奏労山ビシ一・　　ㇸㇵミせ山汎洪せヘ|
// |覇陽和允丁ㇵ　ㇸ・ㇸ・　　・　一ヘ丁せせ|
// |覇奏洪火ㇵㇸ　一シ丁火火ビミシシヘ一・シ|
// |群李せㇵ一ㇸシ火汎労労洪汎汎允汎允せ丁ㇵ|
// |労火一一ㇵ火洪労允火丁ミシシミビせ丁丁ビ|
// |ビ・　ミ和洪せミ一　ㇸ一一一・ㇸヘビ一ㇵ|
// |一ミ李李山ミㇸ一ミビせ山山火丁ヘ・ㇵヘ・|
// |火労和山シ　シ火汎允火丁ミミビせビㇵㇸ一|
// |山群労火一ㇵ火洪山ミ一　ㇸㇸ・・ヘビ丁・|
// |火群労火一ヘ山洪ビ一ㇸミビせ火ビシ・ㇵ火|
// |せ陽労ビ・ミ允允シ・ミ山洪李労せミ一ㇸㇸ|
// |洪奏允シ一せ洪ビ　ミ允和陽労せㇵ・シミミ|
// |陽洪丁・ビ労ビ・ミ汎奏義労火ㇸヘせ汎洪山|
// |李火　丁労火ㇸミ洪群義李火・ミ汎洪允火丁|
// |汎シ一山汎シ一せ和覇奏允ヘㇵせせ山允ミ　|
// +----------------------------------------+
// 2026 (April 23rd) 22:56:42
// end signature

