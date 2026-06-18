#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int p=0,a=0,s=0;
    for(int i=1;i<=N;i++){
        s+=A[i];
        if(s>=p){
            a++;
            p=s;
            s=0;
        }
    }
    cout<<a<<endl;
}
