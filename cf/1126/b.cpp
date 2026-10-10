#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<int>A(N+1);
        vector<int>freq(N+1);
        for(int i=1;i<=N;i++){
            int v;cin>>v;freq[v]++;
        }
        bool win=false;
        for(int i=0;i<=N;i++){
            if(freq[i]>=2*K)continue;
            if(freq[i]==2*K-1)win=true;
            break;
        }
        cout<<(win?"YES\n":"NO\n");
    }
}
