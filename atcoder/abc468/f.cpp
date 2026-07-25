#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    int ans=0;
    vector<int>remove(N+1);
    int m=0;
    for(int i=1;i<=N;i++)if(A[i]>m){
        m=A[i];remove[i]=true;
        ans++;
    }
    using pii=pair<int,int>;
    vector<pii>lis;
    for(int i=1;i<=N;i++){
        if(remove[i])continue;
        if(lis.empty()||A[i]>lis.back().first)lis.push_back({A[i],i});
        else *lower_bound(lis.begin(),lis.end(),pii{A[i],i})={A[i],i};
    }
    ans+=lis.size();
    for(auto [v,i]:lis)remove[i]=true;
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |群耗李洪允せ火火ビ丁ミミミ丁ビせ允洪李李|
// |李汎山火丁シヘㇵㇵㇸㇸㇸㇸㇵヘミ火山山允|
// |山ビミㇵㇸ　　・　ㇸ一ㇵㇵㇵㇵㇵミ丁丁丁|
// |ミㇵ　ㇸㇵシ・一一ㇵㇵㇵヘシシシヘ一一ㇵ|
// |一・ㇵシヘ・ㇸㇸ　・・　　・ㇵシミシㇵ・|
// |　ㇵ一　　ㇸ一　ㇵ　一ヘシシヘシシシミヘ|
// |　ㇸ・一　シㇸ一一・ヘ丁火せ火火丁ビビヘ|
// |・　ㇸヘミシ・ㇵㇸ一ミビせ山山山せ丁ビ火|
// |・ㇸㇵシ丁ヘ　ㇵ・一ㇵヘシ丁ビ火火ミシ火|
// |　・ミㇵㇸ　ㇵㇸ一ㇸ・　ㇸ一ㇵヘミビシ火|
// |　ㇵ　ㇸㇵシミシㇵ一ㇸ一ㇸㇸ　・ㇵシ丁せ|
// |・ㇸヘ丁丁ヘㇸㇵシミ丁丁丁ミヘ一　一ミ火|
// |ㇸシビ丁ヘㇸシ丁火山山山山せビミヘ・一ミ|
// |一丁せミ一ヘ丁せ允洪労李李労汎山火ミ一・|
// |一丁せミㇸシビ允洪和耗奏和洪山火丁ミシヘ|
// |一丁せミㇸミせ汎李奏陽奏労允火ミㇵㇸ　・|
// |ヘ火火ヘヘビ允李奏義群和汎火シㇸ・ㇵヘㇵ|
// |ビせシ一丁允李奏慶陽和汎火シ・一ミビ火丁|
// |山丁ㇸ丁山労奏慶義耗洪せシ　ヘビ山汎允火|
// |火シヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (July 25th) 23:30:26
// end signature
