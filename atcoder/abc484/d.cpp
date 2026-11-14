#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    READ(int,N);
    Vec<int>A(N+1);read(A);
    map<int,int>freq,seen;
    int ans=0;
    int i=1;
    while(i<=N){
        int a=A[i];
        ans+=i-1-freq[A[i]];
        while(A[i]==a){
            freq[a]++;
            i++;
        }
    }
    cout<<ans+1<<endl;
}
// 1 4 4 1 4 2 1
