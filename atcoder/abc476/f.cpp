#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define int long long
signed main() {
    int N,M;cin>>N>>M;
    vector<vector<int>>C(N+1,vector<int>(N+1));
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<int>B(N+1);for(int i=1;i<=N;i++)cin>>B[i];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            C[i][j]=A[i]*B[j]%M;
    vector<vector<int>>addr(N+1,vector<int>(N+1));
    vector<vector<int>>addl(N+1,vector<int>(N+1));
    vector<vector<int>>psC(N+1,vector<int>(N+1));
    auto get=[&](auto&v,int i,int j){
        if(i>=1&&i<=N&&j>=1&&j<=N)return v[i][j];
        return 0ll;
    };
    for(int j=N;j>=1;j--){
        for(int i=1;i<=N;i++){
            int bad=1-(i==1)-(i==N);
            addr[i][j]=get(addr,i-1,j+1)+get(addr,i+1,j+1)-bad*get(addr,i,j+2)+get(C,i,j+1)+C[i][j];
        }
    }
    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            int bad=1-(i==1)-(i==N);
            addl[i][j]=get(addl,i-1,j-1)+get(addl,i+1,j-1)-bad*get(addl,i,j-2)+get(C,i,j-1)+C[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            psC[i][j]=psC[i-1][j]+psC[i][j-1]-psC[i-1][j-1]+C[i][j];
        }
    }
    auto sumsq=[&](int i,int j,int r){
        int r1=max(1ll,i-r),c1=max(1ll,j-r);
        int r2=min(N,i+r),c2=min(N,j+r);
        return psC[r2][c2]-psC[r1-1][c2]-psC[r2][c1-1]+psC[r1-1][c1-1];
    };
    vector<vector<int>>ans(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++){
        int sum=sumsq(i,1,N-1)*(N-1);
        for(int k=N-2;k>=0;k--)sum-=sumsq(i,1,k);
        ans[i][1]=sum;
        for(int j=2;j<=N;j++){
            sum+=addl[i][j-1];
            sum-=addr[i][j];
            ans[i][j]=sum;
        }
    }
    int fin=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            fin^=ans[i][j]+(i-1)*N+j-1;
        }
    }
    cout<<fin<<endl;
}
