#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    READ(int,N,L,R);
    Vec<int>A(N+1);
    read(A);
    Vec<int>ps=A.ps(),B=ps;
    B.push_back(0);
    B.sort(1);
    B.erase(unique(B.begin()+1,B.end()),B.end());
    int M=B.size()-1;
    SegtreeSum st(M);
    ll ans=0;
    st.update(lower_bound(B.begin()+1,B.end(),0)-B.begin(),1);
    FOR(i,1,N){
        int l=lower_bound(B.begin()+1,B.end(),ps[i]-R)-B.begin();
        int r=upper_bound(B.begin()+1,B.end(),ps[i]-L)-B.begin()-1;
        ans+=st.query(l,r);
        int p=lower_bound(B.begin()+1,B.end(),ps[i])-B.begin();
        st.update(p,st[p]+1);
    }
    write(ans);
}
