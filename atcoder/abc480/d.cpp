#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>psA(N+1),pspsA(N+1),T(N+1);
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    for(int i=1;i<=N;i++)pspsA[i]=pspsA[i-1]+psA[i];
    for(int i=1;i<=N;i++){
        T[i]=T[i-1]+i;
    }
    auto sum=[&](int x)->int{
        if(x==0)return 0;
        int i=lower_bound(T.begin(),T.end(),x)-T.begin();
        return pspsA[i-1]+psA[x-T[i-1]];
    };
    while(Q--){
        int L,R;cin>>L>>R;
        cout<<sum(R)-sum(L-1)<<"\n";
    }
}
