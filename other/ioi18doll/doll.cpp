#include "doll.h"
#include <bits/stdc++.h>
using namespace std;
void create_circuit(int M, std::vector<int> A) {
    vector<int>X(4e5),Y(4e5);
    function<void(int,int,int)>build=[&](int v,int l,int r){
        if(l==r){
            return;
        }
        int m=l+(r-l-1)/2;
        int lc=v+1,rc=v+2*(m-l+1);
        build(lc,l,m);
        build(rc,m+1,r);
        X[v-1]=-lc;Y[v-1]=-rc;
    };
    build(1,0,A.size()-1);
    int c=0;
    vector<short>state(4e5);
    function<void(int,int,int)>dfs=[&](int v,int l,int r){
        state[v]=!state[v];
        if(l==r){
            printf("%d = %d\n",c,v);
            if(c<A.size()){
                if(X[v-1]!=0)X[v-1]=A[c];
                else Y[v-1]=A[c];
            }else{
                if(c==2*A.size()-1)Y[v-1]=0;
                else Y[v-1]=-1;
            }
            return;
        }
        int m=l+(r-l-1)/2;
        int lc=v+1,rc=v+2*(m-l+1);
        if(state[v])dfs(lc,l,m);
        else dfs(rc,m+1,r);
    };
    for(;c<2*A.size();c++)dfs(1,0,A.size()-1);
    vector<int>C(M+1);
    C[0]=-1;
    for(int i=1;i<=M;i++)C[i]=-1;
    answer(C,X,Y);
}
