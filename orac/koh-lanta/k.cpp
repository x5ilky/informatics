#include <bits/stdc++.h>
using namespace std;
struct group {
    int lt,gt;
    int use(int v){
        if(v<lt)return lt;
        if(v>gt)return gt;
        return v;
    }
    group compose(group b){
        if(lt>b.gt) return {b.gt,b.gt};
        if(gt<b.lt) return {b.lt,b.lt};
        return {
            max(lt,b.lt),
            min(gt,b.gt)
        };
    }
    strong_ordering operator<=>(const group&o)const = default;
};
struct repr {
    int p;group g;int s;
    strong_ordering operator<=>(const repr&o)const = default;
};
const int INF=1e9;
const repr NOREPR={-1,{-1,-1},-1};
const group ID={-INF,INF};
using node=array<repr,8>;
const node IDNODE={{
    {-1,ID,-1},
    NOREPR,
    NOREPR,
    NOREPR,
    NOREPR,
    NOREPR,
    NOREPR,
    NOREPR,
}};
struct segtree {
    vector<node>T;int N;
    segtree(int N):T(2*N,IDNODE),N(N){}
    int id(bool p,bool g,bool s){
        return (p<<2)|(g<<1)|s;
    }
    node merge(node a,node b){
        if(a[0]!=NOREPR)return b; // identities
        if(b[0]!=NOREPR)return a; // identities
        node c{};c.fill(NOREPR);
        for(int i=0;i<8;i++){
            if(a[i]==NOREPR)continue;
            for(int j=0;j<8;j++){
                if(b[j]==NOREPR)continue;
                if((i&0b001)&&(j&0b100)){
                    auto [mn,mx]=minmax({a[i].s,b[j].p});
                    c[id(i&0b100,1,j&0b001)]={
                        a[i].p,
                        a[i].g.compose(group{mn,mx}).compose(b[j].g),
                        b[j].s,
                    };
                }
                if(i==0b001&&(~j&(0b100))){
                    c[id(1,j&0b010,j&0b001)]={ a[i].s, b[j].g, b[j].s };
                }
                if(!(i&0b001)&&j==0b100){
                    c[id(i&0b100,i&0b010,1)]={ a[i].p, a[i].g, b[j].p };
                }
                if((~i&0b001)&&(i&0b010)&&(~j&0b100)&&(j&0b010)){
                    c[id(i&0b100,1,j&0b001)]={ a[i].p, a[i].g.compose(b[j].g), b[j].s };
                }
                if(i==0b100&&j==0b001){
                    c[0b101]={ a[i].p, ID, b[j].s };
                }
            }
        }
        return c;
    }
    void update(int v,int x){
        v+=N;
        T[v]=IDNODE;
        if(x!=-1) {
            T[v]=node{
                NOREPR,
                {-1,ID,x},
                NOREPR,
                NOREPR,
                {x,ID,-1},
                NOREPR,
                NOREPR,
                NOREPR,
            };
        }
        for(v>>=1;v;v>>=1)
            T[v]=merge(T[v*2],T[v*2+1]);
    }
    node query(int l,int r){
        node L=IDNODE,R=IDNODE;
        for(l+=N,r+=N;l<r;l>>=1,r>>=1){
            if(l&1)L=merge(L,T[l++]);
            if(r&1)R=merge(T[--r],R);
        }
        return merge(L,R);
    }
};

signed main () {
    int N,Q;cin>>N>>Q;
    map<int,int>A,B;segtree st(1e6+1);
    for(int i=1;i<=N;i++){
        int p;cin>>p;A[p]=i;st.update(p,i);B[i]=p;
    }
    for(int q=1;q<=Q;q++){
        string T;cin>>T;
        if(T=="W"){
            int first=A.begin()->first;
            node v=st.query(first+1,1e6+1);
            cout<<v[0b010].g.use(A[first])<<endl;
        } else if (T=="U"){
            int x,v;cin>>x>>v;
            st.update(B[x],-1);
            st.update(v,x);
            A.erase(B[x]);
            A[v]=x;B[x]=v;
        }
    }
}

// begin signature
// +----------------------------------------+
// |労洪汎允山せ火ビビビ火せ火火せせ山汎洪李|
// |山せ火ビ丁シヘヘヘヘシシシシミ丁ビせ允洪|
// |ミシヘヘ一ㇸㇵシヘ一ㇸ・・ㇸ一ヘミビせ允|
// |ㇸ・　　・ㇸ一・　ㇸ一一一ㇸ　・ㇵシビ山|
// |ㇸㇵ一　　ㇸㇸ　　　シ丁ミシヘ一　一シビ|
// |シヘ・ㇸㇵㇸ　ㇸ一ㇵせせせ火シシヘㇸ・ㇵ|
// |ビヘ・ㇵミㇸ一ヘミ丁允せビミシ一ヘミㇵ・|
// |ビヘㇸシミ一シ丁火せ山山せ火丁ヘ　ㇵ丁シ|
// |ミ一ヘビミシビ山允洪洪洪汎允火シ・ㇸシ丁|
// |ㇵヘビミ丁火允労李和耗和労允ビヘ・ㇸミ丁|
// |ヘ丁せせ山汎李奏群陽陽耗洪山ビシㇸㇵビシ|
// |ビ火汎洪洪和奏義義覇陽耗労允火ミヘシビヘ|
// |ミ火汎李耗耗陽覇陽慶義群和洪允火ミミビヘ|
// |シミせ洪和奏群陽群群慶慶群耗労允ビヘヘシ|
// |シ一ミせ汎労和耗耗和奏群陽群和洪せミ一ヘ|
// |丁ㇵ一ミ火允汎洪労洪労和耗耗和洪山丁ㇵ一|
// |ミシㇸㇵミビせ山山せ允洪洪洪汎允火シヘㇸ|
// |ㇵシ一ㇸヘミ丁丁丁ビ火せ山せ火ビシㇵ　一|
// |　ㇸ一　・一ㇵㇵㇵシミ丁ミミヘ一・ㇸヘ丁|
// |　ㇸ・・ㇸ・・・　ㇸ一一一ㇸ　・ㇵミビヘ|
// +----------------------------------------+
// 2026 (July 14th) 17:27:10
// end signature


