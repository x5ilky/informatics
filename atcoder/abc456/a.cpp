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
#define int long long
const int INF=1ull<<60;
signed main(){
    int X;cin>>X;
    cout<<(X>=3&&X<=18?"Yes\n":"No\n");
}

// begin signature
// +----------------------------------------+
// |李李李和労汎允山山山せせせ火火火火せ允洪|
// |山山山允せビミシ一ヘシヘㇸㇵ一ㇵヘシ丁せ|
// |シシミシ　シ火允汎洪洪洪允ビ一ㇸ　・ㇵ丁|
// |　　　丁山洪李李労李和耗和允ビ丁シ一　ㇵ|
// |ミシ丁汎労汎山せ允允允汎洪允火ミ一一ㇵ　|
// |允山せ洪山火允洪汎允允洪洪允ビミミシㇵ　|
// |和和李洪允せ汎山允汎洪洪労労山山允山せ丁|
// |陽義群奏耗李洪允労和奏奏耗労汎労和和労允|
// |陽耗和群陽群耗労奏義慶陽群耗労労奏義奏李|
// |李和陽覇覇慶奏奏慶慶群群李洪汎李群覇群李|
// |李陽覇覇覇慶慶陽奏耗和李李李和耗群義耗汎|
// |和義覇覇覇陽奏李洪允山山山山汎労和奏洪せ|
// |労奏慶覇陽耗労允火丁ミシ丁丁ビせ汎李労汎|
// |耗奏義覇群李汎火ミ一・　　ㇸヘ丁丁せ洪汎|
// |陽慶覇覇群李山丁ㇵ一ヘシシㇵㇸ・ヘビビ允|
// |慶覇覇慶奏労せシ一ミ火山山せビヘ　ㇵビ丁|
// |覇覇覇義和汎ビ一丁山洪李李山丁一　　シ丁|
// |覇覇慶耗洪ビㇵビ允李奏李山ミ一シミㇵミミ|
// |覇覇奏労火ヘビ汎耗陽和允ミヘ火山火ヘビ丁|
// |覇義和允丁シ山李群奏洪火ㇵビ汎洪火ヘビ火|
// +----------------------------------------+
// 2026 (May 2nd) 22:00:58
// end signature
