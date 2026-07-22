#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;
using mint=atcoder::modint;
int main() {
    int N,M;cin>>N>>M;
    vector<int>A(N+1),B(N);
    for(int i=1;i<=N;i++){
        int v;cin>>v;A[i]=v;
    }
    for(int i=1;i<=N-1;i++){
        int v;cin>>v;B[i]=v;
    }
    vector<int>C(N);
    for(int i=1;i<=N-1;i++)C[i]=((B[i]-(A[i+1]-A[i]))%M+M)%M;

}
