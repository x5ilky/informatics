#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

struct segtree {
    vector<int> T;
    segtree(int n):T(n*4,-INF){}
    void update(int v,int tl,int tr,int pos,int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            if (pos> tm) update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    int query(int v,int tl,int tr,int ql,int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2;int ans=-INF;
            if (ql<=tm) ans=max(ans,query(v*2,tl,tm,ql,qr));
            if (qr> tm) ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};

signed main() {
    int N,L,H; cin>>N>>H>>L;
    vector<int> h(N+1), gain(N+1,0);
    for (int i=1;i<=N;i++) cin >> h[i];
    for (int i=1;i<=N-1;i++) cin >> gain[i];
    segtree st(N);
    for (int i=1;i<=N;i++) st.update(1,1,N,i,h[i]);

    vector<int> bestS(N+1,-INF),bestF(N+1,0);

    auto relax = [&](int i, int f, int m) {
        int s=m+1LL*(N-i)*f;
        if (s>bestS[i]||(s==bestS[i]&&f>bestF[i])) {
            bestS[i]=s;
            bestF[i]=f;
        }
    };
    auto cur_m = [&](int i) -> int {
        return bestS[i]-1LL*(N-i)*bestF[i];
    };
    relax(1,0,0);
    for (int i=1;i<=N-1;i++) {
        if (bestS[i]==-INF) continue;
        int f=bestF[i];
        int m=cur_m(i);

        if (h[i]>=h[i+1]) {
            int f2=f+gain[i];
            int m2=m+f2;
            relax(i+1,f2,m2);
        }

        if (L>0 && i+L<=N) {
            int mx = st.query(1,1,N,i+1,i+L);
            if (mx<=h[i]+H) {
                int m2 = m+1LL*L*f;
                relax(i+L,f,m2);
            }
        }
    }

    if (bestS[N]==-INF) {
        cout<<-1<<endl;
    } else {
        cout<<bestS[N]<<endl;
    }
}
