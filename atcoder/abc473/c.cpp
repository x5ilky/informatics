#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    map<int,int>A;
    for(int i=1;i<=N;i++){
        int v;cin>>v;A[v]++;
    }
    int mx=0;for(auto [k,v]:A)mx=max(mx,v);
    int c=0;
    for(int i=1;i<=M;i++)c+=A[i]>=mx-1;
    cout<<c<<endl;
}
