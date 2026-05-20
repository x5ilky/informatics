#include <bits/stdc++.h>
using namespace std;
int main() {
    int C,R;cin>>C>>R;
    vector<vector<short>>tree(R+2,vector<short>(C+2));
    int r,c;
    for(int i=1;i<=R;i++){
        string s;cin>>s;
        for(int j=1;j<=C;j++){
            if(s[j-1]=='T')tree[i][j]=true;
            if(s[j-1]=='U')r=i,c=j;
        }
    }
    for(int i=0;i<=R+1;i++)tree[i][0]=tree[i][C+1]=true;
    for(int i=0;i<=C+1;i++)tree[0][i]=tree[R+1][i]=true;
    int P;cin>>P;
    vector<char>ins(P+1);
    for(int i=1;i<=P;i++){string s;cin>>s;ins[i]=s[0];}
    vector<vector<vector<short>>>dp(P+2,vector<vector<short>>(R+2,vector<short>(C+2)));
    dp[P+1][r][c]=true;
    for(int p=P;p>=1;p--){
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(tree[i][j])continue;
                bool w=false;
                switch(ins[p]){
                case 'N':w=tree[i-1][j];break;
                case 'S':w=tree[i+1][j];break;
                case 'W':w=tree[i][j-1];break;
                case 'E':w=tree[i][j+1];break;
                }
                switch(ins[p]){
                case 'N':dp[p][i][j]=dp[p+1][i-1][j]||(w&&dp[p+1][i][j]);break;
                case 'S':dp[p][i][j]=dp[p+1][i+1][j]||(w&&dp[p+1][i][j]);break;
                case 'W':dp[p][i][j]=dp[p+1][i][j-1]||(w&&dp[p+1][i][j]);break;
                case 'E':dp[p][i][j]=dp[p+1][i][j+1]||(w&&dp[p+1][i][j]);break;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            ans+=dp[1][i][j];
        }
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |・・・・・ㇸ一ㇵㇵ一ㇸㇸㇸ一ㇵシ丁火山洪|
// |ㇵㇵㇵㇵㇵㇵㇸ　・一ㇵㇵ一ㇸ　・ㇵミ火允|
// |ビビビビビ丁シㇵㇸ・・・・　　　・ヘ丁山|
// |汎允山丁ヘㇸ　ㇸㇵ一一一一一一ㇵㇸ一ミせ|
// |洪山丁ㇵ　ㇸ・　・ㇸ・　　　　　・一ㇵ丁|
// |汎火ミㇸㇸ　ㇸ・ㇵ　一ヘヘㇵ一　ㇸ・　ㇵ|
// |汎せシㇸㇸㇸ・一一ㇸシミ丁火ビミヘ・　ㇸ|
// |洪せシ・　一・ㇵ・一ヘシ丁ミ火山火ミㇵ　|
// |允ビㇵ・一　・ㇵ・ヘシシㇵ丁ミ火山せミ一|
// |せシ　一・・ㇵ　　　・一ㇵㇵヘミ丁火ビㇵ|
// |ミ・一一一ㇸㇸ一・　・・・　　ㇸヘミ丁一|
// |ㇵㇸシ　・ㇵ・ㇸヘシミミミヘㇵ・・ㇵミㇸ|
// |ヘㇵヘ　ㇸㇸヘミビせせ山せ火ビシㇵ　ㇵ一|
// |丁一ミ・　ㇵミ火允汎洪労労洪汎山ビシㇸㇸ|
// |山ミ一ヘ　ヘビ山洪李耗奏和洪允火丁ミミㇵ|
// |洪せシヘ・シ火汎李耗陽奏李允火ミㇵㇸ・ㇸ|
// |労山丁一ㇵビ允労奏義陽和汎せミ一　一ㇵㇵ|
// |汎ビㇵ一丁允労奏義陽和洪せシ・一ミビビ丁|
// |火ヘㇸ丁山労奏慶義耗洪せシ・ㇵビ山汎允火|
// |シ一ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (May 20th) 20:42:28
// end signature
