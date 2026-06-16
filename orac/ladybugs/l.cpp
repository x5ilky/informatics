#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    auto [a,b]=minmax_element(A.begin()+1,A.end());
    cout<<(*b-*a+1)<<endl;
}
