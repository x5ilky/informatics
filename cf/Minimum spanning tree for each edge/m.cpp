#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_N 300010


int HEAD[MAX_N];
int sz[MAX_N]; // size of component
int mc[MAX_N];

int head(int a){
    if (HEAD[a]==a) return a;
    // return head(HEAD[a]);
    return HEAD[a] = head(HEAD[a]);
}

void join(int a, int b){
    if (sz[head(a)] > sz[head(b)]) swap(a,b);
    HEAD[head(a)] = head(b);

}

struct E {
    int a,b,w,i;
    bool operator< (E other) const {
        return w < other.w;
    }
};

signed main(){
    cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i=1;i<=N;i++) HEAD[i] = i;
    for(int i=1;i<=N;i++) sz[i] = 1;
    // read in edges
    vector<E> edges(M);
    int EE = 0;
    for(auto &e : edges) {
        cin >> e.a >> e.b >> e.w;
        e.i = EE++;
    }
    // Kruskal's algorithm, using UnionFind
    sort(edges.begin(), edges.end());
    int mstCost = 0;
    for(auto e : edges){
        if (head(e.a)!=head(e.b)){
            mstCost += e.w;
            mc[e.a] = max(mc[e.a], e.w);
            mc[e.b] = max(mc[e.b], e.w);
            join(e.a,e.b);
        }
    }
    sort(edges.begin(), edges.end(), [](E a, E b){
        return a.i < b.i;
    });
    for(auto e : edges) {
        cout << (mstCost + e.w - max(mc[e.a], mc[e.b])) << endl;
    }
    // cout << mstCost << '\n';

    return 0;
}
