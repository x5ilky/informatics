#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    string S;
    int i=25;
    while(i){
        while(N>=i)N-=i,S+="AR";
        S+="CR";
        i--;
    }
    cout<<S<<endl;
}
