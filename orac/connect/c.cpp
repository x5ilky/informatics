#include <bits/stdc++.h>
using namespace std;
struct minst {
    vector<int>T;
    minst(int n):T(n*4,1e9) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=min(T[v*2],T[v*2+1]);
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=1e9;
            if (ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
struct maxst {
    vector<int>T;
    maxst(int n):T(n*4,-1e9) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=-1e9;
            if (ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
int main() {
    int N;cin>>N;
    vector<int>A(2*N+1);vector<bool>seen(N+1);
    vector<int>start(N+1),end(N+1);
    for(int i=1;i<=2*N;i++){
        int v;cin>>v;
        A[i]=v<<1;
        if(seen[v])A[i]^=1,end[v]=i;
        else start[v]=i;
        seen[v]=true;
    }
    if("check"){
        minst s(2*N+1);maxst e(2*N+1);
        for(int i=1;i<=2*N;i++)if(~A[i]&1)s.update(1,1,2*N,i,i);
        for(int i=1;i<=2*N;i++)if(A[i]&1)e.update(1,1,2*N,i,i);
        for(int i=1;i<=2*N;i++){
            if(A[i]&1){
                int st=start[A[i]>>1];
                s.update(1,1,2*N,st,1e9);
                e.update(1,1,2*N,i,-1e9);
                if(s.query(1,1,2*N,st,i)<e.query(1,1,2*N,st,i))
                    return cout<<0<<'\n',0;
            }
        }
    }
    if("cons"){
        vector<int>col(N+1,0);
        vector<int>st;
        for(int i=1;i<=2*N;i++){
            int x=A[i]>>1;
            if(A[i]&1){
                if(!st.empty()&&(A[st.back()]>>1)==x)st.pop_back();
                continue;
            }
            if(st.empty()){
                st.push_back(i);continue;
            }
            int y=A[st.back()]>>1;
            if(end[x]>end[y])col[x]=col[y]^1;
            else st.push_back(i);
        }
        for(int i=1;i<=2*N;i++)cout<<col[A[i]>>1]+1<<"\n";
    }
}
