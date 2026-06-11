#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>lis={(int)1e9};
    for(int i=1;i<=N;i++){
        if(A[i]>lis.back()){
            lis.push_back(A[i]);
        } else {
            *lower_bound(lis.begin(),lis.end(),A[i])=A[i];
        }
    }
    cout<<lis.size()<<endl; // by dilworths
}
