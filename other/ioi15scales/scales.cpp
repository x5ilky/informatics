#include "scales.h"
#include <bits/stdc++.h>
using namespace std;

using split=vector<int>;
vector<vector<int>>perms(720);
using pii=pair<int,int>;
struct op{
    int typ,s[3],t;// 0123 sml>
    int eval(int A){
        array<pii,3>B={{{perms[A][s[0]],0},{perms[A][s[1]],1},{perms[A][s[2]],2}}};
        sort(B.begin(),B.end());
        if(typ==3){
            auto it=lower_bound(B.begin(),B.end(),pii{perms[A][t],t});
            if(it==B.end())return B[0].second;
            return it->second;
        }
        return B[typ].second;
    };
};
struct sol{
    op o;sol*a[3];int v;
};

sol*SS;
void init(int T) {
    if("perm"){
        vector<int>P(6);
        iota(P.begin(),P.end(),1);
        int i=0;
        do{perms[i++]=P;}while(next_permutation(P.begin(),P.end()));
    }
    set<split>bad;
    vector<op>ops{};
    for(int a=0;a<6;a++)
        for(int b=a+1;b<6;b++)
            for(int c=b+1;c<6;c++)
                ops.push_back({0,{a,b,c},-1}),
                ops.push_back({1,{a,b,c},-1}),
                ops.push_back({2,{a,b,c},-1});
    for(int t=0;t<6;t++)
        for(int a=0;a<6;a++)
            for(int b=a+1;b<6;b++)
                for(int c=b+1;c<6;c++)
                    if(a!=t&&b!=t&&c!=t)
                        ops.push_back({3,{a,b,c},t});
    using pbs=pair<bool,sol*>;
    function<pbs(split,int)>find=[&](split A,int amt){
        if(A.size()==0)return pbs(true,nullptr);
        if(A.size()==1)return pbs(true,new sol{{},{},A[0]});
        if(bad.find(A)!=bad.end())return pbs{false,nullptr};
        for(auto op:ops){
            split O[3]{};pbs S[3]{};
            for(auto S:A)O[op.eval(S)].push_back(S);
            for(int i=0;i<3;i++)if(O[i].size()>amt/3)goto skip;
            for(int i=0;i<3;i++)if(!(S[i]=find(O[i],amt/3)).first)goto skip;
            return pbs{true,new sol{op,S[0].second,S[1].second,S[2].second,-1}};
        skip:;
        }
        bad.insert(A);return pbs{false,nullptr};
    };
    vector<int>S(720);iota(S.begin(),S.end(),0);
    SS=find(S,729).second;
}


void orderCoins() {
    sol*s=SS;
    while(s->v==-1){
        int r;
        if(s->o.typ==0)r=getLightest(s->o.s[0]+1,s->o.s[1]+1,s->o.s[2]+1);
        if(s->o.typ==1)r=getMedian(s->o.s[0]+1,s->o.s[1]+1,s->o.s[2]+1);
        if(s->o.typ==2)r=getHeaviest(s->o.s[0]+1,s->o.s[1]+1,s->o.s[2]+1);
        if(s->o.typ==3)r=getNextLightest(s->o.s[0]+1,s->o.s[1]+1,s->o.s[2]+1,s->o.t+1);
        int i;
        if(r==s->o.s[0]+1)i=0;
        if(r==s->o.s[1]+1)i=1;
        if(r==s->o.s[2]+1)i=2;
        s=s->a[i];
    };
    int W[6]{};
    for(int i=0;i<6;i++)W[perms[s->v][i]-1]=i+1;
    answer(W);
}

// begin signature
// +----------------------------------------+
// |覇慶群和労允せ火ビビビ火せ允労和李労洪洪|
// |陽耗労山火ミヘ　一ㇵㇵㇵㇸ　山允せ火ビビ|
// |李允ビヘ・ㇵシミミミミミミシ一シㇵ一ㇸ一|
// |せシ　ヘシシヘㇵ一ㇵㇵヘミ丁ミㇵㇵヘヘㇵ|
// |ミㇸシシㇵヘシ丁シ一　・一ヘ丁ビ火せせ火|
// |ヘㇵシヘミシ火シ・ㇸㇸ・　ㇸ　ㇵ丁山労労|
// |ヘㇵヘ丁ヘビミヘミ丁ビビ丁シ一　　ヘビ汎|
// |一ㇵヘシミビシビ山汎洪洪汎允火ミㇵ・一丁|
// |ㇵヘミ一火ミせ汎李耗耗耗耗和労允ビㇵ・ㇵ|
// |せせ丁丁せ允李李洪汎允汎労耗李汎せシ　ㇵ|
// |李汎火汎和和汎せ火ミ丁火允洪せビシ一　ヘ|
// |奏洪労李李山せ丁火せ火せ火火シヘㇵㇸ　シ|
// |奏労李李汎山丁山洪労労労允ミ　・一シㇸヘ|
// |労李労洪洪山丁汎和群奏和汎丁・シ一ㇸ一シ|
// |せ李労山和允ミせ李陽慶耗汎ビ一一・ミヘ　|
// |洪労洪火洪洪火丁允和群奏洪ビㇸ　ㇸ丁せシ|
// |奏群李山汎李山シせ汎労洪允ミㇸㇸミㇵ火ビ|
// |陽奏洪ビ汎李山丁丁火火汎せㇵ一ビビせせ火|
// |李汎ビ火汎和汎せビ丁火允丁・ヘせ洪李労山|
// |允丁一丁允労和洪汎汎洪允丁ㇸㇵ丁せせ火シ|
// +----------------------------------------+
// 2026 (September 1st) 19:42:17
// end signature
