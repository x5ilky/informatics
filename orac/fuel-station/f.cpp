#include <bits/stdc++.h>

using namespace std;

#define int long long

struct S{
    int x,a,b;
    bool operator<(const S& other) const {
        return x<other.x;
    }
};
signed main() {
    using pii=pair<int,int>;
    int N,D;cin>>N>>D; N++;
    vector<S> s(N+1);
    for (int i=1;i<=N-1;i++) cin>>s[i].x>>s[i].a>>s[i].b;
    s[N].x=D;s[N].a=0;s[N].b=(1ull<<48);
    sort(s.begin()+1,s.end());
    int sf=0,f=0; set<pii>S;
    for (int i=1;i<=N;i++){
        auto [x,a,b]=s[i];
        while (f<x){
            sf+=x-f; f+=x-f;
            while (!S.empty()&&S.begin()->first<sf){
                f-=S.begin()->second; S.erase(S.begin());
            }
        }
        if (sf<=b){
            f+=a;
            S.insert({b,a});
        }
    }
    cout<<sf<<endl;
}
