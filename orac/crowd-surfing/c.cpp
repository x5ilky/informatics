#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C;cin>>R>>C;
    vector<vector<int>>ch(R+1,vector<int>(C+1));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++)ch[i][j]=S[j-1];
    }
    vector<vector<bool>>seen(R+1,vector<bool>(C+1));
    vector<vector<bool>>good(R+1,vector<bool>(C+1));
    using pii=pair<int,int>;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(seen[i][j])continue;
            int u=i,v=j;
            vector<pii>p={{u,v}};
            while(!seen[u][v]){
                seen[u][v]=true;
                if(ch[u][v]=='v')u++;
                if(ch[u][v]=='>')v++;
                if(ch[u][v]=='+'){
                    good[u][v]=true;
                    break;
                }
                if(ch[u][v]=='*'){
                    good[u][v]=false;
                    break;
                }
                p.push_back({u,v});
            }
            for(auto[x,y]:p)good[x][y]=good[u][v];
        }
    }
    int ans=0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            ans+=!good[i][j];
        }
    }
    cout<<ans<<endl;
}
