#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int main() {
    using uint=unsigned int;
    int N;cin>>N;
    vector<int>A(N+1);
    int sm=0;
    for (int i=1;i<=N;i++){
        cin>>A[i];sm+=A[i];
    }
    if(sm%N!=0) return cout<<-1<<endl,0;
    for (int i=1;i<=N;i++){
        A[i]-=sm/N;
    }
    struct node {
        long long ops,v;int prev,merge;
        bool operator<(const node& other) const {
            return ops<other.ops;
        }
    };
    vector<node>dp(1<<N,{1000000,1000000,-1,false});
    for(int i=0;i<N;i++){
        dp[1<<i]={0,A[i+1],-1};
    }
    for(uint m=1;m<(1<<N);m++){
        if(__popcount(m)<=1){
            continue;
        }
        for (int sub=m;;sub=(sub-1)&m) {
            if(sub==m)continue;
            int inv=(~sub)&m;
            if(dp[sub].v<0&&dp[inv].v<0)continue;
            node v={dp[sub].ops+dp[inv].ops+1,dp[sub].v+dp[inv].v,sub,false};
            if(dp[sub].v==0||dp[inv].v==0)
                v={dp[sub].ops+dp[inv].ops,dp[sub].v+dp[inv].v,sub,true};
            dp[m]=min(dp[m],v);
            if (sub==0) break;
        }
    }
    cout<<dp[(1<<N)-1].ops<<endl;
    function<int(uint)> recon=[&](uint v){
        if(__popcount(v)==1){
            return __countr_zero(v)+1;
        }
        int l=recon(dp[v].prev),r=recon((~dp[v].prev)&v);
        if(A[r]>A[l])swap(l,r);
        if(!dp[v].merge) {
            cout<<l<<" "<<r<<" "<<A[l]<<endl;
            A[r]+=A[l];
            A[l]=0;
        } else {
            if(A[r]==0)return l;
            if(A[l]==0)return r;
        }
        return r;
    };
    recon((1<<N)-1);
}

// begin signature
// +----------------------------------------+
// |覇覇陽耗李洪汎允・一一一・火せ允允汎労李|
// |義耗労汎せㇸ丁火火ビ丁シㇵ一・　丁ビせ汎|
// |李允火ヘせ汎汎せㇸヘ　・ㇸ　　　　ㇵミビ|
// |せ・せ労汎シ一ㇵ・・ㇵヘシミヘㇸ　　ㇸ一|
// |　山労一　ヘㇸㇸ　ㇸㇸ　　ㇸヘ丁ㇵ　一　|
// |ヘ労允丁ヘ　一・ヘ　一シミミミ丁ミミ・ヘ|
// |シ労ㇵ一一　　一ㇵㇸミミ丁ビせ允允山ビㇵ|
// |せ李火ミ一ㇸ・ヘㇸ・　　・ㇸㇵミ火允汎火|
// |労李洪山ミ　・ヘ一ヘシミシヘㇸ　ㇵ丁火火|
// |陽群李山シ・ヘ丁火山允山山火丁ㇵ　ㇵ一一|
// |慶耗汎丁ヘビ山洪李和和李労汎せミㇸㇵㇵ一|
// |和洪火ミせ洪和李労洪労和奏李汎火ビ火火ビ|
// |允せミ火洪李汎山火せ山允労允火山洪労労洪|
// |丁ミヘせ労洪せ丁せ洪李李労山せ洪允允允汎|
// |　ヘ一火洪洪火ミ山李奏陽李山せせビミミ丁|
// |ミ一ㇸ丁汎労火ミ允和陽陽和山火丁ㇵ・　　|
// |せㇵ一ビ洪汎ビ丁汎耗慶陽李せミㇸㇸシミミ|
// |丁ㇵシ山李山シせ労群陽和允ミ　ヘ火山允せ|
// |ヘㇸビ汎洪火ミ允李群和允ミ　シ山労和李允|
// |ㇵ一ビ汎労せシせ洪和労火ㇵ一火洪奏義和山|
// +----------------------------------------+
// 2026 (April 1st) 16:12:56
// end signature









