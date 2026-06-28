#include <bits/stdc++.h>
using namespace std;
#define int long long
// CONSTANT optimising
// struct node {
//     int sum=0,a=0,b=0;
// };
// struct segtree {
//     vector<node>T;int N;
//     segtree(int N):N(N),T(4*N){}
//     int si(int l,int r){
//         return 1LL*(l+r)*(r-l+1)/2;
//     }
//     void apply(int v,int l,int r,int a,int b){
//         T[v].sum+=a*si(l,r)+b*(r-l+1);
//         T[v].a+=a;
//         T[v].b+=b;
//     }
//     void push(int v,int l,int r){
//         if(!T[v].a&&!T[v].b) return;
//         int m=(l+r)/2;
//         apply(v*2,l,m,T[v].a,T[v].b);
//         apply(v*2+1,m+1,r,T[v].a,T[v].b);
//         T[v].a=T[v].b=0;
//     }
//     void range_affine(int v,int l,int r,int ql,int qr,int a,int b){
//         if(qr<l||r<ql) return;
//         if(ql<=l&&r<=qr) return apply(v,l,r,a,b);
//         push(v,l,r);
//         int m=(l+r)/2;
//         range_affine(v*2,l,m,ql,qr,a,b);
//         range_affine(v*2+1,m+1,r,ql,qr,a,b);
//         T[v].sum=T[v*2].sum+T[v*2+1].sum;
//     }
//
//     int query_sum(int v,int l,int r,int ql,int qr){
//         if(qr<l||r<ql) return 0;
//         if(ql<=l&&r<=qr) return T[v].sum;
//         push(v,l,r);
//         int m=(l+r)/2;
//         return query_sum(v*2,l,m,ql,qr)+query_sum(v*2+1,m+1,r,ql,qr);
//     }
// };


// chat gpt affine fenwick
using ll=long long;

struct fenwick {
    int N;
    vector<ll>T;

    fenwick(int N):N(N),T(N+2){}

    void add(int i,ll x){
        for(;i<=N;i+=i&-i) T[i]+=x;
    }

    ll query(int i) const {
        ll ans=0;
        for(;i>0;i-=i&-i) ans+=T[i];
        return ans;
    }
};

struct segtree {
    int N;
    fenwick A,B,C;

    segtree(int N):N(N),A(N+1),B(N+1),C(N+1){}

    static ll tri(ll x){
        return x*(x+1)/2;
    }

    void event(int p,ll a,ll b,ll c){
        if(p>N) return;
        A.add(p,a);
        B.add(p,b);
        C.add(p,c);
    }

    // x[i] += a*i+b for l <= i <= r
    void range_affine(int l,int r,ll a,ll b){
        event(
            l,
            a,
            b,
            -a*tri(l-1)-b*(l-1)
        );

        event(
            r+1,
            -a,
            -b,
            a*tri(r)+b*r
        );
    }

    ll prefix_sum(int x) const {
        if(x<=0) return 0;

        ll a=A.query(x);
        ll b=B.query(x);
        ll c=C.query(x);

        return a*tri(x)+b*x+c;
    }

    ll query_sum(int l,int r) const {
        return prefix_sum(r)-prefix_sum(l-1);
    }
};
void solve() {
    int N,Q;cin>>N>>Q;
    const int K=__lg(N)+1;
    vector<vector<segtree>>S(K);
    for(int i=0;i<K;i++){
        for(int j=0;j<(1<<i);j++){
            S[i].push_back(segtree((N+(1<<i)-1)/(1<<i)));
        }
    }
    for(int q=1;q<=Q;q++){
        int l,r;cin>>l>>r;
        for(int i=0;i<K;i++){
            int c=(r-l+1)>>i;
            if(c<=0)continue;
            int rl=l-1+(1<<i);
            int j=rl%(1<<i);
            int L=rl>>i;
            int R=L+c-1;
            auto&seg=S[i][j];
            seg.range_affine(L,R,1,1-L);
        }
    }
    vector<int>A(N+1);
    for(int i=0;i<K;i++){
        for(int j=0;j<(1<<i);j++){
            for(int k=1;k<=S[i][j].N;k++){
                int l=(k<<i)+j;
                if(l>N)break;
                int v=S[i][j].query_sum(k,k);
                A[l]+=v<<max(0ll,i*2-1);
            }
        }
    }
    for(int i=1;i<=N;i++)cout<<A[i]<<" ";
    cout<<endl;
}
signed main() {
    int T;cin>>T;
    while(T--)solve();
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎允汎汎労和奏義覇覇覇覇覇|
// |慶奏李汎山火丁ミミ丁ビせ汎労耗義覇覇覇覇|
// |和汎火ミㇵ一ミビせせせ火火汎李群覇覇覇覇|
// |山ミ一一ミせ汎労李李李洪允せ労奏慶覇覇覇|
// |ミㇸ一丁山労和李労洪労労李労洪李群覇覇覇|
// |ヘ・ヘ火洪洪允せ火火火火せ允洪和李陽覇覇|
// |シ・ㇵ火洪山ビシㇵ一ㇸ一ㇵシ丁せ汎李群慶|
// |シ・ㇵ火山丁ㇵ　ㇸ・　　　・　一ミせ洪耗|
// |ヘㇸヘ山ミㇸ　・ㇵシミミミシヘヘㇵシ火洪|
// |　ㇸビヘ　・シビせ山山山山せビミ火丁丁山|
// |・シㇸ　シ火火丁シヘヘヘミ丁火ミシヘヘシ|
// |・　ㇸ丁ビシㇸ　ㇸ一ㇸ・　一ㇸ　ㇸ一ㇸ　|
// |丁シ・ㇵ一・ヘㇸ　ㇸ一ㇸ　ㇸ　ㇵ一・シミ|
// |洪允ビ一　ヘ　ㇵヘ一・・一一ㇸ・・ヘㇸㇵ|
// |奏耗洪火一一ㇸヘ・一ヘミビ火火ビシ一・ㇸ|
// |群慶耗允ミ・ヘㇸ一ミ火山汎労山丁シ一ㇸㇸ|
// |和耗労せヘㇸ一一丁允労和和汎ビㇵ　ㇵシヘ|
// |汎允火ヘ・　ㇵビ洪耗陽耗汎丁ㇸㇵビせ山火|
// |丁シシㇸ・丁火洪奏覇奏汎丁・シせ労和労允|
// |　ㇸㇸ・シ丁允耗慶陽李せㇵ一火労群群労允|
// +----------------------------------------+
// 2026 (June 28th) 13:48:34
// end signature
