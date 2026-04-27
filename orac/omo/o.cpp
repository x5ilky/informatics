#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
struct query{
    int l,r,b,i;
    bool operator<(const query&o)const{
        return make_tuple(b,r,l)<make_tuple(o.b,o.r,o.l);
    }
};
int main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<query>queries(Q+1);
    static const int B=750;
    for(int i=1;i<=Q;i++)cin>>queries[i].l>>queries[i].r;
    for(int i=1;i<=Q;i++)queries[i].i=i;
    for(int i=1;i<=Q;i++)queries[i].b=(queries[i].l-1)/B;
    sort(queries.begin()+1,queries.end());
    int l=1,r=0;unordered_map<int,int>freq;vector<bool>ans(Q+1);int odd=0;
    for(int i=1;i<=Q;i++){
        auto q=queries[i];
        while(l<q.l)odd+=(freq[A[l++]]^=1)?1:-1;
        while(l>q.l)odd+=(freq[A[--l]]^=1)?1:-1;
        while(r<q.r)odd+=(freq[A[++r]]^=1)?1:-1;
        while(r>q.r)odd+=(freq[A[r--]]^=1)?1:-1;
        ans[q.i]=(odd<=1);
    }
    for(int i=1;i<=Q;i++){
        cout<<(ans[i]?"YES\n":"NO\n");
    }
}

// begin signature
// +----------------------------------------+
// |覇覇覇義群耗李労労労李李李和奏陽慶覇覇覇|
// |覇義奏李汎山火ビビビ火火せ允洪李奏義義慶|
// |奏労山ビヘ一ミシㇵㇸㇸ一ヘミ火允李李李和|
// |汎ビㇵㇸミ一・ㇵㇵ一・　・ㇸヘ火せせせ山|
// |ビㇸ一ヘ　ヘ・ㇸヘシシシ丁ビ丁ヘ一一ㇵヘ|
// |　　ヘ・ヘ　　・一一ㇸ・　・ヘ火火シ・ㇸ|
// |丁ㇵㇵ　ㇸ　　　一ㇵㇵミ丁ヘ・一丁せ火ヘ|
// |山ヘㇵ・ヘミシ　ミ・　一ヘ丁火シ・ㇵ火允|
// |せ一ㇵビ山火ㇸヘ一ㇵシヘㇵ　ㇵビ丁ㇸㇵミ|
// |ミㇸ火労せㇵヘ一ヘせ允山火ヘ　ㇵ丁ヘ一・|
// |・ミ汎允ヘ一ㇵㇵ山和耗李允丁・一ミ一　ㇸ|
// |ㇸ火労ビ・ミ　丁洪陽慶奏洪せミ・　・・・|
// |　丁洪ビㇸシ・ミ允耗義慶奏労山ミビミㇵシ|
// |シ・ビせ丁　ミ　ミ山李群義義耗汎火ビビ丁|
// |　　　丁允ビ・シㇸㇵビ汎労和李和和汎丁ㇸ|
// |ビ丁ヘ　ミ山ビㇸㇵヘ・シビせせせ山せ山ビ|
// |洪洪火ヘㇸミ山丁一・ヘ・・一一一シせ労山|
// |耗李允ビヘ一ミ火丁ヘㇸ・ㇸㇵミ火汎和李汎|
// |奏奏労允せビ丁ミ丁ビ火火せ山洪和群陽奏労|
// |耗陽李和労洪汎汎洪労労李和耗陽慶覇覇群洪|
// +----------------------------------------+
// 2026 (April 27th) 12:28:40
// end signature


