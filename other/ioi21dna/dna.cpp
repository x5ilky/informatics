#include "dna.h"
#include <bits/stdc++.h>
using namespace std;

int N;vector<int>A,B;
array<array<vector<int>,3>,3>D;
array<array<vector<int>,3>,3>psD;
void init(std::string a, std::string b) {
    map<char,int>C;C['A']=0,C['T']=1,C['C']=2;
    N=a.size();
    A.resize(N+1),B.resize(N+1);
    for(int i=0;i<N;i++)A[i+1]=C[a[i]],B[i+1]=C[b[i]];
    for(int a=0;a<=2;a++)
        for(int b=0;b<=2;b++){
            D[a][b]=vector<int>(N+1);
            psD[a][b]=vector<int>(N+1);
            for(int i=1;i<=N;i++)D[a][b][i]=A[i]==a&&B[i]==b;
            for(int i=1;i<=N;i++)psD[a][b][i]=psD[a][b][i-1]+D[a][b][i];
        }
}

int get_distance(int x, int y) {
    x++,y++;
    array<int,3>cA{},cB{};
    for(int a=0;a<=2;a++)
        for(int b=0;b<=2;b++)
            cA[a]+=psD[a][b][y]-psD[a][b][x-1],
            cB[b]+=psD[a][b][y]-psD[a][b][x-1];
    if(cA!=cB)return -1;
    int ans=0;
    int c[3][3]{};
    for(int a=0;a<=2;a++)
        for(int b=0;b<=2;b++)
            c[a][b]+=psD[a][b][y]-psD[a][b][x-1];
    using pii=pair<int,int>;
    for(auto [a,b]:{pii{0,1},pii{1,2},pii{2,0}}){
        int v=min(c[a][b],c[b][a]);
        ans+=v;
        c[a][b]-=v;
        c[b][a]-=v;
    }
    int tot=0;
    for(int a=0;a<=2;a++)
        for(int b=0;b<=2;b++)
            tot+=c[a][b]*(a!=b);
    assert(tot%3==0); // yo am i tripping
    ans+=tot/3*2;
    return ans;
}

// begin signature
// +----------------------------------------+
// |ミシヘヘヘヘシシヘヘヘシミ丁ビせ山せせせ|
// |一ㇸ・　　・ㇸ・・　・ㇸ一ヘミビビ丁丁丁|
// |ㇸ一ㇵㇵ一ㇸㇸ一一　　・ㇸ一ヘヘㇵㇵㇵㇵ|
// |シミ丁ミミシㇵㇸㇸ一ㇸ・　一ㇸ　　　　　|
// |火せ火丁ヘ一ヘシミミシヘ一　ㇸ一ㇵヘㇵ一|
// |山山ビシ一ヘミビビビビビミヘㇵシ丁丁丁ミ|
// |汎山ビシ一シビビ丁ミビ火ビビミ丁火山山せ|
// |汎せ丁ヘ一ミビビシビせ允允山火火山汎洪洪|
// |山火ビ丁丁丁ビミ丁せ汎労労洪山せ汎李和和|
// |允せ丁シミ丁丁ミせ汎李耗和洪山汎李奏群奏|
// |汎せミシビ丁シ火允労耗耗李汎允労耗陽群和|
// |山ビシミ丁ミミ火允労李労汎せ汎労耗耗和労|
// |ビミㇵシビビ火火せ允汎允山火山汎労労労汎|
// |シヘシビ火山允允允山せ火火火火せ山允允山|
// |シㇵミ火山汎洪労労労洪汎允せビミ丁火火火|
// |丁ヘ丁せ允洪李耗耗耗和洪允火ミヘㇵシシシ|
// |ビ丁火允洪和奏群陽奏李汎せ丁ヘ・　・ㇸㇸ|
// |火山允労和群義義奏李汎せ丁ㇵ　一一ㇸㇸㇸ|
// |汎允洪和群慶慶群和洪山丁ㇵ　ㇵヘㇵシシミ|
// |洪汎李奏義覇陽耗労允火シㇸㇸヘㇵシビ火丁|
// +----------------------------------------+
// 2026 (July 17th) 16:26:30
// end signature

