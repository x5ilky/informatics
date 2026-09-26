#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    using pii=pair<int,int>;
    vector<pii>q(Q+1);
    for(int i=1;i<=Q;i++){
        int t;cin>>t;
        if(t==1){
            int v;cin>>v;
            q[i]={t,v};
        } else {
            string c;cin>>c;
            q[i]={t,c[0]};
        }
    }
    vector<bool>on(N+1);
    for(int i=1;i<=Q;i++)if(q[i].first==1)on[q[i].second]=!on[q[i].second];
    set<int>used,cur;
    for(int i=1;i<=N;i++)if(!on[i])cur.insert(i);
    vector<char>ans(N+1,'a');
    for(int i=Q;i>=1;i--){
        auto [t,j]=q[i];
        if(t==1){
            on[j]=!on[j];
            if(!on[j]&&used.find(j)==used.end())cur.insert(j);
            else if(on[j]&&cur.find(j)!=cur.end())cur.erase(j);
        }else{
            for(auto v:cur)ans[v]=j;
            for(auto v:cur)used.insert(v);
            cur.clear();
        }
    }
    for(int i=1;i<=N;i++)cout<<ans[i];cout<<endl;
}
