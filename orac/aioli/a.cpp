#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int N;cin>>N;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];

    auto prec=[&](vector<int>&A,vector<int>&B){
        vector<int>C(N+1),D(N+1),psC(N+1);
        for(int i=1;i<=N;i++)C[i]=lower_bound(A.begin()+1,A.end(),B[i],greater<int>())-A.begin()-1;
        for(int i=1;i<=N;i++)D[i]=A.end()-lower_bound(A.begin()+1,A.end(),B[i],greater<int>());
        for(int i=1;i<=N;i++)psC[i]=psC[i-1]+D[i];
        return make_tuple(C,psC);
    };
    auto [CB,psCB]=prec(A,B);
    auto [CA,psCA]=prec(B,A);
    auto solve=[&](vector<int>&C,vector<int>&psC,int a,int b){
        int it=upper_bound(C.begin()+1,C.end(),a)-(C.begin()+1);
        if(it<=0)it=0;
        int cnt=min(b,it);
        return psC[cnt]-cnt*(N-a);
    };
    
    int Q;cin>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        cout<<solve(CA,psCA,b,a)<<" "<<solve(CB,psCB,a,b)<<"\n";
    }
}

// ad-hoc
// no signature
// may 6th 9:18am
