#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>A(N+1);
        for(int i=1;i<=N;i++)cin>>A[i];
        map<int,int>odd,even;
        int ans=0;
        for(int i=1;i<=N-4;i+=2){
            int v=A[i]+A[i+2]-A[i+4];
            ans+=odd[v];
            if(i>=5)odd[A[i-4]+A[i-2]-A[i]]++;
        }
        for(int i=2;i<=N-4;i+=2){
            int v=A[i]+A[i+2]-A[i+4];
            ans+=even[v];
            if(i>=5)even[A[i-4]+A[i-2]-A[i]]++;
        }
        odd.clear(),even.clear();
        for(int i=1;i<=N-4;i+=2){
            int v=A[i]+A[i+2]-A[i+4];
            odd[v]++;
        }
        for(int i=2;i<=N-4;i+=2){
            int v=A[i]+A[i+2]-A[i+4];
            even[v]++;
        }
        for(auto [k,v]:odd){
            ans+=v*even[k];
        }
        cout<<ans<<endl;
    }
}
