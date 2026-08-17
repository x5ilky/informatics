#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,X;cin>>N>>X;
    int p=-1,c=0,ans=0;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        if(v<X)c=0;
        else ans=max(ans,++c);
        p=v;
    }
    cout<<ans<<endl;
}
