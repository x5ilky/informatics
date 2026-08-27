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
        if(!l)l=new node(0ll);
        if(!r)r=new node(0ll);
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
using pii=pair<int,int>;
vector<pii>C;int N;
vector<node*>nodes;
void init(int _N, int _A[], int _B[]) {
    N=_N;C.resize(N+1);
    for(int i=1;i<=N;i++)C[i]={_A[i-1],_B[i-1]};
    sort(C.begin()+1,C.end());
    nodes[0]=new node(0);
    int j=1;
    for(int i=1;i<=N;i++){
        nodes[i]=nodes[i-1];
        while(j<=N&&C[j].first<=i)nodes[i]=nodes[i]->add(1,N,C[j].second,1);
    }
}

int can(int M, int K[]) {

	return 0;
}
