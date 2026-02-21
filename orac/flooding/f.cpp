#include <bits/stdc++.h>

// query i, w = house many houses will be covered with how much water
//      O(log N) with binary lifting

using namespace std;

#define int long long
const int INF=1e18;
signed main() {
    int N; cin >> N;
    vector<int>H(N+2);for(int i=1;i<=N;i++)cin>>H[i];
    vector<int>ps(N+1);for(int i=1;i<=N;i++)ps[i]=ps[i-1]+H[i];
    vector<vector<int>>lift(N+1,vector<int>(20,0));
    stack<int> s; // indices
    H[N+1] = INF;
    s.push(N+1);
    for(int i=N;i>=1;i--){
        while(H[s.top()] < H[i]) s.pop();
        lift[i][0] = s.top();
        s.push(i);
    }
    for(int k=19;k>=1;k--){
        for(int i=N;i>=1;i--){
            lift[i][k]=lift[lift[i][k-1]][k-1];
        }
    }
    int Q,K;cin>>Q>>K;
    for(int q=1;q<=Q;q++){
        int ans=INF, lastestHigh=1;
        for(int i=1;i<=N;i++){
            if (i>1&&H[i]>H[i-1])lastestHigh=i;

        }
    }
}
