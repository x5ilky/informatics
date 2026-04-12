#include <bits/stdc++.h>

using namespace std;
#define int long long

// cp-algo
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}


signed main() {
    int N,M,Q;cin>>N>>M>>Q;
    Vertex* str=build(1,M);
    vector<Vertex*>st(N+1);
    for(int i=1;i<=N;i++)st[i]=str;
    for(int i=1;i<=Q;i++){
        int t;cin>>t;
        if(t==1){
            int X,Y;cin>>X>>Y;
            st[X]=st[Y];
        }
        if(t==2){
            int X,Y,Z;cin>>X>>Y>>Z;
            st[X]=update(st[X],1,M,Y,Z);
        }
        if(t==3){
            int X,L,R;cin>>X>>L>>R;
            cout<<get_sum(st[X],1,M,L,R)<<endl;
        }
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎允汎汎労和和李李和耗奏陽|
// |群奏李汎山火丁一ヘシヘㇵ一・せ山山汎労和|
// |洪汎火ミㇵビ山山せビミヘ一ㇸ・シミビ山汎|
// |丁ミㇵ山洪労汎せ火丁ミヘ一・　　・ㇵミせ|
// |・シ洪耗和労洪山ビシヘシミ丁ミシ一ㇸ・シ|
// |ヘせ耗群耗李允山せビミヘㇵミ火允せ丁ㇵㇸ|
// |火允群群奏労李洪山ビミ一一・ㇸミせ汎山丁|
// |汎汎陽陽耗耗李允ビヘ丁火火ビミ一ヘ丁ミミ|
// |李和慶陽群和允ビミせ汎労労洪山丁一・　ヘ|
// |労覇義陽李山ミ丁允李奏群労山ビ丁一ㇵミ　|
// |慶義群李せシ丁汎耗義群奏洪せシビㇸヘ丁　|
// |覇陽李山ミシ山和義義奏労汎せミ丁・シビ　|
// |覇群労火ヘシ允和義義陽李山ミ一丁ㇸヘビㇵ|
// |慶義李允丁一火労群覇陽李せシ　ヘヘㇸビ丁|
// |群覇群労せ丁シ山和義義耗允ミ　ㇸ丁　シ允|
// |耗慶慶奏汎火丁ビ洪群覇奏李山ミㇸミ　シビ|
// |李慶慶群労せ火丁汎耗義耗労火丁ミㇸ・一ㇸ|
// |李覇義群労せミ火汎和群李允火ヘ・ミヘヘシ|
// |奏慶陽群労山ミ丁山洪労労火ㇵヘビ山せ丁一|
// |耗義奏耗和汎火ヘ丁火せ火ビ丁せ火ミㇵシ・|
// +----------------------------------------+
// 2026 (April 11th) 23:05:34
// end signature

