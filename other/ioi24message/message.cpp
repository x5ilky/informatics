#include "message.h"
#include <bits/stdc++.h>
using namespace std;

void send_message(std::vector<bool> M, std::vector<bool> C) {
    // printf("GOOD OR NOT\n");
    // for(int i=0;i<31;i++){
    //     printf("%d ",(int)C[i]);
    // }
    // printf("GOOD OR NOT\n");
    vector<vector<bool>>P(16);
    vector<int>Ci;for(int i=0;i<31;i++)if(!C[i])Ci.push_back(i);
    for(int i=0;i<16;i++){
        int dist=i==15?Ci[0]+31-Ci[i]:Ci[i+1]-Ci[i];
        for(int j=0;j<dist-1;j++)P[i].push_back(0);
        // printf("dist %d = %d\n",i,dist);
        P[i].push_back(1);
    }
    M.push_back(1);
    int N=M.size();
    int col=0;
    for(int i=0;i<N;i++){
        if(P[col].size()>=66)col++;
        P[col].push_back(M[i]);
    }
    for(int i=0;i<66;i++){
        vector<bool>p(31);
        for(int j=0;j<16;j++)if(P[j].size()>i)p[Ci[j]]=P[j][i];
        send_packet(p);
    }
}

std::vector<bool> receive_message(std::vector<std::vector<bool>> R) {
    vector<vector<bool>>P(31);
    int N=R.size();
    for(int i=0;i<N;i++)for(int j=0;j<31;j++)P[j].push_back(R[i][j]);
    // for(int j=0;j<N;j++){
    //     for(int i=0;i<31;i++){
    //         printf("%d ",(int)R[j][i]);
    //     }
    //     printf("\n");
    // }
    vector<int>offset(31);
    for(int i=0;i<31;i++){
        int j=0;while(P[i][j]!=1)j++;j++;
        offset[i]=j;
    }
    auto check=[&](int u)->vector<bool>{
        vector<bool>seen(31);
        int k=u;int c=0,m=100;
        while(!seen[k]){
            seen[k]=true;
            m=min(m,k);
            k=(k+offset[k])%31;
            c++;
        }
        return c==16?seen:vector<bool>{};
    };
    vector<bool>good;
    for(int i=0;i<31;i++){
        if(check(i).size()){
            good=check(i);
            break;
        }
    }
    vector<bool>O;
    for(int i=0;i<31;i++){
        if(!good[i])continue;
        int j=offset[i];
        while(j<P[i].size())O.push_back(P[i][j++]);
    }
    while(O.back()==0)O.pop_back();
    O.pop_back();
    return O;
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏和労汎允允允汎労李奏陽覇覇覇覇覇|
// |陽奏李汎山火丁ミミ丁ビせ允労耗陽覇覇覇覇|
// |労汎火ミㇵ一シビ火せせ火火汎李群慶慶義義|
// |ビミ一ㇸㇵヘミビせ允火火山せ洪耗耗和和和|
// |一　　ㇸ　・　ㇸヘビ山允汎允汎汎允允允允|
// |・・ㇵ丁ㇸヘ　一シミミミ丁ビせビ丁ミシミ|
// |ㇵ一　一ヘㇸ一ㇵ・　　　・一シヘㇸ　　・|
// |火火ビヘヘ　ㇸ・一　・・　・ㇸ・一ㇵㇸ一|
// |洪労汎ビㇸ・ㇵ　ㇵミ丁丁ミヘㇸㇸ　ヘシミ|
// |群李せヘ　・ㇵ丁せ允汎允せ火ミㇸ一一ビシ|
// |耗允ミㇸ・ミ山洪允火丁シㇵㇵㇵ一一一ビミ|
// |李山ヘ・ミ允允火シ一　ㇸ一ㇵ一ㇸ一一ミシ|
// |山ビㇵㇸ丁允ビㇵ　ㇵミビ火火火ビシ一　一|
// |シㇵㇸ・丁丁シ・ㇵ丁せ汎洪労労洪允せミ一|
// |・ㇸ　一・　ㇸ　シせ汎李奏耗労允火ビ丁ビ|
// |シ　・一ヘミシㇵ丁允李群群李允ビヘ一一ㇸ|
// |ㇸヘヘビ山允山火せ労群義和允ビ一・ㇸ・ヘ|
// |ㇵミ山洪和和労允労群義耗允丁ㇸㇵ一一ㇵ火|
// |ミ允和陽義陽和労群慶耗汎丁・シ・・ヘせ允|
// |せ李陽覇覇義和耗慶陽労せㇵ一　　ヘ火洪允|
// +----------------------------------------+
// 2026 (July 24th) 18:17:59
// end signature
