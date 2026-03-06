#include "crumbs.h"
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) printf(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct E{
    int from,to;
    basic_string<int>bits;
};
vector<vector<E>> adj;
vector<vector<basic_string<int>>> bits={
    {{}}
};
const int BITS=14;
void init(int N, int M, std::vector<int> A, std::vector<int> B) {
    adj.resize(N+1);

    vector<int> prog(6,0);
    for (int i=0;i<M;i++){
        adj[A[i]].push_back({A[i],B[i],basic_string<int>{}});
        adj[B[i]].push_back({B[i],A[i],basic_string<int>{}});
    }
    bits.resize(BITS+10);
    for (int i=1;i<=BITS;i++){
        for(auto e:bits[i-1]){
            bits[i].push_back(e+0);
            bits[i].push_back(e+1);
        }
    }
    for (int i=1;i<=N;i++){
        int rem=adj[i].size();
        if(rem<=1)continue;
        int sk=1;
        for (int k=1;k<=BITS;k++){
            if(rem>=(1<<k))sk=k;
        }
        for (int k=sk;k<=BITS&&rem>0;k++){
            int fillleft=1<<k;
            while (fillleft>0 and rem>0){
                adj[i][--rem].bits=bits[k][prog[k]];
                fillleft--;
                prog[k]++;prog[k]%=(1<<k);
            }
        }
    }
}

const int INF=1e9;
std::vector<int> encode(std::vector<int> bits) {
    std::basic_string<int> ans={1};
    function<void(int,int)> dfs=[&](int node,int l) {
        if(l>=bits.size()) return;
        int bn=-1,bl=0; 
        for (auto& e : adj[node]){
            for(int i=0;i<e.bits.size();i++){
                if(l+i>=bits.size())break;
                if(e.bits[i]!=bits[l+i]) goto out;
            }
            if (e.bits.size()>=bl){
                bl=e.bits.size();
                bn=e.to;
            }
out:;
        }
        dbg("encode: bn %d bl %d len %d\n",bn,bl,l);
        ans+=bn;
        dfs(bn,l+bl);
    };
    dfs(1,0);
    dbg("encode: ");
    for (auto e:ans)dbg("%d ",e);
    dbg("\n");
    return vector<int>(ans.begin(),ans.end());
}

std::vector<int> decode(std::vector<int> walk) {
    int n;
    basic_string<int> bits{};
    for (int i=1;i<=walk.size()-1;i++){
        n=walk[i-1];
        for (auto & e : adj[n]){
            if(e.to==walk[i]){
                bits+=e.bits;
                break;
            }
        }
    }
    bits.resize(1000);
    dbg("decode: ");
    for (auto e:bits)dbg("%d ",e);
    dbg("\n");
    return std::vector<int>(bits.begin(),bits.end());
}
