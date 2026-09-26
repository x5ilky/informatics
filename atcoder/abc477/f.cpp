#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    node *l=nullptr,*r=nullptr;
    int sm=0,lz=0;
    node(){}
    node(node *l,node *r,int sm,int lz):l(l),r(r),sm(sm),lz(lz){}
    node* clone(){
        return new node(*this);
    }
    void apply(int l,int v){
        sm+=l*v;
        lz+=v;
    }
    void push(int tl,int tr){
        if(!lz||tl==tr)return;
        int tm=(tl+tr)/2;
        l=l->clone();
        r=r->clone();
        l->apply(tm-tl+1,lz);
        r->apply(tr-tm,lz);
        lz=0;
    }
    node* update(int tl,int tr,int ql,int qr,int accum=0){
        node *v=clone();
        if(ql<=tl&&tr<=qr){
            v->apply(tr-tl+1,accum);
        }else{
            v->push(tl,tr);
            int tm=(tl+tr)/2;
            if(ql<=tm)v->l=v->l->update(tl,tm,ql,qr,accum);
            if(qr>tm)v->r=v->r->update(tm+1,tr,ql,qr,accum);
            v->sm=v->l->sm+v->r->sm;
        }
        return v;
    }
    int query(int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            return sm+(int)(tr-tl+1)*a;
        }else{
            a+=lz;
            int tm=(tl+tr)/2;
            int ans=0;
            if(ql<=tm)ans+=l->query(tl,tm,ql,qr,a);
            if(qr>tm)ans+=r->query(tm+1,tr,ql,qr,a);
            return ans;
        }
    }
};

node* build(int l,int r){
    node *v=new node();
    if(l!=r){
        int m=(l+r)/2;
        v->l=build(l,m);
        v->r=build(m+1,r);
    }
    return v;
}
signed main() {
    int N,M,Q;cin>>N>>M>>Q;
    vector<node*>st(N+1);
    st[0]=build(1,M);
    for(int i=1;i<=N;i++){
        int l,r;cin>>l>>r;
        st[i]=st[i-1]->update(1,M,l,r,1);
    }
    while(Q--){
        int R1,R2,C1,C2;cin>>R1>>R2>>C1>>C2;
        cout<<(st[R2]->query(1,M,C1,C2,0)-st[R1-1]->query(1,M,C1,C2,0))<<endl;
    }
}
