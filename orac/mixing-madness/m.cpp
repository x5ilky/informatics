#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N;cin>>N;vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    int K;cin>>K;vector<int>B(K+1);for(int i=1;i<=K;i++)cin>>B[i];
    vector<int>vd(N+1,-1);
    vd[0]=0;
    vector<int>psA(N+1);for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    vector<unordered_map<int,int>>M(K+1);
    for(int k=1;k<=K;k++){
        M[k][0]=0;
    }
    for(int i=1;i<=N;i++){
        for(int k=1;k<=K;k++){
            int v=psA[i]-B[k]*i;
            if(M[k].find(v)!=M[k].end()){
                vd[i]=M[k][v];
                for(int k=1;k<=K;k++){
                    M[k][psA[i]-B[k]*i]=i;
                }
                break;
            }
        }
    }
    printf("\n");
    if(vd[N]==-1)cout<<"IMPOSSIBLE\n";
    else {
        cout<<"POSSIBLE\n";
        vector<pair<int,int>>R;
        int p=N;
        while(p!=0){
            R.push_back(minmax(p,vd[p]));
            p=vd[p];
        }
        cout<<R.size()<<endl;
        for(int i=R.size()-1;i>=0;i--)cout<<R[i].first+1<<" "<<R[i].second<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪山火ビ丁丁ビ火せ允労耗陽義|
// |慶群李汎山火丁シ一・　　ㇸㇵシビ山洪李和|
// |和汎せミㇵ一ㇵ・・ㇸ一ㇸ・　・ヘビ山山山|
// |山ミ一一一　ㇵㇸ一ㇵ・　　・ヘㇵヘヘヘミ|
// |ミㇸ一ㇸ一一ㇵ　ㇸㇵシミ丁ミシㇵシㇸㇵㇸ|
// |ㇸ・ㇸ一ヘㇵ　・ヘビせ允汎せビ丁丁シヘ　|
// |ㇸシ丁火火丁一一ミビビ丁ヘ丁ミミ丁ビビ丁|
// |シ火允洪せヘせ労耗奏奏耗和洪せヘ　　ㇸヘ|
// |せ洪和允ミ洪群覇慶陽群奏奏群李山ミミヘㇸ|
// |李和允火李陽群奏和労洪洪洪労汎汎允山火ミ|
// |李山火労李労労汎せ火ビビビビビ允允汎汎せ|
// |山シビ山せ允火ミㇵㇸ・ㇸ一・ヘシミ丁せ汎|
// |ビㇸ一シビ火ヘ　　　　・ㇵヘ・・　ㇸヘ火|
// |火一ㇵ一・シㇸ・ヘミシㇵヘ火ビ丁丁ミ一ㇸ|
// |山シ　ミミㇸㇸㇵビ火山山ビせビ火火ビビシ|
// |汎丁　　シ一・シミㇵㇵビ汎山洪允山允汎山|
// |汎ミ　ヘ・　　ミㇸㇵ・シ山汎山汎和和耗汎|
// |火ヘ一ビㇸ一一シ　一一ビ火山労奏義奏洪山|
// |ㇵ・シヘㇸ　シミㇵシ火允允和労耗和奏和汎|
// |ㇸ　シ一ヘ・ヘせせ允汎火山汎山労陽慶耗允|
// +----------------------------------------+
// 2026 (May 15th) 18:40:20
// end signature




