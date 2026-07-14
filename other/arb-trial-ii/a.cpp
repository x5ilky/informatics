#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    int a1,a2,b1,b2,c1,c2,d1,d2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
    int a=0,b=0,c=0;
    a+=(d2-d1);
    b+=(d2-d1);
    c+=(d2-d1);
    b+=(c2-c1);
    a+=(c2-c1);
    a+=(b2-b1);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
}
