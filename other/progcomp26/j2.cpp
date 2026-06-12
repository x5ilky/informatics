#include <bits/stdc++.h>
using namespace std;
int main() {
    int C,R,Q,c,r;cin>>R>>C>>Q>>r>>c;
    vector<vector<char>>B(R+1,vector<char>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++){
            B[i][j]=S[j-1];
        }
    }
    string S;cin>>S;
    for(int i=1;i<=Q;i++){
        if(S[i-1]=='n')r--;
        if(S[i-1]=='e')c++;
        if(S[i-1]=='s')r++;
        if(S[i-1]=='w')c--;
    }
    cout<<B[r][c]<<endl;
}
