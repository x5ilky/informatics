#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N,M;cin>>N>>M;
    vector<int>P(N+1),Q(N+1);
    for(int i=1;i<=N;i++)cin>>P[i];
    for(int i=1;i<=N;i++)cin>>Q[i];
    vector dp(M+1,vector(N,vector(N,0)));
    dp[0][0][0]=1;

}
