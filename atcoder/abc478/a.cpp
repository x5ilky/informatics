#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B;cin>>A>>B;
    vector<int>C(A);
    for(int i=0;i<B;i++){
        C[i%A]++;
    }
    for(int i=0;i<A;i++)cout<<C[i]<<endl;
}
