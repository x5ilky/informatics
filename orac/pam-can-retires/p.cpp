#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long
struct E {
    int t, c, v;
};
bool operator<(const E& left, const E& right) {
    if (left.t == right.t) 
        return left.v > right.v;
    return left.t < right.t;
}

using pii = pair<int, int>;
const int INF = 1e15+7;
struct segtree {
    vector<pii> T; 
    segtree(int n) : T(n*4, {-INF, 0}) {}
    
    void update(int v, int tl, int tr, int pos, int a) {
        if (tl == tr) {
            T[v] = {a, pos};
        } else {
            int tm = (tl+tr)/2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, a);
            else 
                update(v*2+1, tm+1, tr, pos, a);
            T[v] = max(T[v*2], T[v*2+1]);
        }
    }
    pii query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return {-INF,0};
        if (tl == ql and tr == qr) {
            return T[v];
        } else {
            int tm = (tl+tr)/2;
            return max(query(v*2, tl, tm, ql, min(qr, tm)),
                       query(v*2+1, tm+1, tr, max(ql, tm+1), qr));
        }
    }
};

signed main() {
    int R,C,B,F; cin>>R>>C>>B>>F;
    map<int, vector<int>> fruitsR, blocksR, fruitsC, blocksC;
    for (int i=1;i<=B;i++){
        int r,c; cin>>r>>c;
        blocksR[r].push_back(c);
        blocksC[c].push_back(r);
    }
    for (int i=1;i<=F;i++){
        int r,c; cin>>r>>c;
        fruitsR[r].push_back(c);
        fruitsC[c].push_back(r);
    }

    map<int,vector<array<int,3>>> fruitrgR, blockrgR;
    vector<E> ev;

    for (auto& [r, fruits] : fruitsR) {
        sort(fruits.begin(),fruits.end());
        auto& blocks=blocksR[r];
        sort(blocks.begin(),blocks.end());
        blocks.push_back(C+1);
        int a=0, b=0, s=1,e=1;
        while(b<blocks.size()) {
            int c=0;
            while (a<fruits.size()&&fruits[a]<blocks[b]) a++,c++;
            e = blocks[b]-1;
            if (s<=e and c>0) {
                fruitrgR[r].push_back({s,e,c});
            }
            s=e=blocks[b]+1;
            b++;
        }
    }
    for (auto& [c, fruits] : fruitsC) {
        sort(fruits.begin(),fruits.end());
        auto& blocks=blocksC[c];
        sort(blocks.begin(),blocks.end());
        blocks.push_back(R+1);
        int a=0, b=0, s=1,e=1;
        while(b<blocks.size()) {
            int cnt=0;
            int sa = a;
            while (a<fruits.size()&&fruits[a]<blocks[b]) {
                a++,cnt++;
            }
            a = sa;
            while (a<fruits.size()&&fruits[a]<blocks[b]) {
                ev.push_back({fruits[a],c,cnt-1});
                ev.push_back({fruits[a]+1,c,cnt});
                a++;
            }
            e = blocks[b]-1;
            if (s<=e and cnt>0) {
                ev.push_back({s,c,cnt});
                ev.push_back({e+1,c,-INF});
            };
            s=e=blocks[b]+1;
            b++;
        }
    }
    sort(ev.begin(), ev.end());

    segtree st(C+1);

    int e = 0, ans = 0;
    for (auto& [r, ranges] : fruitrgR) {
        while (e<ev.size() and ev[e].t<=r) {
            st.update(1, 1, C, ev[e].c, ev[e].v);
            e++;
        }
        
        for (auto& [s, e, c] : ranges) {
            auto q = st.query(1, 1, C, s, e);
            int v = c+q.first;

            auto &row = fruitsR[r];

            ans = max(ans, v);
        }
    }
    cout << ans << endl;
}
