#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
signed main() {
    int N,C;cin>>N>>C;
    using pii=pair<int,int>;
    vector<pii>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i].first>>P[i].second;
    sort(P.begin()+1,P.end(),greater<pii>());
    int ans=-(1ull<<60);
    for(int i=0;i<(1<<N);i++){
        vector<int>L;
        for(int j=0;j<N;j++){
            if(i&(1<<j))L.push_back(j+1);
        }
        int c=-L.size()*C,r=N-L.size();
        for(auto l:L){
            int a=min(r,P[l].second-1);
            c+=(a+1)*P[l].first;
            r-=a;
        }
        if(r<=0)ans=max(ans,c);
    }
    cout<<ans<<endl;
}
