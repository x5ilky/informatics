#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    sort(A.begin()+1,A.end());
    priority_queue<int>pq;
    map<int,int>freq;
    for(int i=1;i<=N;i++)freq[A[i]]++;
    vector<int>B(N+1,-1);
    for(int i=1;i<=N;i++){
        if(freq[i-1]>0){
            B[i]=i-1;
            for(int k=1;k<=freq[i-1]-1;k++)pq.push(i-1);
            freq[i-1]=0;
        }else{
            if(pq.empty()){
                cout<<"No\n";
                return 0;
            }
            B[i]=pq.top();pq.pop();
        }
    }
    for(auto [k,v]:freq)if(v>0){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for(int i=1;i<=N;i++)cout<<B[i]<<" ";
    cout<<endl;
}
