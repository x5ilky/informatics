#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K,D;cin>>N>>K>>D;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>ps(N+1);
    for(int i=1;i<=N;i++){
        ps[i]=ps[i-1];
        if(ps[i]+A[i]-ps[max(i-K,0ll)]>D)
            ps[i]=ps[max(i-K,0ll)]+D;
        else ps[i]+=A[i];
    }
    cout<<ps[N]<<endl;
}
