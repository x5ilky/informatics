#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>A(N+1);
        bool good=0;
        for(int i=1;i<=N;i++)cin>>A[i];
        int ans=0;
        for(int i=1;i<N;i++){
            int d=A[i]-2*A[i+1];
            if(d<0){
                cout<<-1<<'\n';
                goto skip;
            }
            ans=max(ans,d);
        }
        for(int i=1;i<=N;i++)good|=A[i]>0;
        cout<<(good?max(1LL,ans):0)<<'\n';
skip:;
    }
}
