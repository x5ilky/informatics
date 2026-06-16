#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    const int INF=1ull<<60;
    vector<int>A(N+1),psA(N+1),pmn(N+2,INF),smn(N+2,INF);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)A[i]=-A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    for(int i=1;i<=N;i++)pmn[i]=min(pmn[i-1],psA[i]);
    for(int i=N;i>=1;i--)smn[i]=min(smn[i+1],psA[i]);
    for(int i=1;i<=N;i++){
        // +2 +4 -10 +3 +4 -3
        //            3  7  4
        //  2  6  -4 -1  3  0
        int o=A[i]-psA[i];
        if(smn[i]+o>=0&&pmn[i-1]+o>=0){
            return cout<<i<<endl,0;
        }
    }
}

