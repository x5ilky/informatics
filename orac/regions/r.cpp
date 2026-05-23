#include <bits/stdc++.h>
using namespace std;
// answer queries (r1, r2) find nodes (e1, e2) such that R[e1]==r1 and R[e2]==r2 and e1 is an ancestor of e2
int main() {
    int N,R,Q;cin>>N>>R>>Q;
    vector<int>r(N+1),p(N+1);
    for(int i=1;i<=N;i++){
        if(i!=1){
            int P;cin>>P;p[i]=P;
        }
        int rr;cin>>rr;r[i]=rr;
    }
}
