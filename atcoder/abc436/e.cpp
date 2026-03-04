#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    int N;cin>>N;
    vector<int>P(N+1),F(N+1);for (int i=1;i<=N;i++) {
        cin>>P[i];
        F[P[i]]=i;
    }
    vector<int>seen(N+1,false);
    int ans=0;
    for(int i=1;i<=N;i++){
        if(seen[i])continue;
        int size=0;
        int n=i;
        do {
            size++; seen[n=P[n]]=true;
        } while(n!=i);
        ans+=size*(size-1)/2;
    }
    cout<<ans<<endl;
}
