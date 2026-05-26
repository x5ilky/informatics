#include <bits/stdc++.h>
using namespace std;
int main() {
    int R,C,T;cin>>R>>C>>T;
    vector<int>A(R*C+1),B(R*C+1);
    auto id=[&](int r,int c){return (r-1)*C+c-1;};
    for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)cin>>A[id(i,j)];
    for(int i=1;i<=T;i++){
        int r,c,v;cin>>r>>c>>v;
        B[id(r,c)]=v;
    }
    int SR,SC;cin>>SR>>SC;
    int v=0,cnt=0;
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>q;q.push({0,0});
    vector<int>seen(R*C+1);
    multiset<int>ts;
    while(true){
        // printf("loop v = %d\n",v);
        while(q.size()){
            auto [w,u]=q.top();
            int r=u/C+1,c=u%C+1;
            if(w>v)break;
            q.pop();
            if(seen[u])continue;
            seen[u]=true;
            if(B[u]>0)ts.insert(B[u]);
            if(r<R&&!seen[id(r+1,c)])q.push({A[id(r+1,c)],id(r+1,c)});
            if(r>1&&!seen[id(r-1,c)])q.push({A[id(r-1,c)],id(r-1,c)});
            if(c<C&&!seen[id(r,c+1)])q.push({A[id(r,c+1)],id(r,c+1)});
            if(c>1&&!seen[id(r,c-1)])q.push({A[id(r,c-1)],id(r,c-1)});
        }
        if(seen[id(SR,SC)]){
            cout<<cnt<<endl;
            return 0;
        }
        if(ts.empty()){
            cout<<-1<<endl;
            return 0;
        }
        v+=*prev(ts.end());cnt++;
        ts.erase(prev(ts.end()));
    }
}
