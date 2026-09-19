#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
struct mxst {
    vector<pii>T;
    mxst(int n):T(n*4,{-1e9,-1}) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]={a,pos};
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    pii query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2;pii ans={-1e9,-1};
            if (ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
struct mnst {
    vector<pii>T;
    mnst(int n):T(n*4,{1e9,-1}) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]={a,pos};
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=min(T[v*2],T[v*2+1]);
        }
    }
    pii query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2;pii ans={1e9,-1};
            if (ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
int main() {
    int N,M;cin>>N>>M;
    mnst A(N+1);mxst B(N+1);
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        A.update(1,1,N,i,v);
        B.update(1,1,N,i,v);
    }
    for(int i=1;i<=M;i++){
        int l,r;cin>>l>>r;
        pii mn=A.query(1,1,N,l,r);
        pii mx=B.query(1,1,N,l,r);
        A.update(1,1,N,mn.second,mx.first);
        A.update(1,1,N,mx.second,mn.first);
        B.update(1,1,N,mn.second,mx.first);
        B.update(1,1,N,mx.second,mn.first);
    }
    for(int i=1;i<=N;i++)cout<<A.query(1,1,N,i,i).first<<" ";
    cout<<endl;
}
