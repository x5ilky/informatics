#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N,a,b;cin>>N>>a>>b;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    if (a<b){
        swap(a,b);swap(A,B);
    }
    using pii=pair<int,int>;
    vector<pii> v;
    for (int i=1;i<=N;i++)v.push_back({A[i],B[i]});
    sort(v.begin(),v.end(),[&](pii l, pii r) {
        return (l.second-l.first)<(r.second-r.first);
    });
    int ans=0;
    //for (int i=0;i<N;i++)printf("(%d,%d) ",v[i].first,v[i].second);
    //printf("\n",a);
    for (int i=0;i<a;i++)ans+=v[i].first;
    for (int i=a;i<N;i++)ans+=v[i].second;
    cout<<ans<<endl;
}