#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, D; cin>>N>>D;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    queue<int>eggs;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=A[i];k++)eggs.push(i);
        for(int k=1;k<=B[i];k++)eggs.pop();
        while(!eggs.empty() and eggs.front()<=(i-D))eggs.pop();
    }
    cout<<eggs.size()<<endl;
}
int main() {
    int T; cin>>T;
    while(T--)solve();
}
