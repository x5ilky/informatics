#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int N,M,K;cin>>N>>M>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>B(N+1);
    for(int i=1;i<=N;i++){
        B[i]=B[i-1];
        if(B[i]-B[max(i-M,0ll)]+A[i]>K){
            cout<<"No"<<endl;
        }else{
            B[i]+=A[i];
            cout<<"Yes"<<endl;
        }
    }
}
