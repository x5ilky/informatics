#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
signed main() {
    freopen("cats.in", "r", stdin);
    freopen("cats.out", "w", stdout);
    int N,K;cin>>N>>K;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    sort(A.begin()+1,A.end());
    sort(B.begin()+1,B.end());
    int lo=2,hi=3e6;
    while(lo+1<hi){
        int mid=(lo+hi)/2,gt=0;
        // printf("mid=%lld\n",mid);
        for(int i=1;i<=N;i++){
            gt+=B.end()-lower_bound(B.begin()+1,B.end(),mid-A[i]);
        }
        if(gt>=K)lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
}

// begin signature
// +----------------------------------------+
// |覇義群和労洪允山山山允汎洪労李耗群義覇覇|
// |陽耗労允せビミミシミ丁火火山允洪李奏群群|
// |労允ビミㇵㇸヘシㇵㇵ一ㇵヘミビ山洪労労李|
// |せミ一・シㇵ　・一一一ㇸ　ㇸヘビせせせ山|
// |ミㇸ・ヘ・ㇸ一　ㇸ一一ㇸㇸ一ㇵㇵヘヘヘミ|
// |ヘ　一ㇸㇸㇸ　ㇸ一ㇸヘシミミシヘ一ㇵㇸ一|
// |ヘ　一　ㇵヘシㇸ一シビせせせせせビミ一　|
// |シ　ㇸ一ミビㇵ　・ㇸ一ㇸ　山火ミㇵ一　・|
// |ㇵㇸㇸミせシシ山洪李和洪山ビヘ　火ビシ一|
// |　・ミ山丁労奏義覇慶慶奏労山ミ一　ㇵ一ㇸ|
// |・ミ允李陽覇義群奏耗和洪せ丁ㇵ一一一ヘヘ|
// |ヘ山群覇陽奏李労洪汎允山せ丁ビミ　・せせ|
// |ビ耗覇陽和洪允山汎李和李洪山山ミ　ㇸ　洪|
// |せ群慶奏労允ビ汎労奏陽陽奏李允ビミヘ一　|
// |ビ奏慶奏労山ミ火洪奏慶義耗洪山丁シㇵ一ㇵ|
// |ミ奏慶奏洪火ヘビ汎耗慶陽和汎ビヘ・ㇸ一一|
// |山陽陽和允丁ㇸ丁汎和義奏洪せヘ　ヘ丁ビビ|
// |耗慶耗汎火ヘ一ビ汎和群労せシ　シせ汎洪允|
// |慶群労せ火シㇵビ允労李山シ　ミ山李奏和允|
// |慶耗汎ビビミヘシせ允允火ㇵ一ビ洪耗群李山|
// +----------------------------------------+
// 2026 (April 17th) 18:50:28
// end signature

