#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    int N,Q,S,T;cin>>N>>Q>>S>>T;
    LazySegTree st(N+1);
    for(int i=0;i<=N;i++){
        int v;cin>>v;
        st.add(i,i,v);
    }
    int a=0;
    FOR(i,0,N-1){
        int x=st[i],y=st[i+1];
        a+=(x-y)*(x<y?S:T);
    }
    while(Q--){
        int l,r,z;cin>>l>>r>>z;
        if(l>0){
            int x=st[l-1],y=st[l];
            a-=(x-y)*(x<y?S:T);
        }
        if(r<N){
            int x=st[r],y=st[r+1];
            a-=(x-y)*(x<y?S:T);
        }
        st.add(l,r,z);
        if(l>0){
            int x=st[l-1],y=st[l];
            a+=(x-y)*(x<y?S:T);
        }
        if(r<N){
            int x=st[r],y=st[r+1];
            a+=(x-y)*(x<y?S:T);
        }
        cout<<a<<endl;
    }
}
