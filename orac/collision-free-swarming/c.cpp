#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define printf(...)
#define int long long 
struct node{
    int mi; int cnt; 
};
const int maxn=1e5+10; node tr[maxn<<2]; int lz[maxn<<2]; 
node combine(node left, node right){
    node cur; 
    if(left.mi<right.mi)return left;
    else if(right.mi<left.mi)return right; 
    cur.mi=left.mi; cur.cnt=left.cnt+right.cnt; 
    return cur; 
}
void build(int l, int r, int rt){
    if(l==r){
        tr[rt]={0,1}; return; 
    }
    int mid=(l+r)>>1; build(l,mid,rt<<1); build(mid+1,r,rt<<1|1); 
    tr[rt]=combine(tr[rt<<1],tr[rt<<1|1]); 
}
void pushdown(int rt){
    if(lz[rt]){
        tr[rt<<1].mi+=lz[rt]; lz[rt<<1]+=lz[rt]; 
        tr[rt<<1|1].mi+=lz[rt]; lz[rt<<1|1]+=lz[rt]; lz[rt]=0; 
    }
}
void update(int l, int r, int rt, int L, int R, int x){
    if(L<=l && r<=R){
        tr[rt].mi+=x; lz[rt]+=x; return; 
    }
    int mid=(l+r)>>1; pushdown(rt); 
    if(L<=mid)update(l,mid,rt<<1,L,R,x);
    if(R>mid)update(mid+1,r,rt<<1|1,L,R,x); 
    tr[rt]=combine(tr[rt<<1],tr[rt<<1|1]); 
}
node query(int l, int r, int rt, int L, int R){
    if(L<=l && r<=R)return tr[rt]; 
    int mid=(l+r)>>1; pushdown(rt); 
    if(L<=mid && R<=mid)return query(l,mid,rt<<1,L,R); 
    if(R>mid && L>mid)return query(mid+1,r,rt<<1|1,L,R); 
    return combine(query(l,mid,rt<<1,L,R),query(mid+1,r,rt<<1|1,L,R)); 
}

