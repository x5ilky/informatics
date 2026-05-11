#include <bits/stdc++.h>
using namespace std;
#define int long long
int R,C,Q;vector<vector<int>>A;
const int INF=1ull<<60;
void p1(){
    vector<vector<int>>dp(R+1,vector<int>(C+1,-INF)),mx(R+1,vector<int>(C+1,-INF));
    dp[1][1]=mx[1][1]=A[1][1];
    for(int r=1;r<=R;r++){
        for(int c=1;c<=C;c++){
            if(r==1&&c==1)continue;
            mx[r][c]=max({mx[r-1][c-1],mx[r-1][c],mx[r][c-1]});
            dp[r][c]=mx[r][c]+A[r][c];
            mx[r][c]=max(mx[r][c],dp[r][c]);
        }
    }
    cout<<dp[R][C]<<endl;
}
void p2(){

}
signed main() {
    cin>>R>>C;A.resize(R+1,vector<int>(C+1,0));for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)cin>>A[i][j];
    cin>>Q;
    if(Q==0)p1();
}
