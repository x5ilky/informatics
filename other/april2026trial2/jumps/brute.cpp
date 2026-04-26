#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>g;vector<int>H;
using pii=pair<int,int>;
const int INF=1e9+7;
void init(int N, vector<int> _H) {
    H=_H;
    H.resize(N+1);
    g.resize(N+1); 
    H[N]=INF;
    stack<pii>st;
    st.push({INF,-1});
    for(int i=0;i<N;i++){
        while(H[i]>st.top().first){
            g[st.top().second].push_back(i);
            st.pop();
        }
        st.push({H[i],i});
    }
    st.push({INF,-1});
    for(int i=N-1;i>=0;i--){
        while(H[i]>st.top().first){
            g[st.top().second].push_back(i);
            st.pop();
        }
        st.push({H[i],i});
    }
}

int minimum_jumps(int A, int B, int C, int D) {
    vector<int>dist(H.size(),-1);
    queue<int>q;
    for(int i=A;i<=B;i++)q.push(i),dist[i]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(auto v:g[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    int M=INF;
    for(int i=C;i<=D;i++)if(dist[i]!=-1)M=min(M,dist[i]);
    return M==INF?-1:M;
}
