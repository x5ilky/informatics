#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
// cp-algo
struct Vertex {
    Vertex *l, *r;
    int mn;
 
    Vertex(int val) : l(nullptr), r(nullptr), mn(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), mn(1048576) {
        if (l) mn = min(mn,l->mn);
        if (r) mn = min(mn,r->mn);
    }
};
 
Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(1048576);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}
 
int get_min(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1048576;
    if (l == tl && tr == r)
        return v->mn;
    int tm = (tl + tr) / 2;
    return min(get_min(v->l, tl, tm, l, min(r, tm)),
          get_min(v->r, tm+1, tr, max(l, tm+1), r));
}
 
Vertex* update(Vertex* v, int tl, int tr, int pos, int val) {
    if (tl == tr)
        return new Vertex(val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, val));
}
 
 
signed main() {
    int Q;cin>>Q;
    vector<Vertex*>ver(Q+1);
    ver[1]=build(0,262144);
    int V=1,r=0;
    for(int i=1;i<=Q;i++){
        string t;cin>>t;
        int v,a,b;cin>>v>>a>>b;
        if(t=="u"){
            ver[V+1]=update(ver[v-r],0,262144,a,b);
            V++;
        }
        if(t=="q"){
            int ans=get_min(ver[v-r],0,262144,a,b);
            cout<<ans<<endl;
            r+=ans;
        }
    }
}
 
// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎允允允汎労和耗和和耗奏群義|
// |陽奏李汎山火丁ミㇸ一一ㇸ・允允允汎洪李耗|
// |労汎火ミㇵシ火せ火ビミヘㇵㇸ　ミビせ允労|
// |火ミ一ビ允洪洪山ビ丁シㇵ一・　　一シビ山|
// |一ㇸ山李耗洪汎允せ丁ヘㇵヘシヘㇵ・　一ミ|
// |ㇵビ李群李和汎火火丁ミヘシビ山せビシヘ　|
// |ビせ耗群奏李洪汎山火丁シ丁ビ火ビ山汎せミ|
// |允洪群群奏和李洪せミミせ允洪洪洪汎允火ビ|
// |李李慶陽奏耗洪火シビ山労和奏群和労洪汎山|
// |洪慶義陽和汎ビミ山労和群陽耗洪山火丁丁ビ|
// |義義陽和允丁ビ允和陽慶群労山丁丁ㇸ　・丁|
// |覇義和允火ミ山和陽覇群労山ビㇵ丁　ヘヘ火|
// |覇陽労せ丁シ山和義慶耗和汎火シ丁ㇸヘミㇸ|
// |慶義和山丁一火労群覇陽和允丁ㇸヘヘㇸビ丁|
// |奏覇群労せミシ山和義慶耗汎丁・・丁・シミ|
// |耗慶慶耗汎せミ火洪群覇奏李せシ・丁・ヘ　|
// |和慶義奏洪火せビ洪奏慶奏洪山ビヘㇵㇸヘㇵ|
// |和覇陽奏洪火丁火洪耗陽耗汎ビシ・ヘ一一ㇵ|
// |群義群奏洪火ヘ火汎李奏耗汎ビヘ丁火火ビヘ|
// |奏義群和李允丁ミ火汎李耗労山火せビシヘヘ|
// +----------------------------------------+
// 2026 (April 23rd) 21:52:54
// end signature

 
