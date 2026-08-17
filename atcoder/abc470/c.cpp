#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    map<int,int>freq;int x=0;
    for(int i=1;i<=Q;i++){
        int t;cin>>t;
        if(t==1){
            int a;cin>>a;
            x^=freq[a];
            freq[a]++;
            x^=freq[a];
        }else if(t==2){
            for(auto it=freq.begin();it!=freq.end();){
                x^=it->second;
                it->second--;
                x^=it->second;
                if(it->second==0)it=freq.erase(it);
                else it++;
            }
        }
        cout<<x<<endl;
    }
}
