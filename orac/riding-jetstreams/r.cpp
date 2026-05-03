#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
struct segtree{
    vector<int>T;int N;
    segtree(int N):N(N),T(2*N,INF){}
    void set(int v,int a){
        for(T[v+=N]=a;v>>=1;)
            T[v]=min(T[v<<1],T[v<<1|1]);
    }
    int query(int l,int r){
        int L=INF,R=INF;
        for(l+=N,r+=N;l<r;l>>=1,r>>=1){
            if(l&1)L=min(L,T[l++]);
            if(r&1)R=min(T[--r],R);
        }
        return min(L,R);
    }
};
signed main(){
    int N,C,D,S,E;cin>>N>>C>>D>>S>>E;
    segtree st(N+1);
    for(int i=1;i<=N;i++){int v;cin>>v;st.set(i,v);}
    struct range{
        int l,r,d,s;
        bool operator<(const range&o)const{
            return tie(l,r,d,s)<tie(o.l,o.r,o.d,o.s);
        }
    };
    set<range>R;
    R.insert({1,N,INF,D});
    auto norm=[&](range&r,int s){
        int m=st.query(r.l,r.r+1);
        r.d+=(r.s-s)*m;
        r.s=s;
        return r;
    };
    auto split=[&](int pos,int s){
        auto it=R.upper_bound({pos,INF,INF,INF});
        if(it==R.begin())return;it--;
        auto v=*it;
        if(pos<v.l||pos>=v.r)return;
        R.erase(it);
        norm(v,s);
        // printf("v={l=%d,r=%d,d=%d,s=%d}\n",v.l,v.r,v.d,v.s);
        range left={v.l,pos,v.d,v.s},right={pos+1,v.r,v.d,v.s};
        norm(left,s);norm(right,s);
        R.insert(left);R.insert(right);
    };
    auto merge=[&](int l,int r,int s){
        range nr={l,r,INF,s};
        for(auto it=R.lower_bound({l,0,0,0});
                it!=R.end()&&it->r<=r;it=R.erase(it)){
            auto v=*it;
            norm(v,s);
            nr.d=min(nr.d,v.d);
        }
        R.insert(nr);
    };
    struct event{
        int pos,time,type;
        bool operator<(const event&o)const{
            return make_tuple(time,-type,pos)<make_tuple(o.time,-o.type,o.pos); 
        }
    };
    priority_queue<event>pq;
    for(int i=1;i<=C;i++){
        int l,s,e;cin>>l>>s>>e;
        pq.push({l,e,1});
        pq.push({l,e,2});
        pq.push({l,s,3});
        pq.push({l,s,4});
        if(e==D){
            split(l,D);
        }
    }
    for(auto it=R.begin();it!=R.end();it++){
        if(it->l<=E&&E<=it->r){
            auto v=*it;
            R.erase(it);
            R.insert({v.l,v.r,0,v.s});
            break;
        }
    }
    set<int>wall={0,N};
    while(!pq.empty()){
        auto t=pq.top();pq.pop();
        if(t.time<=0)break;
        if(t.type==1){
            wall.insert(t.pos);
        }else if(t.type==3){
            wall.erase(t.pos);
        }else if(t.type==4){// merge
            auto rit=wall.upper_bound(t.pos);
            auto lit=prev(rit);
            merge(*lit+1,*rit,t.time);
        }else if(t.type==2){// split
            // printf("split pos=%d time=%d\n",t.pos,t.time);
            split(t.pos,t.time);
        }
        // for(auto r:R){
        //     printf("{l=%d,r=%d,d=%d,s=%d},",r.l,r.r,r.d,r.s);
        // }
        // printf("\n");
    }
    for(auto it=R.begin();it!=R.end();it++){
        if(it->l<=S&&S<=it->r){
            auto v=*it;
            norm(v,0);
            cout<<v.d<<endl;
            break;
        }
    }
}

// begin signature
// +----------------------------------------+
// |耗李労洪洪洪労労洪允せ火ビビ火山汎労耗奏|
// |山火丁丁丁丁ビ丁丁ヘ一・　・ㇸヘ丁せ汎汎|
// |ㇸ　・・　・ㇵㇸ・ヘヘシ丁ミヘ・一シシミ|
// |ミビ火ビ丁シ一ミ丁シヘヘミシビミㇸ一ㇸ・|
// |汎労李労允丁丁一　一ㇵㇵㇸ・シせ丁ㇸヘビ|
// |奏陽群洪火シㇵㇸミシヘヘシ丁一一ヘ火ㇵ・|
// |陽奏耗洪ビシㇸㇵ　ヘ丁火火ビビミ　ㇸビヘ|
// |李洪允山丁シ・ㇵ　ヘミシ一汎山せビシㇸビ|
// |せ丁シヘ一ミ火李群義群奏耗・・　山ビㇸシ|
// |ㇸ・・　山群慶群和一ミビ火ビミㇵㇸビ・ミ|
// |ヘミせ陽慶奏李ㇵ丁ビせ允火シㇸ・一　ㇸミ|
// |允李覇群和一シミシヘヘシシミミシㇵ・シ一|
// |耗覇群李ヘ一一ㇸシビせ山允汎山シㇸㇸシ　|
// |慶慶耗汎一ヘㇸミ山洪李和和洪せヘㇸシ一・|
// |覇覇耗汎ㇸㇸミ　ヘビ山允允せ丁一一ミ　ㇸ|
// |覇慶耗允ㇸ・　ミㇵ　一ヘシヘㇸㇸミヘ　　|
// |覇陽労　　一ヘ・シ丁ヘ一一ㇵミ火ビヘ　シ|
// |義李せ・・一ミㇵ・ヘミビビ丁ミㇵ　ヘビ汎|
// |耗山・　丁火ビ丁ヘㇸ　　　・一シ火汎和汎|
// |労ビ　ㇵ山労洪汎せビ丁丁ビ火山汎李奏群洪|
// +----------------------------------------+
// 2026 (May 3rd) 14:36:33
// end signature
