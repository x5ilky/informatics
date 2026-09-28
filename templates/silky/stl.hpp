// Silky Template Library
#ifndef _SILKY_TL
#define _SILKY_TL
#include <bits/stdc++.h>

template <class T>
struct Reader;
#define _impl_read_cin(t) \
    template<> \
    struct Reader<t> { \
        static void read(t&v) { \
            std::cin>>v; \
        } \
    };
_impl_read_cin(int);
_impl_read_cin(bool);
_impl_read_cin(std::string);
_impl_read_cin(char);
_impl_read_cin(short);
_impl_read_cin(long long);
_impl_read_cin(float);
_impl_read_cin(double);
template <class T>
struct Writer;
#define _impl_write_cout(t) \
    template<> \
    struct Writer<t> { \
        static void write(const t&v) { \
            std::cout<<v; \
        } \
    };
_impl_write_cout(int);
_impl_write_cout(bool);
_impl_write_cout(std::string);
_impl_write_cout(char);
_impl_write_cout(short);
_impl_write_cout(long long);
_impl_write_cout(float);
_impl_write_cout(double);

template <class T>
struct Vec : std::vector<T> {
    using std::vector<T>::vector;
#define _wrap_ret_void(fn) \
    void fn(int i, int j){ \
        std::fn(this->begin()+i, this->begin()+j); \
    } \
    void fn(int i=1){ \
        fn(i,this->size()); \
    }
#define _wrap_ret_it(fn) \
    int fn(const T&v,int i,int j){ \
        return std::fn(this->begin()+i,this->begin()+j,v)-this->begin(); \
    } \
    int fn(const T&v,int i=1){ \
        return fn(v,i,this->size()); \
    }
    _wrap_ret_it(find);
    _wrap_ret_it(lower_bound);
    _wrap_ret_it(upper_bound);
    _wrap_ret_void(reverse);
    _wrap_ret_void(sort);
};
template <class T>
struct Reader<Vec<T>> {
    static void read(Vec<T>&v) {
        for(int i=1;i<=v.size()-1;i++)
            Reader<T>::read(v[i]);
    }
};
template <class T>
struct Writer<Vec<T>> {
    static void write(const Vec<T>&v) {
        for(int i=1;i<=v.size()-1;i++){
            if(i!=1)std::cout<<" ";
            Writer<T>::write(v[i]);
        }
    }
};
template <class T>
struct Writer<Vec<Vec<T>>> {
    static void write(const Vec<Vec<T>>&v) {
        for(int i=1;i<=v.size()-1;i++){
            Writer<Vec<T>>::write(v[i]);
            std::cout<<"\n";
        }
    }
};

template<class T>
void read_one(T& x) {
    Reader<T>::read(x);
}
template<class... T>
void read(T&... x) {
    (read_one(x), ...);
}

