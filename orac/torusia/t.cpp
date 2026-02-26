#include <bits/stdc++.h>
#include "science.h"

using namespace std;
#define dbg(...) fprintf(stderr, __VA_ARGS__)

const int N=4096,M=64; // sqrt(4096)
int w(int n) { return (n+N*N)%N; }
void alison() {
    for (int k=1;k<=M/2;k++) {
        mark(k,k);
    }
}
void bill() {
    int cx=-1,cy=-1;
    vector<int> order(M);
    std::iota(order.begin(),order.end(),0);
    // std::shuffle(order.begin(), order.end(), std::mt19937{std::random_device{}()});
    int i=0;
    for (int k=0;k<M;k++) {
        int p=w(order[i++]*M);i%=M;
        if(cx==-1) {
            int v=numColumn(p);
            if(v>0) {
                cx=p;
            }
        } else {
            int v=numRow(p);
            if(v>0) {
                cy=p;
            }
        }
    }
    if (cx!=0) for (int k=0;k<M;k++) {
        int p=w(order[i++]*M);i%=M;
        int v=numColumn(p);
        if(v>0) {
            cx=p;break;
        }
    }
    dbg("is %d,%d\n",cx,cy);
    for(int k=5;k>=0;k--){
        int v=numRow(w(cy-(1<<k)));
        if(v>0)cy-=(1<<k);
    }
    for(int k=5;k>=0;k--){
        int v=numColumn(w(cx-(1<<k)));
        if(v>0)cx-=(1<<k);
    }
    found(w(cx-1),w(cy-1));
}
