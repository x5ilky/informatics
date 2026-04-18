#include <bits/stdc++.h>
using namespace std;
void solve(){
    string S,T;cin>>S>>T;vector<char>a,b;
    {
        vector<char>s;
        for(auto c:S){
            s.push_back(c);
            while(s.size()>=4){
                if( s[s.size()-1]==')'&&
                    s[s.size()-2]=='x'&&
                    s[s.size()-3]=='x'&&
                    s[s.size()-4]=='('){
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.push_back('x');
                    s.push_back('x');
                }else break;
            } 
        }
        a=s;
    }
    {
        vector<char>s;
        for(auto c:T){
            s.push_back(c);
            while(s.size()>=4){
                if( s[s.size()-1]==')'&&
                    s[s.size()-2]=='x'&&
                    s[s.size()-3]=='x'&&
                    s[s.size()-4]=='('){
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.push_back('x');
                    s.push_back('x');
                } else break;
            }
        }
        b=s;
    }
    if(a.size()!=b.size()){
        cout<<"No\n";return;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";
};
int main() {
    int T;cin>>T;
    while(T--)solve();
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎山火ビ丁丁ビビビ火山汎労耗|
// |義奏李汎山火丁ヘ一ㇸ・・ㇸㇸ一ㇵミビ山洪|
// |李汎火ミㇵ一　一一ヘシシヘ一・・ㇸヘビ允|
// |山ミ一一　ㇵヘ丁火山山山火丁ヘ　ㇸ・シせ|
// |ミㇸ一・一ミせ汎労李和李労允火シ　ヘ・ミ|
// |ㇵ・ㇸㇵヘ火汎和奏陽義義群耗労山丁ㇸㇵ一|
// |ㇵ一・ㇵヘせ洪耗義覇慶義陽陽陽耗汎ビㇵ一|
// |火火ビヘヘせ労群陽奏耗和　ㇸㇸㇸ　洪ビ一|
// |洪労汎火ミ允和奏和洪ヘ丁ビビ丁ミシヘ一　|
// |群奏洪火汎李李汎ミせ火火火丁シヘヘㇵㇵ一|
// |陽和允耗和汎ミシヘㇵ一ㇵㇸㇸ　ㇸ一ㇸ　・|
// |李李奏労　ㇵ・・一ㇵ一一・・ヘㇵ　ㇵㇵ　|
// |汎群李山ㇸㇸㇵ　ㇸ一ㇵ一ㇸ　・一シㇸ　ㇵ|
// |労群労せ・ㇵ　ヘ一　　・　ㇸㇵ　　ㇵㇵ・|
// |李陽李山一ㇸ一ㇵ・ヘシミミシ一一ㇵㇵㇸ　|
// |せ陽李山ヘ　シ　ヘビせ允允山火ビシ一・ㇸ|
// |汎群洪火一ㇵㇸㇵビ汎李耗和汎ビㇵ・ㇵシヘ|
// |奏李山ㇵ一　ヘ火洪耗義耗允丁ㇸㇵビ山山火|
// |耗允ヘㇸ・丁火洪奏慶耗汎丁・シせ労和労山|
// |李せㇸ・シ丁允和義陽労せㇵ一火労群群労允|
// +----------------------------------------+
// 2026 (April 18th) 22:17:39
// end signature
