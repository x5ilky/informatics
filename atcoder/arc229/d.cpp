#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int K;cin>>K;
        vector<int>A(K+2);
        for(int i=1;i<=K+1;i++)cin>>A[i];
        int s=0;
        int mn=*min_element(A.begin()+1,A.end());
        for(int i=1;i<=K+1;i++)
            if(A[i]<K){
                cout<<"Alice\n";
                goto skip;
            }
        for(int i=1;i<=K+1;i++){
            s+=A[i]-mn;
        }
        if(mn%K==0&&s<K)cout<<"Bob\n";
        else cout<<"Alice\n";
skip:;
    }
}
