#include "kthnumber.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <new>
using namespace std;
int subtask1(int N) {
    vector<int> v;
    v.push_back(ask_host({0, 1}));
    v.push_back(ask_host({0, 2}));
    v.push_back(ask_host({1, 2}));
    sort(v.begin(), v.end());

    if (v[0] == v[1]) return 1;
    else return 2;
}
int subtask2(int N, int M) {
    int suspect = -1;
    for (int i = 0; i < (N+1)/2; i++) {
        vector<int> query;
        for (int k = 0; k < N/2; k++) {
            query.push_back(k);
        }
        for (int k = 0; k < (N+1)/2; k++) {
            if (k == i) continue;
            query.push_back(k+N/2);
        }
        // for (auto& i : query) printf("%d ", i);
        // printf("\n");
        int v = ask_host(query);
        if (suspect == -1) suspect = v;
        else if (suspect == v) {
            continue;
        } else if (suspect == v+1) {
            return v;
        } else if (suspect == v-1) {
            return suspect;
        } 
    }
    if (suspect <= N/2) return suspect;
    return suspect-1;
    assert(false);
}
int subtask3(int N, int M) {
    if(M<=(N+1)/2){
        map<int,int>freq;
        for(int i=0;i<M+1;i++){
            vector<int>q;
            for(int j=0;j<M+1;j++){
                if(j!=i)q.push_back(j);
            }
            freq[ask_host(q)]++;
        }
        return freq.rbegin()->second;
    } else {
        map<int,int>freq;
        for (int i=M-1;i<N;i++){
            vector<int>q;
            for(int j=0;j<=M-2;j++){
                q.push_back(j);
            }
            q.push_back(i);
            freq[ask_host(q)]++;
        }
        if (freq.size()>1){
            auto [big,bigcnt]=*freq.rbegin();
            int less_than=(N-M+1)-bigcnt;
            return big-less_than;
        }
        int c=freq.begin()->first;
        // well either its all < or all >
        vector<int>q;
        for (int i=M-1;i<N;i++){
            q.push_back(i);
        }
        int s=M-q.size();
        for(int i=0;i<s;i++)q.push_back(i);
        int z=ask_host(q);
        if(z<c)return c-(N-M);
        return c;
    }
}

int find_K(int N, int M, int subtask) {
    if (subtask == 1) return subtask1(N);
    if (subtask == 2) return subtask2(N, M);
    if (subtask == 3) return subtask3(N, M);
    return 1;
}

// begin signature
// +----------------------------------------+
// |覇覇覇義奏和労洪　一ㇵ一・労労労労和耗群|
// |覇義奏労允ㇸビせ山せ火丁シㇵㇸ　火山汎李|
// |奏労山ヘ允李李労山ビシ一・　　　一シビ允|
// |允　允耗群和允ビミシヘ一・丁ミ一　　ヘビ|
// |丁汎陽義和允汎允汎允せビシㇸ　ミシ・ㇸ一|
// |ヘ耗覇陽労和和耗李労汎山ビミヘㇸ　ㇵ一シ|
// |ㇵ耗覇陽群奏労せシヘヘミビ火せ火ビシ一ㇸ|
// |一奏覇義慶耗汎丁ㇸ一丁山洪労李李労汎せミ|
// |火義覇覇群労火一一ビ汎和群陽群和洪允山山|
// |奏覇覇陽労火火山山労群慶義耗汎火ミヘㇵヘ|
// |覇覇陽労汎李李洪和群陽陽労せミㇵシ一ㇵ・|
// |覇義和耗群和汎洪汎洪耗労火ㇵヘシㇸ・一一|
// |覇覇慶義耗汎允丁ミビ汎汎ミ　　丁・　ㇵ・|
// |覇覇覇義李山山シシせ汎洪ビ　ㇸシヘ一ㇸミ|
// |義覇覇覇奏允ミ火丁允李せ允シヘヘシ一シ　|
// |耗覇覇覇義李火せ火労奏汎労火ㇸミ一ヘㇵ一|
// |洪慶覇覇奏汎丁ビ洪耗奏労和山ヘ　ミㇸシシ|
// |奏覇覇義奏洪ビ允耗義奏義和允ミミㇸシㇵ丁|
// |覇覇義奏奏洪山耗慶奏慶義耗汎ビヘㇸ・一ヘ|
// |覇陽慶和李李洪群義李奏陽群李汎せ火ビ火シ|
// +----------------------------------------+
// 2026 (April 4th) 17:22:47
// end signature




