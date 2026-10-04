#include <bits/stdc++.h>
using namespace std;

#define int long long
struct segtree{
    vector<int>A,B;
    int N;
    struct state{
        int l,r;
        bool al,ar;
    };
    struct node{
        state best[2];
        bool id=0,g=1,one=1;
        int l,r;
    };
    vector<node>T;
    segtree(int N,vector<int>A,vector<int>B):A(A),B(B),N(N),T(4*N,node{{},1}){}
    state merge_state(state a,state b,bool&g){
        g&=(a.r==b.r||a.al);
        g&=(a.l==b.l||b.ar);
        return {
            a.l,b.r,
            a.al&&b.al&&a.l==b.l,
            a.ar&&b.ar&&a.r==b.r
        };
    }

    node merge(node a,node b){
        if(a.id)return b;
        if(b.id)return a;
        node c;
        c.l=a.l;c.r=b.r;
        c.g=a.g&&b.g;
        if(!c.g)return c;
        int al=A[a.r]-B[a.r],ar=A[a.r]+B[a.r];
        int bl=A[b.l]-B[b.l],br=A[b.l]+B[b.l];
        if(al>bl||ar>br){
            c.g=0;
            return c;
        }

        if(a.best[1].r<=b.best[0].l){
            c.best[0]=a.best[0];
            c.best[1]=b.best[1];
            c.one=0;
            return c;
        }
        state s=merge_state(a.best[1],b.best[0],c.g);
        c.one=a.one&&b.one;
        c.best[0]=a.one?s:a.best[0];
        c.best[1]=b.one?s:b.best[1];
        return c;
    }

    void update(int v,int tl,int tr,int pos,int b){
        if(tl==tr){
            int l=A[pos]-b,r=A[pos]+b;
            T[v].best[0]=T[v].best[1]={l,r,1,1};
            T[v].id=0;
            T[v].g=T[v].one=1;
            T[v].l=T[v].r=pos;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,b);
        else update(v*2+1,tm+1,tr,pos,b);
        T[v]=merge(T[v*2],T[v*2+1]);
    }
    node query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr)return T[v];
        int tm=(tl+tr)/2;
        node a={{{},{}},1};
        if(ql<=tm)a=merge(a,query(v*2,tl,tm,ql,qr));
        if(qr>tm)a=merge(a,query(v*2+1,tm+1,tr,ql,qr));
        return a;
    }
};
signed main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>A(N+1),B(N+1);
        for(int i=1;i<=N;i++)cin>>A[i];
        for(int i=1;i<=N;i++)cin>>B[i];

        segtree st(N,A,B);
        for(int i=1;i<=N;i++)st.update(1,1,N,i,B[i]);

        int Q;cin>>Q;
        while(Q--){
            int P;int S;
            cin>>P>>S;
            st.B[P]=S;
            st.update(1,1,N,P,S);
            cout<<(st.T[1].g?"Yes\n":"No\n");
        }
    }
}
