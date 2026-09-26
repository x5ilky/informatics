#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,D;cin>>N>>D;
    vector<pair<int,int>>A(N+1);for(int i=1;i<=N;i++)cin>>A[i].first,A[i].second=i;
    sort(A.begin()+1,A.end());
    vector<int>B{};
    for(int i=1;i<=N;i++){
        if((i==1||A[i].first-A[i-1].first>=D)&&(i==N||A[i+1].first-A[i].first>=D))B.push_back(A[i].second);
    }
    sort(B.begin(),B.end());
    cout<<B.size()<<endl;
    for(auto v:B)cout<<v<<" ";
}
