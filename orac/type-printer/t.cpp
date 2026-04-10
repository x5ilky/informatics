#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;cin>>N;
    vector<string>S(N+1);
    for(int i=1;i<=N;i++)cin>>S[i];
    function<int(vector<int>,int)>rec=[&](vector<int>I,int depth){
        if(I.empty())return 0;
        int cost=0;
        array<vector<int>,26>A{};
        for(auto i:I){
            if(depth>=S[i].size())continue;
            if(A[S[i][depth]-'a'].empty())cost+=2;
            A[S[i][depth]-'a'].push_back(i);
        }
        for(auto c:A) cost+=rec(c,depth+1);
        return cost;
    };
    vector<int> I(N);
    iota(I.begin(),I.end(),1);
    int cost=rec(I,0),l=0;
    for(int i=1;i<=N;i++)
        l=max(l,(int)S[i].size());
    cout<<cost+N-l<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇陽奏和李洪允山せ山允洪李奏慶覇覇|
// |覇覇群和洪山火ビシㇵ一一ㇵシ丁山洪耗義覇|
// |陽李允ビヘㇵㇸㇸヘㇵ一一ㇸ　ㇸミ山李群覇|
// |洪ビㇵ一・ㇵシビ火せせビミ一・一丁汎耗陽|
// |ビㇸ一　シ火汎労和和和労汎せシ　シビ允労|
// |ミ・ㇵ一火洪耗陽慶覇覇慶陽耗洪火一ㇵ丁丁|
// |ミ・一ヘ山李陽覇義群群陽陽陽陽和允シ・ビ|
// |丁・一シ允耗慶群李洪洪李労洪洪洪せミ一・|
// |シ一　ビ労義群労汎労允せ丁ミミミヘ・シ丁|
// |　ㇸミ洪陽奏汎洪山丁ㇵ　・・ㇵㇵㇵせ洪労|
// |・シ汎群奏允山ミ・一　　　・ㇵヘミビせ汎|
// |　火李和允丁一一ヘ丁ビ火ビミㇵ　・・ヘビ|
// |　ビ李汎丁一ヘ一火洪李李洪山丁シ一一ㇵ・|
// |一一山山ヘ一一シ・ミ允労せシ・ㇸㇵヘㇵ丁|
// |丁・ビ山ㇵㇵミ　シㇵㇸミビㇸㇵビ山せせせ|
// |丁・火せ一シ允火ㇵ・ヘ一　ㇸビせミ一・ㇸ|
// |シㇵ山丁　丁允洪せミヘ一　丁せㇵㇸシ丁ミ|
// |　ビ火・ミ一丁せ允汎火・ミ火ㇸシせ洪労允|
// |シ山ㇵシ允火ビビビせ一ミ火・丁洪奏義群労|
// |丁ビ　ビ李李李李労丁ㇸせヘㇵ允奏覇覇義労|
// +----------------------------------------+
// 2026 (April 10th) 18:05:01
// end signature
