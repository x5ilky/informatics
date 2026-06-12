#include <bits/stdc++.h>
using namespace std;
string C="ABCDEFGHIJLMNOPQRSTUVWXYZ";
int main() {
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        string A,B;cin>>A>>B;
        cout<<C[(int)(A.size()-1)*5+B.size()-1];
    }
    cout<<endl;
}
