#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int N;cin>>N;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];

    const int FACTOR=1e7;
    int hi=FACTOR*FACTOR,lo=-FACTOR*FACTOR;
    for(int i=1;i<=N-1;i++){
        int intc=(B[i+1]-B[i])*FACTOR/(A[i]-A[i+1]);
        if(A[i]>A[i+1]){
            lo=max(lo,intc);
        } else {
            hi=min(hi,intc);
        }
    }
    if(hi>lo)cout<<"YES\n";
    else cout<<"NO\n";
}
