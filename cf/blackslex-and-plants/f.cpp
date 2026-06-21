#include <bits/stdc++.h>
using namespace std;
int main() {
    int l,r;cin>>l>>r;
    for(int i=l;i<=r;i++)printf("[%d] %d\n",i,i*(i&-i));
}
