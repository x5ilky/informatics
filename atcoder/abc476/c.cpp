#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    multiset<int>B;
    for(int i=1;i<=N;i++){
        B.insert(A[i]);
        if(i>=3)cout<<(*------B.end())<<endl;
    }
}
