#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
// cp-algo
struct node {
    node *l, *r;
    int sum;

    node(int val) : l(nullptr), r(nullptr), sum(val) {}
    node(node *l, node *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

node* build(int tl, int tr) {
    if (tl == tr)
        return new node(0);
    int tm = (tl + tr) / 2;
    return new node(build(tl, tm), build(tm+1, tr));
}

int get_sum(node* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

node* update(node* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new node(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new node(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new node(v->l, update(v->r, tm+1, tr, pos, new_val));
}

signed main() {
    int N;cin>>N;
    vector<int>S(N+1),T(N+1);
    for(int i=1;i<=N;i++)cin>>S[i];
    for(int i=1;i<=N;i++)cin>>T[i];
    auto OS=S,OT=T;
    int L=0;
    {
        set<int>C;
        FOR(i,1,N)C.insert(S[i]);
        FOR(i,1,N)C.insert(T[i]);
        map<int,int>C2;
        for(auto v:C)C2[v]=++L;
        FOR(i,1,N)S[i]=C2[S[i]];
        FOR(i,1,N)T[i]=C2[T[i]];
    }
    vector<node*>st1(L+1),st2(L+1);
    st1[0]=st2[0]=build(1,L);
    vector<int>A(L+1),B(L+1);
    FOR(i,1,N){
        A[S[i]]=i;
        B[T[i]]=i;
    }
    FOR(i,1,L){
        st1[i]=st1[i-1];
        st2[i]=st2[i-1];
        if(A[i])st1[i]=update(st1[i],1,L,T[A[i]],1);
        if(B[i])st2[i]=update(st2[i],1,L,S[B[i]],1);
    }
    int ans=0;
    FOR(i,1,N){
        int rs=st1[S[i]]->sum;
        int rt=st2[T[i]]->sum;
        ans+=abs((OS[i]-rs)-(OT[i]-rt));
        ans+=get_sum(st1[S[i]-1],1,L,T[i]+1,L);
    }
    cout<<ans<<endl;
}
