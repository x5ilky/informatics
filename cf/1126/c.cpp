#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int msb=0,c=0;
        for(int i=0;(1<<i)<=N;i++){
            msb=1<<i;c=i;
        }
        vector<int>D;
        function<void(int)>dfs=[&](int d){
            if(d==0){
                D.push_back(msb>>d);
                return;
            }
            dfs(d-1);
            D.push_back(msb>>d);
            dfs(d-1);
        };
        dfs(c+1);
        cout<<D.size()<<endl;
        for(auto v:D)cout<<v<<" ";cout<<endl;
        // {
        //     int N=D.size();
        //     int p=0;
        //     for(int i=1;i<=N;i++){
        //         for(int j=i;j<=N;j++){
        //             int c=0;
        //             for(int k=i;k<=j;k++){
        //                 c^=D[k-1];
        //             }
        //             if(c==0)p++;
        //         }
        //     }
        //     cout<<N-p<<endl;
        // }
    }
}
