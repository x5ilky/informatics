#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
using namespace std;
 
const int INF=1e18+9;
struct node {
    gp_hash_table<signed, int> mn;
};
struct segtree {
    vector<node> T;
    segtree(int n): T(4*n, {{}}) {}
    
    void update(int v, int tl, int tr, int pos, int c, int a) {
        if(tl==tr) {
            if (T[v].mn.find(c)!=T[v].mn.end())
                T[v].mn[c]=min(T[v].mn[c],a);
            else
                T[v].mn[c]=a;
        } else {
            int tm=(tl+tr)/2;
            pos <= tm ? update(v*2,tl,tm,pos,c,a)
                    : update(v*2+1,tm+1,tr,pos,c,a);
            int l = T[v*2].mn.find(c)!=T[v*2].mn.end()?T[v*2].mn[c]:INF;
            int r = T[v*2+1].mn.find(c)!=T[v*2+1].mn.end()?T[v*2+1].mn[c]:INF;
            T[v].mn[c]=min(l,r);
        }
    }
    int query(int v, int tl, int tr, int ql, int qr, int a){
        if (ql>qr)return INF;
        if (ql==tl&&qr==tr) {
            return T[v].mn.find(a)!=T[v].mn.end() ? T[v].mn[a] : INF;
        }
        int tm=(tl+tr)/2;
        int l = query(v*2,tl,tm,ql,min(qr,tm),a);
        int r = query(v*2+1,tm+1,tr,max(ql,tm+1),qr,a);
        return min(l, r);
    }
};
 
// dp[r1][c1] + r2-r1 + c2-c1
// dp[r1][c1]-r1-c1 + r2+c2
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int R, C, K; cin>>R>>C>>K;
    vector<vector<int>>grid(R+2,vector<int>(C+2,0));
    for(int r=1;r<=R;r++)
        for(int c=1;c<=C;c++)
            cin>>grid[r][c];
    vector<vector<int>>dp(R+2,vector<int>(C+2,INF));
    segtree st(R+1);
    dp[1][1]=0;
    for(int c=1;c<=C;c++) {
        for(int r=1;r<=R;r++) {
            int mn = st.query(1, 1, R, 1, r, grid[r][c]);
            if (mn != INF) {
                dp[r][c]=min(dp[r][c],mn+r+c-1);
            }

            dp[r][c+1]=min(dp[r][c+1],dp[r][c]+(grid[r][c]!=grid[r][c+1]));
            dp[r+1][c]=min(dp[r+1][c],dp[r][c]+(grid[r][c]!=grid[r+1][c]));
 
            int v=dp[r][c]-r-c;
            st.update(1, 1, R, r, grid[r][c], v);
        }
    }
    // for (int r=1;r<=R;r++) {
    //     for (int c=1;c<=C;c++) printf("%d ", dp[r][c]);
    //     printf("\n");
    // }
    cout<<dp[R][C]<<endl;
}
