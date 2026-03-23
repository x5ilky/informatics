#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int N,X;cin>>N>>X;
    for (int i=1;i<=N;i++){
        int v;cin>>v;
        if(v<X){
            X=v;cout<<1<<endl;
        } else cout<<0<<endl;
    }
}
