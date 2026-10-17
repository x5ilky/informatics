#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    if(A[N]-A[1]<B[N]-B[1])swap(A,B);
    const int INF=2e9;
    {
        multiset<int>Y;
        for(int i=1;i<=N;i++)Y.insert(B[i]);
        int S=A[1]+B[N],D=INF;
        for(int i=1;i<=N;i++){
            if(Y.find(S-A[i])!=Y.end())Y.erase(Y.find(S-A[i]));
        }
        dcheck(Y);
    }
}
