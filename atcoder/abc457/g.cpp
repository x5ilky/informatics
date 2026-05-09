#include <bits/stdc++.h>
using namespace std;
// dont laugh at me theres like no way this works
int main() {
    int N;cin>>N;
    using pii=pair<int,int>;
    // (x,t)
    vector<pii>pts(N);
    for(int i=0;i<N;i++)cin>>pts[i].second>>pts[i].first;
    auto solve=[&](vector<pii>pts)->int{
        multiset<int>pos;
        sort(pts.begin(),pts.end(),[](pii a,pii b){
            return make_tuple(a.second,-a.first)<make_tuple(b.second,-b.first);
        });
        int ans=pts.size();
        for(auto p:pts){
            auto it=pos.lower_bound(p.first);
            if(it!=pos.end()){
                ans--;
                pos.erase(it);
            }
            pos.insert(p.first);
        }
        return ans;
    };
    for(auto&e:pts)e={e.first-e.second,e.first+e.second};
    int ans=solve(pts);
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火ビ丁ミミミ丁ビせ允洪李耗|
// |和労允せビミシヘㇵㇸㇸㇸㇸㇵヘミ火山洪李|
// |汎せ丁ヘ一ㇸ・・一一ㇸㇸ・　・ㇵミ火允労|
// |ビシㇸㇸ・ㇸㇸ　ㇸ一ㇵㇵ一一一一ヘビ山洪|
// |ヘ・ㇸ　一　一一　・・　　・ㇸ　・シ火允|
// |ㇵ　一・ㇸㇸ一　ㇵ　一ヘシシヘシ一　ヘビ|
// |ㇵ　一・ㇸ一ㇸ一一・ヘ丁火せ火火ビシ一ㇵ|
// |ヘ　ㇸ　ㇸ一・ㇵㇸ一ミせ允允允汎汎せ丁ㇵ|
// |一ㇸ一ㇸ　ヘ　ㇵ・シミ丁丁丁ビビせ山せミ|
// |　・　ㇸ一・ㇵ　・・ㇸ一一一ㇵヘミビせミ|
// |　ㇸㇵ・・一ㇵヘㇵㇵㇸ一一ㇸ　・ㇵシビシ|
// |・　ㇸヘミ丁ㇵㇵシミ丁丁丁ミヘ一　一ミヘ|
// |　一ミビ丁ㇵシ丁火山山允山せ火ミヘ・一シ|
// |・ヘビせミヘ丁せ允洪労李李労汎山火ミ一・|
// |・シ火せミシ火允労和耗奏和洪山火丁シシヘ|
// |ㇸミせせミミせ汎李奏陽奏労允火ミㇵ・　・|
// |ㇵビ允火ヘビ允李奏義群和汎火シㇸ・ㇵヘㇵ|
// |丁允せミ丁允李奏慶陽和汎火シ・一ミビ火丁|
// |山山丁丁山労奏慶義耗洪せシ　ヘビ山汎允火|
// |汎せシ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (May 9th) 22:55:11
// end signature
