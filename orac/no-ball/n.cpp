#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
struct BIT{
    int n; vector<int> t;
    BIT(int n):n(n),t(n+1){}
    void add(int i,int v){ for(;i<=n;i+=i&-i) t[i]+=v; }
    int sum(int i){ int r=0; for(;i;i-=i&-i) r+=t[i]; return r; }
    int query(int l,int r){ return sum(r)-sum(l-1); }
    int kth(int k){
        int i=0;
        for(int p=1<<__lg(n);p;p>>=1)
            if(i+p<=n && t[i+p]<k) k-=t[i+=p];
        return i+1;
    }
};
int block_size;
struct query{
    int x0,y0,x1,y1,idx,block;
    bool operator<(query other)const{
        if(block!=other.block)return block<other.block;
        if(block&1)return x1>other.x1;
        return x1<other.x1;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    using pii=pair<int,int>;
    int N,Q;cin>>N>>Q;
    vector<pii>pos(N+1);
    for(int i=1;i<=N;i++)cin>>pos[i].first>>pos[i].second;
    vector<query>Qs(Q);
    vector<pii>ans(Q);
    for(int i=0;i<Q;i++){
        cin>>Qs[i].x0>>Qs[i].y0>>Qs[i].x1>>Qs[i].y1;
        Qs[i].idx=i;
    }
    unordered_map<int,int>to_coord,from_coord;
    to_coord.reserve(2*N),from_coord.reserve(2*N);
    {
        int c=1;
        set<int>p;
        for(int i=1;i<=N;i++)p.insert(pos[i].first),p.insert(pos[i].second);
        for(int i=0;i<Q;i++)p.insert(Qs[i].x0),p.insert(Qs[i].y0),p.insert(Qs[i].x1),p.insert(Qs[i].y1);
        for(auto& v:p)to_coord[from_coord[c]=v]=c,c++;
        for(int i=1;i<=N;i++)pos[i]={to_coord[pos[i].first],to_coord[pos[i].second]};
        for(int i=0;i<Q;i++) Qs[i]={ to_coord[Qs[i].x0], to_coord[Qs[i].y0], to_coord[Qs[i].x1], to_coord[Qs[i].y1],Qs[i].idx };
    }
    // for(auto [k,v]:from_coord)printf("%d -> %d\n",k,v);
    int S=to_coord.size();
    block_size=ceil(sqrt(S));
    for(auto &q:Qs) q.block=q.x0/block_size;
    sort(Qs.begin(),Qs.end());
    BIT st(S+1);
    auto solve=[&](bool second){
        st=BIT(S+1);
        int cl=1,cr=0,ll=0,lr=0;
        for(const auto&q:Qs){
            while(cr<q.x1){
                cr++;
                while(lr<N&&pos[lr+1].first<=cr){
                    st.add(pos[++lr].second,1);
                }
            }
            while(cr>q.x1){
                while(lr>=1&&pos[lr].first>=cr){
                    st.add(pos[lr].second,-1);
                    lr--;
                }
                cr--;
            }
            while(cl<q.x0){
                while(ll<lr&&pos[ll+1].first<=cl){
                    ll++;
                    st.add(pos[ll].second,-1);
                }
                cl++;
            }
            while(cl>q.x0){
                cl--;
                while(ll>=1&&pos[ll].first>=cl){
                    st.add(pos[ll].second,1);
                    ll--;
                }
            }
            int cnt=st.query(q.y0,q.y1),offset=st.sum(q.y0-1);
            int med=st.kth(offset+(cnt+1)/2);
            (second?ans[q.idx].second:ans[q.idx].first)=(cnt==0?from_coord[q.x0]:from_coord[med]);
        }
    };
    sort(pos.begin()+1,pos.end());
    sort(Qs.begin(),Qs.end());
    solve(true);
    for(int i=1;i<=N;i++)swap(pos[i].first,pos[i].second);
    for(auto&q:Qs){
        swap(q.x0,q.y0);
        swap(q.x1,q.y1);
        q.block=q.x0/block_size;
    }
    sort(pos.begin()+1,pos.end());
    sort(Qs.begin(),Qs.end());
    solve(false);
    for(int i=0;i<Q;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇覇覇義群耗和李和耗群義覇慶義義義慶覇|
// |和和耗耗洪允せビビ火山汎和和労洪洪労李耗|
// |火せ山火シㇵ丁火ビ丁ビビせビ丁ミミ丁火允|
// |・ㇸㇵ一丁ㇵ・　・・・　　・一一ㇸ　一ミ|
// |ビ丁ヘㇸ・シ丁火せせ火丁ヘ　・ㇸ・一シㇸ|
// |ヘ・ㇵ一丁山汎山火丁丁丁丁丁シ　一一ㇵㇵ|
// |ビㇵ　ミ山允ビヘ・シビ火火ミ一ㇵㇵㇸㇸヘ|
// |汎ヘㇸ火允丁ㇸ・シせ洪和洪汎允丁ㇸミ　ヘ|
// |山一丁允ミ　ㇵヘ丁洪労せミシミシ　　ヘㇵ|
// |丁ミせヘ一　ㇵ丁汎汎ミㇵㇵ・・ㇵシヘ・一|
// |ビ允火ㇸ・一丁允允ヘせ允せㇵ　一一　ㇵシ|
// |丁和火　・ビビ労丁山耗耗せㇸ丁ㇵ・ミㇸヘ|
// |ミ允ミ・ㇸ丁ビ労丁せ和洪丁　ビ山ミ　ヘㇸ|
// |丁ヘ一ㇸㇸㇸ火山汎シ火山火ㇵヘ允洪丁ヘヘ|
// |　　　ㇸヘ一ㇸ丁允洪ビ一一　　一火火山せ|
// |火ビ・ミ一ヘシㇸ丁山労山ビ丁ビミ　シ允允|
// |允ヘㇵ丁・丁せㇵ一ミ丁火火ビシ　ヘせ洪労|
// |ミ一火　ミ一丁丁一・ヘㇸ　・・シ山李陽洪|
// |・せㇸ丁允せビビビシヘヘシビ山労群覇陽李|
// |シミ一山耗和李李労汎允汎洪李奏慶覇覇慶李|
// +----------------------------------------+
// 2026 (April 14th) 22:56:16
// end signature




