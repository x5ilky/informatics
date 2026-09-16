#include "mushrooms.h"
#include <bits/stdc++.h>
using namespace std;
int count_mushrooms(int N) {
    set<int>C[2]{};int K=100;C[0].insert(0);
    int k=1;
    bool add=(N<=2*K+2)&&N%2==0;
    for(int i=1;i<=2+add&&k<N;i++)C[use_machine({0,k})].insert(k++);
    auto take5=[&](){
        int a0[3]{},a1[2]{};auto it=C[0].begin();
        for(int i=0;i<3;i++)a0[i]=*it++;
        it=C[1].begin();
        for(int i=0;i<2;i++)a1[i]=*it++;
        int v[5]{},b[5]{};
        for(int i=0;i<5;i++)v[i]=k+i;
        int res1=use_machine({v[0],a0[0],v[1],a0[1],v[2],a0[2]});
        b[0]=res1&1;
        int bc=res1>>1;
        if(bc==2||bc==0){
            b[1]=bc>>1,b[2]=bc>>1;
            int res2=use_machine({v[3],a0[0],v[4],a0[1]});
            b[3]=res2&1;
            b[4]=(res2>>1)&1;
        }else{
            int res2=use_machine({a1[0],v[2],a1[1],a0[2],v[1],a0[1],v[3],a0[0],v[4]});
            if(res2>=5){
                b[1]=1;
                b[2]=0;
                res2-=5;
            }else{
                b[1]=0;
                b[2]=1;
                res2--;
            }
            b[4]=res2&1;
            b[3]=(res2>>1)&1;
        }
        for(int i=0;i<5;i++)C[b[i]].insert(i+k);
        k+=5;
    };
    for(int i=1;k<N&&k<2+add+2*K;i++){
        if(C[0].size()>=3&&C[1].size()>=2&&k+5<=N)take5();
        else{
            int p=C[1].size()>=2;
            int x=*C[p].begin(),y=*++C[p].begin();
            int a=k++;int b=k++;
            int r=use_machine({x,a,y,b});
            if(r==3)C[!p].insert(a),C[!p].insert(b);
            if(r==2)C[!p].insert(a),C[p].insert(b);
            if(r==1)C[p].insert(a),C[!p].insert(b);
            if(r==0)C[p].insert(a),C[p].insert(b);
        }
    }
    int cnt[2]{};
    while(k<N){
        vector<int>qry{};
        int p=C[0].size()<C[1].size();
        auto it=C[p].begin();
        int i=0;
        for(;i<C[p].size()&&k<N;i++){
            qry.push_back(*it++);
            qry.push_back(k++);
        }
        int ans=use_machine(qry);
        cnt[!p]+=ans/2;
        cnt[p]+=(i-1)-ans/2;
        C[p^(ans&1)].insert(k-1);
    }
    return cnt[0]+C[0].size();
}

// begin signature
// +----------------------------------------+
// |ミヘ一ㇸㇸ一ㇵヘㇵ一ㇵヘミビせ汎李奏慶覇|
// |　一ㇵヘヘㇵㇸ一ㇵㇵ一・　ㇵミ火汎和群覇|
// |ビ火せ山せ火丁ヘ一・　・ㇸㇵヘ丁山労奏慶|
// |洪李李汎せ丁ヘ・・ヘㇵㇵシ丁丁ビ火洪耗慶|
// |耗和汎ビヘ・ㇸ一　一一一・・ヘビビ山李陽|
// |汎汎山ミヘ・一ㇸヘㇸ　　ㇸヘ一ㇸミ山汎李|
// |ビ丁丁ミシ・ㇸㇵ・一シミシ一・シ　ヘせ汎|
// |一・　　　・・ヘ・ヘヘミ火せミ・ヘ・シ山|
// |ㇵㇸヘ　一・・・　ㇸ一一ヘ火せヘ・ㇵ一火|
// |　ㇸ一丁・・ㇸ・ㇸㇸ・　一シビㇵ一ㇸヘせ|
// |・ミせㇵ一シミミㇵㇸ・　ㇸ一一　ヘㇸビ允|
// |ミ火ヘミ火ビヘㇸ　　　　一　一ㇵ　一シ火|
// |山ミビ山火ヘ　一　ㇸ一一・・　ヘ　・　ヘ|
// |山丁山汎ビ一ㇸㇸヘ丁火火ビミシミ丁シㇵ　|
// |ヘ丁允汎ビ一一一丁山洪労洪汎せ山せビビ丁|
// |一ビ汎洪ビ一・ヘ火洪和群群李允ビシ一ㇸㇸ|
// |シ山李允ミ・・丁汎耗義義和汎ビㇵ　ㇵヘヘ|
// |せ労汎ビ一　シ山和義義耗汎丁ㇸㇵ丁せ山火|
// |洪労火ヘ　ミ火労群慶耗汎丁・シせ洪李労山|
// |李汎丁一ㇵシ允和義陽労せㇵ一火労群陽和允|
// +----------------------------------------+
// 2026 (September 16th) 19:56:56
// end signature
