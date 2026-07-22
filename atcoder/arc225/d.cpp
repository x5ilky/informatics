#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int ans=0;
    for(int i=1;i<=N;i++){
        ans+=abs(i-A[i]);
    }
    cout<<(ans/2)<<endl;
}
