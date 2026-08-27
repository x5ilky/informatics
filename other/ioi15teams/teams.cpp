#include "teams.h"
#include <bits/stdc++.h>
using namespace std;

struct node{
    node*l,*r;int cnt;
    node(int cnt):l(nullptr),r(nullptr),cnt(cnt){}
    node(node*l,node*r):l(l),r(r),cnt(0){
        if(l)cnt+=l->cnt;
        if(r)cnt+=r->cnt;
    }
    void fix(){
        if(!l)l=new node(0ll,0ll);
        if(!r)r=new node(0ll,0ll);
    }
    node*add(int tl,int tr,int pos,int a){
        if(tl==tr)return new node(cnt+a);
        int tm=(tl+tr)/2;fix();
        if(pos<=tm)return new node(l->add(tl,tm,pos,a),r);
        if(pos >tm)return new node(l,r->add(tm+1,tr,pos,a));
        assert(0);
    };
    int range_sum(int tl,int tr,int ql,int qr){
        if(ql<=tr&&tr<=qr)return cnt;
        int tm=(tl+tr)/2,ans=0;fix();
        if(ql<=tm)ans+=l->range_sum(tl,tm,ql,qr);
        if(qr >tm)ans+=r->range_sum(tm+1,tr,ql,qr);
        return ans;
    };
};
int N;
using pii=pair<int,int>;
vector<node*>st;
void init(int _N, int A[], int B[]) {
    N=_N;st.resize(N+1);
    st[0]=new node(0);
    vector<pii>P;for(int i=0;i<N;i++)P.push_back({A[i],B[i]});
    sort(P.begin(),P.end());
    int j=0;
    for(int i=1;i<=N;i++){
        st[i]=st[i-1];
        while(j<N&&P[i].first<=i)st[i]=st[i]->add(1,N,P[i].second,1);
    }
}
int can(int M,int K[]) {
    for(int i=0;i<M;i++){
    }
	return 0;
}
