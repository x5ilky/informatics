#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
    int N; cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];

    unordered_map<int,int> l;
    int ans=0;
    for(int i=1;i<=N;i++){
        ans=max(ans, l[A[i]]=max(l[A[i]],l[A[i]-1]+1));
    }
    cout<<ans<<endl;
}
