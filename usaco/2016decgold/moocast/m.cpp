#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    Vec<pii>A(N+1);read(A);
    int lo=0,hi=1e9;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        DSU dsu(N+1);
        FOR(i,1,N){
            auto sq=[&](int x){
                return x*x;
            };
            FOR(j,1,N){
                if(sq(A[j].first-A[i].first)+sq(A[j].second-A[i].second)<=mid)dsu(i,j);
            }
        }
        bool bad=false;
        FOR(i,1,N)if(dsu[i]!=dsu[1])bad=true;
        if(bad)lo=mid;
        else hi=mid;
    }
    cout<<hi<<endl;
}
