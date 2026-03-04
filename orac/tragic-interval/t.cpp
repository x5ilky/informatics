#include <bits/stdc++.h>

using namespace std;

#define printf(...)
const int INF=1e9+7;
struct segtree {
    vector<int> mn; vector<int> mx;
    segtree(int n) : mn(4*n), mx(4*n) {
    }

    void update(int v, int tl, int tr, int pos, int a) {
        if (tl==tr){
            mn[v]=a;
            mx[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm)
                update(v*2,tl,tm,pos,a);
            if (pos> tm)
                update(v*2+1,tm+1,tr,pos,a);
            mn[v]=min(mn[v*2],mn[v*2+1]);
            mx[v]=max(mx[v*2],mx[v*2+1]);
        }
    }
    int query_min(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr){
            return mn[v];
        } else {
            int tm=(tl+tr)/2,ans=INF;
            if (ql<=tm)
                ans=min(ans,query_min(v*2,tl,tm,ql,qr));
            if (qr> tm)
                ans=min(ans,query_min(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
    int query_max(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr){
            return mx[v];
        } else {
            int tm=(tl+tr)/2,ans=-INF;
            if (ql<=tm)
                ans=max(ans,query_max(v*2,tl,tm,ql,qr));
            if (qr> tm)
                ans=max(ans,query_max(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};

int main() {
    using pii=pair<int,int>;
    int N,M;cin>>N>>M;
    segtree st_val(N+1),st_pos(N+1);
    vector<pii> p;
    for(int i=1;i<=N;i++) {
        int v;cin>>v;
        st_val.update(1,1,N,i,v);
        p.push_back({v,i});
    }
    sort(p.begin(),p.end());
    for(int i=0;i<N;i++) {
        st_pos.update(1,1,N,i+1,p[i].second);
    }
    for(int q=1;q<=M;q++){
        string qt;cin>>qt;
        if (qt=="S") {
            int l,r;cin>>l>>r;
            int lv=st_val.query_min(1,1,N,l,l),rv=st_val.query_min(1,1,N,r,r);
            st_val.update(1,1,N,r,lv);
            st_val.update(1,1,N,l,rv);
            auto lit=lower_bound(p.begin(),p.end(),pii{lv,l});
            auto rit=lower_bound(p.begin(),p.end(),pii{rv,r});
            *lit={lv,r};
            *rit={rv,l};
            st_pos.update(1,1,N,lit-p.begin()+1,r);
            st_pos.update(1,1,N,rit-p.begin()+1,l);
            // 1 5 3 4 2
        } else if (qt=="C"){
            int l,r;cin>>l>>r;
            int mn=st_val.query_min(1,1,N,l,r),mx=st_val.query_max(1,1,N,l,r);
            auto lit=lower_bound(p.begin(),p.end(),pii{mn,0});
            auto rit=lower_bound(p.begin(),p.end(),pii{mx+1,0});
            auto lp=lit-p.begin()+1;
            auto rp=rit-p.begin();
            int leftmost=st_pos.query_min(1,1,N,lp,rp);
            int rightmost=st_pos.query_max(1,1,N,lp,rp);
            printf("left %d right %d\n",leftmost, rightmost);
            if (leftmost<l or rightmost>r){
                cout<<"No\n";
            } else cout<<"Yes\n";
        }
    }
}
