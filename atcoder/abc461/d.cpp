#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int R,C,K;cin>>R>>C>>K;
    vector<vector<int>>A(R+1,vector<int>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++){
            A[i][j]=S[j-1]-'0';
        }
    }
    vector<vector<int>>psA(R+1,vector<int>(C+1));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            psA[i][j]=A[i][j]+psA[i-1][j]+psA[i][j-1]-psA[i-1][j-1];
        }
    }
    int ans=0;
    using pii=pair<int,int>;
    vector<pii>freq(501*501+1);
    int timer=0;
    auto get=[&](int i)->int&{
        if(freq[i].second!=timer)return freq[i].second=timer,freq[i].first=0;
        return freq[i].first;
    };
    for(int i=1;i<=R;i++){
        for(int j=i;j<=R;j++){
            vector<int>psSum(C+1);
            for(int k=1;k<=C;k++)psSum[k]=psSum[k-1]+psA[j][k]-psA[j][k-1]-psA[i-1][k]+psA[i-1][k-1];
            timer++;
            freq[0]={1,timer};
            for(int k=1;k<=C;k++){
                ans+=psSum[k]-K>=0?get(psSum[k]-K):0;
                get(psSum[k])++;
            }
        }
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |シㇵ一ㇸㇸ一ㇵヘミミミヘㇵ一一ㇵヘシ丁火|
// |　・一一一一・　ㇸ・　・ㇸㇸㇸ・　ㇸㇵミ|
// |シ丁丁ビ丁ミヘ一ㇸ一ㇸ・　・ㇸ・・ㇸ・ㇵ|
// |せ允允山ビミㇵㇸ　一・　・一ㇵㇵ一ㇸ　ㇸ|
// |労洪山丁ヘㇸ　ㇸ　ㇸ・　　・　・・・ㇵ・|
// |李汎火シ一・・・ㇵ　ㇸㇵシシシ一　ㇵ・ㇸ|
// |李允火シ・ㇸㇵヘㇵㇸ　ㇸ一ㇵヘ丁シ一・ㇵ|
// |李允ビヘㇵシシㇵ・ㇸㇵシ丁ビビビ丁丁ㇵ　|
// |労山火ミ丁シㇸㇵ・シ丁ミシㇵシ丁火せミㇸ|
// |允せミ一一　ㇵ　ヘ一ㇸ・・・ㇸㇵシ丁ミㇸ|
// |せシ・一一ㇸㇸ・・一ㇵㇵㇵ一ㇸ　ㇸヘヘ　|
// |ミㇸ一ミ・ㇵㇸヘミ丁ビビビ丁シㇵ・ㇸㇵ・|
// |シ　ヘㇵ　ㇵミビせ允汎汎允山せビシㇸ・・|
// |ミㇸ一一・シビ山汎労李和和洪允せ火丁ㇵ　|
// |火ヘ　一ㇸミ火汎労耗奏奏李汎せ丁シヘㇵヘ|
// |せミㇸ　一ミせ洪和群陽耗労山ビヘㇸ　・　|
// |火ヘ　　ヘ火汎李群慶群李允ビヘ・一ヘミシ|
// |ミㇸ・ㇵビ允李群慶陽和汎火ヘ　ヘ丁せせ火|
// |ㇵ・一丁山労奏慶陽耗洪火シ　ヘ火允労汎せ|
// |　　ヘ火汎和陽覇群李允丁一ㇸ丁山李和汎火|
// +----------------------------------------+
// 2026 (July 20th) 17:10:33
// end signature

