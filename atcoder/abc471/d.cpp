#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int Q,V;cin>>Q>>V;
    multiset<int>B;
    while(Q--){
        int tt;cin>>tt;
        if(tt==1){
            int t,w;cin>>t>>w;
            B.insert(w-t);
        }else{
            int t;cin>>t;
            if(B.empty())cout<<-1<<endl;
            else {
                int w=*B.rbegin();
                B.erase(--B.end());
                cout<<min(w+t,V)<<endl;
            }
        }
    }
}
