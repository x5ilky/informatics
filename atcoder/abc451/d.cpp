#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    using pii=pair<int,int>;
    vector<int>p10;vector<pii> p2;
    {
        int n=1;
        for (int i=0;i<=10;i++){
            p10.push_back(n);
            n*=10;
        }
    }
    set<int>all;
    set<pii>cur;
    for (int i=0;i<=30;i++){
        p2.push_back({1<<i,floor(log10((1<<i)))+1});
        cur.insert({1<<i,floor(log10((1<<i)))+1});
    }
    while(!cur.empty()){
        set<pii>nw;
        for(auto n:cur)
            all.insert(n.first);
        for (auto c:cur) {
            for(auto d:p2){
                if(d.second+c.second>=10)continue;
                int n=p10[d.second]*c.first+d.first;
                if(all.find(n)==all.end()) {
                    nw.insert({n,d.second+c.second});
                }
            }
        }
        cur=nw;
    }
    vector<int>a(all.begin(),all.end());

    int N;cin>>N;
    cout<<a[N-1]<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎允汎汎労允山火火ビ火せ山|
// |慶奏李汎山火丁ミミ丁ビビミヘ一ㇸㇸ一ヘミ|
// |和汎火ミㇵ一シビ火丁ㇵㇵヘシヘㇵㇸ　　ㇸ|
// |山ミ一一ミせ允ビヘミビせ山せ火丁シシシヘ|
// |ミㇸ一丁せ允ビシミミビビビミ一　・ㇸ・　|
// |ヘ・ㇵ一ㇵシ丁シビ山汎山丁一・ヘ丁ビビ丁|
// |一・一ㇵㇵ一　一ミせ洪山ミシㇵ　ㇵ丁山汎|
// |　ヘ丁火丁一ㇸシ火山允汎汎允せ丁ヘ　ヘ火|
// |シせ汎ビ一ㇸ丁山洪汎允允汎火丁ヘㇵㇵ　シ|
// |允汎ビ一ㇵビ汎山ビ丁ミ丁ビせ山丁一一・ヘ|
// |汎丁ㇸヘせ火ミㇵ・　　ㇸㇵシ丁ビㇵ一シヘ|
// |火一ㇸミミ一　ㇵミ丁ミㇵ一　ㇵミㇵㇸビシ|
// |丁・シシ　ㇵヘ火允汎允ビヘ　一・ㇵ　ミビ|
// |せㇵㇵ一一一シ山労耗耗労せヘㇸ・一ㇵㇵビ|
// |汎丁　ㇸㇵ・ㇵ火労群覇陽李せㇵシビビ丁ビ|
// |火せビシシ　　丁汎耗慶慶耗汎せビヘ一・ㇸ|
// |汎洪汎せシ　　シ山李耗奏和汎ビ一・ヘシシ|
// |奏奏李山シ・ㇵせ労奏慶耗汎丁・ㇵビ山允せ|
// |覇群洪ビㇸ一火労群慶耗汎丁・シ山労和李允|
// |群李山シ　ミ允耗慶陽李せㇵ一火労群義和允|
// +----------------------------------------+
// 2026 (April 3rd) 17:08:32
// end signature
