#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
using pii=pair<int,int>;
using oset = tree<pii, null_type, less<pii>, rb_tree_tag,
                  tree_order_statistics_node_update>;
int main() {
    oset O;int N,Q;cin>>N>>Q;
    for(int i=1;i<=N;i++)O.insert({0,i});
    vector<int>freq(N+1);
    int b=0;
    for(int i=1;i<=Q;i++){
        int t,u;cin>>t>>u;
        if(t==1){
            O.erase({freq[u],u});
            O.insert({++freq[u],u});
            if(O.begin()->first>b)b++;
        }else if(t==2){
            cout<<N-(int)O.order_of_key({u+b,0})<<endl;
        }
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎允汎汎労和奏陽慶覇覇覇覇|
// |慶奏李汎山火丁ミミ丁ビせ汎労和奏陽覇覇覇|
// |和汎せ丁ヘㇸヘ丁ビビビビ火山汎李耗陽覇覇|
// |山丁ㇵ・シ丁シㇵㇸ・ㇸ一ヘミ火允労奏義覇|
// |丁ㇸ・ミシㇸ・ㇵ丁火ビ火ミㇸㇵ丁山労奏義|
// |シ　ㇵシ・一ビビシㇵ一一ㇵシ丁シシ火洪和|
// |シ　一ヘ・シ火シ・ㇸ一　ㇸ一ㇸㇵ丁シ丁せ|
// |シ　一ヘミビ丁一ㇸㇵ・シ丁丁ㇵㇸ一ㇸシ一|
// |ヘ一ヘ火允火ㇵㇸヘ　ミせ汎允丁一ㇵシㇵㇵ|
// |　ㇸビ洪せヘㇸヘ・ミ允李耗洪ビ一・　・　|
// |　シ允山ヘㇸヘㇸビ汎耗義耗汎火ミミシ一・|
// |ㇸビ汎丁・シ　ミ允耗義義耗李允汎允せミㇸ|
// |ㇸミ允丁・シ　ミ允耗義覇慶群李李労洪山シ|
// |・一ビ山シ・ヘㇸビ汎和群慶群和汎火ビ火せ|
// |ビ一ㇸ丁山シ・ヘ・ミせ洪和耗和耗労火ヘせ|
// |汎ビㇵㇸミせヘ・シ　ㇵ丁せ允允允汎汎ビビ|
// |李允丁ㇵㇵ丁ビㇵ・シ・ㇸヘミミミ丁丁せ火|
// |山洪せ丁ㇵㇵ丁ミ一　一一・　・ヘビ汎李汎|
// |洪労汎せビミシシミヘㇵㇵヘミ火允労奏奏洪|
// |耗汎李労汎允山山允せせせ山汎労和群義和允|
// +----------------------------------------+
// 2026 (May 23rd) 22:16:33
// end signature

