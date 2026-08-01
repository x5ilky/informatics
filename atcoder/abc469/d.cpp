#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    set<int>a,b;
    using pii=pair<int,int>;
    vector<pii>A(M+1);
    for(int i=1;i<=M;i++)cin>>A[i].first>>A[i].second;
    auto t=[&](int v){
        int c=0;
        vector<int>freq(N+1);
        for(int i=2;i<=M;i++){
            if(A[i].first==v||A[i].second==v)c++;
            else {
                freq[A[i].first]++;
                freq[A[i].second]++;
            }
        }
        int a=0;
        for(int k=1;k<=N;k++){
            if(k==v)continue;
            if(freq[k]+c==M-1)a++;
        }
        return a;
    };
    bool good=1;
    for(int i=1;i<=M;i++){
        if(A[i].first==A[1].first||A[i].first==A[1].second||
        A[i].second==A[1].first||A[i].second==A[1].second);
        else good=0;
    }
    cout<<t(A[1].first)+t(A[1].second)-good<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇陽奏和労汎山せ火火火山允労耗陽覇覇|
// |義群耗労允せビミㇵ一ㇸㇸ一ヘ丁せ汎和群群|
// |労汎山丁ヘㇵ　一ヘ一ㇸ一ㇸ・一ミせ汎汎洪|
// |ビシ一一・ㇵ・ㇸヘシヘヘヘシシㇵ丁ミ丁ビ|
// |・ㇸㇵヘㇵ・ㇸ・　ㇸㇸ　・ㇸヘㇸ　　　ㇸ|
// |ヘ丁せビ　シㇵ・シ　ㇵミビビ丁ビシ・ヘミ|
// |ビ允允ミ　ミㇸㇵㇵㇸ丁山洪労洪洪洪火ヘ・|
// |山労せ　　ミㇸシㇸㇵせ労耗陽群奏群李允ミ|
// |労汎丁一一ミ・シ・ビ汎耗慶慶群陽義群労せ|
// |労ビ・　火ㇸシ　ミ汎奏慶奏李李李和奏李せ|
// |火ㇸ火山ヘㇵㇵヘ山耗群李允洪群奏和労洪ビ|
// |ヘビ労火ㇸシ・ミ允和汎允せ労洪允せビビミ|
// |ヘ丁汎山ヘ一ヘ一ビ汎和耗李允火シ一・　・|
// |一・ビ洪せヘ一ヘ　シせ洪洪火ヘ　一シミミ|
// |ヘㇵ　丁允山ミ　ヘ一ㇸシビビㇸ一丁火ビ火|
// |丁せヘ　ミ山允ビㇵ　ㇵ一　ㇸ　ミシ一・ㇸ|
// |火洪火ヘ・ミせ汎火ミㇵ一ㇸ一ヘㇵ・ヘミシ|
// |せ李允ビシ一ミ火山山せ火ㇵㇵㇸヘ火允汎山|
// |丁奏労汎せビ丁丁丁火山シㇸ・ミ允和奏耗汎|
// |火義群和洪洪允洪洪李せ一ヘㇵせ和義覇奏汎|
// +----------------------------------------+
// 2026 (August 1st) 23:41:51
// end signature
