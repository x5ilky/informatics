#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int R,C,K,H,V;cin>>R>>C>>K>>H>>V;
    vector<int>h(H+2),v(V+2);
    for(int i=1;i<=H;i++)cin>>h[i];
    for(int i=1;i<=V;i++)cin>>v[i];
    h[H+1]=R;v[V+1]=C;
    sort(h.begin()+1,h.end());
    sort(v.begin()+1,v.end());
    int lo=0,hi=R*C;
    const int INF=1e9;
    vector<vector<signed>>dp(H+2,vector<signed>(V+2,INF));
    vector<deque<signed>>dqi(H+2);
    vector<deque<signed>>dqj(V+2);
    auto sim=[&](int mid){
        for(auto&v:dp)fill(v.begin(),v.end(),INF);
        for(auto&v:dqi)v.clear();
        for(auto&v:dqj)v.clear();
        dp[H+1][V+1]=0;
        dqi[H+1].push_back(V+1);
        dqj[V+1].push_back(H+1);
        for(int i=H+1;i>=1;i--){
            for(int j=V+1;j>=1;j--){
                if(i==H+1&&j==V+1)continue;
                int di=h[i]+mid/v[j];
                while(dqj[j].size()&&h[dqj[j].back()]>di)dqj[j].pop_back();
                if(dqj[j].size())dp[i][j]=min(dp[i][j],dp[dqj[j].back()][j]+1);
                int dj=v[j]+mid/h[i];
                while(dqi[i].size()&&v[dqi[i].back()]>dj)dqi[i].pop_back();
                if(dqi[i].size())dp[i][j]=min(dp[i][j],dp[i][dqi[i].back()]+1);
                if(dp[i][j]<INF)dqi[i].push_front(j),dqj[j].push_front(i);
            }
        }
        // for(int i=H+1;i>=1;i--){
        //     for(int j=1;j<=V+1;j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     printf("\n");
        // }
        signed ans=INF;
        for(int i=H+1;i>=1;i--){
            for(int j=V+1;j>=1;j--){
                if(h[i]*v[j]<=mid){
                    ans=min(ans,dp[i][j]);
                    // printf("%d,%d works = %d\n",i,j,dp[i][j]);
                }
            }
        }
        return ans;
    };
    // cout<<sim(18)<<endl;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        // printf("%d needs %d cuts\n",mid,sim(mid));
        if(sim(mid)<=K)hi=mid;
        else lo=mid;
    }
    cout<<hi<<endl;
}

// begin signature
// +----------------------------------------+
// |ヘ一ㇸ・・ㇸ一ㇵヘヘㇵ一ㇸㇸ一ㇵヘシ丁火|
// |　・ㇸ一一ㇸ・　ㇸ　・ㇸㇸㇸ・　・一シ丁|
// |ヘシミミミシㇵㇸ一ㇸ　・・・・ㇸㇸ・ㇵヘ|
// |ビ火せせビシㇵ・・・　　　・一ㇵㇸ　ㇸ・|
// |允汎允火ビ丁シㇵ・一ㇵㇵㇵ一・　一ㇸ　　|
// |洪洪允汎允山火ビシ一ㇸㇸ一ㇵシㇵㇸㇸ一一|
// |李労労李李労洪允火丁ヘ一ㇸ・　一シヘミミ|
// |和李耗奏奏耗和労汎せ丁ミミシヘ一一ㇵシヘ|
// |耗奏陽義義陽群耗労允火火せ火丁シㇸ・ヘㇵ|
// |奏義覇覇覇慶陽耗労允允汎汎山火ミ一・ヘヘ|
// |義覇覇覇覇慶陽耗李李李李労允火シㇸㇸシ一|
// |覇覇覇覇覇慶群和洪和奏耗労允ビヘ・一シ一|
// |慶覇覇覇覇義奏李洪和奏耗労允ビシ・一ミミ|
// |陽慶覇覇覇義奏和洪洪李李洪允火シㇸㇸシビ|
// |和奏陽義義陽奏和洪山允汎允山火ミシヘヘヘ|
// |洪李耗奏奏耗和労汎せビ火火火丁ヘ一・　　|
// |允汎労李李労洪允せビ山允せ丁ヘ・・一ㇵㇵ|
// |山李汎允允允せ火火允洪山丁ヘ　一シ丁丁ミ|
// |李洪せ火ビ丁ミ火允洪山ビヘ　ㇵミ火山せ丁|
// |労允火シヘㇵ丁山洪汎火ミㇸㇸシ火允洪山丁|
// +----------------------------------------+
// 2026 (June 5th) 15:46:49
// end signature





