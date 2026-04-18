#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int R,C;cin>>R>>C;
    vector<vector<int>>A(R+1,vector<int>(C+1));for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)cin>>A[i][j];
    vector<vector<int>>ΣC(R+2,vector<int>(C+1));
    for(int i=R;i>=1;i--)for(int j=1;j<=C;j++)ΣC[i][j]=ΣC[i+1][j]+A[i][j];
    vector<vector<int>>mxL(R+2,vector<int>(C+2,0)),mxR(R+2,vector<int>(C+2,0));
    for(int c=1;c<=C;c++){
        for(int r=R;r>=1;r--){
            int v=ΣC[r][c]+mxL[r][c-1];
            mxL[r][c]=max(v,mxL[r+1][c]);
        }
    }
    for(int c=C;c>=1;c--){
        for(int r=R;r>=1;r--){
            int v=ΣC[r][c]+mxR[r][c+1];
            mxR[r][c]=max(v,mxR[r+1][c]);
        }
    }
    int ans=0;
    for(int c=0;c<=C;c++){
        ans=max(ans,mxL[1][c]+mxR[1][c+1]);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |シヘ一一ㇸ一ㇵヘミミミミヘㇵ一一一ㇵシミ|
// |　・ㇸ一一ㇸ・・一ㇸ・・　ㇸㇸㇸㇸ　・一|
// |シミ丁丁丁ミヘ一一ㇸ一一一ㇵヘミシヘㇸ　|
// |せ山允允火ミㇵㇸ　・ㇸ　ㇸ一一一シ丁シ一|
// |洪労允ビシㇸ　一一　一ヘミ丁丁ミシヘビミ|
// |李汎せ丁ㇵ　ㇵヘ　・ㇸ一ㇵヘミビせ火丁丁|
// |洪山ビミ一・シㇵ　ㇸ一一ㇸ・　ㇸヘ丁火せ|
// |汎せミㇵ　一ミㇵヘミ丁丁丁ミシㇵ・ㇸヘ丁|
// |せ丁ㇵ　　ヘヘㇵ一一ㇵヘシ丁ビ丁シ一・ヘ|
// |ミㇸㇸ　ㇸ　　　・　・ㇸㇸㇵヘシ丁ヘ・一|
// |・ㇸ・一一一一一・　・ㇸㇸ・　ㇸㇵシㇸ一|
// |・一シ丁シ一　一ヘシミミミシㇵㇸ　ㇵ一ㇸ|
// |　ㇵ丁シㇸㇸヘ丁火せ山山山せビミㇵ　一　|
// |・　シㇵ　ㇵ丁せ允洪労労労洪汎山ビシㇸ・|
// |　ㇸ　ㇵ　ヘビ山洪李耗奏和洪山火丁ミミㇵ|
// |　ヘ一　ㇸシ火汎李奏陽奏李允火ミㇵㇸ・・|
// |・ヘヘ・ㇵビ允李奏義群和汎火ミ一　一ㇵㇵ|
// |ヘㇸㇸ一丁允李奏慶陽和洪火シ・一ミビビ丁|
// |ㇸ一ㇸ丁山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |・　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 18th) 15:40:46
// end signature
