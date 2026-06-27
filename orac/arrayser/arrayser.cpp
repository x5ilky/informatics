#include "arrayser.h"
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
void play_arrayser(int N) {
    using pii=pair<double,int>;
    vector<pii>dp(N+1);
    vector<double>dp2(N+1);
    dp[1]={dp2[1]=1,1};
    dp[2]={dp2[2]=1,1};
    auto get=[&](int i){
        return i<1||i>N?0:dp[i].first;
    };
    auto get2=[&](int i){
        return i<1||i>N?0:dp2[i];
    };
    for(int i=3;i<=N;i++){
        pii best={-1,0};
        for(int j=1;j<=i;j++){
            double score=0,cnt=0;
            for(int k=1;k<=i;k++){
                if(k==j-1||k==j||k==j+1)continue;
                cnt++;
                auto [a,b]=minmax({j,k});
                score+=get(a-2)+get(b-a-1)+get(i-b-1);
            }
            best=max(best,{score/cnt+1,j});
        }
        dp[i]=best;
        {
            double score=0,cnt=0;
            for(int k=1;k<=i;k++){
                cnt++;
                score+=get(k-2)+get(i-k-1);
            }
            dp2[i]=score/cnt+1;
        }
    }
    vector<int>A(N+1);
    while(true){
        int c=0,j=-1,s=0;double m=-1;vector<pii>l;
        for(int i=1;i<=N;i++){
            if(A[i]==0)c++;
            else {
                if(c>0)l.push_back({c,s});
                c=0;
                s=i;
            }
        }
        if(c!=0&&dp[c].first>m){
            l.push_back({c,s});
        }
        double sum=0;
        for(auto [len,s]:l)sum+=dp2[len];
        for(auto [len,s]:l){
            // printf("%f %d\n",len,s);
            if(sum-dp2[len]+dp[len].first>m){
                m=sum-dp2[len]+dp[len].first;
                j=dp[len].second+s;
            }
        }
        for(auto d:{-1,0,1})if(1<=d+j&&d+j<=N)A[d+j]=1;
        int k=do_turn(j-1);k++;
        if(k==0)break;
        for(auto d:{-1,0,1})if(1<=d+k&&d+k<=N)A[d+k]=1;
        if(all_of(A.begin()+1,A.end(),[](int a){return a==1;}))break;
    }
    // for(int i=1;i<=N;i++){
    //     printf("no %d = %f\n",i,dp2[i]);
    // }
}

// begin signature
// +----------------------------------------+
// |義群耗労洪允山せせせ山允汎労和耗和李李李|
// |耗李汎山火丁ミシシシミビせ允労洪允允山允|
// |汎せ丁シ一ㇸㇵシ丁丁丁ミ丁せせビ丁丁丁丁|
// |ビシㇸ・ヘ丁火山允山允せ火丁ヘ一ㇸㇸㇸ一|
// |シ・・シビ山丁ミミ丁ビビシ一　ㇸㇵㇵㇵㇸ|
// |ㇵ　一丁山ㇵㇸ一丁火せ丁一　ㇵㇵㇵヘミ丁|
// |ㇸ・　一ㇵ　ㇵビせ允ㇵシㇸㇸ　　・・　一|
// |ミミシ一ㇸ丁汎和・ㇸ一一一・一シミミシㇵ|
// |山山せミ山和労　・ㇵヘシミ丁丁火山山せビ|
// |李労山労李一・ㇵミ火せ火丁せ允洪李労汎せ|
// |耗洪耗洪　　ヘビ允洪洪山火汎和奏群和洪せ|
// |和和洪・ㇸ一ビ允李奏李允汎和奏耗和和洪火|
// |奏労ㇵ　ㇸ一ビ汎和群和汎汎和労洪汎汎汎せ|
// |群李・ㇸ・ㇵ丁せ汎労李和和洪允せ火ビビ火|
// |陽和汎ヘ・ㇵビ山労和奏奏李汎せ丁シㇵㇵㇵ|
// |慶奏洪　　ヘ火汎李奏義奏労山丁ヘ・・ㇸㇸ|
// |義耗洪一ㇸミ山労奏義陽和汎ビヘ　ㇵミ丁ミ|
// |陽和ヘ　シせ洪奏義義耗汎火ヘ　ヘビ山允せ|
// |奏労・ヘ火洪耗義慶奏洪せシ　シせ洪李労山|
// |奏・・ミ山労群覇陽和允ビ一一丁允李耗洪せ|
// +----------------------------------------+
// 2026 (June 27th) 16:34:20
// end signature
