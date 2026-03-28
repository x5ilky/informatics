#include <bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

void solve(){
    using pii=pair<int,int>;
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1);
    for (int i=1;i<=N;i++)cin>>A[i];
    vector<pii> ranges(Q);
    for (int i=1;i<=Q;i++)cin>>ranges[i-1].first>>ranges[i-1].second;
    map<pii,int>ans;
    
    function<void(int,int,vector<pii>)> f=
    [&](int l,int r,vector<pii>s){
        if(s.empty())return;
        if(l>=r) {
            for(auto r:s)ans[r]=1;
            return;
        }
        int m=(l+r)/2;
        vector<pii>left,right,cross;
        int cl=INF,cr=-INF;
        for (auto&[l,r]:s){
            if(l>m)right.push_back({l,r});
            else if(r<m)left.push_back({l,r});
            else {
                cross.push_back({l,r});
                cl=min(cl,l);
                cr=max(cr,r);
            }
        }
        f(l,m-1,left);
        f(m+1,r,right);
        if(cross.empty()) return;
        sort(cross.begin(),cross.end(),[](pii l, pii r){
            if(l.first==r.first)
                return l.second<r.second;
            return l.first>r.first;
        });
        vector<int>lb,rb,llis(m-cl+2),rlis(cr-m+2),lmin(m-cl+3,INF),rmax(cr-m+2,-INF);
        for(int i=m;i>=cl;i--){
            lmin[m-i+1]=min(lmin[m-i],A[i]);
            if(lb.empty()||-A[i]>lb.back()){
                lb.push_back(-A[i]);
            } else {
                int low=lower_bound(lb.begin(),lb.end(),-A[i])-lb.begin();
                lb[low]=-A[i];
            }
            llis[m-i+1]=lb.size();
        }
        for(int i=m+1;i<=cr;i++){
            rmax[i-m]=max(rmax[i-m-1],A[i]);
            if(rb.empty()||A[i]>rb.back()){
                rb.push_back(A[i]);
            } else {
                int low=lower_bound(rb.begin(),rb.end(),A[i])-rb.begin();
                rb[low]=A[i];
            }
            rlis[i-m]=rb.size();
        }
        for(auto [l,r]:cross){
            int x=llis[m-l+1],y=rlis[r-m];
            if(x>y)swap(x,y);
            ans[{l,r}]=(x<=1&&y<=1)?(lmin[m-l+1]<rmax[r-m])+1:(3*y/2);
        }
    };
    f(1,N,ranges);
    for (auto r:ranges){
        cout<<ans[r]<<endl;
    }
}
int main() {
    int Q;cin>>Q;
    while (Q--)solve();
}
