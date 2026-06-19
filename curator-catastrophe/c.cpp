#include <bits/stdc++.h>
using namespace std;
// BEGIN DEBUG
#define __t template
#define __T typename
#define _U(a,b) using _ ## a = b;
_U(OS,ostream)_U(S,string)_U(F,false_type)_U(T,true_type);__t<class T>struct _is:_F{};
#define _T_(d,c) __t<d>struct _is<c>:_T{};
_T_(,_S);_T_(,char*);_T_(,const char*);_T_(size_t N,char[N]);_T_(size_t N,const char[N]);
#undef _T_
__t<class T>struct is_iterable{__t<class U>static auto test(int)->decltype(begin(declval<const U&>()),end(declval<const U&>()),_T{});__t<class>static _F test(...);static const bool value=decltype(test<T>(0))::value;}; __t<class A,class B>_OS& operator<<(_OS&,const pair<A,B>&); __t<class...Ts>_OS& operator<<(_OS&,const tuple<Ts...>&); __t<class T>__T enable_if<is_iterable<T>::value&&!_is<__T decay<T>::type>::value,_OS&>::type operator<<(_OS&,const T&); __t<class A,class B>_OS& operator<<(_OS& o,const pair<A,B>& p){return o<<'('<<p.first<<","<<p.second<<')';} __t<int I,class...Ts>__T enable_if<I==sizeof...(Ts),void>::type _pt(_OS&,const tuple<Ts...>&){} __t<int I,class...Ts>__T enable_if<I<sizeof...(Ts),void>::type _pt(_OS& o,const tuple<Ts...>& t){if(I)o<<",";o<<get<I>(t);_pt<I+1>(o,t);} __t<class...Ts>_OS& operator<<(_OS& o,const tuple<Ts...>& t){o<<'(';_pt<0>(o,t);return o<<')';} __t<class T>__T enable_if<is_iterable<T>::value&&!_is<__T decay<T>::type>::value,_OS&>::type operator<<(_OS& o,const T& v){o<<'[';bool f=0;for(const auto& x:v)o<<(f?",":""),f=1,o<<x;return o<<']';}
namespace dbg{ inline void _fs(_OS& os,const _S& fmt){os<<fmt;} __t<__T T,__T...Rest>void _fs(_OS& os,const _S& fmt,const T& value,const Rest&...rest){size_t pos=fmt.find("{}");if(pos==_S::npos)throw runtime_error("too many arguments for format _S");os<<fmt.substr(0,pos)<<value;_fs(os,fmt.substr(pos+2),rest...);} __t<__T...Args>void print(_OS& os,const _S& fmt,const Args&...args){
#ifdef DEBUG
_fs(os,fmt,args...);
#endif
} __t<__T...Args>void println(_OS& os,const _S& fmt,const Args&...args){
#ifdef DEBUG
_fs(os,fmt,args...);os<<'\n';
#endif
} __t<__T...Args>void print(const _S& fmt,const Args&...args){print(cerr,fmt,args...);} __t<__T...Args>void println(const _S& fmt,const Args&...args){println(cerr,fmt,args...);} }
#define dprint(...) dbg::println(__VA_ARGS__)
#define dcheck(v) dbg::println("{} = {}",#v,v)
// END DEBUG
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    if(all_of(B.begin()+1,B.end(),[&](int v){return v==B[1];}))
        return cout<<(is_sorted(A.begin()+1,A.end())?0:-1)<<endl,0;
    vector<short>sorted(N+1);
    for(int i=1;i<=N;i++)sorted[i]=i==A[i];
    using pii=pair<int,int>;
    vector<pii>ans;
    vector<int>loop;
    int fine;
    for(int i=1;i<=N;i++){
        if(sorted[i])continue;
        int j=i;
        vector<pii>c;
        while(true){
            dprint("at {} now {}",i,j);
            if(sorted[j]){
                // closed loop 
                loop.push_back(j);
                goto skip;
            }
            if(B[j]!=B[A[j]]){
                c.push_back({j,A[j]});
                sorted[j]=sorted[A[j]]=true;
                fine=A[j];
                break;
            }
            sorted[j]=true;
            c.push_back({j,A[j]});
            j=A[j];
        }
        while(c.size())ans.push_back(c.back()),c.pop_back();
skip:;
    }
    dcheck(loop);
    if(loop.size()==1){
        int v=loop.back();
        ans.push_back({v,fine});
        int j=v;
        vector<pii>c;
        do{
            c.push_back({j,A[j]});
            j=A[j];
        }while(A[j]!=v);
        sorted[j]=true;
        dcheck(c);
        while(c.size())ans.push_back(c.back()),c.pop_back();
        ans.push_back({j,fine});
    }else if(loop.size()>=2){
        for(int i=0;i<loop.size()-1;i++){
            ans.push_back({loop[i],loop[i+1]});
        }
        vector<int>n;
        for(auto v:loop){
            int j=v;
            vector<pii>c;
            do{
                c.push_back({j,A[j]});
                j=A[j];
            }while(A[j]!=v);
            sorted[j]=true;
            dcheck(c);
            while(c.size())ans.push_back(c.back()),c.pop_back();
            n.push_back(j);
        }
        for(int i=loop.size()-2;i>=0;i--){
            ans.push_back({n[i+1],n[i]});
        }
    }
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans)cout<<u<<" "<<v<<endl;
}

// begin signature
// +----------------------------------------+
// |　　　　ㇸㇵミビせ火ビビビ火せ允洪李耗奏|
// |シシシㇵㇸ　一シヘㇵ一ㇵㇵシミビ山汎洪労|
// |せせ火丁シ一　　・ㇸㇸㇸ　・ㇵミ火火せ允|
// |労洪汎山ビシㇵシミ丁丁ミヘ一　ㇵヘシ丁火|
// |奏和李洪允火ビせせせせ山火ミㇵ・　　一シ|
// |李洪允允山火丁ミシヘシシミビビミミシ一　|
// |洪山せ山ビミㇵㇸ　　　　・一ヘミ丁ビ火ミ|
// |允火山火シ一　　・・　ㇸㇸ・　・ㇸ一シ丁|
// |允允火シ一ㇸ・　・・・・一ㇸ　ㇸ　ㇸ　一|
// |允ビ丁丁丁ヘㇸ　ㇸ一・　　・　　　　・ㇸ|
// |允山ビヘ・ㇸㇸ　ㇸ一　・ㇸㇸㇸ・　　ㇸ　|
// |山丁一　ㇸ・・ヘ　一シ丁丁ミミヘ一　・ㇸ|
// |ビヘ　　・　ヘ・一丁せ山允山せ火丁ヘ・　|
// |ビㇵ　・ㇸ　ヘ　ヘビ允労李李労洪允火ミ一|
// |火ヘ　・ㇵㇸㇵ・ㇵビ允李奏群群奏和労允火|
// |せシ・　ヘㇵㇸ一一丁允李群慶慶陽陽奏李汎|
// |火ㇵ　一丁ㇵㇸ一一丁允労耗陽陽群義陽和汎|
// |ミㇸㇸ丁丁ㇸ一ㇸ一丁せ洪和耗李耗耗李汎せ|
// |ㇵ　シせシ・ㇵ・一ミ火允汎汎汎洪汎山火丁|
// |ㇵㇸミせミㇸㇸㇵ　ㇵミビ火ビ火火ビ火丁一|
// +----------------------------------------+
// 2026 (June 18th) 17:51:16
// end signature

