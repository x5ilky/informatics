#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(N+1,1e9);
    for(int i=1;i<=N;i++)pq.push({A[i],i}),dist[i]=A[i];
    dist[0]=0;pq.push({0,0});
    while(pq.size()){
        int d=pq.top().first,i=pq.top().second;
        pq.pop();
        if(d>dist[i])continue;
        dist[i]=d;
        if(i>1&&d+1<dist[i-1])pq.push({d+1,i-1});
        if(i<N&&d+1<dist[i+1])pq.push({d+1,i+1});
    }
    cout<<accumulate(dist.begin(),dist.end(),0)<<endl;
}

