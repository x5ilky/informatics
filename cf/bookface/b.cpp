#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N,D;cin>>N>>D;
        vector<int>A(N+1);
        for(int i=1;i<=N;i++)cin>>A[i];
        sort(A.begin()+1,A.end());
        int c=0;
        priority_queue<int>pq;
        for(int i=1;i<=N;i++){
            A[i]-=(i-1)*D;
            if(A[i]<0){
                c+=-A[i];
                A[i]=0;
            }
            pq.push(A[i]);
            pq.push(A[i]);
            c+=pq.top()-A[i];
            pq.pop();
        }
        cout<<c<<endl;
    }
}
