#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;cin>>Q;
    using uint=uint64_t;
    auto pow=[&](uint a,uint e,uint mod){
        uint out=0,m=a;
        while(e){
            if(e&1)(out+=m)%=mod;
            (m*=m)%=mod;
            e<<=1;
        }
        return out;
    };
    while(Q--){
        uint A,B;cin>>A>>B;
        uint ord=1;
        for(int k=1;k<=64;k++){
            if(pow(A,ord,1<<k)!=pow(A,ord*2,1<<k))ord*=2;
        }
    }
}
