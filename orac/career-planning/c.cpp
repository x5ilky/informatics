#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int MOD=1e9+7;
struct segtree {
    vector<int> T;
    segtree(int n):T(n*4){}
    void update(int v,int tl,int tr,int pos,int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            if (pos> tm) update(v*2+1,tm+1,tr,pos,a);
            T[v]=T[v*2]%MOD+T[v*2+1]%MOD;
            T[v]%=MOD;
        }
    }
    int query(int v,int tl,int tr,int ql,int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=0;
            if (ql<=tm) ans+=query(v*2,tl,tm,ql,qr)%MOD;
            if (qr> tm) ans+=query(v*2+1,tm+1,tr,ql,qr)%MOD;
            return ans%MOD;
        }
    }
};

signed main() {
    using pii=pair<int,int>;
    int H,W,K;cin>>H>>W>>K;
    vector<pair<int,pii>>coord;
    vector<vector<pii>>floor(H+1,vector<pii>(W+1));

    for(int y=H;y>=1;y--){
        for (int x=1;x<=W;x++) {
            cin>>floor[y][x].first;
            coord.push_back({floor[y][x].first,{x,y}});
        }
    }
    sort(coord.begin(),coord.end());
    int c=1;
    map<int,int>gt; int prev=coord[0].first;
    for(auto&[v,d]:coord) {
        if(v!=prev) {
            gt[prev]=c;
            prev=v;
        }
        floor[d.second][d.first].second=c++;
    }
    gt[prev]=c;
    segtree st(W*H+1);
    for (int x=1;x<=W;x++){
        st.update(1,1,W*H,floor[1][x].second,1);
    }
    for (int y=2;y<=H;y++) {
        vector<pii>updates;
        for (int x=1;x<=W;x++) {
            int ans=st.query(1,1,W*H,1,gt[floor[y][x].first]-1);
            updates.push_back({ans,floor[y][x].second});
        }
        for (auto& [v,i]:updates)
            st.update(1,1,W*H,i,v);
        if(y-K>0) {
            for (int x=1;x<=W;x++) {
                st.update(1,1,W*H,floor[y-K][x].second,0);
            }
        }
    }
    int ans=0;
    for (int x=1;x<=W;x++){
        ans+=st.query(1,1,W*H,floor[H][x].second,floor[H][x].second)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
