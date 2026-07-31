#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)A[i]-=i;
    int d=0;
    priority_queue<int>pq;
    for(int i=1;i<=N;i++){
        pq.push(A[i]);
        pq.push(A[i]);
        d+=pq.top()-A[i];
        pq.pop();
    }
    cout<<d<<endl;
}
