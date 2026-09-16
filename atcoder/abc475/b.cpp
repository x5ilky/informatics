#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    int a=0,b=0,c=0;
    for(int i=1;i<=N;i++){
        int d=((A[i]+999)/1000)*1000-A[i];
        a+=(d%1000/100);
        b+=(d%100/10);
        c+=(d%10/1);
    }
    cout<<c<<" "<<b<<" "<<a<<endl;
}
