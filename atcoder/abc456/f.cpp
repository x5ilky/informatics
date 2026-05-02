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
struct node{
    array<int,4>a,e;
};
struct segtree{
    vector<node>T;
    segtree(int N):T(N*4){}
    array<int,4> cmb(array<int,4> l,array<int,4> r){
        return {
            min({l[0]+r[0],l[0]+r[1],l[2]+r[0]}),
            min({l[1]+r[0],l[1]+r[1],l[3]+r[0]}),
            min({l[0]+r[2],l[0]+r[3],l[2]+r[2]}),
            min({l[1]+r[2],l[1]+r[3],l[3]+r[2]}) 
        };
    }
    node merge(node l,node r){
        node res;
        res.e=cmb(l.e,r.e);
        auto x=cmb(l.a,r.e);
        auto y=cmb(l.e,r.a);
        for(int i=0;i<4;i++)res.a[i]=min(x[i],y[i]);
        return res;
    }
    // 11 01 10 00
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v].a={a,INF,INF,INF};
            T[v].e={a,INF,INF,0};
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    node query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2;node l,r;
        if(ql<=tm)l=query(v*2,tl,tm,ql,qr);
        if(qr >tm)r=query(v*2+1,tm+1,tr,ql,qr);
        if(ql<=tm&&qr>tm)return merge(l,r);
        if(ql<=tm)return l;
        if(qr >tm)return r;
        assert(false);
    }
};
void solve(){
    int N,K;cin>>N>>K;
    segtree st(N+1);
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        st.update(1,1,N,i,v);
    }
    int ans=INF;
    for(int i=1;i<=N;i++){
        for(int k=K;k<=K+1;k++){
            if(i+k-1>N)continue;
            auto v=st.query(1,1,N,i,i+k-1).a;
            // dprint("i={},k={},v={}",i,k,v);
            ans=min(ans,v[0]);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int T;cin>>T;
    while(T--)solve();
}

// begin signature
// +----------------------------------------+
// |丁ミ丁丁火せせ火・一ㇵㇵㇸミシシミ丁ビせ|
// |ㇸㇸ一ㇵヘㇸミビせ山允允山火シ　ㇸ一ヘ丁|
// |一一ㇸ一ビ山允汎汎汎洪労労允ビヘ一　ㇸヘ|
// |丁丁ミせ允山せ火火火せ山允せビシヘㇵ・ㇸ|
// |允山せ山火丁ビ山洪労労洪せビ丁ミシ一・ㇸ|
// |李李労汎山ビ山山山せせ山允允火せせビシ一|
// |耗李洪洪洪允せビ丁ミミミ丁ビせ火せせビミ|
// |李汎允洪允火ミヘ一ㇸ・・ㇸ一ヘ丁火允汎山|
// |汎允労允ビシ一　　・一ㇵ一ㇸ　一シ火山洪|
// |労洪山丁ㇵ　・ㇸヘ一　・・　ㇸㇸㇵミ火允|
// |洪せミㇸ・一ㇵヘ一・・ㇸㇸ・　ㇸ一シビ山|
// |せミ一ヘシ一　一ヘシミミミシㇵㇸㇸミ丁山|
// |せ火丁ヘㇸㇸヘ丁火せ山山山せビミㇵヘシ火|
// |洪せミ一　ㇵ丁せ允洪労労労洪汎山ビシシミ|
// |洪せミ一・ヘビ山洪李耗奏和洪山火丁シシミ|
// |洪せミㇸ一シせ汎李奏陽奏労允火ミヘㇸ・ㇵ|
// |汎ビ丁ヘㇵビ允李奏義群和汎せミ一　一　ㇸ|
// |允允火シ丁允李奏慶陽和洪せシ・一シ・ㇵㇵ|
// |李汎ビ丁山労奏慶義耗洪せシ・ㇸㇸ・ㇵシシ|
// |労山ミ火汎和陽覇群李允丁一ㇸㇸㇸ一シㇵㇵ|
// +----------------------------------------+
// 2026 (May 3rd) 00:01:33
// end signature
