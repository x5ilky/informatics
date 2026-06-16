#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,Q;cin>>R>>C>>Q;
    vector<vector<int>>state(R+1,vector<int>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++){
            if(S[j-1]=='O')state[i][j]=2;
            if(S[j-1]=='#')state[i][j]=1;
        }
    }
    auto solve=[&](int R,int C){
        vector<vector<int>>state2(R+1,vector<int>(C+1));
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(state[i][j]==1)state2[i][j]=1;
            }
        }
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(state[i][j]==2){
                    int i2=i;
                    while(i2>1&&state2[i2-1][j]==0){
                        i2--;
                    }
                    state2[i2][j]=2;
                }
            }
        }
        return state2;
    };
    auto rotate=[](vector<vector<int>>b){
        int R=b.size()-1,C=b[0].size()-1;
        vector<vector<int>>nb(C+1,vector<int>(R+1));
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                nb[j][R-i+1]=b[i][j];
            }
        }
        return nb;
    };
    while(Q--){
        string S;cin>>S;
        if(S=="Bow"){
            state=solve(R,C);
        }else if(S=="Port"){
            state=rotate(state);
            state=solve(C,R);
            state=rotate(state);
            state=rotate(state);
            state=rotate(state);
        }else if (S=="Stern"){
            state=rotate(state);
            state=rotate(state);
            state=solve(R,C);
            state=rotate(state);
            state=rotate(state);
        }else if (S=="Starboard"){
            state=rotate(state);
            state=rotate(state);
            state=rotate(state);
            state=solve(C,R);
            state=rotate(state);
        }
        cout<<"-----------"<<endl;
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(state[i][j]==0)cout<<'.';
                if(state[i][j]==1)cout<<'#';
                if(state[i][j]==2)cout<<'O';
            }
            cout<<endl;
        }
    }
}
