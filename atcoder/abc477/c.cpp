#include <bits/stdc++.h>
using namespace std;
struct segtree {
    vector<int>T;
    segtree(int n):T(n*4,0) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=T[v*2]+T[v*2+1];
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=0;
            if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
            if(qr>tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
            return ans;
        }
    }
};
int main() {
    int Q;cin>>Q;
    string S,T;cin>>S>>T;
    segtree st(S.size());
    for(int i=0;i<S.size();i++){
        if(!(i+T.size()-1<S.size()))break;
        st.update(1,1,S.size(),i+1,1);
        for(int j=0;j<T.size();j++){
            if(S[i+j]!=T[j])st.update(1,1,S.size(),i+1,0);
        }
    }
    while(Q--){
        int l,r;cin>>l>>r;
        int right=r-T.size()+1;
        if(right>=l&&st.query(1,1,S.size(),l,right))cout<<"Yes\n";
        else cout<<"No\n";
    }
}
