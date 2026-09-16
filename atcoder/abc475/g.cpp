#include <bits/stdc++.h>
using namespace std;
using ld=long double;
#define int long long
signed main() {
    int T;cin>>T;
    vector<bool> is_prime(100+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 100; i++) {
        if (is_prime[i] && (long long)i * i <= 100) {
            for (int j = i * i; j <= 100; j += i)
                is_prime[j] = false;
        }
    }
    vector<int>primes={1};
    for(int i=2;i<=100;i++)if(is_prime[i])primes.push_back(i);
    while(T--){
        int N,D;cin>>N>>D;
        int di=find(primes.begin(),primes.end(),D)-primes.begin();
        vector<map<int,int>>dp(23);
        dp[0][1]=0;
        for(int i=1;i<=22;i++){
            if(i==di)continue;
            for(auto [k,v]:dp[i-1]){
                int acc=1;
                for(int j=0;j<=60;j++){
                    if(acc>N)break;
                    if(k*acc<=N)dp[i][k*acc]=v+j;
                    acc*=primes[i];
                }
            }
        }
        pair<int,int>ans={0,0};
        for(auto [k,v]:dp[22])ans=max(ans,{v,k});
        cout<<ans.second<<endl;
    }
}
