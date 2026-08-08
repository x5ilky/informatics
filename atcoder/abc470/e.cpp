#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ld=long double;
int main() {
    int N,L;cin>>N>>L;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    ld mean=0;for(int i=1;i<=N;i++)mean+=A[i];
    mean/=N;
    vector dp(N+1,vector(N+1,vector<ld>(L+1)));
    for(int l=1;l<=L;l++){
        for(int n=1;n<=N;n++){
            for(int rem=0;rem<=n;rem++){
            }
        }
    }
}
