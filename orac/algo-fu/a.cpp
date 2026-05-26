#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,T;cin>>R>>C>>T;
    vector<int>A(R*C+1),B(R*C+1);
    auto id=[&](int r,int c){return (r-1)*C+c-1;};
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)cin>>A[id(i,j)];
    for(int i=1;i<=T;i++){
        int r,c,v;cin>>r>>c>>v;
        B[id(r,c)]=v;
    }
    int SR,SC;cin>>SR>>SC;
    int v=0,cnt=0;
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>q;q.push({0,0});
    vector<int>seen(R*C+1);
    multiset<int>ts;
    while(true){
        // printf("loop v = %d\n",v);
        while(q.size()){
            auto [w,u]=q.top();
            int r=u/C+1,c=u%C+1;
            if(w>v)break;
            q.pop();
            if(seen[u])continue;
            seen[u]=true;
            if(B[u]>0)ts.insert(B[u]);
            if(r<R&&!seen[id(r+1,c)])q.push({A[id(r+1,c)],id(r+1,c)});
            if(r>1&&!seen[id(r-1,c)])q.push({A[id(r-1,c)],id(r-1,c)});
            if(c<C&&!seen[id(r,c+1)])q.push({A[id(r,c+1)],id(r,c+1)});
            if(c>1&&!seen[id(r,c-1)])q.push({A[id(r,c-1)],id(r,c-1)});
        }
        if(seen[id(SR,SC)]){
            cout<<cnt<<endl;
            return 0;
        }
        if(ts.empty()){
            cout<<-1<<endl;
            return 0;
        }
        v+=*prev(ts.end());cnt++;
        ts.erase(prev(ts.end()));
    }
}

// begin signature
// +----------------------------------------+
// |一ㇸ・・・・ㇸ一ㇵㇵㇵ一ㇸ・・ㇸㇸ一ヘシ|
// |　・ㇸㇸㇸㇸ・　・　　・ㇸㇸㇸ・　　ㇸㇵ|
// |ㇵㇸ　　・・ㇸ・　　・　　　・　　　　ㇸ|
// |　ㇸ・・・・ㇸㇸㇸ　・ㇸ一ㇵㇵ一一ㇸ・　|
// |　　　・ㇸㇵシ丁ビビ丁シㇵ・　　　　　ㇸ|
// |ㇵ一ㇵヘシ火山允汎汎汎山火ミヘ・・・ㇸㇸ|
// |ミミシミ火允汎汎允允允允山火丁シヘヘㇵ一|
// |火ビ丁ビ允汎允山せ火火火火丁ミミシヘヘシ|
// |火丁火允汎汎汎汎允山火火火火火ビミシㇵ一|
// |ビせ允洪労労労労洪允山允允允山せビミシㇵ|
// |山汎労和耗耗和李洪汎洪洪洪汎允山火ビミㇵ|
// |汎労耗奏群群奏和労労労洪允山せ允山ビミㇵ|
// |洪李奏陽慶義陽耗李李李洪汎せせ火火火ビシ|
// |汎労耗群義覇義群和労洪汎山せビ丁ミミミミ|
// |山汎李耗群義義群耗李汎允せビ丁シㇵㇵ一ㇵ|
// |洪洪洪李耗奏奏奏和労汎山火丁シㇵㇸ　　　|
// |李李李労李和和李労労允火丁シㇵ・・一ㇵ一|
// |奏奏耗李洪李和李洪汎せビミ一　ㇸヘシミシ|
// |陽群耗労和奏耗李洪山火ミㇵ　一シビ火ビミ|
// |義群和李耗群耗労汎せ丁ヘㇸ・ヘ丁せ山火ミ|
// +----------------------------------------+
// 2026 (May 26th) 15:41:11
// end signature

