#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string A,B;cin>>A>>B;
    for(int i=0;i<N;i++){
        if(A[i]=='*'||B[i]=='*')continue;
        if(A[i]!=B[i])return cout<<"No\n",0;
    }
    cout<<"Yes\n";
}
