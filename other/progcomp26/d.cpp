#include <bits/stdc++.h>
using namespace std;
int main() {
    int R=10,C=10;
    vector<vector<int>>board(R+1,vector<int>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++){
            if(S[j-1]=='A')board[i][j]=1;
            if(S[j-1]=='B')board[i][j]=2;
        }
    }
    vector<string>S;
    auto bounds=[](int r,int c){
        return 1<=r&&r<=10&&1<=c&&c<=10;
    };
    int best=0;vector<string>BS;int sr,sc;int br,bc;
    function<void(int,int,int)>solve=[&](int r,int c,int p){
        if(p>best){
            BS=S;best=p;
            br=sr;
            bc=sc;
        }
        if(bounds(r+2,c+2)&&board[r+1][c+1]==2&&board[r+2][c+2]==0){
            board[r][c]=0;
            board[r+1][c+1]=0;
            S.push_back("SE");
            solve(r+2,c+2,p+1);
            S.pop_back();
            board[r+1][c+1]=2;
            board[r][c]=1;
        } 
        if(bounds(r+2,c-2)&&board[r+1][c-1]==2&&board[r+2][c-2]==0){
            board[r][c]=0;
            board[r+1][c-1]=0;
            S.push_back("SW");
            solve(r+2,c-2,p+1);
            S.pop_back();
            board[r+1][c-1]=2;
            board[r][c]=1;
        } 
        if(bounds(r-2,c+2)&&board[r-1][c+1]==2&&board[r-2][c+2]==0){
            board[r][c]=0;
            board[r-1][c+1]=0;
            S.push_back("NE");
            solve(r-2,c+2,p+1);
            S.pop_back();
            board[r-1][c+1]=2;
            board[r][c]=1;
        } 
        if(bounds(r-2,c-2)&&board[r-1][c-1]==2&&board[r-2][c-2]==0){
            board[r][c]=0;
            board[r-1][c-1]=0;
            S.push_back("NW");
            solve(r-2,c-2,p+1);
            S.pop_back();
            board[r-1][c-1]=2;
            board[r][c]=1;
        } 
    };
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            sr=i,sc=j;
            if(board[i][j]==1)solve(i,j,0);
        }
    }
    cout<<best<<endl;;
    cout<<br<<" "<<bc<<endl;;
    for(auto v:BS){
        cout<<v<<" ";
    }
    cout<<endl;
}
