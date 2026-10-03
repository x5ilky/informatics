#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    Vec<int>A(N+1);read(A);
    Vec<int>pf(N+1),sf(N+2);
    pf[0]=pf[1]=true;
    sf[N+1]=sf[N]=true;
    FOR(i,2,N)pf[i]=pf[i-1]&(A[i]>=A[i-1]);
    ROF(i,N-1,1)sf[i]=sf[i+1]&(A[i]<=A[i+1]);
    StableMin mn(A);
    StableMax mx(A);
    bool good=false;
    FOR(i,1,N-K+1){
        good|=pf[i-1]&&sf[i+K]&&(i==1?-10:mx.query_min(1,i-1))<=mn.query_min(i,i+K-1)&&mx.query_min(i,i+K-1)<=(i==N-K+1?1e9:mn.query_min(i+K,N));
    }
    cout<<(good?"Yes\n":"No\n");
}
