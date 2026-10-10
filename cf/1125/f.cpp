#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>A(N+1);
        for(int i=1;i<=N;i++)cin>>A[i];
        auto factor=[&](int v){
            vector<int>cnt;
            for(int i=2;v>1&&i<=sqrt(v)+1;i++){
                int c=0;
                while(v%i==0){
                    v/=i;
                    c^=1;
                }
                if(c)cnt.push_back(i);
            }
            if(v>1)cnt.push_back(v);
            return cnt;
        };
        set<int>fq;
        map<vector<int>,int>fq2;
        for(int i=1;i<=N;i++){
            fq2[factor(A[i])]++;
        }
        long long ans=0;
        for(int i=1;i<=N;i++){
            auto v=factor(A[i]);
            for(auto x:v){
                auto it=fq.find(x);
                if(it==fq.end())fq.insert(x);
                else fq.erase(it);
            }
            if(fq.size()<=7){
                vector<int>v(fq.begin(),fq.end());
                ans+=fq2[v];
            }
        }
        cout<<ans<<endl;
    }
}
