#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;
//chatgpt double fenwick because constant factor
struct fenwick {
    int N;
    vector<long long> T1, T2;

    fenwick(int N): N(N), T1(N+2), T2(N+2) {}

    void add(vector<long long>& T, int i, long long x) {
        for (; i <= N; i += i & -i) T[i] += x;
    }

    long long query(const vector<long long>& T, int i) const {
        long long ans = 0;
        for (; i > 0; i -= i & -i) ans += T[i];
        return ans;
    }

    // add x to [l, r]
    void add(int l, int r, long long x) {
        add(T1, l, x);
        add(T1, r + 1, -x);

        add(T2, l, x * (l - 1));
        add(T2, r + 1, -x * r);
    }

    // sum of [1, i]
    long long query(int i) const {
        return query(T1, i) * i - query(T2, i);
    }

    // sum of [l, r]
    long long query(int l, int r) const {
        return query(r) - query(l - 1);
    }
};
struct segtree{
    using node=struct{
        int sm,lz;
    };
    int N;vector<node>T;
    segtree(int N):T(N*4,{0,0}){}
    void push(int v,int tl,int tr){
        int tm=(tl+tr)/2;
        T[v*2].sm+=T[v].lz*(tm-tl+1);
        T[v*2+1].sm+=T[v].lz*(tr-tm);
        T[v*2].lz+=T[v].lz;
        T[v*2+1].lz+=T[v].lz;
        T[v].lz=0;
    }
    void update(int v,int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            T[v].sm+=a*(tr-tl+1);
            T[v].lz+=a;
            return;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(ql<=tm)update(v*2,tl,tm,ql,qr,a);
        if(qr >tm)update(v*2+1,tm+1,tr,ql,qr,a);
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
    }
    int query(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v].sm;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2,sm=0;
        if(ql<=tm)sm+=query(v*2,tl,tm,ql,qr);
        if(qr >tm)sm+=query(v*2+1,tm+1,tr,ql,qr);
        return sm;
    }
};
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,K;cin>>N>>K;
    vector<int>R(N+1),C(N+1);
    for(int i=1;i<=N;i++)cin>>R[i];
    for(int i=1;i<=N;i++)cin>>C[i];
    if(accumulate(R.begin(),R.end(),0ll)!=accumulate(C.begin(),C.end(),0ll)){
        // printf("bad sum\n");
        cout<<"NO"<<endl;
        return 0;
    }
    using pii=pair<int,int>;
    vector<pii>RS(N+1);
    for(int i=1;i<=N;i++)RS[i]={R[i],i};
    sort(RS.begin()+1,RS.end());
    reverse(RS.begin()+1,RS.end());
    vector<pii>c(N+1);
    for(int i=1;i<=N;i++)c[i]={C[i],i};
    vector<vector<int>>out(N+1,vector<int>(N+1,0));
    for(int r=1;r<=N;r++){
        sort(c.begin()+1,c.end());
        int j=N,i=N,rem=RS[r].first;
        fenwick st(N+1),str(N+1);
        auto take=[&](int l,int r,int v){
            st.add(l,r,-v);
            str.add(l,r,v);
            rem-=(r-l+1)*v;
            // printf("take %d-%d amt %d\n",l,r,v);
        };
        // printf("[[START REM = %d]]\n",rem);
        for(int j=1;j<=N;j++)st.add(j,j,c[j].first);
        while(rem){
            if(st.query(1,N)<=0){
                // printf("NOT ENOUGH\n");
                cout<<"NO"<<endl;
                return 0;
            }
            // printf("rem = %d\n",rem);
            // for(int i=1;i<=N;i++)printf("%lld ",st.query(1,0,N,i,i));printf("\n");
            // for(int i=1;i<=N;i++)printf("%lld ",str.query(1,0,N,i,i));printf("\n");
            while(i>1&&st.query(i,i)==st.query(i-1,i-1))i--;
            int mxrem=K-str.query(j,j);
            int dif=st.query(i,i)-st.query(i-1,i-1);
            int rm=min(dif,mxrem);
            // printf("i,j = [%d,%d]\n",i,j);
            // printf("rm = %d\n",rm);
            if(rm<=0){
                // printf("rm <= 0\n");
                cout<<"NO"<<endl;
                return 0;
            }
            if((j-i+1)*rm<=rem){
                // printf("less\n");
                take(i,j,rm);
            }else{
                // printf("greater\n");
                int a=rem/(j-i+1);
                take(i,j,a);
                if(rem==0)break;
                take(i,i+rem-1,1);
            }
            while(j>1&&str.query(j,j)>=K)i=min(i,--j);
        }
        // printf("[[END REM]]\n");
        // for(int k=1;k<=N;k++)printf("%lld ",st.query(k,k));printf("\n");
        for(int k=1;k<=N;k++)out[RS[r].second][c[k].second]=c[k].first-st.query(k,k);
        for(int k=1;k<=N;k++)c[k].first=st.query(k,k);
    }
    int s=0;
    for(auto v:c)s+=v.first;
    if(s!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cout<<out[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
}
