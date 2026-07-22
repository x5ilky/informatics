#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
struct matrix{
    vector<vector<int>>v;
    matrix(int N):v(N,vector<int>(N,INF)){}
    matrix operator*(const matrix&o)const{
        int N=o.v.size();
        matrix c(N);
        for(int i=0;i<N;i++)
            for(int k=0;k<N;k++)
                for(int j=0;j<N;j++)
                    c.v[i][j]=min(c.v[i][j],v[i][k]+o.v[k][j]);
        return c;
    }
};
matrix exp(matrix a,int b){
    matrix c(a.v.size());
    for(int i=0;i<a.v.size();i++)c.v[i][i]=0;
    matrix d=a;
    for(int k=0;k<32;k++){
        if(b&(1<<k))c=d*c;
        d=d*d;
    }
    return c;
}
signed main(){
    int N,M,K;cin>>N>>M>>K;
    matrix m(N);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        m.v[u-1][v-1]=min(m.v[u-1][v-1],w);
    }
    m=exp(m,K);
    int w=m.v[1-1][N-1];
    cout<<(w==INF?-1:w)<<endl;
}

// begin signature
// +----------------------------------------+
// |陽耗李洪允山せ火火火せ山允洪李耗陽慶覇覇|
// |和洪允せビミシヘヘシミ丁火山洪李奏陽覇覇|
// |允火丁ヘ一ㇸヘミ丁丁丁ミ丁火允労耗陽覇覇|
// |ビヘㇸㇸヘ丁火山山允山せ火丁山洪和群慶覇|
// |ヘ・ㇸシビ山汎労李李労洪允山せ允労奏義慶|
// |・　一ㇵシ丁火允汎允允山允允汎洪允労耗群|
// |ㇵㇵ一ㇸ　ㇸヘミ火ビ丁丁丁ビ火せ山允汎労|
// |ビ丁シ一・　・ㇸヘシㇵ一一一ㇵシミ丁火せ|
// |ミㇵㇵ一・　一・・　・ㇸ一ㇸ・　ㇸㇵヘミ|
// |ビビ丁ミヘ一・　一ヘミ丁ミシヘ一ㇸ　・ㇵ|
// |允允山火丁シㇸシヘㇵヘミ丁ビビ丁シㇵㇸ・|
// |李労洪允せ丁ヘㇸヘ丁火山允允允せ火丁ヘ・|
// |群奏耗李汎せ丁ヘビ山汎労汎せビ丁シヘシヘ|
// |覇慶義群和洪山丁火汎労労山ビシㇵミㇵ一一|
// |覇覇覇覇義奏労允火汎李労山丁ㇵㇸヘミシミ|
// |覇覇覇覇覇義奏労山汎和労山丁一ヘㇵヘ・・|
// |覇覇覇覇覇慶群李允労耗洪せシㇵ一ㇸヘ　ㇸ|
// |覇覇覇覇覇義耗洪汎和李山丁ㇵ・・シヘㇸ一|
// |覇覇覇覇慶奏李允李和汎火ヘ　ㇸシミㇸ一ミ|
// |覇覇覇覇陽和汎允李李允ビヘ一ミシㇸㇸシミ|
// +----------------------------------------+
// 2026 (July 19th) 16:14:45
// end signature
