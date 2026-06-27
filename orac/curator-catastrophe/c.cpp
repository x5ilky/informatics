// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;cin>>N;
    vector<int>A(N+1),B(N+1),A2;
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    A2=A;
    if(all_of(B.begin()+1,B.end(),[&](int v){return v==B[1];}))
        return cout<<(is_sorted(A.begin()+1,A.end())?0:-1)<<endl,0;
    vector<vector<int>>poly;
    vector<pair<int,vector<int>>>mono;
    vector<int>seen(N+1);
    vector<int>P(2e5+1);
    unordered_map<int,int>H;
    vector<int>pv;
    set<int>ps;
    set<int>cols;
    for(int i=1;i<=N;i++){
        P[A[i]]=i;
        if(seen[i])continue;
        if(A[i]==i){
            H[B[i]]=i;
            continue;
        }
        pv={i};ps={i};cols={B[i]};
        int j=i;
        seen[j]=true;
        while(ps.find(A[j])==ps.end()){
            j=A[j];
            pv.push_back(j);
            ps.insert(j);
            cols.insert(B[j]);
            seen[j]=true;
        }
        if(cols.size()==1)mono.push_back({*cols.begin(),pv});
        else poly.push_back(pv);
    skip:;
    }
    using pii=pair<int,int>;
    vector<pii>moves;
    auto swp=[&](int a,int b){
        swap(A[P[a]],A[P[b]]);
        moves.push_back({P[a],P[b]});
        swap(P[a],P[b]);
    };
    for(auto&p:poly){
        for(auto v:p)H[B[v]]=v;
        int j=0;
        for(int i=0;i<p.size();i++){
            if(B[P[p[i]]]!=B[P[A[p[i]]]]){
                j=i;break;
            }
        }
        rotate(p.begin(),p.begin()+j,p.end());
        int G=p[0];
        swp(p[0],p[1]);
        for(int i=1;i<p.size()-1;i++){
            if(B[P[p[i]]]!=B[P[A[p[i]]]]){
                swp(p[i],A[p[i]]);
                G=p[i];
            } else {
                int a=p[i],b=A[p[i]];
                swp(p[i],G);
                moves.pop_back();
                moves.pop_back();
                swp(a,b);swp(b,G);
                // keep G
            }
            // dprint("i = {}, moves = {}",i+1,moves);
        }
    }
    {
        map<int,int>cnt;
        map<int,vector<vector<int>>>byc;
        for(auto&[c,v]:mono)cnt[c]++,byc[c].push_back(v);
        priority_queue<pii>pq;
        for(int i=1;i<=2e5;i++)if(cnt[i])pq.push({cnt[i],i});
        while(pq.size()>=2){
            auto [c1,t1]=pq.top();pq.pop();
            auto [c2,t2]=pq.top();pq.pop();
            auto p1=byc[t1].back();byc[t1].pop_back();
            auto p2=byc[t2].back();byc[t2].pop_back();
            H[t1]=p1[0];
            H[t2]=p2[0];
            swp(p1[0],p2[0]);
            for(int i=1;i<p1.size();i++)swp(p1[i-1],p1[i]);
            for(int i=1;i<p2.size();i++)swp(p2[i-1],p2[i]);
            swp(p1.back(),p2.back());
            if(c1-1>0)pq.push({c1-1,t1});
            if(c2-1>0)pq.push({c2-1,t2});
        }
        if(pq.size()){
            auto[c,t]=pq.top();pq.pop();
            for(auto&v:byc[t]){
                int h;
                for(auto [c,i]:H)if(c!=t){ h=i; break; }
                swp(v[0],h);
                for(int i=1;i<v.size();i++){
                    swp(v[i-1],v[i]);
                }
                swp(v.back(),h);
            }
        }
    }
    cout<<moves.size()<<endl;
    for(auto [u,v]:moves){
        cout<<u<<" "<<v<<endl;
        swap(A2[u],A2[v]);
    }
}

// begin signature
// +----------------------------------------+
// |ㇸ一・　ㇵ丁允和群耗和和和奏陽覇覇覇覇覇|
// |汎汎允火ミ・シ山せ丁ミミビせ洪耗義覇覇覇|
// |慶義群和汎丁　一丁せ山ビㇸㇸ丁允洪李耗陽|
// |覇覇覇慶奏汎労和李李李耗群山・一シ丁せ洪|
// |覇覇覇義和汎せ丁ミシミビ山労洪ビシㇸ　ヘ|
// |覇覇義李せシ　一シミミヘ・一ビせ允允丁一|
// |覇慶奏允シㇸ丁丁シシミビ山せシ一　ㇵビ洪|
// |覇慶李ビ　ビ丁ミ火允火丁ミビビ洪允火ヘシ|
// |覇耗せ・ㇵシ山丁労奏陽群李せ・シ山耗允ヘ|
// |奏汎允火シ火ビビ火山洪和陽覇李丁せ洪奏火|
// |労せシ・ㇸㇵㇸ火　ㇸミ山労和群允ㇵ洪洪火|
// |ㇵ一丁山ビ一ビㇸせ丁ㇸ一シせ洪允ミ丁ヘビ|
// |ㇸ允和労ヘ丁ㇵ丁和和允ビシ・シビミ一ㇸㇸ|
// |ㇸ火奏耗丁ヘミミ李群労山ビ丁丁　ㇸㇵヘ一|
// |火一汎慶洪一ビ・せ李せ丁ヘ　　丁せ汎汎洪|
// |洪ㇵビ耗奏火一ビㇵ汎労労李山せ山せビ一一|
// |労シミ李陽山・火・丁ビ洪労汎汎ビㇸ丁火ビ|
// |洪ㇵ丁和群山・ビㇵシ汎奏義群労ミ洪耗耗李|
// |允ㇸビ和奏山一シミㇸビ允洪洪洪労洪耗労丁|
// |汎ヘシ汎群労ビㇸㇵミ・ㇸㇵㇸミ汎耗允ヘㇵ|
// +----------------------------------------+
// 2026 (June 27th) 13:41:05
// end signature




