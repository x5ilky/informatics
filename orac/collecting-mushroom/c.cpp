#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,D,K;cin>>R>>C>>D>>K;
    using pt=complex<int>;
    vector<vector<int>>diff(C+2,vector<int>(R+2)),diff2(C+2,vector<int>(R+2)),diff3(C+2,vector<int>(R+2));
    vector<pt>M;
    for(int y=1;y<=R;y++){
        string s;cin>>s;
        for(int x=1;x<=C;x++){
            if(s[x-1]=='M')M.push_back(pt(x,y));
            if(s[x-1]=='S'){
                diff2[max(x-D,1)][max(y-D,1)]++;
                diff2[max(x-D,1)][min(y+D+1,R+1)]--;
                diff2[min(x+D+1,C+1)][max(y-D,1)]--;
                diff2[min(x+D+1,C+1)][min(y+D+1,R+1)]++;
            }
        }
    }
    vector<int>d(C+1,0);
    for(int y=1;y<=R+1;y++){
        for(int x=1;x<=C+1;x++){
            diff[x][y]=(d[x]+=diff2[x][y]);
        }
    }
    for(int y=1;y<=R+1;y++){
        int c=0;
        for(int x=1;x<=C+1;x++){
            diff3[x][y]=(c+=diff[x][y]);
        }
    }
    int ans=0;
    for(auto m:M){
        if(diff3[m.real()][m.imag()]>=K)ans++;
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |シㇵ一ㇸㇸㇸ一ヘミミヘㇵ一一一ㇵㇵ一一一|
// |　ㇸ一ㇵㇵ一・　ㇸ・　ㇸㇸㇸㇸ　・ㇸ一一|
// |ミ丁ビシ一　　ㇸ一ヘシㇵ一ㇸㇵシミ丁丁ミ|
// |せミㇵ　・ㇸシㇵㇸㇸ　ㇸヘ丁火丁火山山山|
// |丁ㇵ　・一ㇵ　・　ㇸ・　・ヘ丁ビミビ火火|
// |ミ一ㇸ　ㇵ・ㇸ・ㇵ　一ヘㇵ　一シシシヘヘ|
// |丁一ㇸ　ㇵ　・一一ㇸシ丁火ミㇵ　一ミ火ミ|
// |丁一・ㇸ　・・ㇵ・一ミ火せ山ビシ一・シ火|
// |一ㇸㇸ一ヘヘ　ㇵ・一ㇵヘシミ丁ビシㇸ一丁|
// |　・ヘ一ㇸ　ㇵ　・　　・ㇸㇸ一ㇵシㇸ一丁|
// |　ㇵ　一一ㇸㇸ・　ㇸ一ㇵㇵ一・　一ㇵㇵ丁|
// |・ㇵヘミ・ㇵㇸヘミ丁ビビ丁ミシㇵ　ㇸㇸㇵ|
// |　ヘㇵヘ　一シビせ山允允允山火丁ヘㇸㇸ・|
// |・　　・・ヘビ山汎労李李李労允山火ミㇵ　|
// |ミㇸ　　ㇸシ火允労和奏奏李汎せビミヘヘヘ|
// |せミ一　ㇸミせ洪和群義耗労山ビシㇸ　　　|
// |汎火シ　ヘ火汎李群慶群李汎火シ・ㇸヘシシ|
// |山ㇵㇸㇵビ允李群慶陽和汎火ヘ　ㇵ丁火せビ|
// |ㇸ一ㇸ丁山労奏慶義耗洪火シ　ヘ火允洪汎火|
// |ㇵ　ヘ火汎和陽覇群李允丁一一丁山李和汎火|
// +----------------------------------------+
// 2026 (April 16th) 20:26:08
// end signature


