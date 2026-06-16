#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
struct rat {
    int p,q;
    strong_ordering operator<=>(const rat& other) const {
        int lhs=p*other.q,rhs=other.p*q;
        return lhs<=>rhs;
    }
};
 
signed main() {
    int N;cin>>N;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
 
    const int INF=(1ull<<60);
    rat hi={1ull<<30,1},lo={0,1};
    for(int i=1;i<=N-1;i++){
        if(A[i]==A[i+1]) {
            if(B[i]>B[i+1]){
                // good
            } else {
                cout<<"NO\n";
                return 0;
            }
        } else {
            rat intc={B[i+1]-B[i],A[i]-A[i+1]};
            if(intc.q<0)intc.p=-intc.p,intc.q=-intc.q;
            if(A[i]>A[i+1]){
                lo=max(lo,intc);
            } else {
                hi=min(hi,intc);
            }
        }
    }
    if(hi>lo)cout<<"YES\n";
    else cout<<"NO\n";
}