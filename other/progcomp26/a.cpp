#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    array<vector<bool>,2>obs;obs.fill(vector<bool>(N+1,0));
    for(int i=0;i<=1;i++){
        string S;cin>>S;
        for(int j=1;j<=N;j++)obs[i][j]=S[j-1]=='#';
    }
    int fly=0;
    vector<int>state(N+2);
    for(int i=1;i<=N;i++){
        if(obs[!fly][i]){
            cout<<"Impossible\n";
            return 0;
        }
        if(fly){
            state[i]|=0b100;
            state[i+1]|=0b10;
            fly=0;
        } else {
            if(obs[1][i+1]){
                state[i]|=0b01;
                fly=1;
            }
        }
    }
    string S[2];
    S[0].resize(N,'.');
    S[1].resize(N,'.');
    string F="%+";
    for(int j=0;j<=1;j++){
        for(int i=1;i<=N;i++){
            if(obs[j][i])S[j][i-1]=F[j];
        }
    }
    string G="_/\\V";
    for(int i=1;i<=N;i++){
        S[!(state[i]&0b100)][i-1]=G[state[i]&0b11]; 
    }
    cout<<S[0]<<endl;
    cout<<S[1]<<endl;
}
