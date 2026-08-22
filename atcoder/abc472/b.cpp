#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1),psA(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    int c=1e9;
    for(int i=1;i<=N;i++)c=min(c,abs(psA[N]-psA[i]-psA[i]));
    cout<<c<<endl;
}
