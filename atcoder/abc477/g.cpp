#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>tin(N+1),tout(N+1),value(2*N+1);
    int t=1;
    function<void(int,int)>dfs=[&](int u,int p){
        printf("%d add %d\n",t,A[u]);
        value[t]=A[u];
        tin[u]=t++;
        for(auto v:g[u]){
            if(v==p)continue;
            dfs(v,u);
        }
        printf("%d remove %d\n",t,A[u]);
        value[t]=-A[u];
        tout[u]=t++;
    };
    dfs(1,-1);
    using qry=array<int,5>;
    vector<qry>q(Q+1);
    for(int i=1;i<=Q;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        q[i]={tin[a],tin[b],c,d,i};
        tie(q[i][0],q[i][1])=minmax(q[i][0],q[i][1]);
    }
    const int B=350;
    sort(q.begin()+1,q.end(),[&](const qry&a,const qry&b){
        return make_pair(a[0]/B,a[1])<make_pair(b[0]/B,b[1]);
    });
    vector<int>ans(Q+1);
    int l=1,r=0;
    vector<int>sqrt(2*N/B+2,0);
    vector<int>ind(2*N+1,0),cnt(N+1,0);
    auto addsqrt=[&](int i,int v){
        sqrt[i/B]+=v;
        ind[i]+=v;
    };
    auto add=[&](int i,int v){
        if(cnt[i]>0)addsqrt(cnt[i],-1);
        cnt[i]+=v;
        if(cnt[i]>0)addsqrt(cnt[i],1);
    };
    for(int qq=1;qq<=Q;qq++){
        auto [s,t,a,b,i]=q[qq];
        int L=s,R=t;    
        printf("l r = %d %d\n",l,r);
        printf("L R = %d %d\n",L,R);
        while(l>L){
            l--;
            int v=value[l];
            add(abs(v),v/abs(v));
        }
        while(r<R) {
            r++;
            int v=value[r];
            add(abs(v),v/abs(v));
        }
        while(l<L){
            int v=value[l];
            add(abs(v),-v/abs(v));
            l++;
        }
        while(r>R) {
            int v=value[r];
            add(abs(v),-v/abs(v));
            r--;
        }
        int lb=a/B,rb=b/B;
        int c=0;
        if(lb==rb)for(int i=a;i<=b;i++)c+=ind[i];
        else {
            for(int i=a;i<(lb+1)*B;i++)c+=ind[i];
            for(int i=rb*B;i<=b;i++)c+=ind[i];
            for(int i=lb+1;i<=rb-1;i++)c+=sqrt[i];
        }
        ans[i]=c;
    }
    for(int i=1;i<=Q;i++)cout<<ans[i]<<endl;
}
