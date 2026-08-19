#include "friend.h"
#include <bits/stdc++.h>
using namespace std;
// Find out best sample
int findSample(int N,int confidence[],int host[],int protocol[]){
    struct node {
        int type;// 0 par 1 add 2 or 3 val
        int v;
        node*l,*r;
    };
    vector<node*>nd(N,nullptr);nd[0]=new node{3,confidence[0],nullptr,nullptr};;
    node*rt=nd[0];
    for(int i=1;i<N;i++){
        node*nn=new node(*nd[host[i]]);
        node*nv=new node{3,confidence[i],nullptr,nullptr};
        *nd[host[i]]=node{protocol[i],0,nn,nv};
        if(rt==nd[0])rt=nd[host[i]];
        nd[host[i]]=nn;
        nd[i]=nv;
    }
    using pii=array<int,2>;// ndp,dp
    function<pii(pii)>fix=[&](pii v)->pii{
        return {v[0],max(v[0],v[1])};
    };
    function<pii(node*)>solve=[&](node*n)->pii{
        if(n->type==3)return {0,n->v};
        pii l=solve(n->l),r=solve(n->r);
        if(n->type==0)return fix({l[0]+r[1],r[0]+l[1]});
        if(n->type==1)return fix({l[0]+r[0],l[1]+r[1]});
        if(n->type==2)return fix({l[0]+r[0],max(l[1]+r[0],r[1]+l[0])});
        assert(0);
    };
    pii ans=solve(rt);
    return max(ans[0],ans[1]);
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏和労汎允允允汎労李奏陽覇覇覇覇覇|
// |義奏李汎山火丁ミミ丁ビせ允労耗群義覇覇覇|
// |李汎火ミㇵ一シ丁火火火ビ火允洪李奏義覇覇|
// |せミ一ㇸミミシシミビせせせせ山汎和群覇覇|
// |ミㇸㇸ一・ヘ丁火ビ丁ビビせ山允山汎和陽覇|
// |ヘ・ㇸ　ㇵシシㇵㇸ・・ㇸㇵシ丁せ允允李陽|
// |シ・　・一ヘ・・ㇵヘシシヘ一　一ミせせ労|
// |シ・一・シ・一ミビせ山山山火丁ヘ　ㇵ丁山|
// |ㇵㇸ・シ　ㇵビ山洪労李和李労允火ミㇸㇵビ|
// |　・ヘ　シせ洪和耗李李和耗奏李汎ビㇵ・丁|
// |・ㇵㇸ丁允李李汎山山山汎労李允ビミヘㇸ丁|
// |・ㇸ丁汎和洪せ丁シヘミ火允せシㇵ・・ㇸ丁|
// |　ㇵ火労労せシ・シ火允允允山山火丁ヘ・一|
// |・ミせ洪労せヘ　ミ山労耗李和和労洪山ビㇵ|
// |ㇸ丁允洪和允ミㇵミ山李陽群耗労允火ビ丁ビ|
// |一ビ汎洪洪洪ビシビ汎和陽群李允ビヘ一・ㇸ|
// |シ山李允洪労火シ山李陽義和允丁一・ヘシヘ|
// |火労洪火労洪火せ李陽義和允丁・ㇵビ山山火|
// |洪労火せ労労せ労群慶耗汎丁・シせ労和労允|
// |李汎せ火汎和洪耗慶陽労せㇵ一火労群義和允|
// +----------------------------------------+
// 2026 (August 19th) 20:15:28
// end signature
