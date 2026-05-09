#include "machine.h"
#include <bits/stdc++.h>
#include <random>
using namespace std;
mt19937_64 rdm;
vector<int> find_permutation(int N) {
    vector<int>P(N);iota(P.begin(),P.end(),1);
    int K=0;
    while((K=query(P))>sqrt(N))shuffle(P.begin(),P.end(),rdm);
    int score=K;
    for(int i=1;i<=2*K+1;i++){
    }
    return {};
}
