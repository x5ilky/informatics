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
    string S;cin>>S;int N=S.size();
    vector<int>same;
    for(int i=1;i<N;i++){
        if(S[i-1]==S[i])same.push_back(i);
    }
    same.push_back(N);
    int ans=0;
    for(int i=0;i<N;i++){
        ans+=(*upper_bound(same.begin(),same.end(),i))-i;
        ans%=998244353;
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |允允允汎汎山せ火火火ビビビ丁丁丁丁ビ火山|
// |丁丁ビ火ビミシㇸヘミミミヘ・ㇸ一一ヘミビ|
// |一一ㇵヘㇸミ火山允汎汎汎允ビヘㇸ・　一シ|
// |ㇸㇸㇸ丁せ允汎允允允汎洪労山丁ミヘ一　一|
// |丁ミ丁山允せ火火せせせせ山火ビシ一ㇸ一　|
// |山山せ山火丁せ允せせせ山允せ丁丁シヘ一・|
// |李労労汎允火山火せ山汎洪汎汎火火山せビシ|
// |奏和李労洪洪允せ汎労李奏耗労允允洪洪汎せ|
// |和洪洪和耗耗労汎李奏奏労労汎允汎李耗李汎|
// |允洪耗陽義群和和耗李労洪洪汎山洪和耗和汎|
// |洪耗義覇義群和労汎山せ火火せ山允洪李労山|
// |労耗陽陽耗労汎せビミミミミシ丁火山洪允火|
// |労李群奏李允火ミビせせ山せ火ビミ丁せ汎山|
// |耗群陽耗労山ビ火山汎洪労労洪汎山ビシ火山|
// |群義義奏労山ビ山洪李耗奏和洪允火丁ミミビ|
// |義覇義奏労山火汎李耗陽奏李允火ミㇵㇸヘミ|
// |覇覇陽耗洪火允労奏義陽和汎せミㇵヘㇵ一丁|
// |覇慶奏労山允労奏義陽和洪せシシビ火ミヘミ|
// |覇群李允山労奏慶義耗洪せシシ火汎火ヘミミ|
// |慶奏労山汎和陽覇群李允丁一シ火火ミヘミビ|
// +----------------------------------------+
// 2026 (May 2nd) 22:19:59
// end signature
