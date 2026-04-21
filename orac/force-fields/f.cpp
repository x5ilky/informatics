#include <bits/stdc++.h>
#define int long long
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
    vector<vector<int>>T;
    segtree(int N):T(N*4){}
    void merge(int v){ 
        int i=0,j=0;auto&a=T[v*2],&b=T[v*2+1];
        T[v].clear();T[v].reserve(a.size()+b.size());
        while(i<a.size()&&j<b.size()){
            if(a[i]>b[j]){
                T[v].push_back(b[j++]);
            }else{
                T[v].push_back(a[i++]);
            }
        }
        while(i<a.size())T[v].push_back(a[i++]);
        while(j<b.size())T[v].push_back(b[j++]);
    }
    void build(int v,int tl,int tr,vector<vector<int>>&A){ 
        if(tl==tr){
            T[v]=A[tl];
            sort(T[v].begin(),T[v].end());
            return;
        }
        int tm=(tl+tr)/2;
        build(v*2,tl,tm,A);
        build(v*2+1,tm+1,tr,A);
        merge(v);
    }
    int query(int v,int tl,int tr,int ql,int qr,int gte) {
        if(ql<=tl&&tr<=qr){
            return T[v].end()-lower_bound(T[v].begin(),T[v].end(),gte);
        }
        int tm=(tl+tr)/2,cnt=0;
        if(ql<=tm)cnt+=query(v*2,tl,tm,ql,qr,gte);
        if(qr >tm)cnt+=query(v*2+1,tm+1,tr,ql,qr,gte);
        return cnt;
    }
};
signed main() {
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
    segtree st(N*2+1);
    st.build(1,1,2*N,A);
    int ans=0;
    for(int i=1;i<=N;i++){
        int x=rects[i].first;
        int lo=1,hi=2*N;
        while(lo+1<hi){
            int mid=(lo+hi)/2;
            if(st.query(1,1,2*N,x,2*N,mid)>=K) lo=mid; else hi=mid;
            // dprint("mid = {} = {}\n",mid,st.query(1,1,2*N,x,2*N,mid));
        }
        if(st.query(1,1,2*N,x,2*N,lo)>=K){
            ans=max(ans,ctp[x]*ctp[lo]);
        }
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |ミミミ丁ビ火せ火ㇸㇵヘヘㇵ　シシミ丁ビせ|
// |・・ㇸ一ヘ一ミ火山允允允山火シ・ㇸ一ヘミ|
// |ㇵㇵ一ㇵビ山汎汎汎汎汎洪労允ビヘ一　ㇸヘ|
// |ビ丁ミ山允山火ビ火せ山山允せビシヘヘ・ㇸ|
// |汎允山山ビミ丁ミミミミ丁ビビビ丁シㇵ・ㇸ|
// |和労允せ丁シㇵ一・・・ㇸ一ヘミ丁火ビシ一|
// |和洪山ビシ一　ㇸ一ㇵㇵㇵ一・・一ㇵヘ丁ミ|
// |李汎火ミ一　ㇵㇵㇵヘシミ丁ミヘ一ㇸ　・ㇵ|
// |汎せミ一・　　　　　・ㇸ一ㇵシ丁ミシ一　|
// |せミㇸㇸㇵㇸ・丁ミシヘㇵㇵㇵヘㇵミビシ一|
// |シ・　ㇸㇵ丁シ一・　・ㇸ・　　ㇸヘシシㇵ|
// |シヘ　ビシ一　一ヘシミミミシㇵㇸ・　ㇵㇵ|
// |シㇸ火シㇸ・ヘミビせ山山せ火ビミㇵ　　ミ|
// |ヘㇸ丁ㇵ　ㇵ丁火允汎労労労洪汎山ビシㇸ　|
// |ヘ・ミㇵ　ヘビ山洪李耗奏和洪山火丁ミシㇵ|
// |ミ・ㇵ一・シ火汎李奏陽奏李允火ミㇵㇸ・・|
// |ミ・ㇵ・ㇵビ允李奏義群和汎火ミ一・一ヘㇵ|
// |シ　ㇸ一丁允李奏義陽和汎火シ・一ミビ火丁|
// |ㇵ・ㇸ丁山労奏慶義耗洪せシ　ㇵビ山允火シ|
// |ヘ　ヘ火汎和陽覇群李允丁一ㇸ丁山山ビヘ　|
// +----------------------------------------+
// 2026 (April 21st) 18:20:24
// end signature

