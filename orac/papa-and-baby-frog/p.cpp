#include <bits/stdc++.h>
using namespace std;
struct segtree{
    struct Y{
        Y*lc=nullptr,*rc=nullptr;
        int l,r,sum=0;
        Y(int l,int r):l(l),r(r){}
        void update_y(int p,int a){
            sum+=a;
            if(l==r)return;
            int mid=(l+r)/2;
            if(p<=mid){
                if(lc==nullptr)lc=new Y(l,mid);
                lc->update_y(p,a);
            }else{
                if(rc==nullptr)rc=new Y(mid+1,r);
                rc->update_y(p,a);
            }
        }
        int query_y(int ql,int qr){
            if(qr<l||r<ql)return 0;
            if(ql<=l&&r<=qr)return sum;
            int ans=0;
            if(lc!=nullptr)ans+=lc->query_y(ql,qr);
            if(rc!=nullptr)ans+=rc->query_y(ql,qr);
            return ans;
        }
    };
    struct X{
        X*lc=nullptr,*rc=nullptr;
        Y*yt=nullptr;
        int l,r,yl,yr;
        X(int l,int r,int yl,int yr):l(l),r(r),yl(yl),yr(yr){
            yt=new Y(yl,yr);
        }
        void update_x(int x,int y,int a){
            yt->update_y(y,a);
            if(l==r)return;
            int mid=(l+r)/2;
            if(x<=mid){
                if(lc==nullptr)lc=new X(l,mid,yl,yr);
                lc->update_x(x,y,a);
            }else{
                if(rc==nullptr)rc=new X(mid+1,r,yl,yr);
                rc->update_x(x,y,a);
            }
        }
        int query_x(int x1,int x2,int y1,int y2){
            if(x2<l||r<x1)return 0;
            if(x1<=l&&r<=x2)return yt->query_y(y1,y2);

            int ans=0;
            if(lc!=nullptr)ans+=lc->query_x(x1,x2,y1,y2);
            if(rc!=nullptr)ans+=rc->query_x(x1,x2,y1,y2);
            return ans;
        }
    };
    X*root=nullptr;
    map<pair<int,int>,int>A;
    segtree(int xl,int xr,int yl,int yr){
        root=new X(xl,xr,yl,yr);
    }
    void set(int x,int y,int a){
        int d=a-A[{x,y}];
        A[{x,y}]=a;
        root->update_x(x,y,d);
    }
    int query(int x1,int y1,int x2,int y2){
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        return root->query_x(x1,x2,y1,y2);
    }
};
int main() {
    int N,K;cin>>N>>K;
    vector<int>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    const int SEN=N+1;
    vector<vector<int>>up(N+1),down(N+1);
    vector<vector<int>>par(N+2,vector<int>(18,SEN));
    using pii=pair<int,int>;
    {
        set<pii>byval,byidx;
        for(int i=1;i<=N;i++){
            byval.insert({A[i],i});
            byidx.insert({i,A[i]});
        }
        while(byidx.size()){
            auto v=*byval.begin();
            vector<pii>vs;
            while(byval.size()&&byval.begin()->first==v.first){
                pii val=*byval.begin();
                vs.push_back(val);
                byidx.erase({val.second,val.first});
                byval.erase(byval.begin());
            }
            for(auto [v,i]:vs){
                int d=2e9,j=-1;
                auto aft=byidx.upper_bound({i,v});
                if(aft!=byidx.end()){
                    d=aft->first-i;
                    j=aft->first;
                }
                if(aft!=byidx.begin()){
                    auto bef=prev(aft);
                    if(i-bef->first<d){
                        j=bef->first;
                        d=i-bef->first;
                    }
                }
                if(j!=-1){
                    up[j].push_back(i);
                    par[i][0]=j;
                    // printf("up %d -> %d\n",i,j);
                }
            }
        }
    }
    {
        set<pii>byval,byidx;
        for(int i=1;i<=N;i++){
            byval.insert({A[i],i});
            byidx.insert({i,A[i]});
        }
        while(byidx.size()){
            auto v=*byval.rbegin();
            vector<pii>vs;
            while(byval.size()&&byval.rbegin()->first==v.first){
                pii val=*byval.rbegin();
                vs.push_back(val);
                byidx.erase({val.second,val.first});
                byval.erase(val);
            }
            for(auto [v,i]:vs){
                int d=2e9,j=-1;
                auto aft=byidx.upper_bound({i,v});
                if(aft!=byidx.end()){
                    d=aft->first-i;
                    j=aft->first;
                }
                if(aft!=byidx.begin()){
                    auto bef=prev(aft);
                    if(i-bef->first<d){
                        j=bef->first;
                        d=i-bef->first;
                    }
                }
                if(j!=-1){
                    down[j].push_back(i);
                    // printf("down %d -> %d\n",i,j);
                }
            }
        }
    }
    vector<int>tin(N+1),tout(N+1),seen(N+1),depth(N+1,1);int t=0;
    function<void(int)>dfs=[&](int u){
        seen[u]=true;tin[u]=++t;
        for(auto v:down[u])depth[v]=depth[u]+1,dfs(v);
        tout[u]=t-1;
    };
    vector<pii>byhdown;
    for(int i=1;i<=N;i++)byhdown.push_back({A[i],i});
    sort(byhdown.begin(),byhdown.end());
    for(int i=0;i>=N-1;i--){
        int u=byhdown[i].second;
        if(!seen[u])dfs(u);
    }
    segtree st(0,N+1,0,N+1);
    vector<bool>good(N+1);
    function<void(int,int)>dfs2=[&](int u,int d){
        if(st.query(tin[u],depth[u],tout[u],depth[u]+K)){
            good[u]=true;
        }
        st.set(tin[u],d,1);
        for(auto v:up[u]){
            dfs2(v,d+1);
        }
        st.set(tin[u],d,0);
    };
    fill(seen.begin(),seen.end(),0);
    for(int i=0;i<N;i++){
        int u=byhdown[i].second;
        if(!seen[u])dfs2(u,1);
    }
    for(int i=1;i<=N;i++){
        cout<<(int)good[i];
    }
    cout<<endl;
}
