#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    // losing xor(a mod K+1) = 0
    vector<int>game(N+1);
    for(int i=1;i<=N;i++)game[i]=N-1;
    auto score=[&](){
        int s=0;
        for(int i=1;i<=N;i++)s^=game[i]%(N+1);
        return s;
    };
    if(score()==0){
        cout<<"Second"<<endl;
        int i,j;cin>>i>>j;
    }
}
