#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    map<int,int>B;
    int ps=0,v=0;
    B[0]=0;
    for(int i=1;i<=N;i++){
        ps+=A[i]; 
        if(B.find(ps%K)!=B.end())
            B[ps%K]++;
        B[ps%K]=max(B[ps%K],v);
        v=max(v,B[ps%K]);
    }
    cout<<v<<endl;
}
