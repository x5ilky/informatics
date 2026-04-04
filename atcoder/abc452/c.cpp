#include <bits/stdc++.h>

using namespace std;

int main() {
    using pii=pair<int,int>;
    int N;cin>>N;
    vector<pii>schema(N+1);
    for (int i=1;i<=N;i++)cin>>schema[i].first>>schema[i].second;
    
    int M;cin>>M;
    vector<string> S(M+1);
    for (int i=1;i<=M;i++)cin>>S[i];
    vector<vector<vector<bool>>> e(11,vector<vector<bool>>(26,vector<bool>(11,false)));
    for (int i=1;i<=M;i++){
        for(int j=0;j<S[i].size();j++){
            e[S[i].size()][S[i][j]-'a'][j]=true;
        }
    }
    for(int i=1;i<=M;i++){
        if(S[i].size()!=N){
            cout<<"No\n"; continue;
        }
        for (int j=1;j<=N;j++){
            if(!e[schema[j].first][S[i][j-1]-'a'][schema[j].second-1]) {
                cout<<"No\n"; goto skip;
            }
        }
        cout<<"Yes\n";
skip:;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義群和労洪汎允山せせせ山汎労和群義覇|
// |慶群和洪山火丁ミミヘㇵㇵヘシ丁せ汎李奏慶|
// |和汎せミㇵ一一　ㇸ一ㇵ・　・ㇵミせ洪耗陽|
// |山丁一一一ㇸヘ・　　　　ㇸㇸㇸ一丁山李群|
// |ミㇸ一ㇸㇵㇸ一ㇵ一ㇸㇸ　　・ㇸㇵ一丁允和|
// |ヘ・ヘ・ㇵㇵ一ㇵヘ　ㇵミ丁丁丁シㇵ一丁允|
// |シ・ㇵ・ㇵㇵシㇵㇵㇸミせ汎汎汎汎山ビシミ|
// |シ・ㇵ・一・・ヘㇸㇵビせ汎李奏耗和洪山丁|
// |ヘㇸㇵㇵヘシ・シ・丁火火火允李群義奏労山|
// |　ㇸ・せビ・シ　ミ允労労洪汎洪奏覇陽和允|
// |・・允せㇵ一一ㇵせ李陽群奏和労群覇義和允|
// |・ビ火シㇸヘ・シ山李群慶慶群和群慶奏洪山|
// |　ミ一ビヘ一ㇵㇸ丁允李奏群奏群奏奏李汎允|
// |ㇸ・ㇸビ火ㇵㇸヘ　シ火允洪洪洪労労允汎労|
// |ビ一　シ山せシ　ヘ一ㇸシ丁ビ丁火火ビ允和|
// |洪火ヘ　シせ山丁一　ㇵㇸ　・・ㇸシ火洪耗|
// |和汎ビヘ・シ火允ビシㇵㇸㇸ一ヘ丁山洪耗労|
// |奏洪ビビヘ一シビせせ火ビ火せ允洪和和汎せ|
// |耗洪火山火丁ミミ丁ビせ允労李耗陽労和李洪|
// |群李允労洪汎汎汎汎洪李耗陽義覇奏群義耗奏|
// +----------------------------------------+
// 2026 (April 4th) 23:13:54
// end signature
