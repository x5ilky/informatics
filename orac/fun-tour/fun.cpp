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
        using pii=pair<int,int>;
        auto piles=[&](){
            array<pii,3>P={pii{trees[0].size(),0},{trees[1].size(),1},{trees[2].size(),2}};
            sort(P.begin(),P.end());
            return P;
        };
        int p=-1;
        while(trees[0].size()+trees[1].size()+trees[2].size()){
            auto P=piles();
            if(P[0].first+P[1].first<=P[2].first){
                int N=P[2].first;
                vector<int>P1,P2;
                for(auto v:trees[P[0].second])P1.push_back(v);
                for(auto v:trees[P[1].second])P1.push_back(v);
                for(auto v:trees[P[2].second])P2.push_back(v);
                sort(P1.begin(),P1.end(),[&](int u,int v){return d[u]<d[v];});
                sort(P2.begin(),P2.end(),[&](int u,int v){return d[u]<d[v];});
                if(p!=P[2].second)swap(P1,P2);
                for(int i=1;i<=N;i++){
                    cons.push_back(P1.back());
                    cons.push_back(P2.back());
                    P1.pop_back();
                    P2.pop_back();
                }
                break;
            }
            int mx=-1,i=-1;
            for(int k=0;k<=2;k++){
                if(k==p)continue;
                if(trees[k].empty())continue;
                if(d[trees[k].back()]>mx){
                    mx=d[trees[k].back()];
                    i=k;
                }
            }
            p=i;
            cons.push_back(trees[i].back());
            trees[i].pop_back();
        }
        cons.push_back(centr);
    }else assert(false);
    for(auto&v:cons)v--;
    return cons;
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏李労ㇸシ丁丁ミシヘ一　シミシㇵ一|
// |義奏李汎ㇵ火丁シㇵ　・　　・・・　ㇸㇵㇵ|
// |李汎一火シ一ㇸ一一ㇵㇵシ丁ビ丁丁丁火せせ|
// |せビミ一・　ㇸ　ㇵ丁せ允汎汎汎允洪洪洪労|
// |丁ミㇸ　シシ　ヘ火允労和耗李洪允山せ火山|
// |せヘ　　ビヘ・ミ山労奏陽和汎せ丁シヘシミ|
// |ビヘ・ㇸビシ・ミ允李群陽李允ビシ　ㇸシ　|
// |ミシ　ヘ丁シ　ミ允和陽陽李山ミ・ミ・ㇸ　|
// |火ヘミ　丁ヘㇸビ洪奏覇奏洪火一一ㇵㇵ一・|
// |丁山シ一ㇸ・シ山和義陽李せヘㇸㇸヘㇸヘヘ|
// |允火一ヘㇵㇵ火労群慶耗允ミ　ㇵㇸヘ一ビミ|
// |せミ火せ丁シ山和義陽李山ヘㇵ一ミ・一ミミ|
// |せミ山洪ビヘせ労群義和允火火火ビミ一　ヘ|
// |ミビシ火丁一シ山労群義和洪労労洪允せミ一|
// |丁一ㇵㇸ一・・ヘ火洪耗陽奏耗洪山火ビ丁ビ|
// |・丁ㇸ一ㇵヘ　ㇸ丁允李奏群奏李允せビ丁丁|
// |ビ・シ　・シ・シせ労群義和労李李洪允せ山|
// |　ミミ・・　ヘせ労群義和允せせせせ允汎汎|
// |　　シビミㇵ火労群慶耗汎丁ヘヘㇵシ丁丁丁|
// |せシ山汎ビミ允和慶群労せㇵㇸ一ㇸ　・・・|
// +----------------------------------------+
// 2026 (June 9th) 20:29:19
// end signature

