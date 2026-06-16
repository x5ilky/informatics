#include <bits/stdc++.h>
using namespace std;
int main() {
    int w=0;
    for(int i=1;i<=8;i++){
        int x;cin>>x;
        w=max(0,w+x-10);
    }
    cout<<w<<endl;
}
