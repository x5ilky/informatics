#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd;
int main() {
    int N;cin>>N;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    rnd.seed(time(0));
    vector<bool>all(N+1,false);
    uniform_int_distribution<mt19937::result_type> dist2(0,1);
    uniform_int_distribution<mt19937::result_type> distN(1,N);
    for(int i=1;i<=N;i++)all[i]=dist2(rnd);
    int a=0,b=0;
    for(int i=1;i<=N;i++)(all[i]?b:a)+=A[i];
    int d=abs(b-a);
    for(int q=1;q<=100000;q++){
        int u=distN(rnd);
        int na=a,nb=b;
        if(all[u])nb-=A[u],na+=A[u];
        else nb+=A[u],na-=A[u];
        if(abs(na-nb)<d){
            a=na,b=nb,d=abs(na-nb);
            all[u]=!all[u];
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<A[i]<<" "<<(all[i]?'f':'a')<<endl;
    }
    cout<<d<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇慶陽奏和労汎允山允汎労耗陽覇覇覇|
// |覇覇義奏労允せ火ミㇵ一一ㇵシビ允李群群群|
// |慶耗汎火シヘㇸㇸヘヘ一ㇸ　　一丁允允允汎|
// |労火ㇵㇵ・ヘㇵ・ヘミミミビビ丁ヘㇵ一ヘシ|
// |火ㇸㇵ　ミ　シヘ　ㇸ一　　一丁火ビㇵ一　|
// |シ・　一ㇵ一シ・ミ　ヘビ火丁ㇵ　　　ㇵ　|
// |ㇸヘビ火火ミㇵヘシ一火火火ㇵ一丁火せ丁ㇵ|
// |火允洪汎一ヘㇸミ一ヘ山山火・ミ允李耗和汎|
// |李奏奏労火・・丁ㇸせ李洪ミ一山耗慶覇覇奏|
// |慶覇覇和火　丁・ビ李和火　火和覇覇覇覇奏|
// |覇覇群汎ㇵヘヘシ洪群允ㇵミ労義覇覇覇慶労|
// |慶群洪丁ㇸミ・丁労耗せ・ビ李義覇覇慶和火|
// |労汎火ㇸシㇵヘㇵ山李允ヘㇵ山李奏群和允シ|
// |ミミㇵ・ビヘㇵシ・ビ山シ　ㇵ丁山允山丁ㇸ|
// |ㇵ一　ミ山洪丁　ミㇵ一ㇸヘせ汎汎せ丁ミビ|
// |山允シ　丁洪労火ㇵ・シ一ビ洪洪ビ一・一ㇸ|
// |労洪山ミ・丁汎洪ビㇵ　丁洪李ビ・シせ允山|
// |　耗労山ミㇵ丁シㇸ丁火洪李ビ　ビ洪奏奏和|
// |ビ陽奏李汎せシヘ允和和和火　火和慶覇覇耗|
// |ビ群義耗耗せ　ビ和陽奏洪シヘ汎陽覇覇覇和|
// +----------------------------------------+
// 2026 (May 18th) 20:45:16
// end signature

