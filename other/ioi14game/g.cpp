#include "game.h"
#include <bits/stdc++.h>
using namespace std;

vector<int>HEAD;vector<vector<int>>cnt;
int N;
void initialize(int _N) {
    N=_N;
    HEAD.resize(N);
    cnt.resize(N);
    fill(cnt.begin(),cnt.end(),vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            cnt[i][j]=1;
        }
    }
    iota(HEAD.begin(),HEAD.end(),0);
}
int head(int u){
    return u==HEAD[u]?u:HEAD[u]=head(HEAD[u]);
}
void join(int u,int v){
    u=head(u),v=head(v);
    if(u==v)return;
    for(int i=0;i<N;i++){
        cnt[u][i]+=cnt[v][i];
        cnt[i][u]+=cnt[i][v];
        cnt[i][v]=0;cnt[v][i]=0;
    }
    HEAD[v]=u;
}

int hasEdge(int u, int v){
    u=head(u),v=head(v);
    if((--cnt[u][v],--cnt[v][u])==0)return join(u,v),1;
    return 0;
}
