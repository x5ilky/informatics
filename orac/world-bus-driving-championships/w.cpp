#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("busin.txt","r",stdin);
    freopen("busout.txt","w",stdout);
    int N,K;cin>>N>>K;
    vector<int>σ(N+1);for(int i=1;i<=N;i++)cin>>σ[i];
    set<int>see;for(int i=1;i<=K;i++){int v;cin>>v;see.insert(v);}
    vector<int>r;
    int ans=0;
    for(int i=1;i<=N;i++)r.push_back(i);
    for(int k=1;k<=__lg(N);k++){
        // for(auto a:r)printf("%d ",a);
        // printf("\n");
        vector<int>r2;
        for(int i=0;i<r.size();i+=2){
            r2.push_back(σ[r[i]]>σ[r[i+1]]?r[i]:r[i+1]);
            auto p1=see.find(r[i]),p2=see.find(r[i+1]);
            if(p1!=see.end()&&p2!=see.end()){
                see.erase(p1);see.erase(p2);
                ans++;
            }
        }
        r=r2;
    }
    ans+=see.size();
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |群耗労洪允せ火火ビ火火火火せ山允洪労和群|
// |李洪山火丁ミシヘヘヘヘヘシミ丁火山汎労耗|
// |允火ミヘ一ㇸㇵㇸ　　　　・一ヘミ火山洪労|
// |丁ヘㇸㇸ一　ㇸㇸ・　　　　ㇸㇸヘ丁火山汎|
// |ヘ・ㇸ・・ㇸㇸ一ㇸ・・　　・ㇵㇵヘシ丁せ|
// |ㇵ　　ㇸㇵシヘ一一　一ヘシヘヘシヘㇵ一シ|
// |ㇵ　ㇸヘミシ一ㇸㇸ・ㇵㇵシシ丁火ビビシ一|
// |ㇵ　ㇵミ丁ㇵ　ㇵ・一ミビビ火火ビ丁火火丁|
// |・一ミミシㇸ　ㇵ・ㇵヘシヘシシミ丁火火せ|
// |一ㇸミヘㇸ・ㇵ　・　　　　　・一ヘミビせ|
// |ㇸシミ一一ヘシシシヘㇵヘヘㇵ一　・ㇵミ火|
// |シミㇵシ丁ビ火せ火ビビビビ丁ミㇵㇸ・ヘ丁|
// |ミシ丁火山允汎洪汎允允允允山せビシ一・ヘ|
// |ㇵシ火山洪労和和李労李李労汎山火ビ丁ㇵ　|
// |ㇸミ火允労和奏群李和奏和洪山火ミヘㇵ一ㇵ|
// |ㇵミせ汎和奏義群李奏群和汎せ丁ㇵ・　ㇸ・|
// |ヘビ允労奏義義奏奏義耗労山ビヘ　一シミシ|
// |丁山労耗義慶群奏義奏李允ビヘ　ヘ丁火せビ|
// |せ洪耗陽覇陽耗義群李汎火ヘ　ヘビ允洪汎火|
// |允労奏慶慶奏群義耗労山丁一ㇸミ山洪李允ビ|
// +----------------------------------------+
// 2026 (April 17th) 20:57:16
// end signature


