#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,A=0;cin>>N;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        A+=(i%2)*v;
    }
    cout<<A<<endl;
}
