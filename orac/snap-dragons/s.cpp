#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,S;cin>>R>>S;
    map<int,int>a,b;
    for(int i=1;i<=R;i++){
        int v;cin>>v;a[v]++;
    }
    for(int i=1;i<=S;i++){
        int v;cin>>v;b[v]++;
    }
    long long ans=0;
    for(auto&[k,v]:a){
        ans+=v*b[k];
    }
    cout<<ans<<endl;
}