template<class T>
void write_one(T& x) {
    Writer<T>::write(x);
}
template<class... T>
void write(T... x) {
    (write_one(x), ...);
    std::cout<<std::endl;
}
struct DSU {
    Vec<int>e;
    DSU(int n):e(n,-1){}
    int operator[](int x){return e[x]<0?x:e[x]=(*this)[e[x]];}
    int operator()(int x,int y) {
        x=(*this)[x],y=(*this)[y];
        if(x==y)return 0;
        if(e[x]<e[y]) std::swap(x, y);
        e[y]+=e[x];
        e[x]=y;
        return 1;
    }
};
template <bool directed>
struct Graph{
    using pii=std::pair<int,int>;
    int N;
    Vec<Vec<pii>>g;
    Graph(int N):N(N),g(N+1){}
    Vec<pii>& operator[](int u){
        return g[u];
    }
    void operator()(int u,int v,int w=1){
        g[u].push_back({v,w});
        if(!directed)g[v].push_back({u,w});
    }
    template<bool weighted=false>
    void read_graph(int M) {
        for(int i=1;i<=M;i++){
            int u,v;read(u,v);
            int w=1;
            if(weighted)read(w);
            (*this)(u,v,w);
        }
    }
    template<bool weighted=false>
    void read_tree() {
        read_graph<weighted>(N-1);
    }
};
struct SCC {
    Graph<1>&g;
    Vec<int>tin,tlow,comp,st,root;
    int t=1,comps=0;
    SCC(Graph<1>&g):g(g),tin(g.N+1,-1),tlow(g.N+1,-1),comp(g.N+1,-1),root(g.N+1,-1){}
    Graph<1>scc() {
        t=1;
        for(int i=1;i<=g.N;i++)if(tin[i]==-1)dfs(i);
        Graph<1>g2(comps);
        for(int u=1;u<=g.N;u++)
            for(auto [v,w]:g[u])
                if(comp[u]!=comp[v])
                    g2(comp[u],comp[v],w);
        return g2;
    }
private:
    void dfs(int u) {
        tlow[u]=tin[u]=++t;
        st.push_back(u);
        for(auto [v,_]:g[u]){
            if(tin[v]==-1)dfs(v);
            if(comp[v]==-1)tlow[u]=std::min(tlow[u],tlow[v]);
        }
        if(tlow[u]==tin[u]){
            int c=comps++;
            root[c]=u;
            while(true){
                auto v=st.back();st.pop_back();
                comp[v]=c;
                if(u==v)break;
            }
        }
    }
};
template<typename T,auto id,auto f>
struct Stable{
    int N,K;
    Vec<Vec<int>>st;
    Stable(Vec<int>A){
        N=A.size();
        K=__lg(N)+2;
        st.resize(K+1,Vec<int>(N+1));
        copy(A.begin(),A.end(),st[0].begin());
        for(int i=1;i<=K;i++)
            for(int j=0;j+(1<<i)<=N;j++)
                st[i][j]=f(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    T query_sum(int l,int r){
        T sum=id();
        for(int i=K;i>=0;i--)
            if((1<<i)<=r-l+1){
                sum=f(sum,st[i][l]);
                l+=1<<i;
            }
        return sum;
    }
    T query_min(int l,int r){
        int i=std::bit_width((unsigned)(r-l+1))-1;
        return f(st[i][l],st[i][r-(1<<i)+1]);
    }
};
namespace MonoidAdd{
    using T=long long;
    constexpr T id(){ return 0; };
    constexpr T op(T a,T b){ return a+b; };
};
namespace MonoidMin{
    using T=long long;
    constexpr T id(){ return LLONG_MAX; };
    constexpr T op(T a,T b){ return std::min(a,b); };
};
namespace MonoidMax{
    using T=long long;
    constexpr T id(){ return LLONG_MIN; };
    constexpr T op(T a,T b){ return std::max(a,b); };
};
using StableSum=Stable<long long, MonoidAdd::id,MonoidAdd::op>;
using StableMin=Stable<long long, MonoidMin::id,MonoidMin::op>;
using StableMax=Stable<long long, MonoidMax::id,MonoidMax::op>;
struct DoubleFenwick {
    int N;
    Vec<long long>T1,T2;
    DoubleFenwick(int N):N(N),T1(N+2),T2(N+2) {}
    void add(Vec<long long>&T,int i,long long x) {
        for (;i<=N;i+=i&-i)T[i]+=x;
    }
    long long query(const Vec<long long>&T,int i) const {
        long long ans=0;
        for (;i>0;i-=i&-i)ans+=T[i];
        return ans;
    }
    void range_add(int l, int r, long long x) {
        add(T1,l,x);
        add(T1,r+1,-x);
        add(T2,l,x*(l-1));
        add(T2,r+1,-x*r);
    }
    long long prefix_sum(int i) const {
        return query(T1,i)*i-query(T2,i);
    }
    long long range_sum(int l,int r) const {
        return prefix_sum(r)-prefix_sum(l-1);
    }
};
template <class T,auto id,auto op>
struct RSegtree {
    Vec<T>tree;
    int N;
    RSegtree(int N):tree(N*4,id()),N(N) {}
    void update(int pos,const T&a){
        update(1,1,N,pos,a);
    }
    void update(int v, int tl, int tr, int pos, const T&a) {
        if(tl==tr){
            tree[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            tree[v]=op(tree[v*2],tree[v*2+1]);
        }
    }
    
    T query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return tree[v];
        } else {
            int tm=(tl+tr)/2;T ans=id();
            if (ql<=tm)ans=op(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=op(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
    T query(int l,int r){
        r=std::min(r,N);
        l=std::max(l,1);
        if(r<l)return id();
        return query(1,1,N,l,r);
    }
};
template<class T,auto id,auto op>
struct ISegtree {
    int n;
    Vec<T>t;
    ISegtree(int N):n(N),t(2*N,id()){}
    T& operator[](int i) {return t[n + i];}
    void build(){
        for(int i=n-1;i;--i)t[i]=op(t[i<<1],t[i<<1|1]);
    }
    void update(int p,T x) {
        for(t[p+=n]=x;p>>=1;)t[p]=op(t[p<<1],t[p<<1|1]);
    }
    T query(int l,int r)const{
        l++,r+=2;
        if(r<l)return id();
        T L=id(),R=id();
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)L=op(L,t[l++]);
            if(r&1)R=op(t[--r],R);
        }
        return op(L,R);
    }
};

using SegtreeSum=ISegtree<long long, MonoidAdd::id,MonoidAdd::op>;
using SegtreeMin=ISegtree<long long, MonoidMin::id,MonoidMin::op>;
using SegtreeMax=ISegtree<long long, MonoidMax::id,MonoidMax::op>;
struct LazySegTree {
    using ll = long long;

    struct Node {
        ll sum = 0;
        ll mn = LLONG_MAX;
        ll mx = LLONG_MIN;
    };

    struct Tag {
        bool has_set = false;
        ll set = 0;
        ll add = 0;
    };

    int n;
    Vec<Node> t;
    Vec<Tag> lazy;

    LazySegTree(int n)
        : n(n), t(4 * n + 5), lazy(4 * n + 5) {}

    LazySegTree(const Vec<ll>& a)
        : LazySegTree((int)a.size() - 1) {
        build(1, 1, n, a);
    }

    static Node merge(const Node& a, const Node& b) {
        return {
            a.sum + b.sum,
            min(a.mn, b.mn),
            max(a.mx, b.mx)
        };
    }

    void add(int l, int r, ll x) {
        add(1, 1, n, l, r, x);
    }

    void set(int l, int r, ll x) {
        set(1, 1, n, l, r, x);
    }

    Node query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    ll sum(int l, int r) {
        return query(l, r).sum;
    }

    ll min(int l, int r) {
        return query(l, r).mn;
    }

    ll max(int l, int r) {
        return query(l, r).mx;
    }
private:
    void build(int v, int l, int r, const Vec<ll>& a) {
        if (l == r) {
            t[v] = {a[l], a[l], a[l]};
            return;
        }

        int m = (l + r) >> 1;
        build(v << 1, l, m, a);
        build(v << 1 | 1, m + 1, r, a);
        pull(v);
    }

    void pull(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void apply_set(int v, int l, int r, ll x) {
        t[v].sum = x * (r - l + 1);
        t[v].mn = t[v].mx = x;

        lazy[v].has_set = true;
        lazy[v].set = x;
        lazy[v].add = 0;
    }

    void apply_add(int v, int l, int r, ll x) {
        t[v].sum += x * (r - l + 1);
        t[v].mn += x;
        t[v].mx += x;

        lazy[v].add += x;
    }

    void push(int v, int l, int r) {
        if (l == r) return;

        int m = (l + r) >> 1;

        if (lazy[v].has_set) {
            apply_set(v << 1, l, m, lazy[v].set);
            apply_set(v << 1 | 1, m + 1, r, lazy[v].set);

            lazy[v].has_set = false;
        }

        if (lazy[v].add) {
            apply_add(v << 1, l, m, lazy[v].add);
            apply_add(v << 1 | 1, m + 1, r, lazy[v].add);

            lazy[v].add = 0;
        }
    }

    void add(int v, int l, int r, int ql, int qr, ll x) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply_add(v, l, r, x);
            return;
        }

        push(v, l, r);

        int m = (l + r) >> 1;
        add(v << 1, l, m, ql, qr, x);
        add(v << 1 | 1, m + 1, r, ql, qr, x);

        pull(v);
    }

    void set(int v, int l, int r, int ql, int qr, ll x) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply_set(v, l, r, x);
            return;
        }

        push(v, l, r);

        int m = (l + r) >> 1;
        set(v << 1, l, m, ql, qr, x);
        set(v << 1 | 1, m + 1, r, ql, qr, x);

        pull(v);
    }

    Node query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return {};

        if (ql <= l && r <= qr)
            return t[v];

        push(v, l, r);

        int m = (l + r) >> 1;

        return merge(
            query(v << 1, l, m, ql, qr),
            query(v << 1 | 1, m + 1, r, ql, qr)
        );
    }
};
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define ROF(i,a,b) for(int i=(int)(b);i>=(int)(b);i--)
#endif

// int main() {
//     int N;read(N);
//     Vec<Vec<int>>A(N+1,Vec<int>(N+1));
//     read(A);
//     write(A);
//     SegtreeSum st(100);
//     write(st.query(1,5));
// }
