#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,K;cin>>N>>K;
    using pii=pair<int,int>;
    vector<pii>P(N+1);
    for(int i=1;i<=N;i++)cin>>P[i].first>>P[i].second;
    sort(P.begin()+1,P.end());
    int lo=-1,hi=1e9; 
    vector<pii>lis={};
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        lis.clear();
        for(int i=1;i<=N;i++){
            auto [l,r]=P[i];
            if(lis.empty()||l-lis.back().first-1>=mid){
                lis.push_back({r,l});
            }else{
                // Pr <= r
                // printf("two i=%d %d %d\n",i,l,r);
                auto it=lower_bound(lis.begin(),lis.end(),pii{r,-1e13});
                if(it!=lis.end()){
                    // printf("i = %d, found %d %d\n",i,it->second,it->first);
                    if(it==lis.begin()){
                        if(r<=it->first)*it={r,l};
                    } else {
                        auto p=*prev(it);
                        if(r<=it->first&&l-p.first-1>=mid){
                            *it={r,l};
                        }
                    }
                }
            }
            // for(auto [r,l]:lis)printf("%d,%d ",l,r);printf("\n");
        }
        if(lis.size()>=K)lo=mid;
        else hi=mid;
    }
    if(lo==-1)cout<<-1<<endl;
    else cout<<hi<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火ビ丁ミミミ丁火せ允洪和耗|
// |和労允せビミシヘ一ㇸㇸㇸㇸㇵシ丁火允洪洪|
// |汎せ丁ヘ一ㇸ　・一ㇸㇸㇸ　　ㇸヘ丁せせせ|
// |ビシㇸㇸ　一・・一一ㇵ一一ㇵ一ㇸシシシシ|
// |ヘ・ㇸ　一　　ㇸヘシミ丁ミシヘㇸ・　　　|
// |ㇵ　ㇸ・ㇵ・　　ㇸ一ヘシシ丁ミシヘㇸ　ㇸ|
// |ㇵ　ㇸ・ヘヘㇵ一ㇵ一　　　・一シビ丁ㇵ　|
// |ヘ　　ㇵミミㇵ・シビミヘヘㇵ一　一ミビヘ|
// |一ㇸㇵ丁丁ヘ　ㇵ丁火せ火火ビミヘ　一丁丁|
// |　ヘビビヘビ汎李耗奏耗労汎允火ミㇸㇸヘㇵ|
// |ヘ火ビせ労奏群奏群奏和和李汎せミㇸ　・・|
// |ビせ洪奏奏奏和李李奏陽群耗洪せシ・　ミシ|
// |火汎奏群耗李洪汎和陽覇義奏労山ミ・ㇸせせ|
// |ミ労群奏李汎山山労耗陽陽耗李允ビㇵ・ㇸ火|
// |ヘ労群耗労允火ミせ洪和耗和洪山火シ　ㇵ・|
// |ㇵ労群和洪せ丁ㇵミせ允洪洪允火ミㇵㇸ一ミ|
// |ビ和奏労山丁ヘ・ㇵ丁火せせ火ミ一　一ヘヘ|
// |労群李允ビㇵシㇵ一ㇵシシシヘ・一ミビビビ|
// |群和汎ビシ・　　　　　　　ㇸㇵビ山汎允火|
// |奏労山ミㇵ一・一一ヘヘヘシシビ山労和汎火|
// +----------------------------------------+
// 2026 (June 20th) 22:46:32
// end signature
