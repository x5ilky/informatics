#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const pii REL[8]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1},
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1},
};
int main() {
    int R,C;cin>>R>>C;
    vector<vector<short>>on(R+2,vector<short>(C+2));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++)on[i][j]=S[j-1]=='#';
    }
    vector<vector<short>>on2=on;
    for(int k=1;k<=2;k++){
        vector<vector<short>>non=on2;
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(on2[i][j])non[i][j]=false;
                else for(auto [dr,dc]:REL)
                    non[i][j]|=on2[i+dr][j+dc];
            }
        }
        on2=non;
    }
    vector<vector<int>>dist(R+2,vector<int>(C+2,-1));
    queue<pair<int,int>>q;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(on[i][j]&&on2[i][j])q.push({i,j}),dist[i][j]=0;
        }
    }
    while(q.size()){
        auto [r,c]=q.front();q.pop();
        for(auto [dr,dc]:REL)
            if(r+dr<=R&&c+dc<=C&&r+dr>=1&&c+dc>=1&&dist[r+dr][c+dc]==-1){
                dist[r+dr][c+dc]=dist[r][c]+1;
                q.push({r+dr,c+dc});
            }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            printf("%c",(dist[i][j]%2==0)?'#':'.');
        }
        printf("\n");
    }
}

// begin signature
// +----------------------------------------+
// |ミシヘヘヘヘシミミシシヘヘヘヘヘヘシミ丁|
// |一ㇸ・・・・ㇸㇵ一一ㇸ・・・・・ㇸㇸㇵヘ|
// |・ㇸ一一ㇸㇸ　　　・ㇸ一一ㇸㇸㇸ・　・一|
// |ヘシシシシヘ一ㇸㇵシシシシヘㇵㇸ　・・　|
// |ビビビミヘㇸㇵシ丁ビ火火ビビミヘ一　・　|
// |せ火丁ヘ一ㇸヘ丁火せ山允允山せビミㇵ・ㇸ|
// |允火ミヘ・ㇸシ丁せ允汎洪労洪汎允火丁ヘ一|
// |允火ミㇵㇵヘシビ山汎労和和和李労允せ丁ヘ|
// |山ビシシミヘミ火允洪和奏群群奏李洪山ビシ|
// |火ビビシㇵシビ山洪和奏陽慶陽奏和洪山ビヘ|
// |ビ丁ヘㇸㇵ丁せ汎李奏陽覇慶群耗労允火ミ一|
// |丁ヘ・ㇸシビ山洪李奏陽義群耗李汎せ丁ヘ・|
// |シ一　・ヘ丁せ允労和耗奏耗和労允せ丁ㇵ　|
// |ミ一ㇸ　・ヘ丁せ允洪労李李労洪允火丁ㇵ・|
// |丁ヘ・・・・ㇵミ火せ允汎汎汎允山火ミㇵ・|
// |ビシㇸ　・ㇸ　ㇵシ丁火せせせせ火丁シ一　|
// |ビヘ・ㇸ　・ㇸ・一ヘミ丁丁丁丁シヘ一　ㇸ|
// |ミㇵ　一一・　　・一ㇵヘヘㇵㇵㇸ　・ㇵシ|
// |ヘ・ㇸシヘ一ㇸ　　　　・　　　ㇸㇵシ丁ミ|
// |ㇵ　ㇵミミシヘㇵㇵㇵ一一一ㇵヘシ丁ビ火ミ|
// +----------------------------------------+
// 2026 (May 30th) 22:45:01
// end signature
