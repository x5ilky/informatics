#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int ll
const int INF=1ull<<60;
signed main(){
    READ(int,N,M,Q);
    Graph<0>g(N);
    Vec<uvw>E(M+1);
    FOR(i,1,M){
        READ(int,u,v,w);
        E[i]={u,v,w};
        g(u,v,w);
    }
    Vec<int>d(N+1,INF),ds(M+1,INF),de(M+1,INF);
    {
        PQGT<pii>pq;
        d[1]=0;pq.push({1,0});
        while(pq.size()){
        }
    }
}
