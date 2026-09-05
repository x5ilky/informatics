#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        map<int,int>freq;
        int par1[2]{};
        for(int i=1;i<=N;i++){
            int v;cin>>v;freq[v]++;
            par1[v&1]++;
        }
        int mx=freq.rbegin()->first;
        vector<int>B(N+1);
        if(par1[mx%2]<par1[mx&1^1]&&mx%2==1&&freq.find(mx-1)!=freq.end()&&freq[mx-1]>0){
            B[1]=mx;
            B[N]=mx-1;
            freq[mx]--;
            freq[mx-1]--;
        }else{
            B[1]=mx;
            freq[mx]--;
            if(freq[mx]==0)freq.erase(mx);
            int v=prev(freq.end())->first;
            B[N]=v;
            freq[v]--;
        }
        vector<int>par[2]{};
        for(auto [k,v]:freq)for(int i=1;i<=v;i++)par[k&1].push_back(k);
        for(int i=2;i<=N-1;i++){
            if(par[B[i-1]&1^1].size()){
                B[i]=par[B[i-1]&1^1].back();
                par[B[i-1]&1^1].pop_back();
            }else{
                B[i]=par[B[i-1]&1].back();
                par[B[i-1]&1].pop_back();
            }
        }
        int ans=0;
        for(int i=1;i<=N-1;i++)ans+=(B[i]+B[i+1])/2;
        cout<<ans<<endl;
    }
}
