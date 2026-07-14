#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        map<int,int>freq;
        for(int i=1;i<=N;i++){
            int a;cin>>a;
            freq[a]++;
        }
        int c=0;
        for(auto it=freq.rbegin();it!=freq.rend();it++){
            if(c==0&&it->second)c++;
            else if(it->second>=2)c++;
        }
        cout<<((c-1)*2+1)<<endl;
    }
}
