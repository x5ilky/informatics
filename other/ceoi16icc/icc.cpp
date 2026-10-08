#include <bits/stdc++.h>
#include "icc.h"
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
int _query(int A,int B,const int*a,const int*b){
    return query(A,B,const_cast<int*>(a),const_cast<int*>(b));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void run(int N){
    DSU dsu(N+1);
    for(int i=1;i<=N-1;i++){
        map<int,basic_string<int>>comps;
        for(int u=1;u<=N;u++)comps[dsu[u]]+=u;
        map<int,int>id;int K=0;
        for(auto [k,v]:comps)id[k]=K++;
        using pii=pair<int,int>;
        auto fnd=[&](){
            vector<int>bits;
            for(int i=0;(1<<i)<comps.size();i++)bits.push_back(1<<i);
            shuffle(bits.begin(),bits.end(),rng);
            for(int i=0;i<bits.size();i++){
                basic_string<int>A,B;
                for(auto[k,v]:comps)if(id[k]&bits[i])A+=v;else B+=v;
                if(i==bits.size()-1||_query(A.size(),B.size(),A.data(),B.data()))return make_pair(A,B);
            }
            assert(false);
        };
        auto [A,B]=fnd();
        auto se=[&](basic_string<int>&A,basic_string<int>&B){
            int lo=0,hi=A.size();
            while(lo+1<hi){
                int m=(lo+hi)/2;
                basic_string<int> X;
                for(int i=lo;i<m;i++)X+=A[i];
                if(_query(X.size(),B.size(),X.data(),B.data()))hi=m;
                else lo=m;
            }
            return A[lo];
        };
        int u=se(A,B),v=se(B,A);
        setRoad(u,v);
        dsu(u,v);
    }
}
