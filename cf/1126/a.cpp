#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int x,y;cin>>x>>y;
        if(y-x>1){
            cout<<-1<<endl;
            continue;
        }
        cout<<(x+(y%2!=x%2))<<endl;
    }
}
