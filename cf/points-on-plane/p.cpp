#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    using pii=array<int,3>;
    vector<pii>P(N+1);for(int i=1;i<=N;i++)P[i][2]=i,cin>>P[i][0]>>P[i][1];
    const int B=1000;
    vector<vector<pii>>blocks(B+1,vector<pii>());
    for(int i=1;i<=N;i++)blocks[P[i][0]/B].push_back(P[i]);
    for(int i=0;i<=B;i++)sort(blocks[i].begin(),blocks[i].end(),[](pii a,pii b){
        return tie(a[1],a[0],a[2])<tie(b[1],b[0],b[2]);
    });
    vector<int>path;int dir=0;
    for(int i=0;i<=B;i++){
        if(dir)for(int j=0;j<blocks[i].size();j++)path.push_back(blocks[i][j][2]);
        else for(int j=blocks[i].size()-1;j>=0;j--)path.push_back(blocks[i][j][2]);
        if(blocks[i].size())dir=!dir;
    }
    for(auto p:path)cout<<p<<" ";cout<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇陽奏和労汎せ火ビビビせ山洪李群慶覇|
// |覇義耗労允せビシ一・　　ㇸㇵミ火允李群覇|
// |奏労山丁ヘㇵヘㇸ　・ㇸ・一　・シ火洪耗奏|
// |允丁一一ヘ　ㇵ一　・ㇸ・　一　ヘ火山允洪|
// |丁ㇸ一一ㇸㇵ　・ㇵ一ㇸ　・ㇸ・・ヘ火せ火|
// |シ・ヘ　シ　ㇵㇵシ　ㇸㇸㇸ　・　　一火洪|
// |シ・ヘ　ヘㇸヘㇵㇵ一丁山洪允丁ヘ・ㇵ・ミ|
// |ミ・ㇵ・一ヘ・シㇸヘせ労奏陽群労せシ　・|
// |ヘ一ヘ・一ミ・シㇸビ洪奏慶義群耗洪せシ　|
// |　ㇸ・ミ火ㇸシ　ミ汎奏耗耗李汎汎李汎ビㇸ|
// |・ㇵ允山ヘㇵㇵヘ山汎允允山允允允洪汎丁ㇸ|
// |・ビ労火ㇸシ・ミ允洪允せせせ火ミ山洪丁　|
// |　丁汎山ヘ一ヘ一ビビシㇵ一一ㇵシ丁允火一|
// |ㇸ・ビ洪せヘ一シ　ㇵ　ㇵヘシヘㇸ・シ火丁|
// |火ㇵ　ミ允山ミ　ヘ一ヘビ山允允せ丁ㇵ・ミ|
// |労せヘ　ミ山汎ビㇵ一ビ汎李和允丁一　ㇸ・|
// |奏汎火ヘ・ミせシ・丁汎耗耗汎丁・ㇵ丁火ビ|
// |耗李允火シ一ミ　丁汎奏奏汎丁　ミ山労労汎|
// |耗奏李汎せビ・ミ汎奏群洪丁　丁汎耗陽奏洪|
// |奏慶群耗允シ一せ李義和山ヘㇵせ和慶覇群洪|
// +----------------------------------------+
// 2026 (May 25th) 19:39:36
// end signature

