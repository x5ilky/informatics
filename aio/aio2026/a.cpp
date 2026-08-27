#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int a=0;
    for(int i=1;i<=N-1;i++)a=max(a,A[i+1]-A[i]);
    cout<<a<<endl;
}
