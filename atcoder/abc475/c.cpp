#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,S,L;cin>>N>>S>>L;
    vector<int>A(N);for(int i=1;i<=N-1;i++)cin>>A[i];
    vector<int>psA(N);for(int i=1;i<=N-1;i++)psA[i]=psA[i-1]+A[i];
    int ans=0;
    for(int i=S;i<=N;i++){
        for(int j=1;j<=S;j++){
            int a=psA[S-1]-psA[j-1];
            int b=psA[i-1]-psA[S-1];
            if(a*2+b<=L||a+b*2<=L)ans=max(ans,i-j+1);
        }
    }
    cout<<ans<<endl;
}
