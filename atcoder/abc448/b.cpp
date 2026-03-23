#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int N,M;cin>>N>>M;
    vector<int>T(M+1);
    for (int i=1;i<=M;i++)cin>>T[i];
    int ans=0;
    for (int i=1;i<=N;i++){
        int A,B;cin>>A>>B;
        int amt=min(B,T[A]);
        T[A]-=amt;
        ans+=amt;
    }
    cout<<ans<<endl;
}
