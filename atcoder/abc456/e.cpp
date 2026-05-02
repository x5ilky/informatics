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
void solve(){
    int N,M;cin>>N>>M; 
    vector<vector<int>>g(N+1);
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int W;cin>>W;
    vector<vector<short>>hol(N+1,vector<short>(W));
    for(int i=1;i<=N;i++){
        string S;cin>>S;
        for(int j=0;j<W;j++){
            hol[i][j]=S[j]=='o';
        }
    }
    using pii=array<int,4>;
    stack<pii>q;
    vector<vector<int>>seen(N+1,vector<int>(W,0)),been(N+1,vector<int>(W,0));
    for(int i=1;i<=N;i++){
        q.push({-1,-1,i,0});
        while(!q.empty()){
            auto [u2,d2,u,d]=q.top();q.pop();
            if(u2!=-1){
                been[u2][d2]=false;
                continue;
            }
            if(seen[u][d])continue;
            seen[u][d]=true;
            // dprint("at {} {}",u,d);
            been[u][d]=true;
            // dprint("{}",been);
            q.push({u,d,-1,-1});
            for(auto v:g[u]){
                if(hol[v][(d+1)%W]){
                    if(been[v][(d+1)%W])return void(cout<<"Yes\n");
                    if(seen[v][(d+1)%W])continue;
                    q.push({-1,-1,v,(d+1)%W});
                }
            }
            if(hol[u][(d+1)%W]){
                if(been[u][(d+1)%W])return void(cout<<"Yes\n");
                if(seen[u][(d+1)%W])continue;
                q.push({-1,-1,u,(d+1)%W});
            }
        }
    }
    cout<<"No\n";
}
signed main(){
    int T;cin>>T;
    while(T--)solve();
    cout<<endl;
}

// begin signature
// +----------------------------------------+
// |せせせ山允洪汎允允ㇸ一一　ビ丁丁ビ火山汎|
// |ㇵㇵヘシ丁　ミせ允汎洪洪汎せシ・一ヘミ火|
// |一ㇸ・一火汎労和和和耗奏奏労せヘ一　一ミ|
// |ビビ丁汎李労汎允允允汎労李洪せ丁ミヘ・一|
// |洪汎允労允火せ允洪李和洪山火火丁シ一ㇸㇸ|
// |群奏耗労汎せ汎洪和群覇慶奏洪せ汎允火ミ一|
// |覇陽奏耗耗李労山洪李耗奏耗李洪允汎汎山ビ|
// |陽耗労耗奏耗和和和耗李労洪洪洪労和耗和洪|
// |耗洪奏義覇慶義奏李汎山火ビビビせ允洪和和|
// |李奏慶覇覇陽和汎せ丁ヘ一ㇸㇵシビ丁山洪和|
// |義覇覇慶奏労山丁一　一ヘㇵ・ㇸシ火火汎洪|
// |覇覇覇奏労せシ　ㇸ一一ㇸ　ㇸㇸ一丁ミ山洪|
// |覇覇義和允丁ㇵ・・一一一・・　　ㇵ火ビ允|
// |覇覇慶耗汎丁・ㇵヘ一・　・ㇸ一ヘㇵヘ火火|
// |覇覇覇群労火ㇵ一　一ヘシ丁ビビ火せ丁ヘ火|
// |覇覇覇陽李山シ・一丁火山允汎允山李允丁ビ|
// |覇覇覇陽李山ヘ一丁允労李和允丁せ洪山ミビ|
// |覇覇覇奏洪火ヘビ汎和群和允丁ヘ丁ビシミ丁|
// |覇覇義耗允丁ビ洪奏慶耗允丁・・ㇸ　シビビ|
// |覇覇義耗汎ビ山和義群労火ㇵ一ヘ　シ火丁一|
// +----------------------------------------+
// 2026 (May 2nd) 23:07:51
// end signature

