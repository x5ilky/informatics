#include <bits/stdc++.h>
using namespace std;
int main() {
    int l,r;cin>>l>>r;
    for(int i=l;i<=r;i++)printf("[%02d] %08d\n",i,i*(i&-i));
    int ps=0;
    for(int i=l;i<=r;i++)ps+=i*(i&-i),printf("[%02d] %08b\n",i,ps);
}
