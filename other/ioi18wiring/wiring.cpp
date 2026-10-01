#include "wiring.h"
#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
long long min_total_length(std::vector<int> r, std::vector<int> b) {
#define int long long
    Vec<pii>P;
    while(r.size()&&b.size()){
        if(r.back()>b.back())P.push_back({r.back(),0}),r.pop_back();
        else P.push_back({b.back(),1}),b.pop_back();
    }
    while(r.size())P.push_back({r.back(),0}),r.pop_back();
    while(b.size())P.push_back({b.back(),1}),b.pop_back();
    P.reverse(0);
    P.insert(P.begin(),{0,0});
    struct segm {int l,s,e,t;Vec<int>ps;};
    Vec<segm>S={segm{0,-1,-1,-1}};
    const int N=P.size()-1;
    Vec<int>par(N+1);
    FOR(i,1,N){
        auto[j,k]=P[i];
        if(k!=S.back().t){
            S.push_back({1,i,i,k,Vec<int>{0,j}});
        }else{
            S.back().l++;
            S.back().e=i;
            S.back().ps.push_back(S.back().ps.back()+j);
        }
        par[i]=S.size()-1;
    }
    // for(auto&[l,s,e,t,_]:S)dprint("len {}, {}-{}, t{}",l,s,e,t);
    Vec<int>dp(N+1,1e18);
    dp[0]=0;
    FOR(i,1,N){
        segm&sg=S[par[i]];
        if(par[i]!=1){
            segm&pv=S[par[i]-1];
            int pos=i-sg.s+1;
            if(pos<=pv.l)dp[i]=dp[pv.e-pos]+sg.ps.rsum(1,pos)-pv.ps.rsum(pv.l-pos+1,pv.l);
            chmin(dp[i],(i==1?0:dp[i-1])+P[i].first-P[pv.e].first);
        }
        if(par[i]!=S.size()-1){
            segm&nx=S[par[i]+1];
            chmin(dp[i],(i==1?0:dp[i-1])-P[i].first+P[nx.s].first);
        }
    }
    // dcheck(dp);
	return dp[N];
}
