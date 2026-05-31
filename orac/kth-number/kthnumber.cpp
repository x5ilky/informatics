#include "kthnumber.h"
#include <bits/stdc++.h>
using namespace std;
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
        int cnt=0;
        for (int i=M-1;i<N;i++){
            vector<int>q;
            for(int j=0;j<=M-2;j++){
                q.push_back(j);
            }
            q.push_back(i);
            freq[ask_host(q)]++;
            cnt++;
        }
        if (freq.size()>1){
            auto [big,bigcnt]=*freq.rbegin();
            int less_than=(N-M+1)-bigcnt;
            return big-less_than;
        }
        // well either its all < or all >

        int c=freq.begin()->first;
        for (int i=0;cnt<(N+1)/2+1;i++) {
            vector<int>q;
            for (int j=0;j<=M-2;j++) {
                if (j!=i) q.push_back(j);
            }
            q.push_back(M-1);
            q.push_back(M);
            int v=ask_host(q);
            if (v>c) return c;
            if (v<c) return c-(N-M);
            cnt++;
        }
        if(c<=N/2)return c;
        return c-(N-M);
    }
}

int find_K(int N, int M, int subtask) {
    // if (subtask == 1) return subtask1(N);
    // if (subtask == 2) return subtask2(N, M);
    /* if (subtask == 3) */ 
    return subtask3(N, M);
    return 1;
}

// begin signature
// +----------------------------------------+
// |覇覇陽奏和労ㇵビ山允允山火丁ㇵ　耗奏陽義|
// |義奏李汎ヘ山労和耗耗李労允せ丁ヘ・労李耗|
// |李汎一せ和奏和労汎允せビ丁ミミヘ一せ允労|
// |せヘせ李和洪山ビミシㇵ・　　　・ㇸ　ビ允|
// |ㇸシ火山允一ㇵㇵ　ㇸ一ㇸ　ㇸシヘㇸ　　丁|
// |　・一　ㇵミㇵ・ヘ一ㇸ一ヘヘ・一丁ミㇸ　|
// |・・ㇵ一ㇵヘㇸ一・ㇸヘヘㇵ　ㇵヘ　シビ一|
// |・・一一ㇸ・一ㇵㇸミ火せせ丁ㇵㇸミ　シ山|
// |　ㇸ・一ヘミ・　シ山洪洪允せ丁ㇸㇵ一ㇵ火|
// |　ㇸヘㇵ　　ㇸヘ山汎せビ丁ミシ・シ・シ山|
// |・シㇸㇵヘ一一火火ミㇵ・　　　ㇸヘ一ミせ|
// |・シせ丁　ㇸヘシㇸ・ㇵシ丁丁丁シㇵ　一ミ|
// |シ洪汎丁　一ㇸ　ㇵ丁火山汎汎汎山火ミ一・|
// |シ群李せㇵ一一ㇸミせ汎李耗耗李汎允山火シ|
// |・労群洪火一一一ビ允李奏群李汎火丁シシシ|
// |丁ミ李耗允丁・ㇵ火洪耗義奏洪せミ一　ㇸ・|
// |洪允火労洪火ㇵミ允和陽陽李山ミ・ㇵミヘ丁|
// |耗洪ミ允汎火シ山李陽義和山ミ　シせシミ允|
// |奏李ㇵ火せビせ労陽慶耗允ミ　ミ允火一火汎|
// |義耗允一シミ允耗慶陽労せㇵ一火允ミシ山山|
// +----------------------------------------+
// 2026 (May 31st) 16:37:21
// end signature





/*

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

*/
