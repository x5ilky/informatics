#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,W;cin>>N>>W;
    vector<int>A(N+1);
    vector<int>B(N+1);
    for(int i=0;i<N;i++)cin>>A[i]>>B[i];
    int v=0;
    for(int i=0;i<(1<<N);i++){
        int c=0,d=0;
        for(int k=0;k<N;k++){
            if(i&(1<<k))c+=B[k],d+=A[k];
        }
        if(c<=W)v=max(v,d);
    }
    cout<<v<<endl;
}
