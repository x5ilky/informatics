#include <algorithm>
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint998244353;
int main() {
    int N;cin>>N;
    vector<vector<string>>Ss(10+1);
    for(int i=1;i<=N;i++){
        string S;cin>>S;
        Ss[S.size()].push_back(S);
    }
    auto tonum=[&](char c){
        if('a'<=c&&c<='z')return c-'a';
        if('A'<=c&&c<='Z')return c-'A'+26;
        if('0'<=c&&c<='9')return c-'0'+52;
    };
    const int M=62;
    auto solve=[&](vector<string>&S){
        vector<vector<mint>>P(M,vector<mint>(M));
        for(auto&s:S){
            string r=s;
            reverse(s.begin(),s.end());
            P[s.front()][s.back()]+=(s.front()==s.back())?(2-(s==r)):1;
        }
        vector<vector<mint>>doublets(M,vector<mint>(M));
        for(int a=0;a<M;a++){
            for(int b=0;b<M;b++){
                for(int c=0;c<M;c++){
                    for(int d=0;d<M;d++){
                        doublets[a][b]+=P[a][c]*P[c][d]*P[d][b];
                    }
                }
            }
        }
    };
    for(int i=1;i<=10;i++)solve(Ss[i]);
}
