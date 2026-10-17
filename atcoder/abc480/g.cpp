#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<int>A(N+1),dp(N+1,1ll<<60);
    dp[0]=0;
    for(int i=1;i<=N;i++)cin>>A[i];
    LazySegTree st(N+1);
    st.set(1,1,0);
    vector<int>hi,lo;
    for(int i=1;i<=N;i++){
        while(hi.size()&&A[hi.back()]<=A[i]){
            int j=hi.back();hi.pop_back();
            int k=hi.empty()?0:hi.back();
            st.add(k+1,j,A[i]-A[j]);
        }
        hi.push_back(i);
        while(lo.size()&&A[lo.back()]>=A[i]){
            int j=lo.back();lo.pop_back();
            int k=lo.empty()?0:lo.back();
            st.add(k+1,j,A[j]-A[i]);
        }
        lo.push_back(i);
        if(i>=2)dp[i]=min(1ll<<60,st.min(1,i));
        if(i>=2)st.set(i,i,dp[i-1]);
    }
    cout<<dp[N]<<endl;
}
