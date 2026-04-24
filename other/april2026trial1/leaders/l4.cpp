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
    deque<pii>dq(P.begin()+1,P.end());
    int ans=0;
    while(!dq.empty()){
        auto [p,c]=dq.front();dq.pop_front();c--;
        int cnt=1;
        while(!dq.empty()&&c){
            dq.pop_back();
            cnt++;
            c--;
        }
        ans+=p*cnt-C;
    }
    cout<<ans<<endl;
}
