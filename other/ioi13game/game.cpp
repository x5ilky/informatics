#include "game.h"
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll merge(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(a,b);
}
struct segtree{
    struct Y{
        int lc=0,rc=0;
        ll val=0;
        void update_y(int l,int r,int p,ll a){
            if(l==r){
                val=a;
                return;
            }
            int mid=(l+r)/2;
            if(p<=mid){
                if(lc==0)lc=new Y();
                lc->update_y(l,mid,p,a);
            }else{
                if(rc==nullptr)rc=new Y();
                rc->update_y(mid+1,r,p,a);
            }
            ll lv=
                lc==nullptr?0:lc->val;
            ll rv=
                rc==nullptr?0:rc->val;
            val=merge(lv,rv);
        }

        ll query_y(int l,int r,int ql,int qr){
            if(qr<l||r<ql)return 0;
            if(ql<=l&&r<=qr)return val;
            int mid=(l+r)/2;
            ll ans=0;
            if(lc!=nullptr)ans=merge(ans,lc->query_y(l,mid,ql,qr));
            if(rc!=nullptr)ans=merge(ans,rc->query_y(mid+1,r,ql,qr));
            return ans;
        }
    };

    struct X{
        X*lc=nullptr,*rc=nullptr;
        Y*yt=nullptr;

        X(){
            yt=new Y();
        }
        ~X(){
            if(lc)delete lc;
            if(rc)delete rc;
            if(yt)delete yt;
        }

        void update_x(int l,int r,int yl,int yr,int x,int y,ll a){
            if(l==r){
                yt->update_y(yl,yr,y,a);
                return;
            }
            int mid=(l+r)/2;
            if(x<=mid){
                if(lc==nullptr)lc=new X();
                lc->update_x(l,mid,yl,yr,x,y,a);
            }else{
                if(rc==nullptr)rc=new X();
                rc->update_x(mid+1,r,yl,yr,x,y,a);
            }
            ll lv=
                lc==nullptr?0:lc->yt->query_y(yl,yr,y,y);
            ll rv=
                rc==nullptr?0:rc->yt->query_y(yl,yr,y,y);
            yt->update_y(yl,yr,y,merge(lv,rv));
        }

        ll query_x(int l,int r,int yl,int yr,int x1,int x2,int y1,int y2){
            if(x2<l||r<x1)return 0;
            if(x1<=l&&r<=x2)return yt->query_y(yl,yr,y1,y2);

            int mid=(l+r)/2;
            ll ans=0;
            if(lc!=nullptr)ans=merge(ans,lc->query_x(l,mid,yl,yr,x1,x2,y1,y2));
            if(rc!=nullptr)ans=merge(ans,rc->query_x(mid+1,r,yl,yr,x1,x2,y1,y2));
            return ans;
        }
    };

    X*root=nullptr;
    int xl,xr,yl,yr;

    segtree(int xl,int xr,int yl,int yr):xl(xl),xr(xr),yl(yl),yr(yr){
        root=new X();
    }
    ~segtree(){
        delete root;
    }
};

unique_ptr<segtree>st;
void init(int R, int C) {
    st=make_unique<segtree>(1,R,1,C);
}

void update(int P, int Q, ll K) {
    st->root->update_x(st->xl,st->xr,st->yl,st->yr,P+1,Q+1,K);
}

ll calculate(int P, int Q, int U, int V) {
    return st->root->query_x(st->xl,st->xr,st->yl,st->yr,P+1,U+1,Q+1,V+1);
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏和労シビ火火ビミヘ一ㇸ　ミビせ允|
// |義奏李汎丁允洪山せビシㇵ・　　　　一シビ|
// |李汎ミ汎汎せ丁ヘㇵ・ㇸㇵシミミシㇵ・・ヘ|
// |せ山洪せミ一　一　ヘㇵㇸㇸシビせビシ一・|
// |火労せシ・一ミミ　丁火丁ミミㇵビ山せ丁一|
// |允洪火ㇵㇸミせ火ㇵ一ビ汎山丁丁ㇸシシシ丁|
// |せ労火ㇵㇸ丁允洪火ㇵㇸミ火山ビヘ・・ㇸ　|
// |ビ労せヘㇸビ汎耗洪せ一ヘシシミ・ㇵミシ丁|
// |山洪火一ㇵせ労汎允山ㇵヘヘビㇵ一ビ允丁火|
// |和允シ・丁せ山山汎一ㇵㇵ火ヘㇸビ火せシせ|
// |洪ビㇸ・ㇵ丁せ允ㇸㇵㇵ火ミ　ㇸ一ㇵミビ山|
// |允ビミㇵ　ㇵ丁　一ㇸ丁せヘシヘㇵ・・ヘビ|
// |労洪允火シㇸㇵ　一シビ允山山山火丁ヘ・ㇵ|
// |陽群耗労允ビㇵ　ヘビ允洪李和李労洪山ビㇵ|
// |覇覇覇義耗労せシミ山洪耗群耗労允せビビ火|
// |覇覇覇覇慶群労せビ汎和陽群李労山ビミシミ|
// |覇覇覇覇覇義和允山李群義和汎李李洪允山丁|
// |覇覇覇覇覇陽李山李陽義耗汎せ山せ火丁ヘ　|
// |覇覇覇覇覇奏汎労群慶耗汎丁ヘヘㇵㇸ　ㇵ丁|
// |覇覇覇覇陽李允耗慶陽労せㇵ・　ㇵシミミ山|
// +----------------------------------------+
// 2026 (August 2nd) 19:00:48
// end signature
