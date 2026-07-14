#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    // f(l,r,x) = c[x]* (min(l, x-1) + max(0, x-r-1) + 1)
    // f(l,r,x) = L(l,x) + R(r,x) + sum_x c[x]
    // L(l,X) = sum_{x=1}^{l+1} (x-1)c_x + l sum_{x=l+2}^X c[x]
    // R(r,X) = sum_{x=r+2}^X (x-r-1) c[x]
    //        = sum x c[x] - r sum c[x] - sum c[x]
    int N,J,D;cin>>N>>J>>D;
    using pii=pair<int,int>;
    vector<pii>B(N+1);
    for(int i=1;i<=N;i++){ B[i].first=i;cin>>B[i].second; }
    map<int,int>freq;
    for(int i=1;i<=J;i++){
        int l,r;cin>>l>>r;
        freq[r-l+1]++;
    }
    map<int,int>C,L1,R1;
    C[0]=L1[0]=R1[0]=0;
    for(auto [i,c]:freq){
        C[i]=C.rbegin()->second+c;
        L1[i]=L1.rbegin()->second+(i-1)*c;
        R1[i]=R1.rbegin()->second+i*c;
    }
    auto qry=[&](map<int,int>&M,int v){
        auto it=M.upper_bound(v);
        return it==M.begin()?0:(--it)->second;
    };
    auto R2=[&](int r,int X){
        return qry(R1,X)-r*qry(C,X)-qry(C,X);
    };
    auto query=[&](int l,int r,int X){
        int L=qry(L1,l+1)+l*(qry(C,X)-qry(C,l+1)),R=R2(r,X)-R2(r,r+1);
        return L-R+qry(C,X);
    };
    sort(B.begin()+1,B.end(),greater<>());
    set<int>pos;map<int,int>ans;
    for(int i=1;i<=N;i++){
        auto [v,j]=B[i];
        int r=1ull<<40,l=1ull<<40;
        auto rit=pos.lower_bound(j);
        if(rit!=pos.end())r=(*rit)-j;
        if(rit!=pos.begin())l=j-*prev(rit);
        ans[v]=query(l-1,r-1,r+l-1);
        pos.insert(j);
    }
    for(int i=1;i<=N;i++)cout<<ans[i]<<endl;
}

// begin signature
// +----------------------------------------+
// |李労洪汎汎汎允せビ丁ミミ丁ビせ允洪李奏義|
// |せ火ビビビビミヘ一・・・ㇸㇵシビせ汎和群|
// |ヘ一一ㇸ一ㇸ　一一・　　　・ㇸシビ允労労|
// |ㇸㇵㇵㇵ一ㇸ　　　　　ㇸㇵミシヘミせせ山|
// |丁火ミ一　ㇸㇵシシシシㇵシビビビミシシシ|
// |山丁一　ㇵミビせ火ビビ火ビシミヘㇸ　　　|
// |せミㇸ一ミ火ビミヘシミ丁ミシヘㇵㇸㇸミミ|
// |火ヘ　ヘ丁シㇵㇸㇸㇸㇵヘシミヘㇵㇵㇵ　シ|
// |丁ㇸㇵヘㇸ　　ヘミビせ山允允せ丁一一ㇸㇸ|
// |一・ㇸㇸヘヘ丁ビ火せせ山汎労李允丁ㇵㇵヘ|
// |・・シㇵミ丁ミヘヘヘシ丁火允允山丁ヘ　ㇸ|
// |一　ヘシㇵミヘミ丁ビ山允山火ビ丁火ミシㇵ|
// |ミ一ヘㇵ丁ミ火山允汎汎允せビ火山允山せ丁|
// |ヘ・ㇵシミ火允洪李耗洪山允允允山ビミ丁丁|
// |ヘㇸ　シ丁せ洪和群陽奏李允火丁ビビ丁丁ビ|
// |ㇵㇸㇵ　ヘビ允労和奏奏奏和労允山せせ山汎|
// |ㇸヘ丁ㇵ　ヘビせ汎洪洪洪汎允火山労労李耗|
// |ㇸ丁せ丁ヘㇸヘミビ火火火ビせ汎李群群陽慶|
// |シせ丁せビミシシミ丁ビ山汎李奏義覇覇覇覇|
// |シせビ汎允山山山山允洪李耗陽慶覇覇覇覇覇|
// +----------------------------------------+
// 2026 (July 14th) 15:19:35
// end signature
