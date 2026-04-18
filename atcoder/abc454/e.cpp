#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N,Y,X;cin>>N>>Y>>X;
    if((Y==2||Y==N-1)&&(X==2||X==N-1)){
        cout<<"No\n";
        return;
    }
    if(X==1||X==N||Y==1||Y==N){
        cout<<"No\n";
        return;
    }
    if(N%2==1){
        cout<<"No\n";
        return;
    }
    vector<vector<char>> S(N+1,vector<char>(N+1));
    bool right=true;
    for(int i=1;i<=N;i++){
        if(i==Y+1)continue;
        for(int j=1;j<=N;j++){
            S[i][j+!right]=right?'R':'L';
        }
        S[i][right?N:1]='D';
        right=!right;
    }
    if(Y%2==1){
        S[X-1][Y]='D';
        S[X-1][Y+1]='R';
        S[X][Y+1]='R';
        S[X+1][Y+1]='U';
    } else {
        S[X+1][Y]='D';
        S[X+1][Y+1]='L';
        S[X][Y+1]='L';
        S[X-1][Y+1]='U';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T;cin>>T;
    while(T--)solve();
}
