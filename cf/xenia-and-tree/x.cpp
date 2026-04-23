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
#define dprint(...) dbg::print(__VA_ARGS__)
#define dtprint(...) dbg::print("[{}]{}:{}: ",__PRETTY_FUNCTION__,__FILE__,__LINE__),dbg::print(__VA_ARGS__),dbg::print("\n")
// END DEBUG
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
    }
    vector<int>sz(N+1);vector<bool>gone(N);
    using pii=pair<int,int>;
    vector<vector<pii>>cen(N+1);
    function<void(int,int)>fsz=[&](int u,int p){
        sz[u]=1; for(auto v:g[u])if(!gone[v]&&v!=p)fsz(v,u),sz[u]+=sz[v];
    };
    function<int(int,int,int)>fcentr=[&](int u,int s,int p){
        for(auto v:g[u]){
            if(v==p||gone[v])continue;
            if(sz[v]*2>s)return fcentr(v,s,u);
        }
        return u;
    };
    function<void(int,int,int,int)>scentr=[&](int u,int p,int c,int d){
        cen[u].push_back({c,d});
        for(auto e:g[u])if(e!=p&&!gone[e])scentr(e,u,c,d+1);
    };
    function<void(int)>build=[&](int u){
        fsz(u,-1);
        int cent=fcentr(u,sz[u],-1);
        scentr(cent,-1,cent,0);
        gone[cent]=true;
        for(auto v:g[cent]){
            if(gone[v])continue;
            build(v);
        }
    };
    build(1);
    const int INF=1e9+7;
    vector<int>dist(N+1,INF);
    function<void(int)>color=[&](int u){
        for(auto [c,d]:cen[u]){
            dist[c]=min(dist[c],d);
        }
    };
    function<int(int)>query=[&](int u){
        int ans=INF;
        for(auto [c,d]:cen[u]){
            ans=min(ans,d+dist[c]);
        }
        return ans;
    };
    color(1);
    for(int q=1;q<=Q;q++){
        int t,v;cin>>t>>v;
        if(t==1){
            color(v);
        }else if(t==2){
            cout<<query(v)<<endl;
        }
    }
}

// begin signature
// +----------------------------------------+
// |ビビビ火せ允允山せㇸㇵ一・丁ミミ丁ビせ山|
// |一一ㇵヘミ・ミ火山允汎汎允火ヘ・ㇸㇵシビ|
// |一一・一ビ允洪労労労李和和汎火ヘ一　ㇸシ|
// |ビ丁ミ允洪汎山山せ山允汎洪允火ミシヘ・一|
// |汎允山汎せビ火山山山山允せビビ丁シ一・ㇸ|
// |耗和李洪允火ビミミシシミ丁火火允山ビシ一|
// |陽耗労允火ミヘㇸ・　　　・一シ丁ビ火火丁|
// |奏李汎せミ一　ㇸ　・・・　　・・ㇸㇵシビ|
// |労汎せミㇸㇸ　ㇸヘシミミミシㇵ　ㇸㇸ　ㇵ|
// |允火ヘ　・一シミ　　ㇸㇸㇸㇸ・　　一ㇵ　|
// |ビㇵ　ㇸシㇵ・　ㇸ一　・　・ㇸ・　・ㇸ・|
// |ㇵㇵシ一　・・ヘ　ㇵミミシㇵㇸ　　　　ㇸ|
// |ヘㇵ　一シ　ヘ・ㇵ丁山山せ火ミㇵ　　一・|
// |シ・一ミシ　シ　ヘ火汎李李洪允せミ一　ㇵ|
// |シ　ヘビ丁ㇸㇵ・ヘ火洪和陽群耗労允火ヘ　|
// |ミ・ヘせ火ㇵㇸ一一ビ汎耗義覇慶群和洪火シ|
// |ミ・ヘせ火ㇵㇸ一一ビ汎和群慶慶義群李允丁|
// |ヘ・ミ山丁ㇸㇵㇸㇵビ允労耗奏耗奏群李山ビ|
// |一一ビ山ミ・ㇵㇸ一丁せ汎洪洪洪労洪允せビ|
// |一一丁山丁ㇸㇸㇵ　ヘ丁火せ火せせ火せビㇵ|
// +----------------------------------------+
// 2026 (April 22nd) 18:40:25
// end signature
