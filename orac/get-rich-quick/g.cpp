#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    SegtreeMax mx(N+1); 
    SegtreeSum st(N+1);
    FOR(i,1,N)mx.update(i,A[i]);
    FOR(i,1,N)st.update(i,A[i]);
    while(Q--){
        int x,y;cin>>x>>y;
        st.update(x,y);
        mx.update(x,y);
        int i=0,c=0,s=0;
        using pii=pair<int,int>;
        while(i<N){
            int j=mx.find_first(1,[&](int x){
                return x>c;
            });
            if(j>N)break;
            c+=st.query(i+1,j-1);
            int v=mx[j];
            if(c>=v){
                i=j;
                c+=v;
                continue;
            }
            s+=v-c;
            c+=v-c;
            c+=v;
            i=j;
        }
        cout<<s<<endl;
        st.update(x,A[x]);
        mx.update(x,A[x]);
    }
}
