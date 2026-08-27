#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    int i=min_element(A.begin(),A.end())-A.begin();
    for(int k=0;k<N-1;k++){
        if(A[(i+1)%N]<=A[i]){
            cout<<"NO"<<endl;
            return 0;
        }
        i=(i+1)%N;
    }
    cout<<"YES"<<endl;
}
