#include <bits/stdc++.h>
#include <numeric>
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
#include <atcoder/modint.hpp>
using mint=atcoder::modint998244353;
#define int long long
const int INF=1ull<<60;
signed main(){
    string S;cin>>S;int N=S.size();
    vector<mint>dp(3,0);
    for(int i=0;i<N;i++){
        int c=S[i]-'a';
        dp[c]++;
        for(int d=0;d<3;d++)if(d!=c)dp[c]+=dp[d];
    }
    cout<<accumulate(dp.begin(),dp.end(),mint(0)).val()<<endl;
}

// begin signature
// +----------------------------------------+
// |奏奏奏群群耗李労労労洪洪汎允山山允汎労耗|
// |允允汎洪汎山火ㇵ丁火せ火丁ㇸㇵㇵシ丁せ汎|
// |ヘシミビㇵせ労耗群陽陽群奏汎丁ㇵㇸ・シ火|
// |ㇵ一一允和群陽群奏群陽慶慶和允せビヘ　シ|
// |山せ山耗奏李洪洪李和李和和労汎ビヘ一ヘ　|
// |耗耗李耗洪允李奏和李和耗奏李允山火丁ヘ・|
// |覇覇慶陽耗労耗労李耗陽陽陽群労労和李汎火|
// |覇覇覇慶義義奏李李労洪労労和奏群義慶陽和|
// |覇義義慶群李洪山火ビ丁丁ビせ允労耗陽覇陽|
// |群慶陽李允火シ一　　ㇸㇵヘㇵミせ洪耗義陽|
// |義耗汎ビㇵ　一ㇸシビせ山允山火丁山労群耗|
// |李山ミシㇵ・ミせ洪山火火せ火允允ビ汎耗洪|
// |汎洪洪汎山ビ允山丁ㇵ・・一シ火火允せ洪和|
// |耗群陽群労せ汎ビㇵㇸシ丁ミㇵ　シせ火允洪|
// |慶覇覇奏汎せ允ミ　ヘミ丁汎山シ　ヘビせ汎|
// |覇覇慶耗允允山ヘ一火山允汎火一ㇵミㇵ丁せ|
// |覇覇陽洪せ允ビ　丁シㇵヘ丁シ一シ丁ミシ允|
// |覇義李せ火せ一シ　ㇵヘㇸㇵㇸビ洪洪せ丁せ|
// |慶和せせ汎シㇵ一火允せㇵ・ビ労陽労ビ山せ|
// |群洪允火せ一　ビ労耗山ㇵヘ火洪労せミ山汎|
// +----------------------------------------+
// 2026 (May 2nd) 22:35:20
// end signature
