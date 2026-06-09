#include "fun.h"
#include <bits/stdc++.h> 
using namespace std;
int find_dist(int u,int v){
    return hoursRequired(u-1,v-1);
}
int tree_size(int u,int v){
    return attractionsBehind(u-1,v-1);
}
vector<int> createFunTour(int N, int Q) {
    if(N==1)return {0};
    if(N==2)return {0,1};
    vector<int>sz(N+1);sz[1]=N;
    for(int i=2;i<=N;i++){
        sz[i]=tree_size(1,i);
    }
    using pii=pair<int,int>;
    vector<pii>szi;for(int i=1;i<=N;i++)szi.push_back({sz[i],i});
    sort(szi.rbegin(),szi.rend());
    int centr=0;
    for(auto [s,i]:szi)if(s>=(N+1)/2)centr=i;
    // printf("centroid = %d\n",centr);
    vector<int>d(N+1);
    for(int i=1;i<=N;i++){
        if(i==centr)continue;
        d[i]=find_dist(i,centr);
    }
    vector<int>e;
    for(int i=1;i<=N;i++){
        // printf("%d dist %d = %d\n",i,centr,d[i]);
        if(d[i]==1)e.push_back(i);
    }
    vector<int>cons;
    if(e.size()==2){
        pii up={tree_size(centr,e[0]),e[0]};
        pii down={tree_size(centr,e[1]),e[1]};
        pii other=max(up,down);
        vector<vector<int>>trees(2);
        e={centr,other.second};
        for(int i=1;i<=N;i++){
            pii best={1e9,-1};
            for(int t=0;t<=1;t++){
                best=min(best,pii{find_dist(i,e[t]),t});
            }
            trees[best.second].push_back(i);
        }
        for(auto&t:trees)sort(t.begin(),t.end(),[&](int u,int v){return d[u]<d[v];});
        while(trees[0].size()+trees[1].size()){
            if(trees[0].size()>trees[1].size())cons.push_back(trees[0].back()),trees[0].pop_back();
            else cons.push_back(trees[1].back()),trees[1].pop_back();
        }
    }else if(e.size()==3){
        // this part is like wrong?
        vector<vector<int>>trees(3);
        for(int i=1;i<=N;i++){
            if(i==centr)continue;
            if(find_dist(i,e[0])==d[i]-1)trees[0].push_back(i);
            else if(find_dist(i,e[1])==d[i]-1)trees[1].push_back(i);
            else trees[2].push_back(i);
        }
        for(auto&t:trees)sort(t.begin(),t.end(),[&](int u,int v){return d[u]<d[v];});
        priority_queue<pii>pq;for(auto i:{0,1,2})pq.push({trees[i].size(),i});
        while(!pq.empty()){
            auto [sz,i]=pq.top();pq.pop(); 
            if(sz==0)continue;
            auto [sz2,i2]=pq.top();pq.pop(); 
            if(sz2==0)continue;
            cons.push_back(trees[i].back());trees[i].pop_back();
            cons.push_back(trees[i2].back());trees[i2].pop_back();
            pq.push({trees[i].size(),i});
            pq.push({trees[i2].size(),i2});
        }
        if(trees[0].size()+trees[1].size()+trees[2].size()==1){
            for(int i:{0,1,2})if(trees[i].size()==1)cons.push_back(trees[i][0]);
        }
        cons.push_back(centr);
    }else assert(false);
    for(auto&v:cons)v--;
    return cons;
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏李労汎允允允山火丁ミシシミシヘㇵ|
// |義奏李汎山ビ丁ミミ丁ヘㇸ　・・・　ㇸ一ㇵ|
// |李汎火ミㇵ一シ　・ㇸ一シ丁丁丁ミ丁ビ火火|
// |せミ一ㇸ　ㇸ一一ㇵ丁せ允汎汎汎允汎洪労労|
// |ミ・一・・　　ヘビ允労和耗和洪允山せ火山|
// |ヘ・・　一ヘ・ミ山労耗陽耗洪山ビミシシ丁|
// |ヘ・　　丁シ・ミ允李群陽和允ビシ・ミㇸ　|
// |シ・　ㇵ丁シ　ミ允和陽陽李山ミ・ミ・丁一|
// |　ㇵミヘシヘㇸビ洪奏覇奏洪火ㇵㇸㇵㇵ一ヘ|
// |ミせシㇵ丁・シ山和義陽李山ヘㇸ・シㇸㇸ　|
// |汎丁一　・ㇵ火労群慶耗允ミ　ㇵㇸヘ一ㇵ・|
// |せミヘシㇵシ山和義陽李せヘ一一ミ・ㇵミ一|
// |せミせ山丁ヘせ労群義和允火火ビ丁シ一・ヘ|
// |ミビビ汎山シシ山李群陽和洪労洪洪允火ミㇸ|
// |・ㇸㇵミビシ　ヘせ洪耗義耗耗労允せビビビ|
// |一シㇸㇵㇸ・　・丁山李奏群奏労允火丁ミ丁|
// |ㇸせシ・・シ　ヘせ労奏義和労李李洪允山せ|
// |一丁一　　・ヘせ労群義和允せ山せせ允汎洪|
// |ヘ　シ丁シㇵ火労群慶耗汎丁ヘヘㇵミ丁ビビ|
// |・シ山汎ビミ允和慶陽労せㇵㇸㇸㇸ　・ㇸㇸ|
// +----------------------------------------+
// 2026 (May 29th) 16:49:45
// end signature
