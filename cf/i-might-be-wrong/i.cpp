#include "silky/stl.hpp"
using namespace std;
int Tmain() {
    READ(int,N);
    READ(string,S);
    S.insert(S.begin(),'0');
    if(count(S.begin()+1,S.end(),'1')>N/2){
        string T(N+1,'0');
        for(int i=1;i<=N;i++)T[i]=S[N+1-i]^1;
        S=T;
    }
    Vec<int>A(N+1),cs(N+1),last(2*N+1);
    FOR(i,1,N){
        A[i]=A[i-1]+(S[i]=='0'?-1:1);
        cs[i]=cs[i-1]+(S[i]=='1');
        last[N+A[i]]=i;
    }
    if(is_sorted(S.begin()+1,S.end())){
        write(0);return 0;
    }
    int k=0,ans=0;
    while(k<N&&S[k+1]=='0')k++;
    while(true){
        ans++;
        if(k>=-A[N])break;
        int r=last[N-k];
        k=r-cs[r];
    }
    write(ans);
    return 0;
}
