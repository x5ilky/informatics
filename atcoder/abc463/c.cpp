#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>H(N+1),T(N+1);
    using pii=pair<int,int>;
    multiset<int>M;priority_queue<pii,vector<pii>,greater<pii>>dq;
    for(int i=1;i<=N;i++){
        cin>>H[i]>>T[i];
        M.insert(H[i]);
        dq.push({T[i],H[i]});
    }
    int Q;cin>>Q;
    vector<int>q(Q+1),qq;
    for(int i=1;i<=Q;i++)cin>>q[i];
    qq=q;
    sort(q.begin()+1,q.end());
    map<int,int>ans;
    for(int i=1;i<=Q;i++){
        while(dq.size()&&dq.top().first<=q[i]){
            M.erase(M.find(dq.top().second));
            dq.pop();
        }
        ans[q[i]]=*M.rbegin();
    }
    for(int i=1;i<=Q;i++)cout<<ans[qq[i]]<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪汎山火ビビビ火山汎労耗群群|
// |慶群李汎山火丁ミヘ一ㇸㇸ一ㇵミビ山労労労|
// |和汎せミㇵ一・・ㇵ一ㇸㇸ一・ㇸヘビ火火せ|
// |山ミ一一・ㇸ一　一ヘヘヘ一　一・一一一ヘ|
// |ミㇸ・・一一一　　ㇸㇸ　　ㇸㇸ　ㇵヘㇵㇸ|
// |ㇵ・ㇵミビヘㇸ・ヘ　　　ㇸㇸ　ㇵㇵ一シビ|
// |ㇸ一丁せビビビビミㇵ・　　　　ㇸ　ㇸ・ㇸ|
// |・シせ山汎洪汎火丁シヘ一・ㇸシミヘ一ㇵ・|
// |ミせ洪李和洪山ビシㇵ一ㇸㇸ一　ㇵビビヘ・|
// |允李耗労山丁シ・ㇸㇵヘㇵ・ㇸㇸ・シせビㇵ|
// |耗李允ビㇵ一一ㇵ火せせビシ一　　シせせシ|
// |労山ミ・ㇸヘ・シ山李労允せ丁ヘシヘせ山ミ|
// |山ミㇸㇵㇵ一ㇵ一丁山労和労汎せ山ミ丁汎火|
// |火ヘ　シ火ㇵㇸヘ　シ火允洪洪洪允火ミビ汎|
// |火ヘ　ミ山せシ　ヘ一ㇸシ丁ビ丁火火ビ允允|
// |火ㇵ一　シせ山丁一　ㇵㇸ　・ㇸㇸシ火洪耗|
// |丁　シヘ・シ火山ビシㇵㇸㇸ一ヘ丁せ洪耗義|
// |一ヘせビヘ一シビせせ火ビビせ山洪和群慶覇|
// |ㇸビ洪山火丁ミミ丁ビせ允労李耗群慶覇覇覇|
// |ヘせ李李洪汎允允汎洪李耗群義覇覇覇覇覇覇|
// +----------------------------------------+
// 2026 (June 20th) 22:09:08
// end signature
