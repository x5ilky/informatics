#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    int M;cin>>M;
    vector<int>B(M+1);for(int i=1;i<=M;i++)cin>>B[i];
    sort(A.begin()+1,A.end());
    int ans=0;
    for(int i=N;i>=1;i--){
        sort(B.begin()+1,B.end());
        ans+=A[i];
        for(int j=M;j>=1;j--){
            if(A[i]&&B[j])B[j]--,A[i]--,ans--;
        }
    }
    cout<<ans<<endl;
}
