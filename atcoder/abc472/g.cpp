#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C;cin>>R>>C;
    vector<vector<short>>A(R+1,vector<short>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++){
            if(S[j-1]=='+')A[i][j]=1;
            if(S[j-1]=='-')A[i][j]=-1;
            if(S[j-1]=='#')A[i][j]=0;
        }
    }
    for(int i=R;i>=1;i--){
    }
}
