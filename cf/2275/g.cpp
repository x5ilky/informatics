#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int>e;
    DSU(int n):e(n,-1){}
    int operator[](int x){return e[x]<0?x:e[x]=(*this)[e[x]];}
    int operator()(int x,int y) {
        x=(*this)[x],y=(*this)[y];
        if(x==y)return 0;
        if(e[x]<e[y]) swap(x, y);
        e[y]+=e[x];
        e[x]=y;
        return 1;
    }
};
#define int long long 
signed main() {
    int T;cin>>T;
    while(T--){
        int N,M,Q;cin>>N>>M>>Q;
        DSU dsu(N+1);
        using pii=array<int,3>;
        vector<pii>edges(M+1);
        for(int i=1;i<=M;i++)cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
        sort(edges.begin()+1,edges.end());
        int c=0;
        vector<int>cost(N+1);int j=1;
        for(int i=1;i<=M;i++){
            auto [d,u,v]=edges[i];
            c+=d;
            if(dsu[u]==dsu[v])continue;
            cost[j++]=d;
            c-=d;
            dsu(u,v);
        }
        for(int i=N-1;i>=1;i--)cost[i]+=cost[i+1];
        vector<int>a;
        while(Q--){
            int x;cin>>x;
            int lo=N-j,hi=N;
            while(lo+1<hi){
                int mid=(lo+hi)/2;
                if(cost[N-mid]-cost[N-mid+1]>=mid*x)lo=mid;
                else hi=mid;
            }
            a.push_back(c+cost[N-lo]-(lo*(lo+1)/2*x));
        }
        for(auto v:a)cout<<v<<" ";cout<<endl;
    }
}
