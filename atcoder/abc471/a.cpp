#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B;cin>>A>>B;
    if(A+B==9||A-B==9||A*B==9||(A/B==9&&A%9==0))cout<<"Nine\n";
    else cout<<"Nein\n";
}
