#include "silky/stl.hpp"
using namespace std;
int Tmain() {
    READ(int,N,M,A,B);
    Vec<int>C(M+1);read(C);
    C.sort();
    int lo=0,hi=M+1;
    if(B<A){
        A=N-A+1;
        B=N-B+1;
    }
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        dcheck(mid);
        if(B-A<=mid){
            hi=mid;
            continue;
        }
        int s=0;
        int j=1;
        ROF(i,mid,1)s=max(s,C[i]+j++);
        dcheck(s);
        dcheck(B-mid-1);
        if(s<=B-1)lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
    return 0;
}
