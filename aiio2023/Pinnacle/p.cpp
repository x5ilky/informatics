#include <bits/stdc++.h>
#include <cmath>

#define forn(i, n) for (int i = 0; i < n; i++)
#define int long long
#define MAX_N 100020
#define INF ((int) 1.5e9)
using namespace std;

int searchLeft[MAX_N][20];
int searchRight[MAX_N][20];

signed main() {
    int N, Q;
    cin >> N >> Q;
    int A[MAX_N];
    int br[MAX_N], bl[MAX_N];

    A[0] = A[N+1] = INF;
    forn(i, N) cin >> A[i+1];
    forn(i, N+2) br[i] = bl[i] = 0; 

    stack<int> s; // indices
    A[N+1] = INF;
    s.push(N+1);
    for(int i=N;i>=1;i--){
        while(A[s.top()] < A[i]) s.pop();
        br[i] = s.top();
        s.push(i);
    }
    s.push(0);
    for(int i=1;i<=N;i++){
        while(A[s.top()] < A[i]) s.pop();
        bl[i] = s.top();
        s.push(i);
    }

    for(int i=1;i<=N;i++) {
        for (int k=0;k<20;k++){
            searchRight[i][k] = 1 << k;
        }
    }

    forn(_, Q) {
        int l, r; cin >> l >> r;
    }

    return 0;
}
