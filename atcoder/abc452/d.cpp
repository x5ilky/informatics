#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    string S,T;cin>>S>>T;
    int N=S.size(),M=T.size();
    vector<vector<int>>next(M+1,vector<int>(N+1,N));
    for(int i=N-1;i>=0;i--){
        if(S[i]==T[M-1]){
            next[M-1][i]=i;
        } else next[M-1][i]=next[M-1][i+1];
    }
    for(int k=M-2;k>=0;k--){
        int f=N;
        for(int i=N-1;i>=0;i--){
            if(S[i]==T[k]){
                next[k][i]=f;
            } else next[k][i]=next[k][i+1];
            if(S[i]==T[k+1]){
                f=i;
            }
        }
    }
    // for (int k=0;k<M;k++){
    //     for (int i=0;i<N;i++){
    //         printf("%d ", next[k][i]);
    //     }
    //     printf("\n");
    // }
    int ans=0;
    for (int i=0;i<N;i++){
        int j=i;
        for (int k=0;k<M;k++){
            j=next[k][j];
        }
        ans+=j-i;
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |火ビビビ火せせ火ビ丁ミミ丁丁丁ビ火せ允洪|
// |ヘㇵㇵヘシミシヘ一ㇸㇸㇸ一一一ㇵシ丁火山|
// |・・・　・ㇸ　ㇸ一ㇵㇵヘヘヘヘㇵㇸヘ丁せ|
// |ミミシヘ　ㇸ一一ㇸ・・・ㇸㇵヘシヘ一ヘビ|
// |せ火ビ　ㇸㇸ　ㇸ一・・　・ㇸㇵヘシシ一シ|
// |丁シヘ・・・ㇸ　ㇸ一一ヘシミミシシミㇵ一|
// |ヘㇸ　・ㇸ　　一シミ丁丁丁ビ火ビシヘㇵ一|
// |ㇸ　ㇸヘ一　・ㇸ・・ㇸ一ヘミヘシ一　・ㇸ|
// |一ㇸㇵ　　　ㇸ一ㇵㇵㇸ　ㇸ一ヘㇵ・ヘミ一|
// |　・　・一一一ㇸ　・　　　　・ㇸ・ミミ一|
// |　　　　一一ㇸ　ㇸㇵヘシシヘ一・一シヘヘ|
// |　・・シ一　ㇵシ丁火火火火ビミヘㇸ一ヘㇸ|
// |　・ㇵ一　ヘ丁火山汎洪洪汎允山火ミ一　ㇸ|
// |ヘ　ㇵㇸ一ミ火允洪李和耗李汎山火ビ丁ヘ　|
// |ヘㇵ　ㇸ一ミせ汎李耗群耗労允火ミヘ一一ㇵ|
// |ㇵシ　　一丁山労耗陽陽耗洪せ丁ㇵ・・ㇸㇸ|
// |ㇵㇵ・　ヘ火汎和群慶奏李允ビヘ　ㇵシ丁ミ|
// |シ　・ㇵビ允李群慶群和汎ビヘ　ヘビ山山火|
// |ㇸ一一丁山李奏慶陽和汎火ヘ　ヘ火汎労洪せ|
// |　　ヘ火汎和陽慶群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 4th) 23:50:54
// end signature



