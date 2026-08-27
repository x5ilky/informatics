#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,K;cin>>N>>K;
    vector<int>R(N+1),C(N+1);
    for(int i=1;i<=N;i++)cin>>R[i];
    for(int i=1;i<=N;i++)cin>>C[i];
    if(accumulate(R.begin(),R.end(),0ll)!=accumulate(C.begin(),C.end(),0ll)){
        cout<<"NO"<<endl;
        return 0;
    }
    using pii=pair<int,int>;
    vector<pii>RS(N+1);
    for(int i=1;i<=N;i++)RS[i]={R[i],i};
    sort(RS.begin()+1,RS.end());
    reverse(RS.begin()+1,RS.end());
    priority_queue<pii>c;
    for(int i=1;i<=N;i++)c.push({C[i],i});
    vector<vector<int>>out(N+1,vector<int>(N+1,0));
    for(int i=1;i<=N;i++){
        vector<int>lim(N+1,0);vector<pii>back{};
        for(int k=1;k<=RS[i].first;k++){
            if(c.empty()){
                cout<<"NO"<<endl;
                return 0;
            }
            auto [v,j]=c.top();c.pop();
            if(v<=0){
                cout<<"NO"<<endl;
                return 0;
            }
            if(++lim[j]<K)c.push({v-1,j});
            else back.push_back({v-1,j});
            out[RS[i].second][j]++;
        }
        for(auto v:back)c.push(v);
    }
    int s=0;
    while(c.size()){
        s+=c.top().first;
        c.pop();
    }
    if(s!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cout<<out[i][j]<<" ";
        cout<<endl;
    }
}
