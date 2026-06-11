#include <bits/stdc++.h>
#include <cstdarg>
using namespace std;
int main() {
    vector<int>EA(1e7+2),EB(1e7+1);
    int A;cin>>A;
    for(int i=1;i<=A;i++){
        int a,b;cin>>a>>b;
        EA[a]=1;
        EA[b]=-1;
    }
    int B;cin>>B;
    for(int i=1;i<=B;i++){
        int a,b;cin>>a>>b;
        EB[a]=1;
        EB[b]=-1;
    }
    int a=0,b=0,c=0;
    for(int i=0;i<=1e7;i++){
        a+=EA[i];
        b+=EB[i];
        c+=a&&b;
    }
    cout<<c<<endl;
}
