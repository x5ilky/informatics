#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N,K;cin>>N>>K;
    function<vector<mint>(int,int)>merge=[&](int l,int r)->vector<mint>{
        if(l==r){
            mint p=mint(l-1)/l;
            return {1-p,p};
        }
        int m=(l+r)/2;
        return atcoder::convolution(merge(l,m),merge(m+1,r));
    };
    auto res=merge(1,N);
    if(K<N)cout<<0<<endl;
    else if(K-N>=res.size())cout<<0<<endl;
    else cout<<res[K-N].val()<<endl;
}
