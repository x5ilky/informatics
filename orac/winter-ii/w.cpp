#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    using pii=pair<int,int>;
    vector<vector<pii>>rows(30001),cols(30001);
    for(int i=1;i<=N;i++){
        int x,y;cin>>x>>y;
        rows[y].push_back({x,i});
        cols[x].push_back({y,i});
    }
    
    for(int i=0;i<=30000;i++)sort(rows[i].begin(),rows[i].end());
    for(int i=0;i<=30000;i++)sort(cols[i].begin(),cols[i].end());

    vector<vector<pii>>g(N+1);
    for(int i=0;i<=30000;i++){
        for(int j=0;j<(int)rows[i].size()-1;j++){
            g[rows[i][j].second].push_back({rows[i][j+1].first-rows[i][j].first,rows[i][j+1].second});
            g[rows[i][j+1].second].push_back({rows[i][j+1].first-rows[i][j].first,rows[i][j].second});
        }
        for(int j=0;j<(int)cols[i].size()-1;j++){
            g[cols[i][j].second].push_back({cols[i][j+1].first-cols[i][j].first,cols[i][j+1].second});
            g[cols[i][j+1].second].push_back({cols[i][j+1].first-cols[i][j].first,cols[i][j].second});
        }
    }
    vector<int>dist(N+1,1ull<<60);
    priority_queue<pii,vector<pii>,greater<pii>>pq;dist[1]=0;pq.push({0,1});
    while(!pq.empty()){
        auto[d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [w,v]:g[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<(dist[N]>=(1ull<<60)?-1:dist[N])<<endl;
}

// begin signature
// +----------------------------------------+
// |火丁ミシシミ丁火せビ丁丁ビ火せ允労和和和|
// |ㇸ　・ㇸ・　・ㇵ一・　　・一シビ山山山允|
// |ミ丁ビビ丁シㇸ・ㇵヘヘ一一ㇸ　ヘヘヘシミ|
// |汎洪山ミㇸㇸシシヘミミミシ一ㇸ一一ㇸ　・|
// |李山ミ・ㇵビミ火山允汎允山火ビ火火ビミ一|
// |労せヘ・ミシせ汎李耗耗李汎せビビ丁火允せ|
// |李山シ・丁丁允李奏義群労汎洪汎洪允ビシミ|
// |和山シ・丁ビせ洪和和和洪和奏奏耗耗洪火ヘ|
// |労火ㇵ　　ㇸ・ビ汎ㇸシ丁ビビビ耗陽耗汎丁|
// |允シシミヘ洪汎シミ丁火せ允洪洪汎山耗汎丁|
// |丁火ヘ労允　　・　ㇸヘビせ山汎允允汎山シ|
// |火せ洪一シ丁ビ丁ミ・　ヘビビミミミ丁せ一|
// |丁洪せビ山丁せ汎ビ・一ヘヘビシ　　・ㇵㇵ|
// |火汎丁山せミ允和山シシ一　ㇵシ一　ㇵヘ一|
// |火洪ビ允山シ山李洪ビシシ丁ㇵㇸ・ヘ丁ビ火|
// |山洪ビ汎山シ山李和山允允山火ヘヘシ一ㇸㇸ|
// |允允火労せシ允耗李労耗和和汎ビㇵ　ㇵシヘ|
// |洪ビ汎汎ミ火労奏李陽慶奏汎丁ㇸㇵビ山允せ|
// |せせ労火ミ允耗李群覇奏洪丁・シ山労和李允|
// |丁せ洪火丁汎耗労奏陽李せㇵ一火労陽慶耗允|
// +----------------------------------------+
// 2026 (May 14th) 20:55:14
// end signature
