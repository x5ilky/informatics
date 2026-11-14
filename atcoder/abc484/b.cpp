#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    bool good=0;int ans=1e9;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        ans=min(ans,v);
        if(v==9)good=1;
    }
    cout<<(good?ans:-1)<<endl;
}
