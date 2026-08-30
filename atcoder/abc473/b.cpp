#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    map<int,int>A;
    int c=0;
    for(int i=1;i<=N;i++){
        int v;cin>>v;A[v]++;c+=v;
    }
    for(auto [k,v]:A)c-=(v/2)*2*k;
    cout<<c<<endl;
}
