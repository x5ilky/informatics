#include <bits/stdc++.h>
#include <atcoder/all>
#include "silky/stl.hpp"
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N;cin>>N;
    SegtreeSum st(N+1);
    Vec<int>A(N+1),l(N+1);read(A);
    A.push_back(1e9);
    Vec<int>stk={N+1};
    ROF(i,N,1){
        while(A[i]>A[stk.back()])l[stk.back()]=i,stk.pop_back();
        stk.push_back(i);
    }
    Vec<mint>dp(N+1,1);
    FOR(i,2,N){
        dp[i]=dp[i-1]*(i-max(l[i],1));
    }
    cout<<dp[N].val()<<endl;
}
