#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,K;cin>>N>>K;
    vector<vector<short>>doable(N+2,vector<short>(K+1,0));
    doable[N+1][0]=true;
    for(int i=N;i>=1;i--)
        for(int k=0;k<=K;k++){
            doable[i][k]=doable[i+1][k];
            if(k-i>=0)
                doable[i][k]|=doable[i][k-i];
        }
    function<void(vector<int>&,int)>dfs=[&](vector<int>&st,int sum){
        if(st.size()==N-1){
            int r=K-sum;
            if(r>=0&&r%N==0){
                st.push_back(r/N);
                for(auto i:st)cout<<i<<" ";cout<<"\n";
                st.pop_back();
            }
            return;
        }
        if(sum>K)return;
        for(int i=0;1;i++){
            int ns=i*(st.size()+1)+sum;
            if(ns>K)break;
            if(!doable[st.size()+2][K-ns])continue;
            st.push_back(i);
            dfs(st,ns);
            st.pop_back();
        }
    };
    vector<int>st;
    dfs(st,0);
}
