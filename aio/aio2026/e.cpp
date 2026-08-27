#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>psA(N+1);
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    int lo=0,hi=4e9;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        int aft=lower_bound(A.begin()+1,A.end(),mid)-A.begin();
        if(aft<=N/2){
            lo=mid;
            continue;
        }
        int amt=(aft-1-N/2)*mid-(psA[aft-1]-psA[N/2]);
        if(K>=amt)lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
}
