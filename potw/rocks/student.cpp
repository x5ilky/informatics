#include "rocks.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;
int find_heavy_rock(int N, vector<int> r) {
    // TODO: modify this to implement your solution!
    int ps[MAX_N] = {0};
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i-1]+r[i-1];
    }
    
    int lo = 0, hi = N;
    while (lo+1 < hi) {
        int mid = (lo+hi)/2;
        
        vector<int> v;
        for (int i = mid; i < hi; i++) 
            v.emplace_back(i);
        int w = use_scales(v);
        int should = ps[hi] - ps[mid];
        if (w == should+1) {
            // one more
            lo = mid;
        } else {
            hi = mid;
        }
    }

    // I'm guessing the answer is 1. This solves the first sample case!
    return lo;
}
