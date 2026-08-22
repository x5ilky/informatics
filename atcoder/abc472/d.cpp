#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,K;cin>>R>>C>>K;
    vector bomb(R+1,vector(C+1,0));
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++)
            bomb[i][j]=S[j-1]=='#';
    }
    vector sr(R+1,0);
    vector sc(C+1,0);
    for(int i=1;i<=R;i++){
        bool safe=1;
        for(int j=1;j<=C;j++)if(bomb[i][j])safe=0;
        sr[i]=safe;
    }
    for(int i=1;i<=C;i++){
        bool safe=1;
        for(int j=1;j<=R;j++)if(bomb[j][i])safe=0;
        sc[i]=safe;
    }
    using pii=pair<int,int>;
    queue<pii>bfs;
    vector<vector<int>>dist(R+1,vector<int>(C+1,-1));
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++)
            if(sr[i]&&sc[j])
                bfs.push({i,j}),dist[i][j]=0;
    }
    array<pii,4> dir={{{1,0},{0,1},{-1,0},{0,-1}}};
    while(bfs.size()){
        auto [r,c]=bfs.front();bfs.pop();
        for(auto [dr,dc]:dir){
            if(!(r+dr>=1&&r+dr<=R&&c+dc>=1&&c+dc<=C))continue;
            if(dist[r+dr][c+dc]!=-1)continue;
            if(bomb[r+dr][c+dc])continue;
            dist[r+dr][c+dc]=dist[r][c]+1;
            bfs.push({r+dr,c+dc});
        }
    }
    int c=0;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(dist[i][j]<=K&&dist[i][j]!=-1)
                c++;
    cout<<c<<endl;
}
