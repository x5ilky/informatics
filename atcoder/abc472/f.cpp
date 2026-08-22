#include<bits/stdc++.h>
using namespace std;
using ld=long double;
using pt=complex<ld>;
#define x real()
#define y imag()
int main(){
    int N,Q;cin>>N>>Q;
    vector<pt>p(N+1);
    for(int i=1;i<=N;i++){
        ld a,b;cin>>a>>b;
        p[i]=pt(a,b);
    }
    vector<ld>psA(N+1),psX(N+1),psY(N+1);
    for(int i=1;i<=N;i++){
        int j=i==N?1:i+1;
        ld s=p[i].x*p[j].y-p[i].y*p[j].x;
        psA[i]=psA[i-1]+s;
        psX[i]=psX[i-1]+(p[i].x+p[j].x)*s;
        psY[i]=psY[i-1]+(p[i].y+p[j].y)*s;
    }
    cout<<setprecision(20);
    while(Q--){
        int u,v;cin>>u>>v;
        ld A,X,Y;
        if(u<v){
            A=psA[v-1]-psA[u-1];
            X=psX[v-1]-psX[u-1];
            Y=psY[v-1]-psY[u-1];
        }else{
            A=psA[N]-psA[u-1]+psA[v-1];
            X=psX[N]-psX[u-1]+psX[v-1];
            Y=psY[N]-psY[u-1]+psY[v-1];
        }
        ld s=p[v].x*p[u].y-p[v].y*p[u].x;
        A+=s;
        X+=(p[v].x+p[u].x)*s;
        Y+=(p[v].y+p[u].y)*s;
        cout<<X/(3*A)<<' '<<Y/(3*A)<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せせ火ビ丁丁丁ビ火山汎洪洪洪|
// |和労允せビミシヘㇵ一一一ㇵヘミビせ火火せ|
// |汎せ丁ヘ一ㇸ・　ㇸ一・　　　一シシヘシシ|
// |ビシㇸㇸ・・ㇸ　ㇸㇵㇵㇵㇵ一ㇸ　　　　・|
// |ヘ・ㇸシシㇵ一ㇵ・　　　・・一ヘシシヘㇵ|
// |ㇵ　一丁せ一丁せ允汎允せミ一一一ㇸヘ丁ビ|
// |ㇵ　一丁ヘ山労耗奏群群奏李允ビㇵヘシㇵヘ|
// |一　一ㇵ山和群奏和和李李李洪山ビヘㇸㇵシ|
// |ㇸ一一允耗奏和労洪允允允允せビ丁ミㇵㇸ・|
// |丁丁洪群耗労汎せ火ビ丁ビ丁シㇵㇸ一ヘヘヘ|
// |允和群李汎せ丁シㇵシミミシㇵヘミビ火火ビ|
// |李奏李允火シヘミビせ山山火丁火允汎汎汎山|
// |奏耗李洪允火ビせ允洪労労汎山汎洪洪汎洪労|
// |義義陽奏李汎せ汎労和奏奏和労汎山せ火火せ|
// |覇覇覇慶陽耗労汎和奏群奏李汎せビミヘヘシ|
// |覇覇覇覇覇義耗労李奏陽耗労山ビシ一　　　|
// |覇覇覇覇覇慶群李洪和耗李汎火シ・ㇸヘシシ|
// |覇覇覇覇覇義奏労允洪李汎火ヘ　ㇵ丁火せビ|
// |覇覇覇覇覇群李允火山汎火シ　ヘ火允洪汎せ|
// |覇覇覇覇義耗洪せミビ火丁一一丁允李耗洪火|
// +----------------------------------------+
// 2026 (August 22nd) 23:25:47
// end signature

