#include "silky/stl.hpp"
using namespace std;
struct segtree{
    vector<int>T;
    segtree(int N):T(N*4,-2){}
    int merge(int a,int b){
        if(a==-3||b==-3)return -3;
        else if(a==-2)return b;
        else if(b==-2)return a;
        else if(a==b)return a;
        else return -3;
    }
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            if(a==-1)T[v]=-2;
            else T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2,ans=-2;
        if(ql<=tm)ans=merge(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=merge(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};
int main() {
    READ(int,N,Q);
    segtree st(N+1);
    FOR(i,1,N){
        READ(int,v);
        st.update(1,1,N,i,v);
    }
    while(Q--){
        READ(int,tt);
        if(tt==1){
            READ(int,i,x);st.update(1,1,N,i,x);
        }else{
            READ(int,l,r);
            Yes(st.query(1,1,N,l,r)!=-3);
        }
    }
}
