#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;string S;cin>>N>>S;
    using pii=pair<int,int>;
    vector<bool>A(N+1),B(N+1),C(N+1);
    for(int i=0;i<N;i++)if(S[i]=='A')A[i+1]=true;
    for(int i=0;i<N;i++)if(S[i]=='B')B[i+1]=true;
    for(int i=0;i<N;i++)if(S[i]=='C')C[i+1]=true;
    auto solve2=[&](vector<bool>&A,vector<bool>&B){
        vector<int>a(N+1),b(N+1);map<int,int>M;
        for(int i=1;i<=N;i++){
            a[i]=a[i-1]+A[i];
            b[i]=b[i-1]+B[i];
        }

        for(int i=2;i<=N;i++){
            M[a[i]-b[i]]++;
        }
        int pairs=0;
        for(int i=1;i<=N;i++){
            pairs+=M[a[i-1]-b[i-1]];
            printf("%d = %d (+%d)\n",i,a[i]-b[i],M[a[i-1]-b[i-1]]);
            M[a[i-1]-b[i-1]]--;
        }
        return pairs;
    };
    int ab=solve2(A,B),bc=solve2(B,C),ac=solve2(A,C),abc=0;
    printf("%d %d %d\n",ab,bc,ac);
}
