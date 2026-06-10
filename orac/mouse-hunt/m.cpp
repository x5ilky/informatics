#include <bits/stdc++.h>
using namespace std;
int main() {
    using pii=pair<int,int>;
    vector<pii>pts(9);
    for(int i=1;i<=8;i++)cin>>pts[i].first>>pts[i].second;
    pii tl={1e9,-1e9},tr={-1e9,-1e9},bl={1e9,1e9},br={-1e9,1e9};
#define x first
#define y second
    for(int i=1;i<=8;i++){
        pii p=pts[i];
        if(p.x<=tl.x&&p.y>=tl.y)tl=p;
        if(p.x>=tr.x&&p.y>=tr.y)tr=p;
        if(p.x<=bl.x&&p.y<=bl.y)bl=p;
        if(p.x>=br.x&&p.y<=br.y)br=p;
    }
    // printf("%d,%d %d,%d %d,%d %d,%d\n",tl.x,tl.y,tr.x,tr.y,bl.x,bl.y,br.x,br.y);
    for(int i=1;i<=8;i++){
        pii p=pts[i];
        if(p==tl||p==tr||p==bl||p==br)continue;
        if(p.y==tr.y)return cout<<"N"<<endl,0;
        if(p.x==tr.x)return cout<<"E"<<endl,0;
        if(p.y==bl.y)return cout<<"S"<<endl,0;
        if(p.x==tl.x)return cout<<"W"<<endl,0;
    }
    assert(false);
}
