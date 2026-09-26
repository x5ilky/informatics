#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int>e;
    DSU(int n):e(n,-1){}
    int operator[](int x){return e[x]<0?x:e[x]=(*this)[e[x]];}
    int operator()(int x,int y) {
        x=(*this)[x],y=(*this)[y];
        if(x==y)return 0;
        if(e[x]<e[y]) swap(x, y);
        e[y]+=e[x];
        e[x]=y;
        return 1;
    }
};
