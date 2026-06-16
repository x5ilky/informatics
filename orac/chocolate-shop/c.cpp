#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    int a=0;
    for(int i=1;i<=N;i++){
        int v;cin>>v;a+=v;
    }
    cout<<(10-(a%10))%10<<endl;
}
