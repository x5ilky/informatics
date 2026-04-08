#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define int long long

struct layer{
    vector<int>ps;
    int c,r;
};
struct lrq{
    int l,r,q;
    bool operator<(const lrq& other) const {
        if(l==other.l)return r<other.r;
        return l<other.l;
    }
};
signed main() {
    int N;cin>>N;
    vector<layer>L(N+1);
    for (int i=1;i<=N;i++){
        int C,l,r;cin>>C>>l>>r;
        L[i].ps.resize(C+2);
        L[i].c=C+1;
        L[i].r=r;
        L[i].ps[1]=l;
        for(int j=2;j<=C+1;j++){
            int v;cin>>v;L[i].ps[j]=L[i].ps[j-1]+v;
        }
    }

    const int END=1e9;
    using pii=pair<int,int>;
    auto solve=[&](int K){
        map<int,int>ps;
        for(int q=1;q<=N;q++){
            auto l=L[q];
            int S=l.r-l.ps[l.c];
            if(S<K)return false;
            int D=S-K;
            for(int i=1;i<=l.c;i++){
                ps[l.ps[l.c]]=max(ps[l.ps[l.c]],D);
            }
        }
        set<pii>taken;
        for(auto [l,d]:ps){
        }
    };
    int lo=0,hi=END;
    while (lo+1<hi){
        int mid=(lo+hi)/2;
        printf("mid = %3d\n", mid);
        if(solve(mid))lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
}

// begin signature
// +----------------------------------------+
// |覇慶群耗労洪允山せ火ビビビ火山允労和群義|
// |陽耗労允せビミミヘ一一一一ヘミビ山洪和群|
// |労允火ミㇵ一シヘ一ヘシシシヘシシビ允労奏|
// |せミ一ㇸミ火せ丁シㇵㇵㇵㇸ　　ㇸシせ洪耗|
// |シ・ㇸミせビシヘㇸ　　・　　一・ㇸミ山労|
// |ヘ　ㇵビせミㇵ　一ヘミ丁丁ミヘㇸ　・ミ山|
// |ヘ・ㇵビ火シ・一ミヘ一ㇸㇸㇵシビミ一　シ|
// |シ・一ビビㇵ・シ一　一ヘヘㇵ・・シビヘ　|
// |ㇵ・ヘせミ　ヘㇸㇸシビせせ火丁ㇵ　ヘビㇵ|
// |　ㇸビミ・ヘシせ汎労洪山ビヘ・ミㇸㇵビヘ|
// |　ミ丁・せ李群義慶覇群李允丁ㇵ・・ヘビㇵ|
// |ㇸビ火和義慶義群群奏李汎火シㇸ　　シビヘ|
// |・ビ和慶義奏和李労洪汎火シ・一ヘㇸヘ火火|
// |ㇸ允奏陽耗李洪山汎汎火丁一　　・・ㇸ丁汎|
// |丁允奏奏李汎山ビ丁火丁ビビ丁シ丁丁ミシビ|
// |允允奏和汎せ丁ヘシ火允洪洪汎せビヘ一・ㇸ|
// |シ李耗洪せシㇵヘ火汎和奏李允丁一　ㇵヘヘ|
// |汎奏洪火ヘ・シ火洪耗陽李允ミㇸㇵ丁せせビ|
// |耗労火ヘㇸ一火洪奏義和允ミ・ヘ火汎労洪山|
// |和允丁・　シ山李陽奏洪火ㇵ一ビ洪耗群李山|
// +----------------------------------------+
// 2026 (April 7th) 22:44:02
// end signature
