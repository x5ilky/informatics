#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,W;cin>>N>>W;
    vector<int>A(N+1),psA(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    int ans=0;
    for(int i=W;i<=N;i++)ans=max(ans,psA[i]-psA[i-W]);
    cout<<ans<<endl;
}
