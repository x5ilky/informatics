#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    cout.tie(nullptr)->sync_with_stdio(0);
    int N;cin>>N;
    vector<vector<int>>chi(N+1);
    for(int i=1;i<=N;i++){
        int K;cin>>K;
        for(int j=1;j<=K;j++) {
            int v;cin>>v;
            chi[v].push_back(i);
        }
    }
    int best=(1ull<<60);
    auto solve=[&](int root)->int{
        vector<int>dist(N+1,-1);
        queue<int>q;
        q.push(root);
        dist[root]=0;
        int ans=0,reached=0;
        while (!q.empty()){
            auto u=q.front();
            q.pop();
            ans+=dist[u]+1;
            reached++;
            for (auto c:chi[u]){
                if(dist[c]!=-1)continue;
                dist[c]=dist[u]+1;
                q.push(c);
            }
        }
        return reached==N?ans:(1ull<<60);
    };
    for(int i=1;i<=N;i++)best=min(best,solve(i));
    cout<<best<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇慶群耗李洪汎山せ火火せ山允洪和群慶覇|
// |覇群和洪山火ビミヘㇵ一一ㇵシ丁せ汎李群慶|
// |耗洪せ丁ㇵㇸㇸ一一ㇸ・・一　一ミせ洪耗奏|
// |山丁一ㇸシ一　一ㇵㇸ　　　　ㇵ丁丁允汎洪|
// |丁ㇸㇸシ　ㇵㇸ・ㇵヘシヘㇵ　一ㇸミせ火火|
// |・・ㇵ一一ㇸ一シシ丁ビビ丁シヘ・・ヘせ允|
// |ミㇵㇵㇸヘ　ヘシㇵ丁丁丁丁ビせ丁ヘ　一ビ|
// |せㇵ　　ヘ・ヘ・ミヘㇸ　　・一ミ火ミ・一|
// |火シ丁ミ　ヘ　シ・一シミ丁ミㇵ　ヘ火シ　|
// |せ汎丁　一　ヘ・ミ火丁ミシシミㇵ・ミ丁　|
// |汎丁　ㇸ　一ㇵ丁ヘㇸ　ㇸㇸ・　ㇸ　丁シㇵ|
// |火一一一ㇵㇵㇵ　ㇵミミミミ丁ミㇵ　丁ヘミ|
// |火ㇸ・・ㇸ一ㇸミヘㇸ　・・　・・ㇸㇵシ丁|
// |允シㇸㇵ一　ヘヘ　ㇵミビビ丁シミシヘ・ㇸ|
// |丁せㇵㇸㇸㇸシㇸㇵ丁山汎洪洪汎せ丁シヘシ|
// |　一ヘ　・・ミ　シ山労耗群労山ミㇸ・ㇸㇸ|
// |ミㇵ一ㇵ・ㇵ一ㇵせ労奏義和允ミ・ヘ丁火ビ|
// |山せ火ミㇸ一一火労群慶耗允ミ　ミ山洪労汎|
// |李李允ビシ・ビ洪群覇奏汎丁　ミ汎耗陽奏洪|
// |陽奏労火一ヘ山和義義李せㇵㇵせ李義覇奏汎|
// +----------------------------------------+
// 2026 (April 8th) 21:17:52
// end signature





