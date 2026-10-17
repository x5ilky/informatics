#include<bits/stdc++.h>
#include"silky/stl.hpp"
using namespace std;
#define int long long
signed main(){
    int N,K,T;cin>>N>>K>>T;
    RangeContainer R;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        R.add(v,v+K-1);
    }
    long long c=0,cur=0;
    for(auto [l,r]:R.ranges){
        if(l>T)break;
        if(l>cur)c+=(l-cur+K-1)/K;
        cur=max(cur,r+1);
        if(cur>=T)break;
    }
    if(cur<T)c+=(T-cur+K-1)/K;
    cout<<c<<"\n";
}
