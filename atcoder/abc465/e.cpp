#include <bits/stdc++.h>
#include <atcoder/all>
using mint=atcoder::modint998244353;
using namespace std;
int main() {
    string S;cin>>S;
    int N=S.size();
    vector<vector<vector<vector<vector<mint>>>>>dp2(N+1,vector<vector<vector<vector<mint>>>>(3,vector<vector<vector<mint>>>(1<<11,vector<vector<mint>>(2,vector<mint>(2)))));
    dp2[0][0][0][1][0]=1;
    for(int i=1;i<=N;i++){
        for(int m=0;m<3;m++){
            for(int bm=0;bm<(1<<11);bm++){
                for(int t=0;t<2;t++){
                    for(int st=0;st<2;st++){
                        mint cur=dp2[i-1][m][bm][t][st];
                        if(cur.val()==0)continue;
                        int lim=t?S[i-1]-'0':9;
                        for(int d=0;d<=lim;d++){
                            int nt=t&&(d==lim);
                            if(!st&&d==0)dp2[i][0][0][nt][0]+=cur;
                            else{
                                int nbm=bm|(1<<d);
                                dp2[i][(m+d)%3][nbm][nt][1]+=cur;
                            }
                        }
                    }
                }
            }
        }
    }
    mint ans=0;
    for(int j=0;j<(1<<11);j++){
        if(popcount((unsigned)j)!=3&&((j&(1<<3))==0)){
            for(int t=0;t<=1;t++)ans+=dp2[N][0][j][t][1];
        }
    }
    for(int j=0;j<(1<<11);j++){
        if(popcount((unsigned)j)!=3&&(j&(1<<3))){
            for(int m=1;m<3;m++){
                for(int t=0;t<=1;t++)ans+=dp2[N][m][j][t][1];
            }
        }
    }
    for(int j=0;j<(1<<11);j++){
        if(popcount((unsigned)j)==3&&((j&(1<<3))==0)){
            for(int m=1;m<3;m++){
                for(int t=0;t<=1;t++)ans+=dp2[N][m][j][t][1];
            }
        }
    }
    cout<<ans.val()<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇覇陽奏和洪允山山山汎允允汎洪和奏|
// |覇覇慶奏李汎せビシ一ㇸㇸ一ヘ一ㇵヘ丁せ汎|
// |覇奏洪火シヘ　ㇵシミ丁丁シミ丁ミㇵ　ㇵ火|
// |労火ㇵㇵ　シミ火丁丁丁せ汎労労洪山丁ㇸヘ|
// |火一ㇵ　ミビㇵ　　一ㇵ・シせ李陽耗洪火一|
// |丁・シㇵミㇵ一・丁・ヘビ火火火ヘ陽慶耗允|
// |丁・シㇵミㇸㇵヘシ一火洪和耗和耗労ビ義陽|
// |ビ・ヘ一ミミㇸミ一シ允耗陽義覇慶陽和山シ|
// |ミ一・ビミビ・丁ㇸせ汎汎汎洪李耗群労山ビ|
// |　ヘシせ山一丁・丁シヘヘヘミ火允労汎せシ|
// |・ㇸ李洪シヘヘ・ㇵシシシヘ・ㇸミ山山シヘ|
// |ㇸ山汎丁ㇸ丁ㇸ一ヘヘヘㇸ・ヘシ　ミビシㇸ|
// |ㇸ火丁　・ㇵシㇵ山洪汎山ビヘ・丁ㇸヘ一一|
// |・ㇸヘ一ヘシㇵミ・ビ洪耗允丁ㇸㇸヘシヘ一|
// |ㇵヘ・・ミ汎丁　ミ一ㇵビせㇵㇵビ允せ火せ|
// |丁ヘㇵ　ビ労李せㇵ・シ一・　ビせシㇸ　　|
// |丁ㇸ　シㇸビ洪李せシㇵ一ㇸミせㇵㇵ丁火火|
// |一ㇸヘ山ミㇵビ丁　シミ一ミせ・丁汎和耗労|
// |ㇵ一山李汎山ミㇵ山労允シせ・ビ李義覇慶耗|
// |　ミ労義耗せ　火耗陽汎せシヘ汎陽覇覇覇和|
// +----------------------------------------+
// 2026 (July 4th) 21:15:18
// end signature

