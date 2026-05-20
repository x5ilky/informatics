#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    vector<int>D(N+1);
    int L;
    for(int i=1;i<=N;i++){
        int d;cin>>d;
        if(i==N)L=D[N]+d;
        else D[i+1]=D[i]+d;
    }
    // for(int i=1;i<=N;i++)printf("%d ",D[i]);
    vector<vector<int>>jump(N+1,vector<int>(21));
    using pii=pair<int,int>;
    auto next=[&](int i,int k){
        int mid=-1,n=0;
        auto it=upper_bound(D.begin()+1,D.end(),D[i]+k);
        if(it!=D.begin()+1)mid=prev(it)-D.begin(),n=mid-i;
        if(D[i]+k>=L){
            auto it2=upper_bound(D.begin()+1,D.end(),(D[i]+k)%L);
            if(it2!=D.begin()+1){
                mid=prev(it2)-D.begin();
                n=(mid+N)-i;
            }
        }
        return pii(mid,n);
    };
    for(int i=1;i<=N;i++){
        auto [mid,c]=next(i,K);
        auto [end,c2]=next(mid,K);
        jump[i][0]=c+c2+1;
    }
    for(int k=1;k<=20;k++){
        for(int i=1;i<=N;i++){
            jump[i][k]=jump[i][k-1]+jump[(i+jump[i][k-1]-1)%N+1][k-1];
        }
    }
    int ans=1ull<<60;
    for(int i=1;i<=N;i++){
        int d=0,j=i,c=0;
        for(int k=20;k>=0;k--){
            if(d+jump[j][k]<=N){
                d+=jump[j][k];
                j+=jump[j][k];
                c+=1<<k;
                j=(j-1)%N+1;
            }
        }
        ans=min(ans,d==N?c:c+1);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |允山山山允山せビ丁ミシビ火火ビせ山洪李耗|
// |丁丁丁丁ビミシヘヘシミ丁火允洪山ビ山洪李|
// |ㇸㇸㇸ一一ㇸヘシシミ丁丁丁せ允允火火山汎|
// |一一一・ㇸ・　　・一ヘミビビビ丁丁ミビ山|
// |丁シヘ・・ㇸヘヘㇵㇸ　ㇸシビ丁シㇵ一ヘ丁|
// |一・　・　　　ㇸㇵシシ一　ㇵシシㇵ　　一|
// |　　一シシシシㇵ一　ㇸ一一一・シ火シㇸ　|
// |ㇵ　ㇸ丁ミヘㇵㇸㇸㇸㇸㇸㇸ・　・シ火ミㇸ|
// |一ㇸㇵヘㇸㇸ・・ㇵㇵㇸ　・ㇸヘ一一丁ビヘ|
// |　・ㇸ・一ㇵ・ㇸ　・一ㇸㇸ一一ヘミビビㇵ|
// |　・ヘㇵ・・一ㇸ　ㇸ一一一ㇸ・　一シミ・|
// |一ヘ・ㇸヘ・・ㇵシ丁丁丁丁ミヘ一　一ヘ・|
// |ヘ・一ヘ　一シビせ山允允允山火丁ヘ・ㇸ・|
// |ㇵ　ヘ一・ヘビせ汎洪李李李労汎山火ミ一　|
// |ㇵ　　一・シ火允労和奏奏李汎せビミシヘヘ|
// |ㇵ・一　ㇸミせ洪和奏義耗労允ビシ一　　　|
// |ㇸ一シ　ヘビ允李奏義群李汎火シ・ㇸヘシヘ|
// |ㇸミㇸㇵビ允李群慶陽和汎火ヘ　ㇵ丁火せビ|
// |シ一ㇸ丁山労奏慶義耗洪火シ　ヘビ允洪汎火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ丁山李和汎火|
// +----------------------------------------+
// 2026 (May 20th) 20:07:09
// end signature


