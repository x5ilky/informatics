#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        multiset<int>M;
        for(int i=1;i<=N;i++){
            int v;cin>>v;
            M.insert(v);
        }
        int o=0;
        while(M.size()){
            o++;
            if(K>=*M.begin()){
                M.erase(M.begin());
            }else{
                auto it=M.lower_bound(2*(K+1));
                if(it==M.end())it=--M.upper_bound(2*(K+1));
                int x=*it;
                // if(K+1>=(x+1)/2){
                    M.erase(M.find(x));
                    M.insert((x+1)/2);
                    M.insert((x+1)/2);
                // }else{
                //     M.erase(M.find(y));
                //     M.insert((y+1)/2);
                //     M.insert((y+1)/2);
                // }
            }
            K++;
            dcheck(M);
        }
        cout<<o<<endl;
    }
}
