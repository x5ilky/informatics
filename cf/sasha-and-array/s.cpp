#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint1000000007;
struct matrix{
    mint v[2][2];
    matrix operator+(const matrix&o)const{
        matrix c={{{0,0},{0,0}}};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                c.v[i][j]=v[i][j]+o.v[i][j];
        return c;
    }
    matrix operator*(const matrix&o)const{
        matrix c={{{0,0},{0,0}}};
        for(int i=0;i<2;i++)
            for(int k=0;k<2;k++)
                for(int j=0;j<2;j++)
                    c.v[i][j]+=v[i][k]*o.v[k][j];
        return c;
    }
};
const matrix id={{{1,0},{0,1}}};
matrix exp(matrix a,int b){
    matrix c=id;
    matrix d=a;
    for(int k=0;k<31;k++){
        if(b&(1<<k))c=d*c;
        d=d*d;
    }
    return c;
}
matrix fib={{{1,1},{1,0}}};
struct segtree {
    vector<matrix>T,lz;
    segtree(int N):T(N*4,fib),lz(N*4,id){}
    void push(int v){
        T[v*2]=T[v*2]*lz[v];
        lz[v*2]=lz[v*2]*lz[v];
        T[v*2+1]=T[v*2+1]*lz[v];
        lz[v*2+1]=lz[v*2+1]*lz[v];
        lz[v]=id;
    }
    void update(int v,int tl,int tr,int ql,int qr,matrix a){
        if(ql<=tl&&tr<=qr){
            T[v]=a*T[v];
            lz[v]=a*lz[v];
            return;
        }
        push(v);
        int tm=(tl+tr)/2;
        if(ql<=tm)update(v*2,tl,tm,ql,qr,a);
        if(qr >tm)update(v*2+1,tm+1,tr,ql,qr,a);
        T[v]=T[v*2]+T[v*2+1];
    }
    matrix query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        push(v);
        int tm=(tl+tr)/2;matrix a={{{0,0},{0,0}}};
        if(ql<=tm)a=a+query(v*2,tl,tm,ql,qr);
        if(qr >tm)a=a+query(v*2+1,tm+1,tr,ql,qr);
        return a;
    }
};
int main() {
    int N,Q;cin>>N>>Q;
    segtree st(N+1);
    for(int i=1;i<=N;i++){
        int a;cin>>a;
        st.update(1,1,N,i,i,exp(fib,a));
    }
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int l,r,x;cin>>l>>r>>x;
            st.update(1,1,N,l,r,exp(fib,x));
        }else if(t==2){
            int l,r;cin>>l>>r;
            cout<<st.query(1,1,N,l,r).v[1][1].val()<<endl;
        }
    }
}
