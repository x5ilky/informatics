#include "silky/stl.hpp"
using namespace std;
int main() {
    int R,C,K;cin>>R>>C>>K;
    Vec<int>A(R+1),B(C+1);
    read(A,B);
    debug() {
        FOR(i,1,R){
            FOR(j,1,C){
                if(A[i]+B[j]<=K)printf(sRED "%3d " sRESET,A[i]+B[j]);
                else printf("%3d " sRESET,A[i]+B[j]);
            }
            cout<<endl;
        }
    }
    dcheck(A);
}
