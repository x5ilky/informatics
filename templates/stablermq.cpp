#include <bits/stdc++.h>
using namespace std;
template<typename T=int,auto id=[](){return INT_MAX;},auto f=[](int a,int b){return min(a, b);}>
struct stable{
    int N,K;
    vector<vector<int>>st;
    stable(vector<int>A){
        N=A.size();
        K=__lg(N)+2;
        st.resize(K+1,vector<int>(N+1));
        copy(A.begin(),A.end(),st[0].begin());
        for(int i=1;i<=K;i++)
            for(int j=0;j+(1<<i)<=N;j++)
                st[i][j]=f(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    T query_sum(int l,int r){
        T sum=id();
        for(int i=K;i>=0;i--)
            if((1<<i)<=r-l+1){
                sum=f(sum,st[i][l]);
                l+=1<<i;
            }
        return sum;
    }
    T query_min(int l,int r){
        int i=bit_width((unsigned)(r-l+1))-1;
        return f(st[i][l],st[i][r-(1<<i)+1]);
    }
};
