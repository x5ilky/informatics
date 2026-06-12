#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
    auto id=[](int r,int c){return (r-1)*4+c-1;};
    vector<bool>paint(16);
    const int R=4,C=4;int r,c;
    for(int i=1;i<=R;i++){
        string S;cin>>S;
        for(int j=1;j<=C;j++)paint[id(i,j)]=S[j-1]=='O';
        for(int j=1;j<=C;j++)if(S[j-1]=='S')r=i,c=j;
    }
    using fc=array<int,6>;
    map<fc,int>M;
    fc a={0,1,2,3,4,5};
    array<int,6>turn[4]={
        {3,1,0,5,4,2}, // L
        {2,1,5,0,4,3}, // R
        {1,5,2,3,0,4}, // U
        {4,0,2,3,5,1}, // D
    };
    int cnt=0;
    do{
        M[a]=cnt++;
    }while(next_permutation(a.begin(),a.end()));
    auto apply=[&](fc a,int t){
        fc b;
        for(int i=0;i<=5;i++)b[i]=turn[t][a[i]];
        return b;
    };

    struct st{
        char d;int v,bm,f;
        strong_ordering operator<=>(const st&other) const{
            return tie(d,v,bm,f)<=>tie(other.d,other.v,other.bm,other.f);
        }
        bool operator==(const st&other) const{
            return tie(d,v,bm,f)==tie(other.d,other.v,other.bm,other.f);
        }
    };
    using pii=pair<int,st>;
    pii ID={-1,{-1,-1,-1,{}}};
    vector<vector<vector<pii>>>d(R*C,vector<vector<pii>>(1<<7,vector<pii>(720,ID)));
    queue<tuple<int,int,int,fc>>q;q.push({r,c,0,{0,1,2,3,4,5}});
    d[id(r,c)][0][0]={0,{' ',-1,0,{}}};
    while(q.size()){
        auto [r,c,bm,f]=q.front();q.pop();
        // printf("at %d %d %6x %d,%d,%d,%d,%d,%d\n",r,c,bm,f[0],f[1],f[2],f[3],f[4],f[5]);
        {
            int nbm=bm;fc nf=apply(f,0); // L
            if(c>1){
                if(paint[id(r,c-1)])nbm|=(1<<nf[0]);
                if(d[id(r,c-1)][nbm][M[nf]]==ID){
                    d[id(r,c-1)][nbm][M[nf]]={
                        d[id(r,c)][bm][M[f]].first+1,
                        st{'L',id(r,c),bm,M[f]}
                    };
                    q.push({r,c-1,nbm,nf});
                }
            }
        }
        {
            int nbm=bm;fc nf=apply(f,1); // R
            if(c<C){
                if(paint[id(r,c+1)])nbm|=(1<<nf[0]);
                if(d[id(r,c+1)][nbm][M[nf]]==ID){
                    d[id(r,c+1)][nbm][M[nf]]={
                        d[id(r,c)][bm][M[f]].first+1,
                        st{'R',id(r,c),bm,M[f]}
                    };
                    q.push({r,c+1,nbm,nf});
                }
            }
        }
        {
            int nbm=bm;fc nf=apply(f,3); // D
            if(r<R){
                if(paint[id(r+1,c)])nbm|=(1<<nf[0]);
                if(d[id(r+1,c)][nbm][M[nf]]==ID){
                    d[id(r+1,c)][nbm][M[nf]]={
                        d[id(r,c)][bm][M[f]].first+1,
                        st{'D',id(r,c),bm,M[f]}
                    };
                    q.push({r+1,c,nbm,nf});
                }
            }
        }
        {
            int nbm=bm;fc nf=apply(f,2); // U
            if(r>1){
                if(paint[id(r-1,c)])nbm|=(1<<nf[0]);
                if(d[id(r-1,c)][nbm][M[nf]]==ID){
                    d[id(r-1,c)][nbm][M[nf]]={
                        d[id(r,c)][bm][M[f]].first+1,
                        st{'U',id(r,c),bm,M[f]}
                    };
                    q.push({r-1,c,nbm,nf});
                }
            }
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            auto b=d[id(i,j)][0b111111];
            for(int ff=0;ff<720;ff++)if(b[ff]!=ID){
                int u=id(i,j),bm=0b111111;int f=ff;
                cout<<b[f].first<<endl;
                string S;
                while(u!=-1){
                    st s=d[u][bm][f].second;
                    if(s.d!=' ')S+=s.d;
                    u=s.v;
                    bm=s.bm;
                    f=s.f;
                }
                reverse(S.begin(),S.end());
                cout<<S<<endl;
                // printf("%d ",u);
                return 0;
            }
        }
    }
}
