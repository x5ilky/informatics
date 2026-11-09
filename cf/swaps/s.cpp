#include "silky/stl.hpp"
using namespace std;
int Tmain() {
    int N;cin>>N;
    Vec<int>A(N+1),B(N+1);
    read(A,B);
    Vec<int>p(2*N+1,1e9);
    FOR(i,1,N)p[A[i]]=i-1;
    FOR(i,1,2*N)p[i]=min(p[i],p[i-1]);
    int ans=1e9;
    FOR(j,1,N)chmin(ans,j-1+p[B[j]-1]);
    write(ans);
    return 0;
}
