#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,M;cin>>N>>M;
    vector<vector<bool>>b(N+1,vector<bool>(M+1,false));
    for (int i=1;i<=N;i++){
        string s;cin>>s;
        for (int j=1;j<=M;j++) {
            if(s[j-1]=='H')b[i][j]=true;
        }
    }
    vector<vector<int>>dp(N+1,vector<int>(M+1,0)),dpm(N+1,vector<int>(M+1,0));
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            
        }
    }
}
