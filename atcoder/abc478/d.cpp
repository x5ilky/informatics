#include <bits/stdc++.h>
using namespace std;
#include "silky/stl.hpp"
int main() {
    int N,Q;cin>>N>>Q;
    using pii=pair<int,int>;
    vector<vector<pii>>R(Q+1);
    auto add=[&](vector<pii>&v,int l,int r) {
        auto it=lower_bound(v.begin(),v.end(),l,[](const pii&p,int x){
            return p.second+1<x;
        });
        auto jt=it;
        while(jt!=v.end()&&jt->first<=r+1) {
            l=min(l,jt->first);
            r=max(r,jt->second);
            ++jt;
        }
        it=v.erase(it, jt);
        v.insert(it,{l,r});
    };
    FOR(q,1,Q){
        int l,r,X;cin>>l>>r>>X;
        add(R[X],l,r);
    }
    LazySegTree st(N+1);
    for(int i=1;i<=Q;i++)for(auto [l,r]:R[i])st.add(l,r,1);
    for(int i=1;i<=N;i++)cout<<st.sum(i,i)<<" ";cout<<endl;
}
