#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string S;cin>>S;
    int c=0;
    for(int i=0;i<N;i++){
        c+=S[i]=='x'&&(!i||S[i-1]=='x')&&(i==N-1||S[i+1]=='x');
    }
    cout<<c<<endl;
}
