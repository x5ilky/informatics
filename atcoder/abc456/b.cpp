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
using ld=long double;
signed main(){
    vector<vector<ld>>freq(4,vector<ld>(7));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=6;j++){
            int a;cin>>a;
            freq[i][a]++;
        }
    }
    ld ans=0;
    ans+=(freq[1][4]/6)*(freq[2][5]/6)*(freq[3][6]/6);
    ans+=(freq[1][4]/6)*(freq[2][6]/6)*(freq[3][5]/6);
    ans+=(freq[1][5]/6)*(freq[2][4]/6)*(freq[3][6]/6);
    ans+=(freq[1][5]/6)*(freq[2][6]/6)*(freq[3][4]/6);
    ans+=(freq[1][6]/6)*(freq[2][5]/6)*(freq[3][4]/6);
    ans+=(freq[1][6]/6)*(freq[2][4]/6)*(freq[3][5]/6);
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |せせせせ山山せ火火火ビビ丁ミミミ丁ビ火山|
// |シシシミ丁ミㇸシ丁火火火丁シ・ㇸ一ㇵシ丁|
// |　　・一シ火山汎洪洪洪洪洪せミ一ㇸ　一シ|
// |ヘヘㇵ火允汎允山山山允汎汎山ビミシㇵ　一|
// |火ビビ允せビ丁火せ山せ火火ビ丁シ一・ㇸ・|
// |洪汎允せビ丁せ山山允允允允せ火火丁シㇵㇸ|
// |耗耗和労汎山せ火ビ丁丁丁ビ火せ火せせビミ|
// |耗李洪汎山火丁シㇵ一一一ㇵヘミビせ允汎山|
// |労允汎せ丁シ一・・・ㇸ一ㇵヘㇵㇵミ火山汎|
// |山允火シ一ㇵシミミミ丁ビ丁丁ビ丁シミせ汎|
// |山丁ㇵシ丁火せビ丁シヘㇵㇵヘミミビシ火山|
// |ミヘ丁せ山せ火丁ミシミミシヘㇵミミビビせ|
// |ヘビ山山山せ丁ミビ火せせせ火丁シミミ丁せ|
// |シ火允允山ビミ火山汎洪労労洪允せビミシ丁|
// |シ火汎允火丁ビ山洪李耗耗和洪允火丁ミミシ|
// |ミ火汎允ビミ火汎李耗群奏李允火ミ丁ミ一丁|
// |シせ汎せミビ允労奏陽陽和汎せミビ山火ヘミ|
// |ビ汎山丁丁山労奏義陽和洪せシミ山山丁ㇵミ|
// |山允ビミ山労奏慶義耗洪せシ一ミ丁ミ一丁ミ|
// |汎山丁火汎和陽覇群李允丁一　一一・シシミ|
// +----------------------------------------+
// 2026 (May 2nd) 22:06:13
// end signature
