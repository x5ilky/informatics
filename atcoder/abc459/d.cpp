#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;cin>>T;
    while(T--){
        string S;cin>>S;
        vector<int>freq(26);
        for(auto c:S)freq[c-'a']++;
        using pii=pair<int,int>;
        priority_queue<pii>pq;
        for(int i=0;i<26;i++)if(freq[i])pq.push({freq[i],i});
        string T;
        while(pq.size()>=2){
            auto t1=pq.top();pq.pop();
            auto t2=pq.top();pq.pop();
            T+=t1.second+'a';
            T+=t2.second+'a';
            if(t1.first-1>0)pq.push({t1.first-1,t1.second});
            if(t2.first-1>0)pq.push({t2.first-1,t2.second});
        }
        if(pq.size()==1&&pq.top().first==1){
            auto [_,c]=pq.top();pq.pop();
            T+=c+'a';
        }
        if(!pq.empty()){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
            cout<<T<<endl;
        }
    }
}

// begin signature
// +----------------------------------------+
// |労労李洪允山せ火丁ミミシミミビビビ火せ允|
// |山山允せビミシヘ一ㇸ・・ㇸ一ㇵㇵヘシミビ|
// |丁丁丁ヘ一ㇸ　・一ㇸ・・ㇸ・・ㇵミㇵㇵミ|
// |一ㇵㇸㇸ　ㇸㇸ　ㇸㇵ一一ㇸ　ㇸ・ヘ丁ㇵㇵ|
// |ㇸㇸ　　ㇵ　一ㇸㇸㇸ・・　・ㇸ　・一ヘヘ|
// |丁ミシㇵㇸヘ火允汎洪汎山ビヘ一ㇵㇵ一・・|
// |山山せ火丁允李耗群奏奏奏李汎火丁ビビミヘ|
// |労労労洪允和群耗群奏奏奏和労山山允允山火|
// |奏奏李汎耗奏奏耗李労李耗耗和洪洪李李労允|
// |群和労群群和労李耗奏奏義陽耗労耗群奏李允|
// |和和奏耗李奏奏耗和奏義慶群李耗義義奏労山|
// |李群和奏奏和労洪労奏群群和労耗奏耗李允ビ|
// |奏耗奏耗労汎李李洪労和李洪労労労洪洪允ビ|
// |和奏群和洪允李奏労耗和汎允洪汎山せせせ山|
// |耗群群李汎せ允労労洪李洪山せ山ビ丁シシシ|
// |群耗奏李允ビビせ山せ允允せ丁ビシㇵㇸ・・|
// |群耗耗洪せミヘミ丁ミビビミヘシㇸ・一ㇵㇵ|
// |奏奏李允丁ㇵ・ㇸㇸ一ㇵ一・一・一ミビビ丁|
// |奏耗洪山丁一・　ㇸ一ㇸㇸ・　ㇵビ山汎允火|
// |奏耗労山ビヘ・・一ㇸ一・一ㇸミ山労李汎火|
// +----------------------------------------+
// 2026 (May 23rd) 22:23:55
// end signature
