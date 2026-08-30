#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    int a=0;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        if(i>N/2)a+=v;
    }
    cout<<a<<endl;
}