using pii = pair<int, int>;
signed main() {
    int N, R, C; cin >> N >> R >> C;
    vector<pii> cells;
    {
        set<int> xs, ys;
        for (int i = 1; i <= N; i++) {
            int r, c; cin >> r >> c;
            xs.insert(c);
            ys.insert(r);
            cells.push_back({r, c});
        }
    }

    map<int, int> col_up, col_down, row_left, row_right;
    vector<array<int, 4>> orthants;

    // auto debug = [&]() {
    //     printf("COL UP\n");
    //     for (auto& [x, y] : col_up) {
    //         if (x < 1 or x > C or y < 1 or y > R) continue;
    //         printf("x: %d, y: %d\n", x, y);
    //     }
    //     printf("COL DOWN\n");
    //     for (auto& [k, v] : col_down) {
    //         if (k < 1 or k > C or v < 1 or v > R) continue;
    //         printf("x: %d, y: %d\n", k, v);
    //     }
    //     printf("ROW LEFT\n");
    //     for (auto& [k, v] : row_left) {
    //         if (v < 1 or v > C or k < 1 or k > R) continue;
    //         printf("x: %d, y: %d\n", v, k);
    //     }
    //     printf("ROW RIGHt\n");
    //     for (auto& [k, v] : row_right) {
    //         if (v < 1 or v > C or k < 1 or k > R) continue;
    //         printf("x: %d, y: %d\n", v, k);
    //     }
    //     printf("-----------\n");
    // };

#define chexists(col, f, fn, v) col[f] = col.count(f) ? fn(col[f], (v)) : (v)
    for (auto& u : cells) {
        auto [y1, x1] = u;
        printf("MAIN: x = %d, y = %d\n", x1, y1);
        for (auto& v : cells) {
            if (u == v) continue;
            auto [y2, x2] = v;
            printf("SUB: x = %d, y = %d\n", y2, x2);
            if ((x1+y1)%2 != (x2+y2)%2) continue;
            if (y1 == y2) {
                int mid = (x1 + x2)/2;
                chexists(col_up, mid, max, y1-1);
                chexists(col_down, mid, min, y1+1);
                continue;
            }
            else if (x1 == x2) {
                int mid = (y1 + y2)/2;
                chexists(row_right, mid, min, x1+1);
                chexists(row_left, mid, max, x1-1);
                continue;
            } else {
                if (x2 < x1) continue;

                if (y2-y1 == x2-x1) {
                    // topleft bottomright square
                    chexists(row_left, y2, max, x1-1);
                    chexists(col_up, x2, max, y1-1);
                    chexists(row_right, y1, min, x2+1);
                    chexists(col_down, x1, min, y2+1);
                    if (x1 > 1 and y2 < R) orthants.push_back({1, y2+1, x1-1, R});
                    if (x2 < C and y1 > 1) orthants.push_back({x2+1, 1, C, y1-1});
                } else if (y1-y2 == x2-x1) { 
                    // topright bottomleft square
                    chexists(row_left, y2, max, x1-1);
                    chexists(col_up, x1, max, y2-1);
                    chexists(row_right, y1, min, x2+1);
                    chexists(col_down, x2, min, y1+1);
                    if (x1 > 1 and y1 > 1) orthants.push_back({1, 1, x1-1, y2-1});
                    if (x2 < C and y1 < R) orthants.push_back({x2+1, y1+1, C, R});
                } else if (y2 > y1) {
                    int mid = (y2-y1+x2-x1)/2;
                    if (y2-y1 < x2-x1) {
                        chexists(col_up, x1+mid, max, y1-1);
                        chexists(col_down, x2-mid, min, y2+1);
                    } else {
                        chexists(row_right, y2-mid, min, x2+1);
                        chexists(row_left, y1+mid, max, x1-1);
                    }
                } else if (x2 > x1) {
                    int mid = (y1-y2+x2-x1)/2;
                    // topright bottomleft rect
                    if (y1-y2 < x2-x1) {
                        chexists(col_up, x2-mid, max, y2-1);
                        chexists(col_down, x1+mid, min, y1+1);
                    } else {
                        // chexists(row_left, x1-1, max, y1+1);
                        // chexists(row_right, x2+1, min, y2-1);
                        chexists(row_left, y1-mid, max, x1-1);
                        chexists(row_right, y2+mid, min, x2+1);
                    }
                }
            }
        }
        // debug();
    }
    
    int ans = 0;
    {
        vector<vector<pair<int,int>>>ad(maxn); vector<vector<pair<int,int>>>de(maxn); 
        auto rect2 = [&](int x1, int y1, int x2, int y2){
            printf("%d,%d -> %d,%d\n", x1, y1, x2, y2);
            x1 = max(1LL, min(x1, C));
            x2 = max(1LL, min(x2, C));
            y1 = max(1LL, min(y1, R));
            y2 = max(1LL, min(y2, R));
            if (x1 > x2 || y1 > y2) return;
            ad[x1].push_back({(int)y1,(int)y2});
            if (x2+1 <= C) de[x2+1].push_back({(int)y1,(int)y2});
        };
        for (auto& [x, y] : col_up) {
            if (x < 1 or x > C or y < 1) continue;
            rect2(x, 1, x, min(y, R));
        }
        for (auto& [x, y] : col_down) {
            if (x < 1 or x > C or y > R) continue;
            rect2(x, max(y, 1LL), x, R);
        }
        for (auto& [y, x] : row_left) {
            if (x < 1 or y < 1 or y > R) continue;
            rect2(1, y, min(x, C), y);
        }
        for (auto& [y, x] : row_right) {
            if (x > C or y < 1 or y > R) continue;
            rect2(max(x, 1LL), y, C, y);
        }
        for (auto& [x1, y1, x2, y2] : orthants) {
            printf("%d %d %d %d\n", x1, y1, x2, y2);
            rect2(x1, y1, x2, y2);
        }
        build(1,R,1);
        for(int i=1; i<=C; i++){
            for(auto x:ad[i])update(1,R,1,x.first,x.second,1); 
            for(auto x:de[i])update(1,R,1,x.first,x.second,-1); 
            node cur=query(1,R,1,1,R);
            int uncovered = (cur.mi == 0 ? cur.cnt : 0);
            ans+=(R-uncovered);
        }
    }
    cout << R*C-ans << endl;
}
