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
    int _p=0,_m=0;
    vector<vector<int>>poly,mono;
    vector<int>seen(N+1);
    unordered_map<int,int>P;
    map<int,int>H;
    for(int i=1;i<=N;i++){
        P[A[i]]=i;
        if(seen[i])continue;
        if(A[i]==i){
            H[B[i]]=A[i];
            continue;
        }
        vector<int>pv={i};
        set<int>ps={i};
        set<int>cols={B[i]};
        int j=i;
        seen[j]=true;
        while(ps.find(A[j])==ps.end()){
            j=A[j];
            pv.push_back(j);
            ps.insert(j);
            cols.insert(B[j]);
            seen[j]=true;
        }
        (cols.size()==1?mono:poly).push_back(pv);
        (cols.size()==1?_m:_p)+=pv.size();
    skip:;
    }
    using pii=pair<int,int>;
    vector<pii>moves;
    auto swp=[&](int a,int b){
        swap(A[P[a]],A[P[b]]);
        moves.push_back({P[a],P[b]});
        swap(P[a],P[b]);
    };
    for(auto&p:poly){
        dcheck(p);
        for(auto v:p)H[B[v]]=v;
        int j=0;
        for(int i=0;i<p.size();i++){
            if(B[P[p[i]]]!=B[P[A[p[i]]]]){
                j=i;break;
            }
        }
        rotate(p.begin(),p.begin()+j,p.end());
        int G=p[0];
        swp(p[0],p[1]);
        for(int i=1;i<p.size()-1;i++){
            if(B[P[p[i]]]!=B[P[A[p[i]]]]){
                swp(p[i],A[p[i]]);
                G=p[i];
            } else {
                int a=p[i],b=A[p[i]];
                swp(p[i],G);
                moves.pop_back();
                moves.pop_back();
                swp(a,b);swp(b,G);
                // keep G
            }
            // dprint("i = {}, moves = {}",i+1,moves);
        }
    }
    // bug is that monochromatic cycles can save swaps by using
    // same position as commutator for cycles of different colors
    // however this means you need to like chain cycles of 
    // differing colors together to create the largest chain
    // and then resolve that all at once to fix everything
    // something like that
    //
    // consider 
    // 
    // 2 3 1 5 6 4
    // 2 3 5 1 6 4
    // 1 3 5 2 6 4
    // 1 2 5 3 6 4
    // 1 2 3 5 6 4
    // 4 2 3 5 6 1
    // 5 2 3 4 6 1
    // 6 2 3 4 5 1
    // 1 2 3 4 5 6
    // 
    // 2 3 1 5 6 4
    // 2 3 5 1 6 4
    // 1 3 5 2 6 4
    // 1 2 5 3 6 4
    // 1 2 6 3 5 4
    // 1 2 4 3 5 6
    // 1 2 3 4 5 6

    for(auto&v:mono){
        dcheck(v);
        int h;
        for(int i=1;i<=N;i++){
            if(B[i]!=B[v[0]]){
                h=A[i];
                break;
            }
        }

        swp(v[0],h);
        for(int i=1;i<v.size();i++){
            swp(v[i-1],v[i]);
        }
        swp(v.back(),h);
    }
    assert(moves.size()==(_p-poly.size()+_m+mono.size()));
    cout<<moves.size()<<endl;
    for(auto [u,v]:moves)cout<<u<<" "<<v<<endl;
}

// begin signature
// +----------------------------------------+
// |・・　・ㇵ丁山労耗李労労労和奏義覇覇覇覇|
// |山山せ丁ヘ　ヘせ火丁ミミ丁火允李群覇覇覇|
// |奏奏和洪せシ　　一ヘヘㇵ・ㇸミ山李耗奏義|
// |覇覇慶群李山ミせ允労労允火シ　ミビせ汎和|
// |覇覇覇覇義和労労洪洪洪李耗汎丁一ㇸ・ヘせ|
// |覇覇慶陽和汎せ丁シヘシミビ山労汎山せミ　|
// |覇群奏和允丁一・ㇵシシヘ一　ヘ丁火允労允|
// |慶和奏汎丁・ヘビ丁ミミビせせ丁ㇵㇸ・シせ|
// |覇陽洪丁　ミㇵ一ミビ丁ミシシビ汎山ビㇵシ|
// |群汎シ一せシせ火ヘ　ㇵ一　・ㇸミ允洪丁・|
// |允ㇵシ山山允ヘㇸ丁　ヘビせせせ火山和山ㇸ|
// |ヘシ洪耗山一シシ一せ労耗奏耗奏汎火洪洪ㇵ|
// |・火和労丁一丁・火李陽慶耗洪せビミヘシビ|
// |ㇵ丁李和ビㇸ丁一山耗陽奏洪ビ火ㇵ　一ㇵㇸ|
// |ビㇸ山群允一丁・ビ和慶耗山ヘ・一火山允允|
// |允ㇸビ和李ミㇵシシ洪洪労洪山ビ火洪耗群陽|
// |允一丁李李丁一ミㇵビシミビ洪汎労陽覇覇慶|
// |火　せ耗洪シㇵシ一ㇸミ汎耗陽群慶覇覇義奏|
// |ミ一山奏汎ヘヘミ　火洪耗群群群陽群和耗山|
// |丁ㇸせ和洪丁　ミ一ㇵビ山允山汎汎允和せ一|
// +----------------------------------------+
// 2026 (June 26th) 23:23:49
// end signature


