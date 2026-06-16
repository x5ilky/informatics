#include<bits/stdc++.h>
using namespace std;
int main() {
    int R,C;cin>>R>>C;
    vector<vector<bool>>B(R+1,vector<bool>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++)B[i][j]=S[j-1]=='#';
    }
    int ans=1;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(B[i][j])continue;
            int c=0;
            if(i>1)c+=!B[i-1][j];
            if(i<R)c+=!B[i+1][j];
            if(j>1)c+=!B[i][j-1];
            if(j<C)c+=!B[i][j+1];
            if(i==1&&j==1)ans+=max(c-1,0);
            else ans+=max(c-2,0);
        }
    }
    cout<<ans<<endl; 
}
