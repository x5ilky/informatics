#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<string>A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>cnt(N+1);
    while(Q--){
        string S;cin>>S;
        int c=0;
        bool found=0;
        for(int i=1;i<=N;i++){
            if(S==A[i]){
                found=true;
                cnt[i]++;
                break;
            }
        }
        if(found)continue;
        vector<int>cand;
        for(int i=1;i<=N;i++){
            int c=0;
            if(A[i].size()!=S.size())continue;
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]!=S[j])c++;
            }
            if(c==1)cand.push_back(i);
        }
        if(cand.size()==1)cnt[cand.back()]++;
        skip:;
    }
    for(int i=1;i<=N;i++)cout<<cnt[i]<<endl;
}
