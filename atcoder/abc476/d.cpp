#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,M,K,X,Y;cin>>N>>M>>K>>X>>Y;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>B(M+1);for(int i=1;i<=M;i++)cin>>B[i];
    sort(A.begin()+1,A.end());sort(B.begin()+1,B.end());
    int a=X,b=Y,ans=0;
    vector<int>psA(N+1);for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    for(int k=0;k<=M;k++){
        int cnt=(B[k]+K-1)/K;
        if(b>=cnt){
            b-=cnt;
            a+=cnt*K-B[k];
        }
        else break;
        ans=max<int>(ans,upper_bound(psA.begin(),psA.end(),b*K+a)-psA.begin()-1+k);
    }
    cout<<ans<<endl;
}
