#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,M;cin>>N>>M;
    vector<int>taken(M+1,false);
    for(int i=1;i<=N;i++){
        int C;cin>>C;
        int t=0;
        for(int k=1;k<=C;k++){
            int v;cin>>v;
            if (taken[v])continue;
            if(t==0) {
                t=v;
                taken[v]=true;
            }
        }
        cout<<t<<endl;
    }
}
