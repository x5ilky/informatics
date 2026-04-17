#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    vector<int>atleast(N+1,1);
    for(int i=1;i<=M;i++){
        int a,b,c;cin>>a>>b>>c;
        atleast[a]=max(atleast[a],c);
        atleast[b]=max(atleast[b],c);
    }
    for(int i=1;i<=N;i++){
        cout<<atleast[i]<<" ";
    }
    cout<<endl;
}
