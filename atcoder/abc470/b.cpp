#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    map<int,int>M;
    int mx=0;
    for(int i=1;i<=N;i++){
        int v;cin>>v;mx=max(mx,++M[v]);
    }
    cout<<N-mx<<endl;
}
