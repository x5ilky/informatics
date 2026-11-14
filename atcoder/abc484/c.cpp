#include "silky/stl.hpp"
using namespace std;
int main() {
    READ(int,N);
    Vec<int>A(N+1),B(N+1);
    read(A,B);
    int l=1,r=N;
    while(l<=N&&A[l]==B[l])l++;
    while(r>=1&&A[r]==B[r])r--;
    if(l>r)return Yes(1);
    bool ok1=A[l]==B[r],ok2=A[r]==B[l];
    FOR(i,l,r-1){
        if(A[i+1]!=B[i])ok1=false;
        if(A[i]!=B[i+1])ok2=false;
    }
    cout<<(ok1||ok2?"Yes":"No")<<"\n";
}
