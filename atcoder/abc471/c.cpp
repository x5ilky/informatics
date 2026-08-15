#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    int d=0;
    set<int>l,r;
    for(int i=1;i<=N;i++){
        int v;cin>>v;
        if(v<0)l.insert(v);
        if(v>0)r.insert(v);
    }
    int x=0;
    while(l.size()||r.size()){
        if(l.empty()){
            d+=abs(x-*r.begin());
            x=*r.begin();
            r.erase(r.begin());
        }else if(r.empty()){
            d+=abs(x-*l.rbegin());
            x=*l.rbegin();
            l.erase(--l.end());
        }else{
            if(abs(x-*r.begin())<abs(x-*l.rbegin())){
                d+=abs(x-*r.begin());
                x=*r.begin();
                r.erase(r.begin());
            }else{
                d+=abs(x-*l.rbegin());
                x=*l.rbegin();
                l.erase(--l.end());
            }
        }
    }
    cout<<d<<endl;
}
