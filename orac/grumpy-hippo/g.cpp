#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
long long power(long long a, long long b) {
    if (b == 0) return 1;
    long long x = power(a * a % MOD, b / 2);
    return b % 2 ? x * a % MOD : x;
}
long long inverse(long long a) {
    return power(a, MOD - 2);
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    sort(A.begin()+1,A.end());
    vector<int>fac(N+1,1);
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%MOD;
    int ans=0;
    for(int i=1;i<=N;i++){
        int c=lower_bound(A.begin()+1,A.end(),A[i])-A.begin()-1;
        ans+=fac[N]*inverse(N-c)%MOD;
        // printf("%d has %lld\n",i,fac[N]*inverse(N-c)%MOD);
        ans%=MOD;
    }
    int add=fac[N];
    add*=accumulate(A.begin()+1,A.end(),0ll)%MOD;add%=MOD;
    ans+=add;ans%=MOD;
    cout<<ans<<endl;
}
