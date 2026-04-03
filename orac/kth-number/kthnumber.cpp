#include "kthnumber.h"
#include <algorithm>
#include <bits/stdc++.h>
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
        int Q=(N+1)/2+1;
        map<int,int>freq;
        for(int i=1;i<=Q;i++){
            vector<int>q;
            for(int j=1;j<=Q;j++){
                if(j!=i)q.push_back(j);
            }
            freq[ask_host(q)]++;
        }
        return Q-freq.rbegin()->second;
    }
}

int find_K(int N, int M, int subtask) {
    if (subtask == 1) return subtask1(N);
    if (subtask == 2) return subtask2(N, M);
    if (subtask == 3) return subtask3(N, M);
    return 1;
}
