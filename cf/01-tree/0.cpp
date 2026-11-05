#include "silky/stl.hpp"
using namespace std;
int Tmain() {
    READ(int,N);
    Vec<int>A(N+1);read(A);
    Vec<int>nxt(N+2),prv(N+2);
    FOR(i,1,N)nxt[i]=i+1;
    FOR(i,2,N)prv[i]=i-1;
    prv[1]=N+1;
    A.push_back(1e9);
    set<pii>S;FOR(i,1,N)S.insert({A[i],i});
    int C=N;
    while(S.size()){
        auto[x,i]=*S.rbegin();S.erase(--S.end());
        while(true){
            if(A[nxt[i]]==x+1){
                prv[nxt[nxt[i]]]=i;
                nxt[i]=nxt[nxt[i]];
                C--;
            }
            else if(A[prv[i]]==x+1){
                nxt[prv[prv[i]]]=i;
                prv[i]=prv[prv[i]];
                C--;
            }
            else break;
        }
        // dcheck(S);
        // dcheck(C);
    }
    YES(C==1&&A.min()==0);
}
