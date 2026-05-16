#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K,D;cin>>N>>K>>D;
    vector<vector<int>>g(N+1);
    vector<int>par(N+1);
    for(int i=2;i<=N;i++){
        int u,v;cin>>u>>v;
        tie(u,v)=minmax(u,v);
        par[v]=u;
    }
    vector<vector<int>>A(D+1,vector<int>(N+1));
    for(int d=1;d<=D;d++)for(int i=1;i<=N;i++)cin>>A[d][i];
    vector<int>cnt=A[1],imp(N+1);
}
