#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

using namespace std;
struct segtree {
    vector<int>T;int N;
    segtree(int N):T(N+1),N(N){}
    void add(int i,int addend){
        for(;i<=N;i+=i&-i)T[i]+=addend;
    }
    int sum(int i){
        int sum=0;for(;i;i-=i&-i)sum+=T[i];
        return sum;
    }
    int sum(int l,int r){
        return sum(r)-sum(l-1);
    }
};
signed main() {
    cin.tie(0)->sync_with_stdio(false),cout.tie(0);
    int N,K;cin>>N>>K;
    using pii=pair<int,int>;
    vector<pii>rects(N+1);set<int>coord;
    for(int i=1;i<=N;i++)cin>>rects[i].first>>rects[i].second;
    for(int i=1;i<=N;i++)coord.insert(rects[i].first),coord.insert(rects[i].second);
    map<int,int>ptc,ctp; int cnt=0;
    for(auto c:coord)ctp[ptc[c]=++cnt]=c;
    
    vector<vector<int>>A(2*N+1);
    for(int i=1;i<=N;i++)rects[i]={ptc[rects[i].first],ptc[rects[i].second]};
    for(int i=1;i<=N;i++)A[rects[i].first].push_back(rects[i].second);
    sort(rects.begin()+1,rects.end());
    segtree st(N*2);
    for(int i=1;i<=N;i++)st.add(rects[i].second,1);
    long long ans=0;
    int y=2*N;
    for(int i=1;i<=N;i++){
        int x=rects[i].first;
        while(y>=1&&st.sum(y,2*N)<K)y--;
        if(y>=1&&st.sum(y,2*N)>=K){
            assert(ctp.find(y)!=ctp.end());
            ans=max(ans,(long long)ctp[x]*(long long)ctp[y]);
        }
        st.add(rects[i].second,-1);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |ビビビ火せ山せ火火・ㇸㇸ　ミミミミ丁火せ|
// |一ㇵㇵヘミミヘ丁火せ山山せ丁ㇵ・ㇸㇵシ丁|
// |ㇸㇸ　ㇸミせ允汎洪洪洪労労山丁ㇵㇸ　ㇸヘ|
// |ミミシせ允允せせ火せ山允允山ビミシㇵ・ㇸ|
// |山せ火允火丁丁火せせせ山ビ丁ミシヘㇸ・・|
// |労労洪允せ丁ビ丁ミミミミ丁火ビせ火丁ヘㇸ|
// |奏和洪山火ミヘ一ㇸ・・・ㇸㇵシ丁ビ火ビミ|
// |和洪允火ミㇵ・・・・一一ㇵㇸ　ㇸ一ヘシビ|
// |洪山火ミ一　一一ㇸㇸ一一一ㇸ・一ㇸ　・ㇵ|
// |せビヘ・一・　・・・・ㇸ一ㇵヘ一ㇵヘㇸ・|
// |丁ㇵ・　一一一一・　・ㇸㇸ・　ㇸ一一一　|
// |丁シ　　　　　一ヘシミミミシㇵㇸ　ㇸㇸ　|
// |シ　　ㇵ　ㇸヘ丁火せ山山せ火ビミㇵ　・シ|
// |ㇵ　ㇸ・　ㇵ丁せ允汎労労労洪汎山ビシㇸ・|
// |ヘ　一　　ヘビ山洪李耗奏和洪山火丁ミシㇵ|
// |ミ・一　・シ火汎李奏陽奏李允火ミㇵㇸ　・|
// |シ・ㇸ・ㇵビ允李奏義群和汎火シㇸ・ㇵヘㇵ|
// |ㇵ一ㇸ一丁允李奏慶陽和汎火シ・一ミビ火丁|
// |ヘ・ㇸ丁山労奏慶義耗洪せシ　ㇵビ山汎山丁|
// |ㇸ　ヘ火汎和陽覇群李允丁一ㇸ丁山允せ丁ㇵ|
// +----------------------------------------+
// 2026 (April 22nd) 20:31:09
// end signature





