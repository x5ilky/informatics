#include <bits/stdc++.h>

using namespace std;

#define int long long

struct segtree {
    vector<int>T;
    segtree(int N):T(N*4){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=T[v*2]+T[v*2+1];
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2,ans=0;
        if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
        return ans;
    }
};
struct segtree2 {
    vector<int>T;
    segtree2(int N):T(N*4,(1ull<<60)){}
    void update(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v]=a;
            return;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)update(v*2,tl,tm,pos,a);
        if(pos >tm)update(v*2+1,tm+1,tr,pos,a);
        T[v]=min(T[v*2],T[v*2+1]);
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v];
        }
        int tm=(tl+tr)/2,ans=(1ull<<60);
        if(ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
        if(qr >tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
        return ans;
    }
};

signed main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int r=1,cnt=0,ans=0; 
    set<int>cur;
    segtree st(N+10);
    queue<int> next;
    st.update(1,0,N+1,A[1],1);
    cur.insert(A[1]);

    for (int l=1;l<=N;l++){
        printf("%d-%d = %d\n", l,r,cnt);
        while (cnt<K&&r<N){
            r++;
            cur.insert(A[r]);
            cnt+=st.query(1,0,N+1,A[r]+1,N+1);
            st.update(1,0,N+1,A[r],1);
            printf("%d-%d = %d\n", l,r,cnt);
        }
        if(cnt==K) {
            printf("add %d-%d\n",origr,r);
        }
        cur.erase(A[l]);
        cnt-=st.query(1,0,N+1,1,A[l]-1);
        st.update(1,0,N+1,A[l],0);
    }
    cout<<ans<<endl;
}
